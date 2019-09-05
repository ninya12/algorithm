#include <bits/stdc++.h>

using namespace std;

// 직사각형 만들기
vector<int> solution(int brown, int red) {
    vector<int> answer({0, 0});
    int b;
    // O(N^1/2)
    for(int a=1; a*a<=red; a++){
        if(red%a == 0){
            // red = a * b
            b = red / a;
            // a * b = red then entirety = (b+2) * (a+2) = red + 4 + 2(a+b) = red + brown
            if(2*(a+b)+4 == brown){
                // width > length
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
