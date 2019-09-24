#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12928
// 약수의 합.

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> f;
    // 약수를 모두 저장하는 벡터 만들기
    for(int x=1; x<=n; x++){
        if(n%x==0){
            f.push_back(x);
        }
    }
    // 모든 약수의 합
    for(auto i : f) answer += i;
    return answer;
}
