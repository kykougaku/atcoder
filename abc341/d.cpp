#include <bits/stdc++.h>

using namespace std;

long long mygcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main (){
    long long n,m,k;
    cin >> n >> m >> k;
    long long gcd = mygcd(n,m);
    long long lcm = n*m/gcd;

    vector<long long> ans;

    for(long long i=n; i<lcm; i+=n){
            ans.push_back(i);
    }
    for(long long i=m; i<lcm; i+=m){
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    long long size = ans.size();
    long long count = k/size;
    long long mod = k%size;

    if(mod == 0){
        cout << ans.at(size-1)+lcm*(count-1) << endl;
        return 0;
    }

    cout << ans.at(mod-1)+lcm*count << endl;
    return 0;
}