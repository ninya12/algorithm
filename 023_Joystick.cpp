#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/42860
// 조이스틱

using namespace std;

vector<bool> check0(string str, string str2){
    vector<bool> boolean;
    if(str.size() != str2.size()) return boolean;
    for(int i = 0; i < str.size(); i++){
        if(str[i]==str2[i]) boolean.push_back(false);
        else boolean.push_back(true);
    }
    return boolean;
}

int solution(string name) {
    int answer = 0;
    int index =0;
    int size = name.size();
    string start = "";
    vector<bool> check;
    for(int i = 0; i < size; i++){
        start += "A";
    }

    while(1){        
        while(name[index] != start[index]){
            answer++;
            if(name[index] <= 'M' && name[index] >= 'A'){
                start[index]++;
            }
            else{
                if(start[index] == 'A') start[index] = 'Z';
                else start[index]--;
            }
        }
        if(name == start) break;
        check = check0(name, start);
        int left = 0;
        int right = 0;
        for(int i = index+1; i < size + index; i++){
            right++;
            if(check[i%size]){
                break;
            }
        }
        for(int i = index-1; i >= index-size; i--){
            left--;
            if(i >= 0){
                if(check[i]) break;
            }
            else{
                if(check[i+size]) break;
            }
        }

        if(right+left<=0){
            index += right;
            answer += right;
        }
        else{
            if(index+left >= 0) index += left;
            else index = index + left + size;
            answer -= left;
        }
    }
    return answer;
}
