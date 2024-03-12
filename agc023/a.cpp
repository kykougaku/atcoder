#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> a(n),sum(n+1);
    for(long long i = 0; i<n; i++) cin >> a.at(i);
    sum.at(0) = 0;
    for(long long i = 0; i<n; i++){
        sum.at(i+1) = sum.at(i) + a.at(i);
    }
    map<long long, long long> mp;
    for(long long i = 0; i<n+1; i++){
        mp[sum.at(i)] += 1;
    }
    long long ans = 0;
    for(auto x: mp){
        if(x.second > 1){
            ans += x.second * (x.second - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}