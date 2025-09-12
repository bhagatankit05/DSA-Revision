#include <bits/stdc++.h>
using namespace std;

// XOR from 0 to n
int xorUpto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// XOR from L to R
int xorRange(int L, int R) {
    return xorUpto(R) ^ xorUpto(L - 1);
}

int main() {
    int L, R;
    cin >> L >> R;
    cout << xorRange(L, R) << "\n";
    return 0;
}
