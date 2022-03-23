# Tsukuba System Program 2021 #8

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-09/index.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-09/echo-server-select.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第8週 学習の前に

これは筑波大学の授業用のテキストなので、筑波大学のコンピューターを使って実行することが前提となっています。部外者は使えませんので、ローカルで実行します。  

### echoサーバーをローカルで動かすには

第6週に書きました。  


## 第8週 ネットワーク・プログラミング／サーバ側(2)

### 補足

https://vimeo.com/559869494?embedded=false&source=video_title&owner=110451643  

- < 補足 >  

	- 実習室  

	- データ構造とアルゴリズム  

	- ネットワーク・プログラミングの難しさ  

	- メモリ・リーク・パタン  

	- auto変数  

	- C言語のポインタ  

	-  snprintf()のsize  

	- sizeof()の使い方、配列とポインタの違い  

- < 今日の重要な話 >  

- < 復習 >  

### 複数のクライアントに対するサービスの同時提供

https://vimeo.com/559869621?embedded=false&source=video_title&owner=110451643  

- 複数のクライアントに対するサービスの同時提供  
	[echo-server-nofork-fdopen.c](./echo-server-nofork-fdopen.c)  

	- echo-server-nofork-fdopenへの複数のクライアントの接続  

	- 標準のechoサーバへの複数のクライアントの接続  

- < 標準のechoサーバへの複数のクライアントの接続 >  

### fork()

- < 3回forkするプログラム >  
	[fork-hello.c](./fork-hello.c)  

### echo-server-fork-fdopen.c

https://vimeo.com/559869707?embedded=false&source=video_title&owner=110451643  

- echo-server-fork-fdopen.c  
	[echo-server-fork-fdopen.c](./echo-server-fork-fdopen.c)  

	- echo-server-fork-fdopen.c のmain()  

	- echo-server-fork-fdopen.c のecho_server()  

	- echo-server-fork-fdopen.c のdelete_zombie()  

	- echo-server-fork-fdopen.c のその他の関数  

	- echo-server-fork-fdopenの実行例  

- < 図解 >

### ゾンビ・プロセス

### select()による複数のクライアントに対するサービスの同時提供

http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-09/echo-server-select.html  

### 練習問題

https://vimeo.com/559869778?embedded=false&source=video_title&owner=110451643  

