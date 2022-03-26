# Tsukuba Operating System II 2021 #1

筑波大学／情報科学類 オペレーティングシステムII (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2021/  
http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2021/2022-01-07/index.html  
https://vimeo.com/channels/1758392  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第1週 システムコール、Linux task_struct

### ■今日の大事な話

- < ◆参考書 >  

### ■オペレーティングシステムII

- < ◆この授業の狙い >  

- < ◆この授業を受ける意義 >  

- < ◆メタレベルのプログラム >  

- < ◆メタレベルのプログラムとしてのOS >  

- < ◆ シラバス >  

- < ◆この授業の進め方 >  

- < ◆予定 >  

- < ◆Linux >  

### ■システム・コールとライブラリ

- < ◆OSの構造 >  

- < ◆システム・コールのライブラリの違い >  

- < ◆リンク >  

- < ◆hello.cとgcc -S >  

- < ◆printf() のソース・プログラム >  

- < ◆write()システム・コールのマニュアル >  

- < ◆write()システム・コール(ユーザ空間) >  

### ■Linuxカーネルのソース

- < ◆バージョン >  

- < ◆kernel.org >  

- < ◆カーネルのディレクトリ構成 >  

### ■システム・コール

- < ◆システムコールの番号 >  

- < ◆システム・コールの表 sys_call_table >  

- < ◆sys_write() >  

- < ◆エラー番号の例 >  

- < ◆SYSCALL_DEFINEマクロ >  

- < ◆システム・コールの実行のまとめ >  

### ■システム・コールやライブラリを観察するためのコマンド

- < ◆strace コマンド >  

- < ◆ltrace コマンド >  

- < ◆gdb デバッガ >  

- < ◆その他のプロセスを調べるコマンド >  

### ■プロセスとは

- < ◆プロセスの３つの状態 >  

- < ◆プロセスとスレッド >  

### ■利用者から見たプロセスの見え方

- < ◆Unixにおけるプロセスに関するシステム・コール(一部) >  

- < ◆ps lコマンド >  

- < ◆その他のコマンド >  

- < ◆/proc ファイル・システム >  

- < ◆fork() と pid を調べるプログラム >  

- < ◆ppid (parent pid) を調べるプログラム >  

- < ◆fork()によるプロセスの木 >  

- < ◆ユーザ >  

- < ◆グループ >  

- < ◆プロセスの属性 >  

- < ◆idコマンド >  

- < ◆id-simple.c >  

### ■Linux task構造体

- < ◆UID、GIDとアクセス制御 >  

- < ◆task_struct構造体 >  

- < ◆state >  

- < ◆pid_t型 >  

- < ◆struct pid >  

- < ◆pidとtgid >  

- < ◆char comm[TASK_COMM_LEN] >  

- < ◆プロセスの木構造 >  

- < ◆struct task_struct *real_parent >  

- < ◆struct task_struct *parent >  

- < ◆struct list_head children >  

- < ◆struct list_head sibling >  

- < ◆struct cred *cred >  

- < ◆struct cred >  

- < ◆uidとgid >  

- < ◆group_info >  

### ■current

- < ◆getuid()システム・コール >  

- < ◆fork()システム・コール >  

### ■GNU global

- < ◆Emacs gtags-mode >  

