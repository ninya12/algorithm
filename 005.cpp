#include <bits/stdc++.h>

// https://programmers.co.kr/learn/courses/30/lessons/42746
// 가장 큰 수.

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> tempArray = numbers;
    int temp = 0;
    for(int i=0; i<6; i++){
        for(int j =0; j < numbers.size(); j++){
            tempArray[j] = numbers[j] % 10;
        }
    }
    while(!tempArray.empty())
    {
        temp = 0;
        for(auto i : tempArray){
            if(i > temp) temp = i;
        }
        tempArray.erase(find(tempArray.begin(), tempArray.end(), temp));
        auto it = find(tempArray.begin(), tempArray.end(), temp);
        auto Index = distance(tempArray.begin(), it);
        stringstream ss;
        ss << numbers[Index];
        answer += ss.str();
    }
    return answer;
}

bool cmp(const string &a, const string &b) {
	return a + b > b + a ? true : false;
}

string solution2(vector<int> numbers) {
	string answer = "";
	vector<string> strArr;
	for (int i = 0; i < numbers.size(); i++) {
		strArr.push_back(to_string(numbers.at(i)));
	}
	sort(strArr.begin(),strArr.end(),cmp);
	for (string str : strArr) {
		answer += str;
	}
	if (answer[0] == '0')
		return "0";
	return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {6, 10, 2};
    vector<int> v2 = {3, 30, 34, 5, 9};

    string ret1 = solution(v);
    string ret2 = solution(v2);
    return 0;
}
