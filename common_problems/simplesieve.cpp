#include <bits/stdc++.h>
#include <iostream>

#define LOG(x) cout << #x << "=" << x << endl;
#define endl '\n'

using namespace std;

void simpleSieve(int n, vector<int> &primes);

int main() {
  int n;
  vector<int> primes;
  cout << "Enter range : ";
  cin >> n;

  simpleSieve(n, primes);
  for (auto p : primes) {
    cout << p << " ";
  }
  return 0;
}

void simpleSieve(int n, vector<int> &primes) {
  bool mark[n];
  memset(mark, true, sizeof(mark));
  for (int p = 2; p * p < n; p++) {
    if (mark[p] == true) {
      for (int i = p * p; i < n; i += p)
        mark[i] = false;
    }
  }

  for (int p = 2; p < n; p++)
    if (mark[p] == true)
      primes.push_back(p);
}
