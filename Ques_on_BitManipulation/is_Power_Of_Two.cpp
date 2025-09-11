// important question in coding interviews and competitive programming.

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{

    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main()
{
    cout << isPowerOfTwo(1) << endl;
    cout << isPowerOfTwo(2) << endl;
    cout << isPowerOfTwo(3) << endl;
    cout << isPowerOfTwo(16) << endl;
}
