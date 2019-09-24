#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12901
// 2016년

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int sum = 5;
    int month[13] = {0, 31, 29, 31 , 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for(int i = 1; i < a; i++){
        sum += month[i];
    }
    sum += b;
    sum -= 1;
    answer = day[sum%7];
    
    return answer;
}