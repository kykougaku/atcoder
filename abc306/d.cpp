#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> x(n), y(n);
    for(long long i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
    dp.at(0).at(0) = 0;
    
    for(long long i = 1; i < n+1; i++){
        if(x.at(i-1) == 1){
            long long i1 = dp.at(i-1).at(0);
            long long i2 = dp.at(i-1).at(0)+y.at(i-1);
            long long i3 = dp.at(i-1).at(1);
            if(dp.at(i-1).at(0) == -1){
                i1 = -1;
                i2 = -1;
            }
            if(dp.at(i-1).at(1) == -1){
                i3 = -1;
            }
            dp.at(i).at(0) = i1;
            dp.at(i).at(1) = max(i2, i3);
        }

        else{
            long long i4 = max(dp.at(i-1).at(0)+y.at(i-1), dp.at(i-1).at(0));
            long long i5 = dp.at(i-1).at(1)+y.at(i-1);
            long long i6 = dp.at(i-1).at(1);
            if(dp.at(i-1).at(0) == -1){
                i4 = -1;
            }
            if(dp.at(i-1).at(1) == -1){
                i5 = -1;
                i6 = -1;
            }
            dp.at(i).at(0) = max(i4, i5);
            dp.at(i).at(1) = i6;
        }
    }
    if(max(dp.at(n).at(0), dp.at(n).at(1)) == -1) cout << 0 << endl;
    else cout << max(dp.at(n).at(0), dp.at(n).at(1)) << endl;
    return 0;
}