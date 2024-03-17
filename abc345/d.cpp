#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++) cin >> a.at(i) >> b.at(i);
    for(int bit = 0; bit < (1<<n); bit++){
        vector<int> c;
        for(int i = 0; i<n; i++){
            c.push_back(i);
        }
    }
    return 0;
}