#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> d(n);
    for(long long i = 0; i < n; i++){
        cin >> d.at(i);
    }
    long long ab = a+b;

    for(long long i = 0; i < n; i++){
        d.at(i) %= ab;
    }
    sort(d.begin(), d.end());
    if(abs(d.back() - d.front()) <a){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}