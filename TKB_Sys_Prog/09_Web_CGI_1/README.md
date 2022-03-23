# Tsukuba System Program 2021 #9

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-16/index.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-16/file-lock.html  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-16/www-cookie.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第9週 学習の前に

これは筑波大学の授業用のテキストなので、筑波大学のコンピューターを使って実行することが前提となっています。部外者は使えませんので、ローカルで実行します。  
Apache2 は Ubuntu と CentOS ではかなり大きな違いがあります。筑波大学のLinuxはおそらくCentOSです。ローカルの Ubuntu で実行できるよう、違いそうなところには注釈をつけました。  
Ubuntu20.04デスクトップで試しましたが、問題はなさそうです。42VirtualBox(xUbuntu)やWindowsのUbuntu(WSL)でも同じかと思われます。  

### UbuntuのApacheでCGIを動かすには

https://www.server-world.info/query?os=Ubuntu_20.04&p=httpd&f=5  
https://ubuntu.perlzemi.com/blog/20200610082714.html  

安全を考えるとroot領域を直接いじりたくはないのですが、軽い動作確認だけだし…と、この方法を選びました。しくじらなければよいだけなのです。  

1. CGIモジュールを有効にします。  

	CGIモジュールを有効にして、Apacheを再起動します。  
	再起動しないと有効になりませんので注意です。  
	```sh
	sudo a2enmod cgid
	sudo systemctl restart apache2
	```

2. スクリプトを配置します。  

	`/usr/lib/cgi-bin/` にcgiスクリプトを配置すれば実行できます。  
	↓ カレントディレクトリーにある `cgi-hello.cgi` をコピーして配置する例  
	```sh
	sudo cp ./cgi-hello.cgi /usr/lib/cgi-bin/
	```

3. ブラウザでアクセスします。  

	↓ `/usr/lib/cgi-bin/` 内の `cgi-hello.cgi` にアクセスする例  
	```
	http://localhost/cgi-bin/cgi-hello.cgi
	```

4. スクリプトを削除します。  

	`/usr/lib/cgi-bin/` からcgiスクリプトを削除します。  
	`cgi-hello.cgi` を削除する例 (慎重にやりましょう)  
	```sh
	sudo rm /usr/lib/cgi-bin/cgi-hello.cgi
	```

5. CGIモジュールを無効に戻します。  

	CGIモジュールを無効にして、Apacheを再起動します。  
	再起動しないと無効に戻りませんので注意です。  
	```sh
	sudo a2disconf cgid
	sudo systemctl restart apache2
	```

### UbuntuのApacheのログの場所

`/var/log/apache2/` です。  


## 第9週 Web CGI プログラミング(1)

### 補足

- 補足  

	- psコマンド  

	- ゾンビ・プロセス  

	- プロセス数の上限  

	- 環境変数  

	- 小さなプログラムの利用  

	- strrchr()が NULL を返す  

### 今日の重要な話

### CGIの考え方

- < CGIの設定(Apache) >  

- < cgi-hello.c >  

	- cgi-hello.cプログラム全体  

	- cgi-hello.cの端末からの実行  
		`cgi-hello.c` をコンパイルして実行します。  
		```sh
		gcc cgi-hello.c -o cgi-hello.cgi
		./cgi-hello.cgi
		```

	- cgi-hello.cのWebブラウザからの実行  
		1. カレントディレクトリーにある `cgi-hello.cgi` を `/usr/lib/cgi-bin/` に配置します。  
			```sh
			sudo cp ./cgi-hello.cgi /usr/lib/cgi-bin/
			```
		2. Firefox (ブラウザ) から実行します。  
			```
			http://localhost/cgi-bin/cgi-hello.cgi
			```
		3. telnet で実行します。  
			1. telnet でローカルホストに接続します。
				```sh
				telnet localhost 80
				```
			2. GET or POST でアクセスして実行します (空行の最終行はリターンです)   
				GET
				```sh
				GET /cgi-bin/cgi-hello.cgi HTTP/1.0
				HOST: localhost

				```
				POST
				```sh
				POST /cgi-bin/cgi-hello.cgi HTTP/1.0
				HOST: localhost
				Content-Length: 0

				```
		4. 終わったら、1. でroot領域に配置したcgiファイル、カレントディレクトリにあるcgiファイルを削除します。  
			```sh
			sudo rm /usr/lib/cgi-bin/cgi-hello.cgi
			rm ./cgi-hello.cgi
			```

### CGIとフォーム

- < HTML記述例 >  

- < 表示例 >  

- < HTTPにより送られるデータの形式 >  

- < Web サーバからCGIプログラムへのパラメタの受け渡し >  

### cgi-printarg.c

- cgi-printarg.c  

	- シェルからのCGIプログラムの実行  
		1. `cgi-printarg.c` をコンパイルして実行します。  
			```sh
			gcc cgi-printarg.c -o cgi-printarg.cgi
			./cgi-printarg.cgi
			```
		2. 環境変数を設定して実行します。  
			GET
			```sh
			export REQUEST_METHOD=GET
			export QUERY_STRING='lastname=name1&firstname=name2&lang=C&email=who@dom'
			./cgi-printarg.cgi
			unset REQUEST_METHOD
			unset QUERY_STRING
			```
			POST (QUERY_STRING を変更した場合、CONTENT_LENGTH の変更が必要)
			```sh
			export REQUEST_METHOD=GET
			export QUERY_STRING='lastname=name1&firstname=name2&lang=C&email=who@dom'
			export CONTENT_LENGTH=51
			./cgi-printarg.cgi
			unset REQUEST_METHOD
			unset QUERY_STRING
			unset CONTENT_LENGTH
			```

	- cgi-printarg.cのmain()  

- < get_query_string() >  

- < read_query_string() >  

	- Webブラウザの表示例  
		1. カレントディレクトリーにある `cgi-printarg.html` を `/var/www/html/` に配置します。  
			```sh
			sudo cp ./cgi-printarg.html /var/www/html/
			```
		2. カレントディレクトリーにある `cgi-printarg.cgi` を `/usr/lib/cgi-bin/` に配置します。  
			```sh
			sudo cp ./cgi-printarg.cgi /usr/lib/cgi-bin/
			```
		3. Firefox (ブラウザ) から実行します。  
			```
			http://localhost/cgi-printarg.html
			```
		4. 終わったら、1. 2. でroot領域に配置しhtml/cgiファイル、カレントディレクトリにあるcgiファイルを削除します。  
			```sh
			sudo rm /var/www/html/cgi-printarg.html
			sudo rm /usr/lib/cgi-bin/cgi-printarg.cgi
			rm ./cgi-printarg.cgi
			```

- < cgi-printarg.cgiの内部関数 >  

	- safe_printenv()、safe_print_string()、html_escape()  

	- decode_url()  

### Apacheの機能

- < アクセスログとエラーログ >  

- < CGI プログラムを実行するプロセスの権限 >  

- < ステータス行も含むヘッダ(Apache non-parsed headers) >  

### CGIでのその他の注意事項

- < ファイルのロック >  
	http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-16/file-lock.html  

- < Webでのcookie >  
	http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-06-16/www-cookie.html

