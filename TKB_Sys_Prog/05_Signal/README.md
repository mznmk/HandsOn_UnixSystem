# Tsukuba System Program

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-12/index.html  
https://vimeo.com/channels/1707084  


## 第5週 シグナル

### 1. シグナルの基礎知識

< 概要 >  

- コンピュータは入出力機器からのイベント通知を割り込みという仕組みで受け取る．  
- プロセスには，割り込みに相当するイベント通知のメカニズム（ソフトウェア割り込み）として，シグナルが提供されている．  

入出力機器  

- 割り込みは入出力機器からのイベント通知のために考え出されたものである．  
- 入出力機器はコンピュータに I/O コントローラを通して接続されている．  
- コンピュータは，プロセッサとメモリに加え，キーボード，マウス，ディスプレイ，ディスク，ネットワークインタフェースなどの入出力機器（I/Oデバイス）からなる．  
- 入出力機器は I/O コントローラを通して制御される．  
- プロセッサ，メインメモリ，I/O コントローラはシステムバスに接続されており，システムバスを通してお互いにデータをやり取りしている．  
-  I/O コントローラは，システムバスと入出力機器の間でデータの橋渡しをする．  
- 入出力機器は様々な種類のコンピュータに対応するために，標準的なインタフェース(USB, SATA, ...)を提供している．  
- システムバスはプロセッサ固有のものである．入出力機器の標準的なインタフェースに対応するように，I/O コントローラはプロセッサとのセットで使われるように開発される．  
- システムバスは以下のバスから構成される．  
    アドレスバス  
    データバス  
    制御バス（コントロールバス）   
- データをメインメモリまたは I/O コントローラから取り出す場合，プロセッサは取り出したいデータのあるアドレスをアドレスバスに出す．  
- 該当するアドレスにあるメインメモリまたは I/O コントローラのデータがデータバスに出され，それをプロセッサは取得する．  
- 制御バスは，アドレスバスやデータバスへのアクセス制御を行ったり，I/O コントローラの割り込み要求をプロセッサに通知するために使用される．  

ポーリングと割り込み  

- プロセッサは I/O コントローラに入出力要求を出し，I/O コントローラはその要求を解釈し，I/O デバイスに伝える．I/O デバイスは入出力要求を処理し，結果を I/O コントローラに転送し，プロセッサは I/O コントローラからその結果を受け取る． 
- 入出力処理が終了したかどうかをプロセッサが知るための単純な方法は，プロセッサが I/O コントローラの状態をチェックし続けるというものである．このような I/O デバイスへの入出力要求の処理方法をポーリング (polling) と呼ぶ．  
- 通常，I/O デバイスの処理速度はプロセッサの処理速度と比べて非常に遅いため，ポーリングで入出力処理の終了を待っているとプロセッサの使用率を著しく下げてしまう．また，端末からの入力待ちなどの，ユーザからの入力を待つような処理では，複数の端末からの入力に対する応答性を確保することが難しい．  
- 割り込み (interrupt) は，ポーリングの持つ非効率性を解決するため，入出力処理が終了したことをプロセッサに対し通知するために考え出された方法である．I/O コントローラは，I/O デバイスとの入出力処理が終了したら，プロセッサに対し割り込み要求を出す． プロセッサは割り込み要求を受け付けると，現在実行中の処理を中断し，割り込みを処理するために予め設定されたプログラムを呼び出し，実行する． この割り込み処理のためのプログラムを，割り込みハンドラとか割り込みサービスルーチン (ISR: Interrupt Service Routine) などと呼ぶ． 

	■ 割り込みは時間依存の処理を可能にする  

	- 割り込みが考え出されてから，時間に依存した処理もできるようになった．  
	- 割り込みにより，特定のプロセスや特定のデバイスにかかりきりになることなく，公平に有効にプロセッサを分配活用できるようになった．  

	■ 関数呼び出しは同期処理，割り込みは非同期処理  

	- 割り込み処理は本来のプログラムの処理の流れとは無関係に，非同期的 (asynchronous) に発生する．  
	- 一方，関数呼び出しは同期的 (synchronous) であり，明示的に関数を呼び出し，呼び出された関数で処理が行われ，関数呼び出しから戻ってくる．  
	- OS カーネルでの処理にいつでも割り込まれてしまうのでは，データの一貫性を保つことができないので，プロセッサには割り込みを禁止する命令が用意されている．  

