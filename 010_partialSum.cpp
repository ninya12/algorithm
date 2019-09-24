#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12912
// 두 정수 사이 합

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a == b) return a;
    if (a < b) for(int i = a; i <= b; i++) answer += i;
    else for(int i = b; i <= a; i++) answer += i;
    return answer;
}
