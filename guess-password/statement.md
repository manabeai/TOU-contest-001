## Guess Password

インタラクティブな問題です。

サーバーは英小文字からなる長さ $N$ のパスワード $S$ を隠し持っています。
このサーバーには致命的な脆弱性があり、以下のクエリを投げることでパスワードの部分的な情報を得ることが出来ます。

- `? X C` : $S$ の $X$ 文字目と $C$ の辞書順での大小関係を質問し、以下の形式で返答を受け取る。
    - `<` : $S$ の $X$ 文字目が $C$ より小さい。
    - `=` : $S$ の $X$ 文字目は $C$ と等しい。
    - `>` : $S$ の $X$ 文字目が $C$ より大きい。

ただし、クエリを投げすぎると攻撃が検知され、ブロックされてしまうので、$1000$ 回以内にパスワード $S$ を特定してください。

### 制約

- $1 \le N \le 250$
- $N$ は整数

### 入出力

パスワードの長さ $N$ が与えられます。
```md
$N$
```

あなたはパスワードを特定するまで最大 $1000$ 回クエリを投げることができます。
```md
? $X$ $C$
```
$X$ と $C$ は以下の条件を満たしている必要があります。
- $1 \le X \le N$
- $X$ は整数
- $C$ は `a` から `z` の英小文字1文字

クエリに対して、`<=>#` のいずれかが返ってきます。それぞれ以下であることを表しています。
- `<` : $S$ の $X$ 文字目が $C$ より小さい。
- `=` : $S$ の $X$ 文字目は $C$ と等しい。
- `>` : $S$ の $X$ 文字目が $C$ より大きい。
- `#` : クエリの条件に満たない出力だった。またはクエリの最大数を超過した。

パスワードが特定できたらパスワードを以下の形式で出力してください。
```md
! $S$
```

この出力の後、ただちにプログラムを終了してください。
また、途中で`#`を受け取ったときにも、ただちに終了してください。

### 注意点

- 出力を行うたびに、末尾に改行を入れて標準出力をflushしてください。そうしなかった場合、ジャッジ結果がTLEやWAとなる可能性があります。
- 解答を出力したとき、または `#` を標準入力から受け取ったとき、ただちにプログラムを終了してください。そうしなかった場合の判定結果は不定です。
- 余計な改行は不正なフォーマットの出力とみなされることに注意してください。
- この問題のジャッジシステムは適応的ではありません。つまり、パスワード $S$ はジャッジとの対話前に決定され、いかなるタイミングでも変更されることはありません。

### 入出力例

|入力|出力  |説明                                                                     |
|:---|:-----|:------------------------------------------------------------------------|
|`2` |      |パスワード $S$ の長さ $N$ が与えられます。                                   |
|    |`? 1 a` |$1$ 文字目と `a` の大小関係を質問します。                                   |
|`=` |      |$1$ 文字目は `a` である。                                                   |
|    |`? 2 a` |$2$ 文字目と `a` の大小関係を質問します。                                   |
|`>` |      |$2$ 文字目は `a` より大きい。                                               |
|    |`? 2 b` |$2$ 文字目と `b` の大小関係を質問します。                                   |
|`=` |      |$2$ 文字目は `b` である。                                                   |
|    |`! ab`  |特定したパスワードを出力します。                                         |

