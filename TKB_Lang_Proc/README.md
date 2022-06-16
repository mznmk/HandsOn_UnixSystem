# Tsukuba Language Processor 

筑波大学／情報科学類 プログラム言語処理 の学習メモです。  

https://www.hpcs.cs.tsukuba.ac.jp/~msato/lecture-note/comp2014/index.html  


### 第1回 言語処理系とは
    インタプリタとコンパイラ
    言語処理系の基本構成
    例題：式の評価
    ＢＮＦと構文木
    解釈実行：インタプリター
    コンパイラとは
    ソースコード 

### 第2回 字句解析の基礎：正規表現によるパターンマッチ

    字句解析と正規表現
    自動字句解析生成プログラム：lex 

### 第3回 数式の構文解析：top-down parserの作り方

    構文規則
    top-down parser の作り方 

### 第4回 構文解析の基礎

    top-down parserとbottom-up parser
    上向き構文解析と還元
    演算子順位構文解析法
    ＬＲ構文解析法
    構文解析生成プログラムyacc 

### 第5回 tiny Cについて

    tiny Cの言語仕様
    tiny Cの文法
    ソースコード 

### 第6回 tiny C 処理系のデータ構造

    構文木(AST)のデータ構造
    ASTの生成
    ASTのリスト
    コード
    シンボル構造体とシンボルテーブル 

### 第7回 構文解析の実際：yaccの使い方

    yaccの動作
    yaccのactionと意味値(semantic value)
    優先度の定義
    あいまいな文法とshift/reduce conflict, reduce/reduce conflict
    エラー回復処理 

### 第8回 tiny C の構文解析

    字句解析のプログラム： yylex (clex.c)
    構文解析のプログラム : cparser.y
    構文解析のエラールーチン yyerror
    構文解析のプログラムのコンパイル 

### 第9回 インタプリタ(1) 式、変数、関数

    変数の扱い
    関数の定義：構文解析部とのインタフェース
    環境(environment) ：変数と値の結合(bind)
    関数呼び出し
    動的結合と静的結合
    配列と文字列の処理 

### 第10回 インタプリタ(2) 関数と文

    文の実行
    IF文の実行
    複文と局所変数
    return文：setjmp/longjumpの使い方
    while文：制御文
    インタプリタのmainプログラム 

### 第11回 スタックマシン

    スタックマシンの命令
    スタックマシンでの演算
    制御文のコード
    関数呼び出しの構造 

### 第12回 スタックマシンへのコンパイラ

    コンパイラのmainプログラム
    コードの生成ルーチン
    スタックマシンの関数呼び出しの構造
    コンパイラのための環境
    関数のコンパイル
    式のコンパイル
    文のコンパイル
    制御文のコンパイル
    関数呼び出しのコンパイル
    局所変数のコンパイル
    return文のコンパイル
    While文、For文
    変数と配列の宣言
    コンパイラとスタックマシンの実行 

### 第13回 レジスタマシンへのコンパイラ

    IA32命令セット：x86(Pentium)プロセッサ
    関数の呼び出し規則
    コンパイラの中間コード
    式のコンパイル：中間コードへの変換
    関数のコンパイル
    文のコンパイル
    中間コードからマシンコードの生成
    変数と配列の宣言、大域変数
    コンパイラと実行 

### 第14回 コード最適化

    命令の実行回数を減らす最適化
    共通部分式の削除(common sub-expression elimination)
    定数の畳込み(constant folding)、定数伝播(constant propagation)
    ループ不変式の削除（loop invariant motion）
    帰納変数の削除(reduction variable elimination)、 演算子の強さの低減(strength reduction)
    ループ展開(loop unrolling)、ループ融合(loop fusion)
    死んだ命令の削除(dead code elimination)
    複写の伝播(copy propagation)
    コードの巻き上げ(code hosting)
    手続き呼び出しの特殊化、式の性質の利用 



