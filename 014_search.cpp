#include <bits/stdc++.h>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42840
// 모의고사

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> tAnswer(3,0);
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2,1,2,3,2,4,2,5};
    vector<int> v3 = {3,3,1,1,2,2,4,4,5,5};
    int temp = 1;
    int max = -1;

    // 주어진 vector요소와 각 요소를 비교
    for(int i=0; i<answers.size();i++){
        // 반복되는 부분을 나머지연산 인덱스로 처리함 0(첫번째)
        if(answers[i] == v1[i%v1.size()]) tAnswer[0]++;
        if(answers[i] == v2[i%v2.size()]) tAnswer[1]++;
        if(answers[i] == v3[i%v3.size()]) tAnswer[2]++;
    }

    // max_element(begin, end) 함수로 대체 가능
    for(auto i : tAnswer){
        if(i>max) max = i;
    }

    // max값과 같다면 answer에 오름차순으로 저장
    for(int i=1; i<=3; i++){
        if(tAnswer[i-1] == max) answer.push_back(i);
    }

    return answer;
}

int main(){
    vector<int> answer = solution({2,1,2,2,2});
    vector<int> answer2 = solution({1,3,2,4,2});
    vector<int> answer3 = solution({1,3,2,4,2,4,2,2,1,5,1,3,2,4,2,4,2,2,1,5});
    for(auto i : answer) cout << i << " ";
    cout << endl;
    for(auto i : answer2) cout << i << " ";
    cout << endl;
    for(auto i : answer3) cout << i << " ";
    cout << endl;
    return 0;
}