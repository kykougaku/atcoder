#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<long long> c(m);
    for(int i = 0; i < m; i++) cin >> c.at(i);
    vector<long long> dp(n+1, 1000000000);
    dp.at(0) = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i+c.at(j) > n) continue;
            dp.at(i+c.at(j)) = min(dp.at(i+c.at(j)), dp.at(i)+1);
        }
    }
    cout << dp.at(n) << endl;
    return 0;
}