# Tsukuba System Program

筑波大学／情報科学類 システムプログラム (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~syspro/2021/  
http://www.coins.tsukuba.ac.jp/~syspro/2021/2021-04-21/index.html  
https://vimeo.com/channels/1707084  


## 第2週 文字と文字列，標準入出力

### 1. 文字，文字列のデータ表現

※ 特にメモすることはなし。  

< 文字コード >  

ASCIIコード  

EUC-JP  

バックスラッシュ「＼」と円マーク「\」  

さらに詳しい解説  

< C言語における文字と文字列 >  

文字  

文字列  

### 2. 標準入出力

- C言語では標準入出力を用いることで，基本的な入出力を行うことができる．通常，標準入力はキーボードであり，標準出力は端末画面（ウィンドウ）である．  
- 標準エラー出力と呼ばれるもう一つの出力の口がある．標準エラー出力は，エラーメッセージや警告のメッセージなど例外的な処理に関するメッセージを出力するために使用される．  
- UNIX のシェルは，上記の3つの標準入出力をリダイレクションやパイプによってファイルや他のプログラムに切り替えることができる．  
- 文字，書式で指定されるデータを標準入力から受け取るライブラリ関数  
	```c
	int getchar(void);
	int scanf(const char *format, ...);
	```
- 文字，行，書式で指定される文字列を標準出力に出力するライブラリ関数  
	```c
	int putchar(int c);
	int puts(const char *s);
	int printf(const char *format, ...);
	```
- 引数に与えられたファイルポインタに対して入出力を行うライブラリ関数  
	```c
	int   fgetc(FILE *stream);
	char *fgets(char *s, int size, FILE *stream);
	int   fscanf(FILE *stream, const char *format, ...);
	int   fputc(int c, FILE *stream);
	int   fputs(const char *s, FILE *stream);
	int   fprintf(FILE *stream, const char *format, ...);
	```

### 3. 文字操作，文字列操作ライブラリ

< 文字操作 >  

- 大文字または小文字へ変換する関数  
	```c
	int toupper(int c);  /* 大文字へ変換 */
	int tolower(int c);  /* 小文字へ変換 */
	```
- 文字の種類を判別する関数  
	```c
	int isalnum(int c);   /* 英字または数字？ */
	int isalpha(int c);   /* アルファベット？ */
	int isascii(int c);   /* ASCII 文字？ */
	int isblank(int c);   /* 空白文字（スペースまたはタブ）？ */
	int iscntrl(int c);   /* 制御文字？ */
	int isdigit(int c);   /* 数字？ */
	int isgraph(int c);   /* 表示可能文字？（スペースは含まれない） */
	int islower(int c);   /* アルファベットの小文字？ */
	int isprint(int c);   /* 表示可能文字？（スペースは含まれる） */
	int ispunct(int c);   /* 表示可能文字？（スペースと英数字は含まれない） */
	int isspace(int c);   /* 空白文字？（スペース，タブ，改行文字など） */
	int isupper(int c);   /* アルファベットの大文字？ */
	int isxdigit(int c);  /* 16進数での数字？（0〜9, a〜f, A〜F） */
	```

< 文字列操作 >  

文字列の長さ  

```c
size_t strlen(const char *s);
```

文字列の比較  

```c
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);
```

文字や文字列の検索  

```c
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *index(const char *s, int c);
char *rindex(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
```

文字列のコピー，連結（1）  

```c
size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);
char *strncpy(char *dst, const char *src, size_t n);
char *strncat(char *dst, const char *src, size_t n);
char *strcpy(char *dst, const char *src);
char *strcat(char *dst, const char *src);
```

文字列のコピー，連結（2）  

```c
int snprintf(char *dst, size_t size, const char *format, ...);
```

その他の文字列操作関数  

```c
char  *strdup(const char *s);                          /* 文字列の複製 */
char  *strfry(char *string);                           /* 文字列のランダム化 */
char  *strsep(char **stringp, const char *delim);      /* トークンの切り出し */
char  *strtok(char *s, const char *delim);             /* トークンへの分解 */
size_t strcspn(const char *s, const char *reject);     /* 文字セットに含まれない文字数 */
char  *strpbrk(const char *s, const char *accept);     /* 文字セットに含まれる文字の検索 */
size_t strspn(const char *s, const char *accept);      /* 文字セットに含まれる文字数 */
int    strcoll(const char *s1, const char *s2);        /* ロケールに基づく文字列比較 */
size_t strxfrm(char *dst, const char *src, size_t n);  /* ロケールに基づいた文字列変換 */
```

< 文字列と数値の変換 >  

### 4. ポインタ（2）

< 動的メモリ確保 >  

malloc と free  

```c
void *malloc(size_t size);
void *calloc(size_t count, size_t size);
void free(void *ptr);
```
- malloc によって確保されたメモリ領域の内容は不定であり，0に初期化されているわけではない．  
- calloc により確保されたメモリ領域の内容は0である．  
- free は解放するメモリ領域の内容を消去しない．  
- malloc は領域を確保できない場合にNULLを返すため、そのチェックを忘れないようにする。  

使用上の注意  

- malloc で確保した範囲を超えるメモリ領域にアクセスしてはいけない． 
- アクセスできてしまうと，プログラムが動いたり動かなかったり，データ破壊が起こったり起こらなかったりするため，わかりにくいバグになる．  

free 後の誤使用  

- malloc で確保したメモリ領域を free した後に，その領域にアクセスすると何が起こるかは不定である． 
-  解放したメモリ領域へのアクセスは、データの破壊やデータの不正な読み出しなどのわかりにくい問題を引き起こす。  

メモリリーク  

- メモリリークとは，確保したメモリ領域を解放しないことにより，その領域を使用しておらず使用する予定もないのに，確保したままになることを指す．  
- メモリリークが繰り返し起きた場合，大量にメモリが浪費された状態になる．最終的には，メモリ確保ができなくなる． 

