#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// a function that adds 2D vector arr1 and 2d vector arr2
vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2)
{
    int size1 = arr1.size();
    int size2 = arr1[0].size();
    // 2D vector initialization 
    vector<vector<int> > answer(size1, vector<int>(size2, 0));

    for(int i=0;i<arr1.size();i++)
    {
        for(int j=0;j<arr1[0].size();j++)
        {
            // add arr1 and arr2
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}


int main(){
    vector<vector<int> > a;
    vector<vector<int> > b;
    vector<vector<int> > answer;
    // test case a = {{1,2},{2,3}}, b = {{4,5}, {5,8}}
    a.push_back({1,2});
    a.push_back({2,3});
    b.push_back({4,5});
    b.push_back({5,8});

    answer = solution(a, b);

    // 2D vector print to standard output stream
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
