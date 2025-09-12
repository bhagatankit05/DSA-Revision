#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    // XOR gives bits that differ
    int x = start ^ goal;
    
    // Count set bits in x
    int count = 0;
    while (x) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

int main() {
    int start, goal;
    cin >> start >> goal;
    cout << minBitFlips(start, goal) << "\n";
    return 0;
}
