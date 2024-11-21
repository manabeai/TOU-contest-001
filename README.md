
# TOU-contest-001

## rimeの使い方や実装方針
* submoduleとして既にプロジェクトに組み込まれているので各自のインストールは不要
* 既にサンプルとして問題が用意されているので、基本的にはそれをコピペして仕様する
```
a+b                             // 問題名
├── PROBLEM                  // 
├── cpp-correct-all
│   ├── SOLUTION
│   └── main.cc
├── cpp-correct-task1
│   ├── SOLUTION
│   └── main.cc
├── python-correct-all
│   ├── SOLUTION
│   └── main.py
├── python-correct-task1
│   ├── SOLUTION
│   └── main.py
├── statement.md
└── tests
    ├── TESTSET
    ├── all_hand.diff
    ├── all_hand.in
    ├── generator.py
    ├── task1_hand.diff
    ├── task1_hand.in
    └── validator.py
```
### 参考

* 公式wiki  
https://rime.readthedocs.io/ja/latest/

* 非公式ドキュメント  
https://rime-doc.readthedocs.io/ja/latest/intro/overview.html


* わかりやすい解説記事  
https://qiita.com/hiroshi-cl/items/fbd0d0963d8207d33bc6

```
rime/rime.py
```
