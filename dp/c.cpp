#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    vector<vector<long long>> dp(n, vector<long long>(3, 0));
    for(int i = 0; i < n; i++) cin >> a.at(i) >> b.at(i) >> c.at(i);

    dp.at(0).at(0) = a.at(0); dp.at(0).at(1) = b.at(0); dp.at(0).at(2) = c.at(0);

    for(int i = 1; i<n; i++){
        dp.at(i).at(0) = max(dp.at(i).at(0), max((dp.at(i-1).at(1)+a.at(i)), (dp.at(i-1).at(2)+a.at(i))));
        dp.at(i).at(1) = max(dp.at(i).at(1), max((dp.at(i-1).at(0)+b.at(i)), (dp.at(i-1).at(2)+b.at(i))));
        dp.at(i).at(2) = max(dp.at(i).at(2), max((dp.at(i-1).at(1)+c.at(i)), (dp.at(i-1).at(0)+c.at(i))));
    }
    cout<<max(dp.at(n-1).at(0), max(dp.at(n-1).at(1), dp.at(n-1).at(2)))<<endl;
    return 0;
}