#include <bits/stdc++.h>
using namespace std;

const int INT_MAXI = 2147483647;
const int INT_MINI = -2147483648;

long long buildNumber(string &s, int i, long long result, int sign) {
    if (i >= (int)s.size() || !isdigit(s[i])) return result * sign;

    int digit = s[i] - '0';
    result = result * 10 + digit;

    if (sign == 1 && result > INT_MAXI) return INT_MAXI;
    if (sign == -1 && -result < INT_MINI) return INT_MINI;

    return buildNumber(s, i + 1, result, sign);
}

int myAtoi(string s) {
    int i = 0, n = s.size();

    // Skip leading spaces (recursively)
    while (i < n && s[i] == ' ') i++;

    // 2. Check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Recursively build number
    return (int)buildNumber(s, i, 0, sign);
}

int main() {
    cout << myAtoi("42") << endl;             
    cout << myAtoi("   -42") << endl;         
    cout << myAtoi("4193 with words") << endl;
    cout << myAtoi("words and 987") << endl; 
    cout << myAtoi("-91283472332") << endl;  
}
