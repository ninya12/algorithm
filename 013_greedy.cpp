#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int temp;
    // vector initialization to 1
    vector<int> array(n, 1);

    // if lost, minus 1
    for(auto i : lost){
        array[i-1]--;
    }
     
    // if reserve, plus 1
    for(auto i : reserve){
        array[i-1]++;
    }

    // 체육복이 없는 경우 양 옆의 인덱스를 확인하여 2개를 가진 원소가 있는경우 그 원소에서 1을 빼고 현재 인덱스에 1을 더한다.
    for(int i = 0; i < array.size(); i++){
        if(array[i] > 0) continue;
        if(array[i] == 0){
            if(array[i-1] > 1 & i-1>=0){
                array[i]++;
                array[i-1]--;
                continue;
            }
            if(array[i+1] > 1 & i+1<n){
                array[i]++;
                array[i+1]--;
            }

        }
    }
    // 체육복을 가진 요소의 수를 센다
    for(auto i : array){
        if(i>0) answer++;
    }
    return answer;
}

int main(){
    int answer = solution(5, {2, 4}, {1, 3, 5});
    int answer2 = solution(5, {2,4}, {3});
    int answer3 = solution(3, {3}, {1});
    cout << answer << " " << answer2 << " " << answer3;
    return 0;
}