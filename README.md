# jouhoukougakuzikken_programming
情報工学実験Iのプログラミング演習リポジトリ

# 開発者
- kazu-321
- len-0202
- kawawarika

# TODO
- [ ] プログラムの統合(kazu-321)
- [x] メダル獲得情報の入力(kawawarika)
- [ ] メダル順位の順に、メダル獲得情報を一覧表示()
- [ ] 総獲得メダルの多い順にメダル獲得情報と総獲得数を一覧表示()
- [ ] 国名を入力すると、該当国のメダル順位と各獲得メダル数を表示(len-0202)
- [ ] 国名順にメダル獲得情報を一覧表示()
- [ ] メダル獲得情報をCSV形式ファイルとして読み込み・書き込み

# ビルドコマンド
```bash
gcc main.c input.c sort.c
```

# 実行
```bash
./a.out
```

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