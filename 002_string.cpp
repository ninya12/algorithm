#include <bits/stdc++.h>

// https://programmers.co.kr/learn/courses/30/lessons/12981
// 끝말잇기

using namespace std;

// function that decide who is win.
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    // check vector for redundancy.
    vector<string> temp;
    // check boolean for redundancy.
    bool found = false;
    
    auto i = words.begin();
    // start with second words
    int num = 1, count = 1;
    temp.push_back(*i);
    i++;
    num++;
    
    // from second words to end words.
    while(i!=words.end()){
        // check for redundancy.
        for(auto j : temp){
            if(j == *i){
                found = true;
                break;
            }
        }
        if(found) break;
        
        // input current word to redundancy check vector.
        temp.push_back(*i);
        
        // compare previous word's end char and current word's first char
        if(*((*(i-1)).end()-1) != *(*(i)).begin()){
            found = true;
            break;
        }
        
        // add player number and cycle.
        num++;
        if(num > n){
            num = 1;
            count ++;
        }
        i++;
    }

    // if there is overlap or there is no connecting character, answer [num, count].
    if(found){
        answer.push_back(num);
        answer.push_back(count);
    }
    // if there is no overlap, answer [0, 0].
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    

    return answer;
}

int main(){
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<string> words2 = {"hello", "one", "even", "never", "now", "world", "draw"};
    vector<string> words3 = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
    vector<int> answer = solution(3, words);
    vector<int> answer2 = solution(2, words2);
    vector<int> answer3 = solution(5, words3);
    
    // vector print
    for(auto i : answer)
    {
        cout << i << ", ";
    }
    cout << endl;
    
    // vector print
    for(auto i : answer2)
    {
        cout << i << ", ";
    }
    cout << endl;
    
    // vector print
    for(auto i : answer3)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
