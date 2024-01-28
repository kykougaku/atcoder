#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> q(n), a(n), b(n), qq(n);
    for(int i = 0; i < n; i++){
        cin >> q.at(i);
        qq.at(i) = q.at(i);
    }

    for(int i = 0; i < n; i++) cin >> a.at(i);
    for(int i = 0; i < n; i++) cin >> b.at(i);
    int amin = 10000000;
    for(int i = 0; i < n; i++){
        if(a.at(i) == 0) continue;
        amin = min(amin, q.at(i)/a.at(i));
    }

    int ans = 0;

    for(int i = 0; i <= amin; i++){
        for(int j = 0; j < n; j++){
            qq.at(j) = q.at(j) - i* a.at(j);
        }
        int bmin = 10000000;
        for(int j = 0; j < n; j++){
            if(b.at(j) == 0) continue;
            bmin = min(bmin, qq.at(j)/b.at(j));
        }

        ans = max(ans, i + bmin);
    }
    cout << ans << endl;
    return 0;
}