#include <bits/stdc++.h>

using namespace std;

// 단순 2중 for문 시간효율에서 탈락.
string solution(vector<string> participant, vector<string> completion) {
    vector<string> temp = participant;
    for(auto i : completion){
        for(auto j = temp.begin(); j != temp.end();){
            if(i==*j){
                j = temp.erase(j, j+1);
                break;
            }
            else j++;
        }
    }

    return temp[0];;
}

// 정렬과 단일 for문을 이용하여 O(nlogn)시간에 풀어내는 방법.
string solution2(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < participant.size(); i++){
        if(participant[i] != completion[i]) return participant[i];
    }

    return *(participant.end()-1);
}

// Hash map 을 이용한 풀이. O(n) 의 복잡도.
string solution3(vector<string> participant, vector<string> completion) {
    // 순서에 상관 없으므로 효율이 좋은 unordered_map 을 사용한다
    unordered_map<string, int> participants;
    // participant에 있는 이름마다 value를 1 씩 증가시켜서 존재함을 표시한다.
    for (string name : participant) {
        ++participants[name];
    }
    // completion에 있는 이름마다 value를 1 씩 감소시켜서 결승점에 도달했음을 표시한다.
    for (string name : completion) {
        --participants[name];
    }
    // 1보다 큰 값을 가진 pair의 key 값이 결승점에 도달하지 못한 사람의 이름.
    for (auto pair : participants) {
        if (pair.second > 0) {
            return pair.first; 
        }
    }
}

int main(){
    vector<string> testCase1 = {"leo", "kiki", "eden"};
    vector<string> testCase2 = 	{"eden", "kiki"};
    vector<string> testCaseA1 = {"mislav", "stanko", "mislav", "ana"};
    vector<string> testCaseA2 = {"mislav", "stanko", "ana"};

    string answer = solution3(testCaseA1, testCaseA2);
    cout << answer << endl;
    return 0;
}