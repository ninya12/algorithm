#include <string>
#include <vector>
#include <iostream>
#include <stack>

// https://programmers.co.kr/learn/courses/30/lessons/42588
// 탑

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<pair<int, int>> ans;
    pair<int, int> temp;
    for(int i = 0; i < heights.size(); i++){
        temp.first = i + 1;
        temp.second = heights[i];
        ans.push_back(temp);
    }
    for(int i = 0; i < heights.size(); i++){
        int k = 0;
        for(int j = i; j>=0; j--){
            if(ans[j].second > heights[i]){
                k = ans[j].first;
                break;
            }
        }
        answer.push_back(k);
    }
    return answer;
}

int main(){
    vector<int> tc = {6,9,5,7,4};
    vector<int> ans = solution(tc);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}