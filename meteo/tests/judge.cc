#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    // テストライブラリの初期化
    registerTestlibCmd(argc, argv);
    
    
    // 正解出力（正解値）は、入力ファイルから1つの浮動小数点数として読み込む
    double correct = inf.readDouble();
    
    // 提出者の出力値を読み込む
    // ※ 提出者の出力が複数ある場合は、必要に応じてループ処理等で読み込みます
    double contestant = ouf.readDouble();
    
    // // 余計な出力がないかチェック（余計な空白は readSpace() で処理可能）
    // ouf.readSpace();
    // if (!ouf.eof()) {
    //     quitf(_fail, "Extra output is found.");
    // }
    
    // 許容誤差（絶対誤差・相対誤差の閾値）
    double eps = 1e-6;
    
    // 絶対誤差と相対誤差を計算
    double absError = fabs(correct - contestant);
    double relError = absError / max(1.0, fabs(correct));
    
    // どちらかの誤差が eps 以下なら Accepted とする（または両方とも eps 以下でよいなど、問題に応じて調整）
    if (absError <= eps || relError <= eps) {
        quitf(_ok, "Accepted: abs error = %.8f, rel error = %.8f", absError, relError);
    } else {
        quitf(_wa, "Wrong answer: expected %.8f, found %.8f; abs error = %.8f, rel error = %.8f",
              correct, contestant, absError, relError);
    }
    
    return 0;
}
