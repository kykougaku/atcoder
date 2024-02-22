#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a.at(i).at(j);
        }
    }
    long long ans = 0;
    for(int i1=0; i1<m; i1++){
        for(int i2=0; i2<m; i2++){
            if(i1==i2) continue;
            long long sum = 0;
            for(int j=0; j<n; j++){
                sum += max(a.at(j).at(i1), a.at(j).at(i2));
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}