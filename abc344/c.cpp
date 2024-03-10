#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, m, l, q;

    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);

    cin >> m;
    vector<long long> b(m);
    for(int i = 0; i < m; i++) cin >> b.at(i);

    cin >> l;
    vector<long long> c(l);
    for(int i = 0; i < l; i++) cin >> c.at(i);

    cin >> q;
    vector<long long> x(q);
    for(int i = 0; i < q; i++) cin >> x.at(i);

    long long max = 1000000000;

    vector<bool> sum(max, false);
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            for(int u = 0; u < l; u++){
                if(a.at(j) + b.at(k) + c.at(u) >= max) continue;
                sum.at((a.at(j) + b.at(k) + c.at(u))) = true;
            }
        }
    }

    for(int i = 0; i < q; i++){
        if(sum.at(x.at(i)) == true){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}