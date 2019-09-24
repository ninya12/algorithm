#include <bits/stdc++.h>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/12915
// 문자열 마음대로 정렬하기.

void swap(string& str1, string& str2){
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    for(auto i = 0; i < answer.size(); i++){
        for(auto j = 0; j< answer.size(); j++){
            if(answer[i][n] < answer[j][n]){
                swap(answer[i], answer[j]);
            }
            else if(answer[i][n] == answer[j][n]){
                if(answer[i] < answer[j]){
                    swap(answer[i], answer[j]);
                }
            }
        }
    }
    return answer;
}

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main () {
    vector<string> tc = {"abcd", "abcf", "abca"};
    cout << gcd(36, 24);
}