#include "debug.h"

vector<vector<ll>> matscalermultiply(vector<vector<ll>> &A, ll B,
                                     ll mod = MOD) {

  int n = (int)A.size(), m = (int)A[0].size();
  vector<vector<ll>> ans = A;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = ((ans[i][j] % mod) * (B % mod)) % mod;
    }
  }
  return ans;
}

vector<vector<ll>> matmultiply(vector<vector<ll>> &A, vector<vector<ll>> &B,
                               ll mod = MOD) {
  int n1, m1, n2, m2;
  n1 = (int)A.size();
  n2 = (int)B.size();

  // col
  m1 = (int)A[0].size();
  m2 = (int)B[0].size();
  vector<vector<ll>> ans;

  if (m1 == n2) {
    for (int i = 0; i < n1; i++) {
      vector<ll> temp;

      for (int j = 0; j < m2; j++) {
        ll sum = 0;
        for (int k = 0; k < m1; k++) {
          sum = (sum % mod + (A[i][k] % mod * B[k][j] % mod) % mod) % mod;
        }
        temp.push_back(sum);
      }
      ans.push_back(temp);
    }
  }

  return ans;
}

vector<vector<ll>> matexpo(vector<vector<ll>> A, ll e, ll mod = MOD) {
  int n = (int)A.size();
  vector<vector<ll>> ans(n, vector<ll>(n, 0));
  FOR(n) ans[i][i] = 1;
  while (e) {
    if (e & 1)
      ans = matmultiply(ans, A, mod);
    A = matmultiply(A, A, mod);
    e >>= 1;
  }
  return ans;
}

int main() {

  cps();
  vector<vl> a = {{1, 2}, {3, 4}};
  vector<vl> b = {{1, 2}, {3, 4}};
  vector<vl> c = matmultiply(a, b);
  deb(matmultiply(a, b));
  deb(matexpo(a, 0));
  deb(a);
  deb(matscalermultiply(a, 3));
  return 0;
}
