#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, q;
    cin >> n >> q;
    vector<long long> r(n), qu(q), sumr(n+1, 0);
    for(int i = 0; i < n; i++) cin >> r.at(i);
    for(int i = 0; i < q; i++) cin >> qu.at(i);
    sort(r.begin(), r.end());
    for(int i = 0; i < n; i++) sumr.at(i+1) = sumr.at(i) + r.at(i);

    for(int i =0; i<q; i++){
        long long ans = lower_bound(sumr.begin(), sumr.end(), qu.at(i)) - sumr.begin() -1;
        if(ans+1<n+1 and sumr.at(ans+1) == qu.at(i)){
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}