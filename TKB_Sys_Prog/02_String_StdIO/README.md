# Tsukuba System Program 2021 #2

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-04-21/index.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第2週 文字と文字列，標準入出力

### 1. 文字，文字列のデータ表現

- < 文字コード >  

	- ASCIIコード  

	- EUC-JP  

	- バックスラッシュ「＼」と円マーク「\」  

	- さらに詳しい解説  

- < C言語における文字と文字列 >  

	- 文字  
		[char.c](./char.c)  

	- 文字列  
		[string1.c](./string1.c)  
		[string2.c](./string2.c)  
		[string3.c](./string3.c)  
		[string4.c](./string4.c)  

### 2. 標準入出力

- 標準入出力  
	[getcharputchar.c](./getcharputchar.c)  
	[fgetsputs.c](./fgetsputs.c)  
	[fgetsfputs.c](./fgetsfputs.c)  

### 3. 文字操作，文字列操作ライブラリ

- < 文字操作 >  
	[caseconv1.c](./caseconv1.c)  

- < 文字列操作 >  

	- 文字列の長さ  
		[caseconv2.c](./caseconv2.c)  

	- 文字列の比較  

	- 文字や文字列の検索  
		[index.c](./index.c)  

	- 文字列のコピー，連結（1）  
		[strlcpy.c](./strlcpy.c)  

	- 文字列のコピー，連結（2）  
		[snprintf.c](./snprintf.c)  

	- その他の文字列操作関数  

- < 文字列と数値の変換 >  

### 4. ポインタ（2）

- < 動的メモリ確保 >  

	- malloc と free  
		[malloc1.c](malloc1.c)  

	- 使用上の注意  
		[malloc2.c](malloc2.c)  

	- free 後の誤使用  

	- メモリリーク  
		[malloc3.c](malloc3.c)  

