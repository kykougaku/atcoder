#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a.at(i);
    vector<map<long long, long long>> mp(n-1);
    mp.at(0)[a.at(0)] = 1;
    for(int i = 1; i < n-1; i++){
        for(auto p : mp.at(i-1)){
            if(0<=p.first+a.at(i) && p.first+a.at(i)<=20)mp.at(i)[p.first + a.at(i)] += p.second;
            if(0<=p.first-a.at(i) && p.first-a.at(i)<=20)mp.at(i)[p.first - a.at(i)] += p.second;
        }
    }
    cout << mp.at(n-2)[a.at(n-1)] << endl;
    return 0;
}