#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

// https://programmers.co.kr/learn/courses/30/lessons/42587
// 프린터

using namespace std;

bool comp(pair<int, int> n1, pair<int, int>n2){
    return (n1.second < n2.second ? true : false);
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 1;
    vector<pair<int, int>>temp;
    for(auto i=0; i<priorities.size(); i++){
        temp.push_back(pair<int, int>(i, priorities[i]));
    }

    auto it = temp.begin();
    while(!temp.empty()){
        it = max_element(it, temp.end(), comp);
        auto it2 = max_element(temp.begin(), it, comp);
        if(comp(*it, *it2)) it = it2;
        if((*it).first == location){
            return count;
        }
        cout << count << " " << (char)(0x41 + (*it).first) << endl;
        count++;
        temp.erase(it);
        if(it == temp.end()) it = temp.begin();
    }

    return answer;
}

int main(){
    vector<int> tc({2,1,3,2});
    vector<int> tc2({1, 3, 9, 1, 3, 1});
    cout << solution(tc2, 0) << endl;
    return 0;
}
