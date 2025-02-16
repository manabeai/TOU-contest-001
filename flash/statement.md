## 問題文

縦 $H$ 横 $10^{100}$ のグリッドがあります。グリッドの上から $i$ 行目、左から $j$ 列目のマスを $\lparen$ $i$ , $j$ $\rparen$ と呼びます。  
グリッドは最初全て暗闇で覆われています。  
Aoki君はこれから $\lparen$$1$,$A_1$$\rparen$,$\lparen$$1$,$A_2$$\rparen$$\dots$$\lparen$$1$,$A_N$$\rparen$ の $N$ 箇所にライトを置いていきます。  
$\lparen$ $1$ , $A_i$ $\rparen$ に置かれたライトの発する光はそこから $\lparen$ $H$ , $A_i$ $\rparen$ に向かって直線に、$1$ マス進むごとに左右に幅を $1$ マス増やしながら進みます。   
厳密には、 $\lparen$$1$ , $A_i$$\rparen$ に置かれたライトの照らす範囲は $\lparen$$1$ , $A_i$$\rparen$ , $\lparen$$2$ , $A_{i-1}$ $\dots$ $A_{i+1}$ $\rparen$ , $\dots$ , $\lparen$$H$ , $A_{i - H + 1}$ $\dots$ $A_{i + H - 1}$ $\rparen$です。  

![problem image](flash-image.png)

## 制約
- $1 \leq H, N \leq 10^{6}$
- $H \leq A_i \leq 10^{18}$
- $A_i \neq A_j \lparen i \neq j \rparen$
- 入力はすべて整数

## 入力

入力は以下の形式で標準入力から与えられます。  
$H$ $N$  
$A_1$ $A_2$ $\ldots$ $A_N$  

## 出力

ライトで照らされるマスの総数を出力してください。

## サンプル1

### 入力
```
5 3
5 14 10

```

### 出力
```
6

```

## サンプル2

### 入力
```
1000000 1
1000000

```

### 出力
```
1000000000000

```