#include <bits/stdc++.h>

using namespace std;

int main (){
    int q;
    cin >> q;
    vector<int> ans(q);
    for(int datasetindex =0; datasetindex<q; datasetindex++){
        string x, y;
        cin >> x >> y;
        vector<vector<int>> dp(x.size()+1, vector<int>(y.size()+1, 0));
        for(int i = 1; i<=x.size(); i++){
            for(int j = 1; j<=y.size(); j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        ans.at(datasetindex) = dp[x.size()][y.size()];
    }
    for(int i = 0; i<q; i++){
        cout << ans.at(i) << endl;
    }
    return 0;
}