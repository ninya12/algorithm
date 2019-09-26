#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/42577
// phone_book problem.

using namespace std;

bool solution(vector<string> phone_book) {
    for(auto i : phone_book){
        for(auto j : phone_book){
            // if same, continue.
            if(i==j) continue;
            // if j.find(i) == 0, i is j's prefix. return false.
            if(j.find(i) == 0) return false;
        }
    }
    return true;
}
