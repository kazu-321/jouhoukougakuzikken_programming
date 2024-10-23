# jouhoukougakuzikken_programming
情報工学実験Iのプログラミング演習リポジトリ

# 開発者
- kazu-321
- len-0202
- kawawarika
- ryuusei899

# TODO
- [x] プログラムの統合(kazu-321)
- [x] メダル獲得情報の入力(kawawarika)
- [x] メダル順位の順に、メダル獲得情報を一覧表示(len-0202)
- [x] 総獲得メダルの多い順にメダル獲得情報と総獲得数を一覧表示(kazu-321)
- [x] 国名を入力すると、該当国のメダル順位と各獲得メダル数を表示(len-0202)
- [x] 国名順にメダル獲得情報を一覧表示(ryuusei899)
- [x] メダル獲得情報をCSV形式ファイルとして読み込み・書き込み(kazu-321)

# RUN IN COLAB
[Colaboratoryで実行](https://colab.research.google.com/github/kazu-321/jouhoukougakuzikken_programming/blob/main/colab.ipynb)

# ビルドコマンド
```bash
./build.sh
```
もしくは`build.sh`の中身をコピペ


# 実行
```bash
./a.out
```
windowsなら `a.exe`

# デバッグ
```bash
./a.out debug
```

## プログラム内
```c
printf("hello %s","world");
```
の代わりに
```c
printd("hello %s","world");
```
とすると、標準では出力されなくなります。  
`./a.out debug`と、debugという引数が追加された場合のみprintd関数の出力がされます。