例外  

- 割り込みとは別に，プログラムの実行中にそのプログラムに原因が起因するエラーが起こることがある． このようなエラーのことを例外 (exception) と呼ぶ． 例外が発生した場合，OS カーネルの例外ハンドラ（例外処理のためのプログラム）が起動され対処する．  
- 割り込みと例外が似ている点は，OS カーネルの割り込みハンドラまたは例外ハンドラが起動されるという点，そしてこれらのハンドラを呼び出す命令がプログラム中には含まれていないという点である．  
- 異なっているのは，割り込みハンドラが起動されるのはデバイスなどプログラム外部が要因であるのに対し，例外ハンドラが起動されるのはプログラムの実行が要因であるという点である．  

シグナル  

- ハードウェアからの割り込みや例外は OS カーネルにより処理される．ハードウェアを直接操作できるのは OS カーネルだけであるので，通常のユーザプロセスがハードウェアからの割り込みを直接受けることはない．  
- 割り込みや例外の概念はユーザプロセスとして動作するプログラムにも便利である．非同期的に命令を送りそれに応じた処理を行わせるためにも，割り込みの概念は使用できる．例外が起こった場合に，そのイベントに対するプログラム独自の対処をしたい場合もある．  
- UNIXではプロセッサとメモリというコンピュータの基本的な部分はプロセスとして抽象化されているが，同じように割り込みおよび例外を抽象化したのがシグナル (signal) である． 割り込みハンドラに相当するのがシグナルハンドラである．     
- プロセスは，実行中のプログラムに起因する例外や，プロセス外部からのイベントをシグナルとして受け取る． シグナルが受け取られると，OS カーネルに登録したシグナルハンドラが起動される．  
- プロセス外部からのイベントとしてよく使用されているのが，キーボードから Ctrl-C や Ctrl-Z によるプロセス実行の中止または中断である．これらのキーボードからの入力は，まず OS カーネルに含まれるデバイスを制御するデバイスドライバにより処理され，後にプロセスにシグナルとして通知される．  

### 2. シグナルの利用

< シグナルを用いたプログラミング >  

シグナルの種類とデフォルトの動作  

`man 3 signal`
```sh
No    Name         Default Action       Description
1     SIGHUP       terminate process    terminal line hangup
2     SIGINT       terminate process    interrupt program
3     SIGQUIT      create core image    quit program
4     SIGILL       create core image    illegal instruction
5     SIGTRAP      create core image    trace trap
6     SIGABRT      create core image    abort program (formerly SIGIOT)
7     SIGEMT       create core image    emulate instruction executed
8     SIGFPE       create core image    floating-point exception
9     SIGKILL      terminate process    kill program
10    SIGBUS       create core image    bus error
11    SIGSEGV      create core image    segmentation violation
12    SIGSYS       create core image    non-existent system call invoked
13    SIGPIPE      terminate process    write on a pipe with no reader
14    SIGALRM      terminate process    real-time timer expired
15    SIGTERM      terminate process    software termination signal
16    SIGURG       discard signal       urgent condition present on socket
17    SIGSTOP      stop process         stop (cannot be caught or ignored)
18    SIGTSTP      stop process         stop signal generated from keyboard
19    SIGCONT      discard signal       continue after stop
20    SIGCHLD      discard signal       child status has changed
21    SIGTTIN      stop process         background read attempted from control terminal
22    SIGTTOU      stop process         background write attempted to control terminal
23    SIGIO        discard signal       I/O is possible on a descriptor (see fcntl(2))
24    SIGXCPU      terminate process    cpu time limit exceeded (see setrlimit(2))
25    SIGXFSZ      terminate process    file size limit exceeded (see setrlimit(2))
26    SIGVTALRM    terminate process    virtual time alarm (see setitimer(2))
27    SIGPROF      terminate process    profiling timer alarm (see setitimer(2))
28    SIGWINCH     discard signal       Window size change
29    SIGINFO      discard signal       status request from keyboard
30    SIGUSR1      terminate process    User defined signal 1
31    SIGUSR2      terminate process    User defined signal 2
```

signal システムコール  

- signal システムコールは，シグナルをサポートするために最初に作られたシステムコールである．  
	```c
	typedef void (*sig_t)(int);
	sig_t signal(int sig, sig_t func);
	```
	```c
	void signal_handler(int);
	```
