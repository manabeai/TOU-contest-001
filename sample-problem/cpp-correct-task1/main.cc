#include <iostream>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  volatile long long ans = 0;
  for (long long i = 0; i < a; ++i) ++ans;
  for (long long i = 0; i < b; ++i) ++ans;
  cout << ans << endl;
}
