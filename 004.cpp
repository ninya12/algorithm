#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer({0, 0});
    int b;
    for(int a=1; a<pow(red,0.5)+1; a++){
        if(red%a == 0){
            b = red / a;
            if(2*(a+b)+4 == brown){
                if(b>a){
                    answer[0] = b+2;
                    answer[1] = a+2;
                }
                else{
                    answer[0] = a+2;
                    answer[1] = b+2;
                }
            }
        }
    }
    return answer;
}
