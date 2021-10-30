#include <iostream>

#define LOG(x) cout << #x << "=" << x << endl;
#define endl '\n'

using namespace std;

long long fastexpo(int n, int m);

int main() {
  int a = 48;
  cout << fastexpo(a, 9);
  return 0;
}

long long fastexpo(int n, int m) {
  if (m == 0) {
    return 1;
  }
  long long r = fastexpo(n, m / 2);
  if (m % 2 == 0) {
    return r * r;
  } else {
    return r * r * n;
  }
}

ll fastexpo(int n, int m) {
  ll res = 1;
  if (m & 1)
    res *= n;
  FOR(m / 2) { n *= n; }
  res = res * n;

  return res;
}
