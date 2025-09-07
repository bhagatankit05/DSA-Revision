#include <iostream>
using namespace std;

double power(double x, int n) {
    
    if (n == 0)
        return 1;
    
    if (n < 0)
        return 1 / power(x, -n);

    return x * power(x, n - 1);
}

int main() {
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << x << "^" << n << " = " << power(x, n) << endl;
    return 0;
}
