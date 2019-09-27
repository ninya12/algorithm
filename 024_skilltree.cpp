#include <string>
#include <vector>
#include <iostream>

// https://programmers.co.kr/learn/courses/30/lessons/49993
// 스킬트리

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    vector<int> check(skill.size());
    auto it = skill_trees.begin();
    while(it!=skill_trees.end()){
        for(int i = 0; i < skill.size(); i++){
            if((*it).find(skill[i]) != string::npos) check[i] = (*it).find(skill[i]);
            else check[i] = 10000;
        }
        
        for(auto i : check) cout << i << " ";

        for(int i = 0; i < check.size() - 1; i ++){
            if(check[i] > check[i+1]){
                answer--;
                break;
            }
        }
        cout << endl;
        it++;
    }
    return answer;
}
