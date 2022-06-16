# Tsukuba Operating System II 2021 #2

筑波大学／情報科学類 オペレーティングシステムII (2021年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2021/  
http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2021/2022-01-07/index.html
https://vimeo.com/channels/1758392  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第2週 メモリ管理

### ■今日の大事な話

### ■メモリ管理

- < ◆目標 >  

### ■物理メモリの管理

- < ◆ページ構造体 >  

- < ◆ページ構造体のflags(主要部分) >  

- < ◆x86のページ・サイズ >  

- < ◆メモリ・ゾーン >  

- < ◆DMA (Direct Memory Access) >  

- < ◆ページフレームの割当てと開放 >  

- < ◆gfp_t gfp_mask >  

- < ◆外部フラグメンテーション >  

- < ◆Buddyシステム >  

- < ◆Buddyシステムの状態 >  

### ■kmallocとkfree

- < ◆kmalloc() >  

- < ◆kmalloc()のフラグの選択 >  

- < ◆kfree() >  

- < ◆vmalloc()とvfree() >  

### ■スラブアロケータ(slab allocator)

- < ◆free list方式とその問題点 >  

- < ◆スラブ・アロケータの目標 >  

- < ◆ページ・フレーム、スラブ、オブジェクトの関係 >  

- < ◆kmem_cache_create() >  

- < ◆kmem_cache_destroy() >  

- < ◆kmem_cache_alloc()とkmem_cache_free() >  

- < ◆利用例(struct cred) >  

- < ◆/proc/slabinfo >  

### ■ユーザ・プロセスの仮想メモリの実現

- < ◆OSに求められる機能(オペレーティングシステムI復習) >  

- < ◆Unixにおけるメモリに関するシステム・コールとライブラリ >  

- < ◆Unixにおけるプロセスのアドレス空間の基本的な構造 >  

- < ◆実行形式の構造 >  

- < ◆execve() システム・コール >  

### ■Linuxにおけるユーザプロセスのアドレス空間の実装

- < ◆アドレス空間とメモリ・エリア >  

- < ◆task_struct構造体とmm_struct構造体 >  

- < ◆mm_struct構造体 >  

- < ◆vm_area_struct構造体 >  

- < ◆プロセスのアドレス空間の実装 >  

- < ◆プロセスのアドレス空間のレイアウト(動的リンクライブラリ) >  

### ■ページテーブル

- < ◆仮想アドレスと物理アドレス >  

- < ◆1段のページ・テーブル >  

- < ◆多段のページ・テーブル >  

- < ◆x86のページ・テーブル >  

- < ◆x86のページ・テーブル(PAE有効) >  

- < ◆x86_64のページ・テーブル(4レベル) >  

- < ◆x86_64のページ・テーブル(5レベル) >  

### ■ページ・フォールト

- < ◆handle_page_fault() >  

- < ◆handle_mm_fault() >  

- < ◆handle_pte_fault() >  

- < ◆赤黒木(red-black tree (rbtree)) >  

- < ◆Linux red-black treeの基本操作 >  

