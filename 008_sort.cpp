#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(auto i : commands){
        temp = array;
        auto it = temp.begin();
        sort(it+i[0]-1, it+i[1]);
        // index = (i[0] -1) + (i[2] - 1) >> 0부터시작
        answer.push_back(*(it +i[0] + i[2] - 2));
    }
    for(auto i : answer) cout << i << " ";

    return answer;
}

int main(){
    vector<int> testCase = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> testCase2 = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    solution(testCase, testCase2);
    return 0;
}