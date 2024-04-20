#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<string> s(n);
    for(long long i = 0; i < n; i++){
        cin >> s.at(i);
    }
    long long ans = 0;
    vector<long long> cnti(n, 0);
    vector<long long> cntj(n, 0);
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            if(s.at(i).at(j) == 'o'){
                cnti.at(i)++;
                cntj.at(j)++;
            }
        }
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            if(s.at(i).at(j) == 'o'){
                ans += (cnti.at(i) - 1) * (cntj.at(j) - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}