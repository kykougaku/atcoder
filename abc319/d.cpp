#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1LL << 60;

bool check(vector<long long>& l, long long w, long long m, long long n){
    long long cnt = 0LL;
    long long linecnt = 0LL;
    for(long long i = 0; i < n; i++){
        if(linecnt == 0){
            cnt+=1LL;
            linecnt += l.at(i);
            if(linecnt > w) return false;
        }
        else{
            linecnt += 1LL+l.at(i);
            if(linecnt > w){
                cnt+=1LL;
                linecnt = l.at(i);
                if(linecnt > w) return false;
            }
        }
    }
    if(cnt > m) return false;
    else return true;
}

int main (){
    long long n, m;
    cin >> n >> m;
    vector<long long> l(n);
    for(long long i = 0; i < n; i++) cin >> l.at(i);

    long long left = 0LL;
    long long right = MAX;

    while(right - left > 1){
        long long mid = left + (right - left) / 2LL;
        if(check(l, mid, m, n)) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}