#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n ,q;
    cin >> n >> q;
    vector<long long> t(q);
    vector<int> a(n, 1);
    for(int i = 0; i < q; i++){
        cin >> t.at(i);
        t.at(i)--;
        if(a.at(t.at(i)) == 1){
            a.at(t.at(i)) = 0;
        }
        else{
            a.at(t.at(i)) = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += a.at(i);
    }
    cout << ans << endl;
    return 0;
}