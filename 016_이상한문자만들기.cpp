#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/12930
// 이상한 문자 만들기.

string solution(string s) {
    string answer = "";
    int count = 0;
    for(auto i : s){
        if(i==' ') {
            count = 0;
            answer += i;
            continue;
        }
        if(count%2 == 0 && i > 0x60) i -= 0x20;
        else if (count%2 == 1 && i < 0x60) i += 0x20;
        count++;
        answer += i;
    }
    return answer;
}

int main(){
    cout << solution("try hello world") << endl;
    long long n;
    n = 1;
    long long m = sqrt(n);
    if(m * m == n) cout << pow(sqrt(n)+1, 2);
    else cout << -1;
}