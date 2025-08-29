#include <iostream>
#include <string>
using namespace std;

string longestCommonPrefix(string s1, string s2) {
    string result = "";
    int n = min(s1.size(), s2.size());

    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i])
            result += s1[i];
        else
            break;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string prefix, str;
    cout << "Enter string 1: ";
    cin >> prefix;

    for (int i = 2; i <= n; i++) {
        cout << "Enter string " << i << ": ";
        cin >> str;
        prefix = longestCommonPrefix(prefix, str);

        if (prefix.empty()) {
            break;
        }
    }

    cout << "Longest Common Prefix: " << (prefix.empty() ? "None" : prefix) << endl;
    return 0;
}
