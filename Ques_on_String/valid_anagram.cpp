#include <iostream>
#include <algorithm> // for sort
using namespace std;

bool isAnagram(string s, string t) {
  
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "Yes, it is a valid anagram." << endl;
    } else {
        cout << "No, it is not a valid anagram." << endl;
    }

    return 0;
}
