#include <math.h>
#include <iostream>
using namespace std;
int main() {
  int i, j, size;
  int max;

  string s;
  cout << "ENter size of set : ";
  cin >> size;
  cout << "Enter elements of set : ";
  for (i = 0; i < size; i++) { cin >> s[i];
  }

  max = pow(2, size);

  while (max--) {
    cout << "(";
      for (int i = 0; i < size; i++) {
      (max & 1 << i) && cout << s[i] << ",";
    }
    cout << ")\n";
  }
  return 0;
}
