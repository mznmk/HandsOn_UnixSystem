# Tsukuba System Program 2021 #5

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-05-12/index.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第5週 シグナル

### 1. シグナルの基礎知識

< 概要 >  

	- 入出力機器  

	- ポーリングと割り込み  

	- 例外  

	- シグナル  

### 2. シグナルの利用

- < シグナルを用いたプログラミング >  

	- シグナルの種類とデフォルトの動作  

	- signal システムコール  
		[signal.c](./signal.c)  

	- sigaction システムコール  
		[sigaction1.c](./sigaction1.c)  
		[sigaction2.c](./sigaction2.c)  

### 3. シグナルの応用

- シグナルの応用  
	[sigaction3.c](./sigaction3.c)  

	- kill  
		[kill.c](./kill.c)  

	- シグナルハンドラ内での処理についての注意  

### 4. インターバルタイマ

- インターバルタイマ  
	[itimer.c](./itimer.c)  

