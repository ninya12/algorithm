#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42839
// find prime number using permutation.
// 주어진 종이 조각들로 만들 수 있는 수들 중 소수인것의 수를 반환.

// swap char1, char2
// using reference for reducing cost.
void swap(char& s1, char& s2){
    char temp = s1;
    s1 = s2;
    s2 = temp;
}

// whether number is prime or not.
bool isPrime(int n){
    // 1 is not prime.
    if(n == 1 || n < 1) return false;
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}


// str P k. n is str size. se is result set.
void perm(string s, int depth, int n, int k, set<int>& se){
    if(depth == k){
        string t = "";
        for(int i=0; i<k; i++)
            t += s[i];
        // if selected substr t is prime, insert to se for result.
        if(isPrime(stoi(t))) se.insert(stoi(t));
        return;
    }
    
    for(int i = depth; i < n; i++){
        // fix depth - 1, swap depth, i
        swap(s[i], s[depth]);
        // recursive call
        perm(s, depth + 1, n, k, se);
        // for recovery
        swap(s[i], s[depth]);
    }
}

int solution(string numbers) {
    int answer = 0;
    if(numbers.size() < 1 || numbers.size() > 7) return 0;
    set<int> s;
    for(int i = 0; i<numbers.size(); i++){
        perm(numbers, 0, numbers.size(), i+1, s);
    
    // set의 크기가 주어진 문제의 solution. 
    return s.size();
}