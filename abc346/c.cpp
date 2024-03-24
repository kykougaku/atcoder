#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    set<long long> s;
    long long sum = 0;
    for (long long i = 0; i < n; i++){
        cin >> a.at(i);
        if(a.at(i) <= k){
            s.insert(a.at(i));
        }
    }
    for(auto p : s){
        sum += p;
    }
    cout << (1+k)*k/2 - sum << endl;
    return 0;
}