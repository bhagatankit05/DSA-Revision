#include<iostream>
using namespace std;

int main(){

    string num;
    cout<<"Enter numeric string : ";
    cin>>num;

    int n = num.size();
    int loc = -1;

    for (int  i = n-1; i >= 0 ; i--)
    {
        int digit = num[i] - '0';
        if (digit % 2 != 0)
        {
            loc = i;
            break;
        }
        
    }

    if (loc == -1)
    {
         cout << "Largest odd number: " << "" << endl;
    }
    else {
        cout << "Largest odd number: " << num.substr(0, loc + 1) << endl;
    }

    
    

    return 0;
}
