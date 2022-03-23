# Tsukuba Operating System II 2020

筑波大学／情報科学類 オペレーティングシステムII (2020年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2020/  
http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2020/2021-02-03/index.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第5週 割り込みの後半部、ファイルシステム

### ■今日の大事な話


### ■割り込み、後半部

- < ◆gfp_t gfp_mask >  

- < ◆後半部(bottom half、bottom halves) >  


### ■Tasklet

- < ◆Taskletの構造体の宣言 >  

- < ◆Taskletのハンドラ >  

- < ◆Taskletの実行要求 >  

- < ◆Taskletの利用例 >  


### ■Work Queue

- < ◆Work Queueのワーカ・スレッド >  

- < ◆work_struct構造体 >  

- < ◆Work Queue ハンドラ >

- < ◆flush_scheduled_work() >  

- < ◆alloc_workqueue() >  

- < ◆Work Queueの利用例 >  


### ■割り込みの後半部の選択

- < ◆求められる機能 >  

- < ◆層構造 >  

- < ◆継承／委譲 >  

- < ◆VFSレベルのファイルの概念 >  

- < ◆inode番号 >

- < ◆/etc/fstab >  

- < ◆stat()システム・コールとstatコマンド >  

### ■VFSのオブジェクト

- < ◆struct file >  

- < ◆継承・委譲の実装方法 >  

- < ◆struct file_operations >  

- < ◆struct dentry >  

- < ◆dentryの状態 >  

- < ◆struct inode >  

- < ◆struct inode_operations >  

- < ◆struct super_block >  

- < ◆task_struct と struct file >  

### ■read() システムコールと Ext4 ファイルシステム

- < ◆read() システム・コール >  

- < ◆vfs_read() >  

- < ◆Ext4 の file_operations >  

- < ◆Ext4 の inode >  

- < ◆Ext4のext4_file_read_iter() >  

- < ◆汎用のgeneric_file_read_iter() >  

- < ◆汎用のgeneric_file_buffered_read() >  

### ■mkdir() システムコール

- < ◆mkdir() システム・コール >  

- < ◆vfs_mkdir() >  

