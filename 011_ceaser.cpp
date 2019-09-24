#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12926
// 시저암호

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i =0; i<s.size(); i++){
        for(int j=0; j<n; j++)
        {
            // loop 마다 z 이면 a로 바꿔주고 Z이면 A로 바꾼다
            // 이외의 경우 아스키값 +1을 통해 다음 알파벳으로 넘긴다.
            if(s[i]=='z'){
                s[i] = 'a';
            }
            else if (s[i]=='Z'){
                s[i] = 'A';
            }
            else{
                if(s[i]>0x40) s[i] += 1;
            }
        }
    }
    return s;
}