#include <bits/stdc++.h>

// https://programmers.co.kr/learn/courses/30/lessons/12921
// 소수찾기.

using namespace std;

// 소수 개수 찾기
int solution(int n) {
    int answer = 0;
    vector<int> arr;
    // vector initialization. 0~n
    for(int i=0; i<=n; i++) arr.push_back(i);
    // 1 is not prime
    arr[1] = 0;
    // 2부터 시작. i^2 이 n보다 작을때까지만 처리해주면 된다. 10인경우 3까지만 처리하면 남은게 소수.
    for(int i=2; i*i<n; i++){
        if(arr[i] == 0) continue;
        // 소수로 나눠지는 모든 수는 소수가 아니다.
        for(int j=i+i; j<=n; j+=i) arr[j] = 0;
    }
    // 벡터에 남아있는 값들의 개수.
    for(auto i : arr){
        if(i>0) answer++;
    }
    return answer;
}

// 더 간결하고 짧은 코드
int solution2(int n) {
    int answer = 0;
    // boolean vector를 활용
    vector<bool> tmp(n+1, true);

    for (int i=2; i<=n; i++) {
        // true인 경우가 소수
        if (tmp[i] == true) {
            // 소수의 배수를 모두 false로 만든다.
            for (int j=i+i; j<=n; j += i) tmp[i*j] = false;
            answer++;
        }
    }

    return answer;
}

int main(){
    cout << -3 %2;
    return 0;
}