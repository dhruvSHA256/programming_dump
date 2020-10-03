#include <bits/stdc++.h>
#include <iostream>

#define LOG(x) cout << #x << "=" << x << endl;
#define endl '\n'

using namespace std;


int main() {
  int i, x, n, temp;
  cin >> n;
  int a[n];
  temp=n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x==1) {
    a[--temp] = 1;
    }
    if(a[i]!=1) a[i]=0;
  }
  for (i = 0; i < n; i++) {
    cout << a[i];
  }
  return 0;
}
