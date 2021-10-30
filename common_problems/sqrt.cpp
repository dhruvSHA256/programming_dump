#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define LOG(x) cout << #x << "=" << x << endl;

float sqqrt(float n) {
  float sqrt = -1.0;

  LOG(n);

  float l = 0.0, h = n - 1, m;
  float m2;
  int i = 1;
  while (l >= 0.0 && h >= 0.0) {
    m = l + (h - l) / 2;
    m2 = m * m;

    if (abs(m2 - n) <= 0.000001) {
      sqrt = m;
      break;
    }
    if (m2 > n) {
      h = m - 1;
    }
    if (m2 < n) {
      l = m + 1;
    }
  }
  return sqrt;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Pass number";
    return 0;
  }
  float sqrt;
  float n = atof(argv[1]);
  sqrt = sqqrt(n);
  LOG(sqrt);
  return 0;
}
