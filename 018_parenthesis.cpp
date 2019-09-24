#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    
    int a=0, b=0;

    if(s[0]==')' || s[s.length()-1]=='(')
        return false;
    
    for(int i=0; i<s.length();i++){
        if(s[i]=='(')
            a++;
        else if(s[i]==')')
            b++;
        
        if(b>a)
            return false;
    }
   
    return true;
}