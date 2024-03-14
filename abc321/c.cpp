#include <bits/stdc++.h>

using namespace std;

int main (){
    long long k;
    cin >> k;
    vector<long long> all;
    for(long long i = 1; i < (1<<10); i++){
        long long num =0;
        for(long long j = 9; j>=0; j--){
            long long div = (1<<j);
            if((i/div)%2 == 1){
                num = num*10 + j*((i/div)%2);
            }
        }
        all.push_back(num);
    }
    sort(all.begin(), all.end());
    cout << all.at(k) << endl;
    return 0;
}