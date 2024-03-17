#include <bits/stdc++.h>

using namespace std;

int main (){
    long long x;
    cin >> x;
    long long ans = 0;
    if(x%10 == 0){
        ans = x/10;
    }
    else if(x<0){
        ans = x/10;
    }
    else if(x>0){
        ans = x/10;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}