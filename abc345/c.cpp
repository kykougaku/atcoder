#include <bits/stdc++.h>

using namespace std;
long long nc2(long long n){
    return n*(n-1)/2;
}

int main (){
    string s;
    cin >> s;
    map<char, long long> m;
    for(int i =0; i<s.size(); i++){
        m[s.at(i)]++;
    }
    long long ans = nc2(s.size());
    bool flag = false;
    for(auto p: m){
        if(p.second > 1){
            ans -= nc2(p.second);
            flag = true;
        }
    }
    if(flag){
        ans++;
    }
    cout << ans << endl;
    return 0;
}