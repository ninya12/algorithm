#include<bits/stdc++.h>

// https://programmers.co.kr/learn/courses/30/lessons/12982
// 예산

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    for(int i = 0; i<d.size(); i++){
        if(budget - d[i] < 0) continue;
        budget -= d[i];
        answer++;
    }
    
    return answer;
}