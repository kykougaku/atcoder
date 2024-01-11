#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t A,M,L,R;
    cin >> A >> M>> L >> R;
    int64_t ans;

    ans+=(((R-A)%M+M)%M+R)/M;
    ans-=(((L-A)%M+M)%M+L)/M;

    if (((L-A)%M)==0) ans++;

    if(ans>0)cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}