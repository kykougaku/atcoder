#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++){
        cin >> t.at(i);
    }
    int ans = 1<<30;
    for(int i = 0; i < (1<<n); i++){
        int t0=0, t1=0;
        for(int idx = 0; idx<n; idx++){
            if(i & (1<<idx)){
                t1 += t.at(idx);
            }
            else{
                t0 += t.at(idx);
            }
        }
        ans = min(ans,max(t0, t1));
    }
    cout << ans << endl;
    return 0;
}