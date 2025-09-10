#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long solveRec(int idx, int n) {
    if (idx == n) return 1;

    if (idx % 2 == 0)
        return (5 * solveRec(idx + 1, n)) % MOD;
    else
        return (4 * solveRec(idx + 1, n)) % MOD;
}

int main() {
    int n;
    cin >> n;

    cout << solveRec(0, n) % MOD << endl;
    return 0;
}
