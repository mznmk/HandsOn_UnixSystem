# Lecture Note



## 試す

前半は termdemo.c を実行して、結果を確認するだけ。
後半は termdemo.c を実行して、別の Terminal から signal を送って受け取らせる。  



## 使うコマンド

### pgrep ExecuteName

ExecuteName で ProcessID を取得する

### kill -TERM ProcessID

ProcessID に SIGTERM を送る

### kill -HUP ProcessID

ProcessID に SIGHUP を送る


