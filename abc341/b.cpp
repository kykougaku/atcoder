#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> a(n), s(n), t(n);
    for(int i=0; i<n; i++) cin >> a.at(i);
    for(int i=0; i<n-1; i++) cin >> s.at(i)>>t.at(i);

    for(int i=0; i<n-1; i++){
        long long temp = a.at(i) / s.at(i);
        a.at(i+1) += temp * t.at(i);
    }

    cout << a.at(n-1) << endl;

    return 0;
}