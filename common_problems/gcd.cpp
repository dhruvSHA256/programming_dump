#include <iostream>
using namespace std;

int gcd(int n1, int n2) { return (n2 != 0) ? gcd(n2, n1 % n2) : n1; }

int main() {
    int n1, n2;

    cout << "Enter two positive integers: ";
    cin >> n1 >> n2;

    cout << "G.C.D of " << n1 << " & " << n2 << " is: " << gcd(n1, n2);

    return 0;
}
