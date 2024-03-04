#include <bits/stdc++.h>

using namespace std;


bool is_prime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main (){
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++){
        cin >> l.at(i) >> r.at(i);
        if(l.at(i) == 1) l.at(i)=3;
    }
    vector<int> cnt(100001, 0);
    vector<int> sum(100001, 0);
    for(int i = 1; i < 100001; i+=2){
        if(is_prime(i) && is_prime((i+1)/2)){
            cnt.at(i)++;
        }
        if(i>2)sum.at(i) = cnt.at(i)+sum.at(i-2);
    }
    for(int i = 0; i < q; i++){
        cout << sum.at(r.at(i)) - sum.at(l.at(i)-2) << endl;
    }
    return 0;
}