# Tsukuba Operating System II 2020

筑波大学／情報科学類 オペレーティングシステムII (2020年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2020/  
http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2020/2021-01-27/index.html  
https://vimeo.com/channels/1707084  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第4週 時刻と時間の管理、プロセスのスケジューリング

### ■今日の大事な話

- ■今日の大事な話  

	- 時刻と時間の管理  

	- プロセスのスケジューリングの関連  

### ■時刻と時間

- < ◆求められる機能 >  

- < ◆カレンダ時刻のAPI >  

- < ◆インターバルタイマのAPI >  

- < ◆時間切れ処理のAPI >  

### ■時刻・時間関連のハードウェア

- < ◆基本的なモデル >  

- < ◆PIT (Programmable Interval Timer) >  

- < ◆CMOS RTC (Real Time Clock) >  

- < ◆Local APIC (Advanced Programmable Interrupt Controller) Timers >  

- < ◆ACPI (Advanced Configuration and Power Interface) >  

- < ◆TSC (Time Stamp Counter) >  

- < ◆HPET(High Precision Event Timer) >  

### ■jiffiesとHZ

- < ◆tick_periodic() >  

- < ◆do_timer() >  

### ■カレンダー時刻の実装

- < ◆struct timekeeper/xtime >  

- < ◆gettimeofday()システム・コール >  

- < ◆update_wall_time() >  

### ■時間切れ処理(タイマ)

- < ◆struct timer_list >  

- < ◆schedule_timeout() >  

- < ◆High-resolution kernel timers >  

### ■実行の遅延

- < ◆空ループ(busy loop) >  

- < ◆time_befefore() >  

- < ◆cond_resched() >  

- < ◆小さな遅延 >  

- < ◆schedule_timeout() >  

### ■スケジューリングの目標

- < ◆スケジューリング・アルゴリズム >  

- < ◆優先順位式スケジューリング(OS一般) >  

- < ◆レディ・キュー(OS一般) >  

### ■プロセス・スケジューリング関連のAPI

- < ◆Unixにおけるプロセスに関するシステム・コール >  

- < ◆ps -lコマンド >  

- < ◆getpriority-pid.c >  

- < ◆nice値の利用法 >  

- < ◆Linux(CFS)での通常のプロセス(非実時間プロセス)でのnice値の意味 >  

- < ◆スケジューリングを行うためのハードウェア >  

### ■Linux task構造体とnice値

- < ◆task_struct構造体 >  

- < ◆policy >  

- < ◆prioとstatic_prio >  

- < ◆getpriority()システム・コール >  

- < ◆se.load.weight >  

- < ◆sched_class >  

### ■スケジューラとレディ・キュー

- < ◆sched_class使い方 >  

- < ◆Linuxの主要なスケジューリング・クラス >  

- < ◆スケジューラ・クラスの設定 >  

- < ◆CFS(Completely Fair Scheduler) >  

- < ◆runqueues(リスト的な見方) >  

- < ◆赤黒木(red-black tree (rbtree)) >  

- < ◆Linux red-black treeの基本操作 >  

- < ◆runqueues(red-black tree) >  

- < ◆__enqueue_entity() >  

- < ◆tickごとの仕事 >  

- < ◆CFSのentity_tick() >  

- < ◆/proc を使ったスケジューラのパラメタの表示 >  



