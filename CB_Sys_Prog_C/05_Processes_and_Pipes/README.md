# Linux System Programming with C

Chris Brown 先生の講義を HandsOn形式で受講した時の学習メモです。  

https://www.youtube.com/playlist?list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4  
https://www.pluralsight.com/courses/linux-systems-programming  


## 第5章 Processes and Pipes

### 第1節 Entity of Process in Linux System

- プロセスはプログラムのある種のインスタンスといえなくもない。  
- プロセスはいろいろなもので構成されているが、とりあえず一番重要なMemoryを理解する。  
- プロセスメモリーには４つのセグメントがある。  
	- Code   プログラムのコード、読み取り専用のものの領域。  
	- Data   グローバル変数、静的変数の領域。  
	- Stack  一般変数の領域。プログラム実行時に確保され、終了時に開放される。  
	- Heap   プログラム実行時に動的に確保される変数の領域。  
- プログラムは演劇の台本のようなもの、プロセスは俳優のようなもの、と考える。  

### 第2節 Fork System Call and Process Creation in Linux System

- `fork()` を使うとプロセスを複製し、子プロセスをつくることができる。  
- 親プロセス・子プロセスの実行順序は（なにもしなければ）保証されない。  
- なぜ `fork()` が必要なのか？  
	サーバーの待ち受け時の同時多発のタスクなど、分岐して処理したい時に必要。  
- サンプルプログラム `fork_loop.c`   
	親プロセス・子プロセスの実行順序は保証されないことを確認するもの。  

### 第3節 Exec System Call Programming in Linux System

- exec()ファミリー を使うことで、現在のプログラムから他のプログラムを実行することができる。  
- exec()ファミリー には `execl()` `execlp()` `execle()` `execv()` `execvp()` `execvpe()` などがある。  
- たくさんあって混乱しそうだが、以下のように考えると理解しやすい。  
	`l` → 引数をリストで1つずつ渡す  
	`v` → 引数を配列で渡す  
	`e` → 環境変数を配列で渡す  
- サンプルプログラム `tinymenu.c`  
	`execlp()` でプログラム(ps, ls, date)を実行できることを確認するもの。  

### 第4節 Process and it's Lifecycle in Linux System

- プログラムのライフサイクルを考えるため、`exit()` `wait()` をみていく。  
- `exit(n)` 自発的に終了させる。終了ステータスを `n` に入れて返す。(0: success / 1-255: failure)  
- `wait(&status)` 子プロセスの終了を待つ。終了ステータスは `status` に格納される。  
	マクロ `WIFEXITED` で正常終了判定、`WIFSIGNALED` 異常終了判定ができる。  
- サンプルプログラム `exit-status-demo.c`  
	`fork()` `wait()` の挙動を試すためのもの。  
	test1: sleep を短くして子プロセスを正常終了させてみる。  
	test2: `kill (PID)` で SIGTERMシグナルを送って子プロセスを終了させてみる。  
	test2: `kill -9` で SIGSEGVシグナル を送って子プロセスを終了させてみる。  
	test3: NULLポインターに値を代入してsegmentasion faultを起こしてみる。  
- 1つのプロセスでプログラムを実行し続けるより、子プロセスがプログラムの一部を実行するほうが一般的。  
- プロセスライフサイクル  
	`fork()`で子プロセス作成  
	子プロセスの`exec()`で他のプログラム実行  
	→正常終了→その後の処理は実行されずに子プロセス終了  
	→異常終了→その後の処理が実行されて子プロセス終了  
	子プロセスの終了を受け、親プロセスは`wait()`から処理を再開  
- サンプルプログラム `tinyshell.c`  
	プロセスライフサイクルを確認するためのもの。  

### 第5節 Creating PIPES in Linux System

- パイプの作成 (up-stream: fd[1] --pipe--> fd[0]) :down-stream)  
	downstreamがfullならupstreamからの書き込みはブロックされる。
	upstreamがemptyならdownstreamからの読込はブロックされる。  
	```c
	int fd[2];
	pipe(fd);
	```
- ファイルディスクリプターのコピー  
	`dup()`:ファイル記述子 oldfd の複製を作成し、最も小さい未使用のファイル記述子を返す。  
	`dup2()`: 基本は dup() と同じだがnewfd で指定した番号のファイル記述子を返す。既に open しているファイル記述子を指定した場合は、元の記述子は自動的に close される。
	```c
	dup(oldfd);
	dup2(oldfd, newfd);
	```
- パイプの処理の流れ  
	```c
	int p[2];
	pipe(p);
	fork()
	/* Parent */
	dup2(p[0], 0);
	close(p[1]);
	exec(... downstream ...)
	/* Child */
	dup2(p[1], 1);
	close(p[0]);
	exec(... upstream ...)
	```

- パイプは最初両端開いており、不要なものはきちんと閉じることが重要。  
	特に upstream-endの閉じ忘れ(downstream-endの入力の待ち続けが起こる可能性がある) に注意が必要。システムがハングアップする可能性もあるので危険。  

### 第6節 Programming Linux Pipes and Shell

- サンプルプログラム `pipedemo.c`  
	子プロセスで `ls` を実行した結果をパイプで親プロセスに渡し、  
	親プロセスで `sort -r` を実行した結果を標準出力に出力する。  
- サンプルプログラム `pipeshell.c`  
	parserにバグがあってパイプの処理がうまくできておらず、うまく動かない。  
	`exec()` でのコマンド実行を全部子プロセスに投げて親プロセスは管理するのみ、  
	パイプなし/パイプ1個/パイプ2個 に対応できるようにしてあった。  

### 第7節 Pipes in Linux System and Programming Unnamed

- これまで扱ってきたのは匿名パイプであり、それとは別に名前付きパイプがある。 
- 名前付きパイプは `mkfifo` コマンドで作成できる。  
- 名前付きパイプ利用例  
	mkfifo /tmp/demopipe で 名前付きパイプを作成  
	- downstream が開いているパターン  
		cat /tmp/demopipe コマンドを実行する  
		upstream からの入力がないのでブロックされ入力待ち状態となる  
		別のターミナルから 何かを /tmp/demopipe へリダイレクトして流す  
		cat の待ち受けに出力が流れて表示される  
	- downstream が開いていないパターン  
		別のターミナルから 何かを /tmp/demopipe へリダイレクトして流す  
		downstream が開いてないのでブロックされ出力待ち状態となる  
		cat /tmp/demopipe コマンドを実行すると downstream が開く  
		cat の待ち受けに出力が流れて表示される  

