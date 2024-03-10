#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL << 60;

int main (){
    int n, w;
    cin >> n >> w;
    vector<long long> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight.at(i) >> value.at(i); 
    vector<vector<long long>> dp(n+1, vector<long long>(100000+1, INF));
    dp.at(0).at(0) = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 100000; j++){
            dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));
            if(j+value.at(i-1) <= 100000) {
                dp.at(i).at(j+value.at(i-1)) = min(dp.at(i).at(j+value.at(i-1)), dp.at(i-1).at(j)+weight.at(i-1));
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= 100000; i++){
        if(dp.at(n).at(i) <= w) ans = max(ans, (long long)i);
    }
    cout << ans << endl;
    return 0;
}