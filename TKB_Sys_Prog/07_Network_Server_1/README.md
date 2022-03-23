# Tsukuba System Program 2021 #7

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-02/index.html  
www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-02/echo-server-nofork-fdopen.html  
www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-02/http-server.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第7週 学習の前に

これは筑波大学の授業用のテキストなので、筑波大学のコンピューターを使って実行することが前提となっています。部外者は使えませんので、ローカルで実行します。  


## 第7週 ネットワーク・プログラミング／サーバ側(1)

### 補足

https://vimeo.com/554274821?embedded=false&source=video_title&owner=110451643  

- < 補足 >  

	- strcat()とstrncpy()  

	- 名前とコメント  

### echoサーバ

https://vimeo.com/554275137?embedded=false&source=video_title&owner=110451643

- < echo-server-nofork-fdopen.c >  
	[echo-server-nofork-fdopen.c](./echo-server-nofork-fdopen.c)  

	- echo-server-nofork-fdopen.c のmain()  

	- echo-server-nofork-fdopen.c のecho_server()  

	- echo_receive_request_and_send_reply()  

	- echo_receive_request()  

	- echo-server-nofork-fdopenの実行例  

### HTTP(前回)

- < HTTPの要求(オプション付き) >  

### http-server

https://vimeo.com/554275288?embedded=false&source=video_title&owner=110451643  

- < http-server.c >  
	[http-server.c](./http-server.c)  

	- http-server.c のhttp_server()  

	- http-server.c の http_receive_request_and_send_reply()   

	- http-server.c の http_receive_request()  

	- http-server.c の http_send_reply()  

	- http-server.c の http_send_reply_bad_request()  

	- http-serverの実行例  

### echoサーバの細かい所

- echoサーバの細かい所  
	www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-02/echo-server-nofork-fdopen.html  

	- print_my_host_port()  

	- tcp_peeraddr_print()  

	- sockaddr_print()  

	- tcp_acc_port()  

	- fdopen_sock()  

### http-serverの細かい所

- http-serverの細かい所  
	www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-02/http-server.html  

	- http-server.c の print_my_host_port_http()  

	- chomp()  

	- http-server.c のtcp_peeraddr_print()  

	- http-server.c のsockaddr_print()  

	- http-serverの細かい所  

	- http-server.c のfdopen_sock()  

### 練習問題

https://vimeo.com/554275547?embedded=false&source=video_title&owner=110451643  

