#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, bigc;
    cin >> n >> bigc;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a.at(i) >> b.at(i) >> c.at(i);
    vector<pair<long long, long long>> abc(2*n);
    for(int i = 0; i < n; i++){
        abc.at(i) = make_pair(a.at(i), c.at(i));
        abc.at(i+n) = make_pair(b.at(i)+1, -c.at(i));
    }
    sort(abc.begin(), abc.end());

    long long ind_price = 0LL;
    long long ans = 0LL;
    for(int i = 0; i < 2*n - 1; i++){
        ind_price += abc.at(i).second;
        long long start = abc.at(i).first;
        long long end = abc.at(i+1).first;

        ans += min(bigc, ind_price) * (end - start);
    }
    cout << ans << endl;
    return 0;
}