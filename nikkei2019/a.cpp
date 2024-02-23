#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        sum.at(i+1) = sum.at(i) + a.at(i);
    }


    for(int k = 1; k<n+1; k++){
        long long ans = 0;
        for(int i = 0; i <= n-k; i++){
            ans = max(ans, sum.at(i+k) - sum.at(i));
        }
        cout << ans << endl;
    }
    return 0;
}