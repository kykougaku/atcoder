#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, w;
    cin >> n >> w;
    vector<long long> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight.at(i) >> value.at(i);
    vector<vector<long long>> dp(n+1, vector<long long>(w+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j));
        }
        for(int j = 0; j <= w-weight.at(i-1); j++){
            dp.at(i).at(j+weight.at(i-1)) = max(dp.at(i).at(j+weight.at(i-1)), dp.at(i-1).at(j)+value.at(i-1));
        }
    }

    long long ans = 0;
    for(int i = 0; i <= w; i++){
        ans = max(ans, dp.at(n).at(i));
    }
    cout << ans << endl;
    return 0;
}