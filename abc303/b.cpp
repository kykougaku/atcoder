#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> map(n, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j==0){
                map[a[i][j]-1][a[i][j+1]-1]++;
            }
            else if(j==n-1){
                map[a[i][j]-1][a[i][j-1]-1]++;
            }
            else{
                map[a[i][j]-1][a[i][j-1]-1]++;
                map[a[i][j]-1][a[i][j+1]-1]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j && map[i][j]==0){
                ans++;
            }
        }
    }
    cout << ans/2 << endl;
    return 0;
}