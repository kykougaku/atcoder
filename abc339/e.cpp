#include <bits/stdc++.h>

using namespace std;


int main (){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    vector<vector<int>> dp(n, vector<int>(n, 1));
    for(int i = 1; i < n; i++){
        int maxi = 1;
        for(int j = 0; j<=i; j++){
            if(j<i){
                dp.at(i).at(j) = dp.at(i-1).at(j);
                if(abs(a.at(i)-a.at(j))<=d){
                    maxi = max(maxi, dp.at(i).at(j)+1);
                }
            }
            else{
                dp.at(i).at(j) = maxi;
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp.at(n-1).at(i));
    }
    cout << ans << endl;
    return 0;
}