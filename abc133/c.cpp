#include <bits/stdc++.h>

using namespace std;

int main (){
    long long l, r;
    cin >> l >> r;
    long long mmin = 2019;
    for(long long i = l; i <= min(r,l+5000); i++){
        for(long long j = i+1; j <= min(r,l+5000); j++){
            long long mod = (i*j)%2019;
            if(mod < mmin){
                mmin = mod;
            }
        }
    }
    cout << mmin << endl;
    return 0;
}