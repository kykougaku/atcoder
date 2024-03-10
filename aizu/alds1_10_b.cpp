#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> r(n), c(n);
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) cin >> r.at(i) >> c.at(i);
    for(int i = 0; i<n-1; i++){
        dp.at(i).at(i+1) = r.at(i) * c.at(i) * c.at(i+1);
    }
    for(int l = 2; l < n; l++){
        for(int i = 0; i < n - l; i++){
            int j = i + l;
            dp.at(i).at(j) = LLONG_MAX;
            for(int k = i; k < j; k++){
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k+1).at(j) + r.at(i) * c.at(k) * c.at(j));
            }
        }
    }
    return 0;
}