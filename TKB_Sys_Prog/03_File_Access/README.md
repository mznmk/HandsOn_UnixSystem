# Tsukuba System Program 2021 #3

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-04-28/index.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第3週 ファイルアクセス

### 1. ファイルアクセス（基本）

- < ライブラリ関数を用いたファイルの入出力 >  

	- FILE 構造体  

	- ファイルのコピー  
		[filecopy-lib1.c](./filecopy-lib1.c)  

	- main 関数の引数  
		[args.c](./args.c)  
		[filecopy-lib2.c](./filecopy-lib2.c)  

- < システムコールを用いたファイルの入出力 >  

	- ファイルディスクリプタ  

	- 標準入出力のファイルディスクリプタ  

	- ファイルのコピー  
		[filecoy-syscall.c](./filecopy-syscall.c)  

	- ライブラリ関数とシステムコールの混在  

### 2. ファイルアクセス（応用）

- < ファイルのランダムアクセス >  

- < 自分でバッファを確保してのファイルコピー >  
	[filecopy-buf.c](./filecopy-buf.c)  

### 3. 構造体の入出力

- < 構造体のサイズ >  

	- sizeof  
		[addr.h](./addr.h)  
		[sizeof.c](./sizeof.c)  
		[sizeof_padding.c](./sizeof_padding.c)  

	- データファイルのポータビリティ  

- < 構造体の入出力と動的メモリ確保 >  

	- utmp データの読み込み  
		[utmp.c](./utmp.c)  
		[utmp-list1.c](./utmp-list1.c)  
		[utmp-list2.c](./utmp-list2.c)  

- < ファイルのメモリマッピング >  
	[utmp-mmap()](./utmp-mmap.c)  

### 4. ポインタ（3）

- < バッファへのポインタ >  
	[filecopy-buf-bad.c](./filecopy-buf-bad.c)  

- < データ領域の種類と性質 >  

### 5. バッファオーバーフロー

- バッファオーバーフロー
	[/bufferoverflow.c](./bufferoverflow.c)  

