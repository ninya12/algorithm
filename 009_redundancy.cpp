#include <bits/stdc++.h>

using namespace std;

// 최초 작성 코드 TLE
vector<int> solution(vector<int> arr) 
{
    vector<int> answer = arr;
    int temp=-1;
    
    // O(N) 반복문 내부에서 비용이 큰 erase 함수를 사용하여 생긴 문제.
    // iterator를 여러가지로 만지게 됨.
    for (auto i = answer.begin(); i != answer.end();){
        if(temp != *i) temp = *i;
        else {
            i = answer.erase(i);
            continue;
        }
        i++;
    }
    return answer;
}

// 개선코드
// 배열 속 중복을 제거하는 unique 함수가 존재. O(N)으로 해결 가능
vector<int> solution2(vector<int> arr) 
{
    vector<int> answer = arr;
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

int main(){
    vector<int> testCase = {1,1,3,3,0,1,1};
    vector<int> answer;
    answer = solution(testCase);

    for(auto i : answer) cout << i << " ";

    return 0;
}