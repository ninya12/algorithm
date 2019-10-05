#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

// https://programmers.co.kr/learn/courses/30/lessons/42586
// 기능개발

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> ans;
    for(auto i=0; i<progresses.size(); i++){
        if((100 - progresses[i]) % speeds[i] == 0) ans.push((100 - progresses[i]) / speeds[i]);
        else ans.push((100 - progresses[i]) / speeds[i] + 1);
    }

    int now = ans.front();
    int count = 1;
    while(!ans.empty()){
        ans.pop();
        if(ans.empty()){
            answer.push_back(count);
            break;
        }
        if(ans.front() <= now){
            count++;
        }
        else{
            now = ans.front();
            answer.push_back(count);
            count = 1;
        }
    }

    for(auto i : answer){
        cout << i << endl;
    }

    return answer;
}

int main(){
    solution({93, 30, 55}, {1, 30, 5});
    return 0;
}