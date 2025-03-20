#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<char> stack;
    
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        stack.push_back(c);
        if (stack.size() >= M) {
            bool allSame = true;
            for (int j = 1; j < M; j++) {
                if (stack[stack.size() - 1] != stack[stack.size() - 1 - j]) {
                    allSame = false;
                    break;
                }
            }
            if (allSame) {
                stack.resize(stack.size() - M);
            }
        }
    }

    cout << stack.size() << endl;
}
