#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12945
// 피보나치 수

using namespace std;

int solution(int n) {
    long long a = 0;
    long long b =1;
    long long fibo = a+b;
    for(int i = 2; i < n; i++){
        a = b;
        b = fibo;
        fibo = a%1234567+b%1234567;
    }
    
    return fibo%1234567;
}
