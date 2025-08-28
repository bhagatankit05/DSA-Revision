#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    string temp = s1 + s1;
    
    for (int i = 0; i <= temp.length() - s2.length(); i++) {
        if (temp.substr(i, s2.length()) == s2) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (isRotation(s1, s2))
        cout << "Yes, rotation hai" << endl;
    else
        cout << "No, rotation nahi hai" << endl;

    return 0;
}
