#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n,m;
    cin >> n >> m;
    vector<long long> s(n-1), a(m), ss(n,0);
    for(int i = 0; i < n-1; i++){
        cin >> s.at(i);
        ss.at(i+1) = ss.at(i) + s.at(i);
    }
    for(int i = 0; i < m; i++){
        cin >> a.at(i);
    }
    long long k = 0;
    long long ans = 0;
    for(int i = 0; i < m; i++){
        ans += abs(ss.at(a.at(i)+k) - ss.at(k));
        k += a.at(i);
    }
    cout << ans % 100000 << endl;
    return 0;
}