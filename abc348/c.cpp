#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> a(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> c.at(i)>> a.at(i);
    }
    map<long long, long long> mp;
    for(int i = 0; i < n; i++){
        if(mp.count(a.at(i))){
            mp[a.at(i)] = min(mp[a.at(i)], c.at(i));
        }
        else{
            mp[a.at(i)] = c.at(i);
        }
    }
    long long oishisa = 0;
    for(auto p : mp){
        if(oishisa < p.second){
            oishisa = p.second;
        }
    }
    cout << oishisa << endl;
    return 0;
}