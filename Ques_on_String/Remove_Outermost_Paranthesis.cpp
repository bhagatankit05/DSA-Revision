#include<iostream>
#include<string>

using namespace std;

string remOuterParanthesis(string s){
    string result = " ";
    int cnt = 0;

    for(int i=0;i<s.length();i++){
        if (s[i]=='(')
        {
            if (cnt > 0)
            {
                result +=s[i];
            }
            cnt++;
            
        }else{
                cnt--;
                if (cnt>0)
                {
                    result +=s[i];
                }
                
        }
    }
    return result;
}
int main(){
    string s = "(()())(())";
    cout<<remOuterParanthesis(s)<<endl;
    return 0;
}