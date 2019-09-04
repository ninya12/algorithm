#include <bits/stdc++.h>
using namespace std;

// make rectangle using 2D position.
vector<int> solution(vector<vector<int> > v) {
    // vector initialization
    vector<int> ans({0, 0});
    // bit operation a xor a = 0, 0 xor b= b
    ans[0] = v[0][0]^v[1][0]^v[2][0];
    ans[1] = v[0][1]^v[1][1]^v[2][1];

    return ans;
}

int main(){
    // test case
    vector<vector<int> > v = {{{1, 4}, {3, 4}, {3, 10}}};
    vector<int> answer = solution(v);
    // vector print
    for(auto i : answer) cout << i << " ";
    return 0;
}
