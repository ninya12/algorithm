#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2)
{
    int size1 = arr1.size();
    int size2 = arr1[0].size();
    vector<vector<int> > answer(size1, vector<int>(size2, 0));

    for(int i=0;i<arr1.size();i++)
    {
        for(int j=0;j<arr1[0].size();j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}


int main(){
    vector<vector<int> > a;
    vector<vector<int> > b;
    vector<vector<int> > answer;
    a.push_back({1,2});
    a.push_back({2,3});
    b.push_back({4,5});
    b.push_back({5,8});

    answer = solution(a, b);

    for(vector<int> vec : answer)
    {
        for(auto i:vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
