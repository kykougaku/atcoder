#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        int pp;
        cin >> pp;
        pp--;
        p.at(pp) = i;
    }
    int q;
    cin >> q;
    vector<int> a(q), b(q);
    for(int i = 0; i < q; i++){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--; b.at(i)--;
    }
    for(int i = 0; i < q; i++){
        if(p.at(a.at(i)) < p.at(b.at(i))) cout << a.at(i)+1 << endl;
        else cout << b.at(i)+1 << endl;
    }
    return 0;
}