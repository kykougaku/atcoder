#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m), c(m);
    for(int i = 0; i<n; i++) cin >> a.at(i);
    for(int i = 0; i<m; i++) cin >> b.at(i) >> c.at(i);
    sort(a.begin(), a.end());
    return 0;
}