## 問題文
$N$個の駅があり、駅名は順に $S_1$ $S_2$ $\ldots$ $S_N$  と与えられます。
電車で出発駅 $T$ から到着駅 $U$ まで行くとき、何個の駅を通過するか出力してください。

## 制約
- $T$ は出発駅, $U$ は到着駅
- $T \neq U$
- $T,U$ は $S_1$$\ldots$$S_N$ の中に含まれる
- $N$は整数
- $2 \leq N \leq 1000$
- $T,U$ および $S_1$ $\ldots$ $S_N$ はすべて1文字以上20文字以下の英文字列

## 入力

入力は以下の形式で標準入力から与えられます。  
$T$  
$U$  
$N$  
$S_1$  
$S_2$  
$S_3$  
$\vdots$  
$S_N$  

## 出力
通過する駅の個数を出力してください。

## サンプル1

### 入力
```
Tokyo
Nakano
6
Tokyo
Kanda
Ochanomizu
Yotsuya
Shinjuku
Nakano
```

### 出力
```
4

```
Tokyo駅からNakano駅に行くとき、Kanda,Ochanomizu,Yotsuya,Shinjukuの4つの駅を通過するので、4を出力します。
## サンプル2

### 入力
```
Mitaka
Asagaya
8
Koenji
Asagaya
Ogikubo
NishiOgikubo
Kichijoji
Mitaka
Musashisakai
HigashiKoganei
```

### 出力
```
3
```
上方向へ行かなければならない場合があることに注意してください。
## サンプル3

### 入力
```
Shibuya
Shinjuku
6
Akabane
Ikebukuro
Shinjuku
Shibuya
Ebisu
Osaki
```

### 出力
```
0
```