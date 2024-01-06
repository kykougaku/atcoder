#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t a, b;
    cin >> a >> b;
    int64_t ans = a/b;
    if(a%b >0)ans++;
    cout << ans << endl;
    return 0;
}