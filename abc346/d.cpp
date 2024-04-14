#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL << 60;

int main (){
    long long n;
    string s;
    cin >> n >> s;
    vector<long long> c(n);
    for(long long i = 0; i < n; i++){
        cin >> c.at(i);
    }
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(2, INF)));
    if(s.at(0) == '0'){
        dp.at(0).at(0).at(0) = 0;
        dp.at(0).at(0).at(1) = c.at(0);
    }
    else{
        dp.at(0).at(1).at(0) = c.at(0);
        dp.at(0).at(1).at(1) = 0;
    }
    for(long long i = 1; i < n; i++){
        if(s.at(i) == '0'){
            dp.at(i).at(0).at(0) = min(dp.at(i-1).at(0).at(1)+0, dp.at(i).at(0).at(0));
            dp.at(i).at(0).at(1) = min(dp.at(i-1).at(0).at(0)+c.at(i), dp.at(i).at(0).at(1));
            dp.at(i).at(1).at(0) = min(dp.at(i-1).at(0).at(0)+0, dp.at(i-1).at(1).at(1)+0);
            dp.at(i).at(1).at(1) = min(dp.at(i-1).at(0).at(1)+c.at(i), dp.at(i-1).at(1).at(0)+c.at(i));
        }
        else{
            dp.at(i).at(0).at(0) = min(dp.at(i-1).at(0).at(1)+c.at(i), dp.at(i).at(0).at(0));
            dp.at(i).at(0).at(1) = min(dp.at(i-1).at(0).at(0)+0, dp.at(i).at(0).at(1));
            dp.at(i).at(1).at(0) = min(dp.at(i-1).at(0).at(0)+c.at(i), dp.at(i-1).at(1).at(1)+c.at(i));
            dp.at(i).at(1).at(1) = min(dp.at(i-1).at(0).at(1)+0, dp.at(i-1).at(1).at(0)+0);
        }
    }
    cout << min(dp.at(n-1).at(1).at(0), dp.at(n-1).at(1).at(1)) << endl;
    return 0;
}