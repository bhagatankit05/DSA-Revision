#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    string words[100];  

    cout << "Enter the words: ";
    for (int i = 0; i < n; i++) {
        cin >> words[i];   
    }

    cout << "Reversed string: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }

    return 0;
}
