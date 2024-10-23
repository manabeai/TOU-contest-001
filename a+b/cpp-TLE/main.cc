#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int c = 0;
  for (int i = 0; i < 10000000000; ++i) {
    c++;
  }
  for (int i = 0; i < b; ++i) {
    c++;
  }
  cout << a+b << endl;
  return 0;
}
