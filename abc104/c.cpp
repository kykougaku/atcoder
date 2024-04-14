#include <bits/stdc++.h>

using namespace std;

int main (){
    long long d,g;
    cin >> d >> g;
    vector<long long> p(d), c(d);
    for (int i = 0; i < d; i++){
        cin >> p.at(i) >> c.at(i);
    }

    long long ans = 1LL<<60;
    for(int now = 0; now < (1<<d); now++){
        long long sum = g;
        long long cnt = 0;
        for(int shift = d-1; shift >= 0; shift--){
            if(now & (1<<shift)){
                for(int i = 0; i < p.at(shift); i++){
                    sum -= 100*(shift+1);
                    if(i == p.at(shift)-1) sum -= c.at(shift);
                    cnt++;
                    if(sum <= 0){
                        ans = min(ans, cnt);
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}