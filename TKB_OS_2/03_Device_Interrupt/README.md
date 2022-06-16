# Tsukuba Operating System II 2021 #3

筑波大学／情報科学類 オペレーティングシステムII (2020年) の学習メモです。  

http://www.coins.tsukuba.ac.jp/~yas/coins/os2-2021/  
https://vimeo.com/channels/1758392  

テキストを普通に読むだけだと目が滑ってしまい、頭に内容が入りにくかったので、タイトル・見出しをここに切り出して、頭を整理してからテキストを読みました。  
サンプルコードを動かしながら、頭ではなく身体で理解することを意識しました。  


## 第3週 デバイスドライバと割り込み処理、inb()とoutb()

### ■今日の大事な話

### ■デバイス・ドライバ

- < ◆Unix系OSのデバイス・ドライバの種類 >  

- < ◆メジャー番号とマイナー番号 >  

- < 文字型デバイスの登録 >  

- < ◆file_operations構造体 >  

- < ◆inode 構造体 >  

- < ◆file構造体 >  

- < ◆ioctl()システム・コール >  

- < ◆alloc_chrdev_region() >  

- < ◆device_create() >  

### ■x86 CMOS Real-Time Clock

- < ◆rtc-read-time.c >  

- < ◆drivers/rtc/{class.c,dev.c} >  

- < ◆rtc_dev_open() >  

- < ◆rtc_dev_release() >  

- < ◆rtc_dev_ioctl() >  

- < ◆copy_from_user()とcopy_to_user() >  

- < ◆rtc_read_time() >  

- < ◆入出力の方法 >  

- < ◆outb()とinb() >  

- < ◆CMOS RTCの入出力ポート >  

- < ◆rtc_cmos_read() >  

- < ◆outb()とinb()の実装(インライン関数) >  

- < ◆asm()文 >  

- < ◆outb()とinb()の実装(マクロ) >  

- < ◆/proc/ioports  >  

### ■割り込み

- < ◆割り込みの必要性 >  

- < ◆割り込みとは >  

- < ◆x86の割り込みコントローラ >  

- < ◆Intel 8259 PIC >  

- < ◆APIC >  

- < ◆例外 >  

- < ◆割り込みハンドラ >  

- < ◆割り込み記述子テーブル >  

- < ◆割り込みの前半部分と後半部分 >  

- < ◆割り込み番号の共有 >  

### ■Linuxにおける割り込みハンドラの登録

- < ◆request_irq() >  

- < ◆free_irq() >  

- < ◆irq_handler_t handler >  

- < ◆/proc/interrupts >  

- < ◆x86 CMOS Real-Time Clock rtc_interrupt() >  

### ■Linuxにおける割り込みハンドラの実行

- < ◆x86 Interrupt Descriptor Table (IDT) >  

- < ◆irq_entries_start() >  

- < ◆__handle_irq_event_percp() >  

### ■割り込みハンドラのプログラミングの注意点

- < ◆割り込みコンテキスト(アトミック・コンテキスト) >  

- < ◆割り込みの許可・禁止 >  

- < ★問題(301) x86 CMOS RTCからの月日データの入力 >  

- < ★問題(302) 割り込みの利用 >  

