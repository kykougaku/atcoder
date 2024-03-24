#include <bits/stdc++.h>

using namespace std;

int main (){
    long long h, w, m;
    cin >> h >> w >> m;
    vector<long long> t(m), a(m), x(m);
    for(int i = 0; i < m; i++){
        cin >> t.at(i) >> a.at(i) >> x.at(i);
        a.at(i)--;
    }

    vector<long long> sum1(m+1, 0), sum2(m+1 ,0);
    sum1.at(0) = 0; sum2.at(0) = 0;
    for(int i = 0; i < m; i++){
        if(t.at(i) == 1){
            sum1.at(i+1) = sum1.at(i) + 1;
        }else{
            sum2.at(i+1) = sum2.at(i) + 1;
        }
    }

    map<long long, long long> ans;
    for(int i = 0; i < m; i++){
        if(t.at(i) == 1){
            ans[x.at(i)] = w - min(sum2.at(m) - sum2.at(i+1), w);
        }
        else{
            ans[x.at(i)] = h - min(sum1.at(m) - sum1.at(i+1), h);
        }
    }
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}