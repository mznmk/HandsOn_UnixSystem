# Tsukuba System Program 2021 #6

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/index.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/getaddrinfo.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/tcp_connect.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/fdopen_sock.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/marshaling.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第6週 学習の前に

これは筑波大学の授業用のテキストなので、筑波大学のコンピューターを使って実行することが前提となっています。部外者は使えませんので、ローカルで実行します。  

### echoサーバーをローカルで動かすには

Ubuntu20.04 にはデフォルトで Apache2 がインストールされており、80番ポートが開いています。それを利用します。  

1. Apache2 のサービスを停止します。
	```sh
	sudo systemctl stop apache2.service
	```
2. echo サーバーを 80番ポートで動かします。  
	次回第7週に登場する [echo-server-nofork-fdopen.c](./echo-server-nofork-fdopen.c) を使います。80番ポートで待ち受けます。  
	```sh
	gcc echo-server-nofork-fdopen.c -o echo-server-fork-fdopen
	./echo-server-fork-fdopen 80
	```
3. Apache2 のサービスを再開します。  
	```sh
	sudo systemctl restart apache2.service
	```

## 第6週 ネットワーク・プログラミング／クライアント側

### 今日の重要な話

https://vimeo.com/551455897?embedded=false&source=video_title&owner=110451643  

- < TA、教員、隣の人の活用 >

- < トップダウン的な理解 >  

- < 例題のプログラムの利用方法 >  

- < Emacs Tips >  

### 1. TCP/IPの基本的な考え方

https://vimeo.com/551456027?embedded=false&source=video_title&owner=110451643  

- < ストリーム >  

- < 通信路の開設 >  

### 2. クライアント・サーバ・モデル

- < クライアントのパタン >  

- < サーバのパタン >  

- < 情報科学類「システムプログラム」独自のクライアントを作成するためのAPI >  

### 3. TCP/IP の汎用クライアント・プログラムとしての telnet コマンド

https://vimeo.com/551456164?embedded=false&source=video_title&owner=110451643  

- < telnet コマンドとは >  

- < TCPの汎用クライアントとしてのtelnet >  

- < telnetによるecho サーバへの接続 >  
	echoサーバーは上記方法でローカルで動かします。  

- < telnetによるdaytime サーバへの接続 >  

- < echoサービスと daytimeサービス >  

- < 様々なOSでのtelnetコマンド >  

### 4. echoサービスのクライアント

https://vimeo.com/551456408?embedded=false&source=video_title&owner=110451643  

- < echo-client-fdopen-one.c >  
	[echo-client-fdopen-one.c](./echo-client-fdopen-one.c)  

	- echo-client-fdopen-one.c のmain()  

	- echo_client_one()  

	- echo_send_request()  

	- echo_receive_reply()  

### 5. HTTP

https://vimeo.com/551456502?embedded=false&source=video_title&owner=110451643  

- < HTTPの要求 >  

	- HTTPの要求での Host: の役割  

- < HTTPの応答 >  

- < telnetによるWWWサーバへのアクセス >  

- < HTTPのメソッド >  

- < HTTPの応答 >  

### 6. 細かい話

- 細かい話  

	- TCP/IP  

	- ソケットAPI  

	- DNS(Domain Name System)  
		http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/getaddrinfo.html	 

	- tcp_connect()の詳細  
		http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/tcp_connect.html	 

	- fdopen_sock()の詳細  
		http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/fdopen_sock.html	 
	- marshaling/unmarshaling  
		http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-26/marshaling.html  

### 練習問題

https://vimeo.com/551456605?embedded=false&source=video_title&owner=110451643  

