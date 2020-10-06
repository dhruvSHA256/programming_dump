#include <bits/stdc++.h>

#include <cstdio>
#include <future>
#include <iostream>

#define LOG(x) cout << #x << "=" << x << endl;
#define endl '\n'

using namespace std;

int occurance(int array[], int low, int high, int search, int lastoccur);

int main() {
    int n, sea, first, last;
    cout << "Enter size of array : ";
    cin >> n;
    int array[n];

    cout << "Enter search term: ";
    cin >> sea;
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> array[i];

    first = occurance(array, 0, n - 1, sea, 0);
    if (first == -1) {
        cout << "None";
        return 0;
    }
    last = occurance(array, 0, n - 1, sea, 1);
    cout << last - first + 1;
    return 0;
}

int occurance(int array[], int low, int high, int search, int lastoccur) {
    int mid, idx = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (array[mid] == search) {
            idx = mid;
            if (lastoccur)
                low = mid + 1;
            else
                high = mid - 1;
        } else if (array[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return idx;
}
