#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    stack<pair<char, int>> st;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (st.empty()) {
            st.push({ c,1 });
        }
        else {
            if (st.top().first == c) {
                st.top().second++;
                if (st.top().second == M) {
                    st.pop();
                }
            }
            else {
                st.push({ c,1 });
            }
        }
    }
    int ans = 0;
    while (!st.empty()) {
        ans += st.top().second;
        st.pop();
    }
    cout << ans << endl;
}