- pause を呼び出したプロセスはシグナルを受け取るまで実行を停止する．  
	```c
	int pause(void);
	```
- signal と pause を使ったプログラム例  
	[signal.c](./signal.c)  
- signal システムコールの最初の（しかしながら System V 系の UNIX まで継承された）仕様は，多くの問題を持っていた．  

sigaction システムコール  

- signal システムコールの混乱状態を解決するために，POSIX では sigaction という新しいシステムコールを導入した．  
	```c
	int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	```
	```c
	struct  sigaction {
			union __sigaction_u __sigaction_u;  /* signal handler */
			sigset_t sa_mask;               /* signal mask to apply */
			int     sa_flags;               /* see signal options below */
	};
	union __sigaction_u {
			void    (*__sa_handler)(int);
			void    (*__sa_sigaction)(int, struct __siginfo *,
						void *);
	};
	#define sa_handler      __sigaction_u.__sa_handler
	#define sa_sigaction    __sigaction_u.__sa_sigaction
	```
- signal のプログラムを，sigaction で "sa_handler" を使うように変更したプログラム 
	[sigaction1.c](./sigaction1.c)  
- sigaction で "sa_sigaction" を使うように変更したプログラム  
	[sigaction2.c](./sigaction2.c)  

### 3. シグナルの応用

受け取りたくないシグナルは無視することができる．  

```c
#define SIG_DFL         (void (*)(int))0
#define SIG_IGN         (void (*)(int))1
```

kill  

- プロセスへシグナルを送るためには kill システムコールを使用する．  
	```c
	int kill(pid_t pid, int sig);
	```
- コマンドライン引数にプロセス ID を受け取り，そのプロセスに対し SIGINT を送るプログラム  
	[kill.c](./kill.c)  

シグナルハンドラ内での処理についての注意  

-  sig_atomic_t は，割り込まれずに書き込みが可能な変数の型である． volatile は型修飾子と呼ばれるもので，型の前に付けて使用する． volatile を付けることによって，コンパイラによる最適化が抑止され，sigint_count に対する読み書きは，必ずメモリに対して行なわれるようになる（sigint_count がレジスタに割り当てられることがなくなる）．  
- このような宣言が必要な理由は，シグナルハンドラの呼び出しが，関数呼び出しのようにプログラムの制御の流れに沿ったものではなく，プログラム外部のイベントに起因し非同期的に起こるものだからである． プログラムの制御の流れに沿っている場合，変数への読み書きはコンパイラの制御下にあるため，最適化により一時的にレジスタに置かれている変数の値が正しく参照される． しかし，シグナルハンドラは，本来のプログラムの制御の流れとは無関係に，プログラムの実行に割り込んで呼び出される． 最適化により変数の値が一時的にレジスタに置かれているところにシグナルハンドラの呼び出しが起こった場合，シグナルハンドラはその最新の値にアクセスすることはできない． また，シグナルハンドラが変数の値を書き換えたとしても，割り込まれたプログラムはその変更に気がつかないこともあり得る．  
- volatile と宣言された変数は必ずメモリに割り当てられるため，どういうタイミングでシグナルによる割り込みが起きても，必ず最新の値を参照することができる． また，sig_atomic_t は割り込まれずに書き込みが可能な変数の型を提供するため，変数の読み書きの途中で割り込まれることがない． 例えば，値を変数の下位バイトには書き込んだが上位バイトにまだ書き込んでいない瞬間に割り込まれることがない． そのため，一貫性のある値を読み書きすることができる． 

### 4. インターバルタイマ 

- ある一定時間ごとにシグナルを発生させ，現在の処理を継続しながら別の処理がしたい場合にはインターバルタイマという機能が使える．  
- インターバルタイマは setitimer システムコールを用いて設定できる．  
	```c
	int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue);
	```
	```c
	struct itimerval {
			struct  timeval it_interval;    /* timer interval */
			struct  timeval it_value;       /* current value */
	};
	struct timeval {
			time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
			suseconds_t  tv_usec;  /* and microseconds */
	};
	```
- ITIMER_REAL を指定した setitimer によって作られるインターバルタイマにより，実際の時間で1秒ごとにシグナルを受け，10回シグナルを受け取ると終了するプログラム  
	[itimer.c](./itimer.c)  

