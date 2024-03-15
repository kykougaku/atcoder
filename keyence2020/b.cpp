#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<long long> x(n), l(n), s(n), t(n);
    vector<pair<long long, long long>> p(n);
    for(int i = 0; i < n; i++) cin >> x.at(i) >> l.at(i);
    for(int i = 0; i < n; i++){
        s.at(i) = x.at(i) - l.at(i);
        t.at(i) = x.at(i) + l.at(i);
        p.at(i) = make_pair(s.at(i), t.at(i));
    }
    sort(p.begin(), p.end());
    int last = p.at(0).second;
    int i = 1;
    int count = 0;
    while(i < n){
        if(last<=p.at(i).first){
            count++;
            last = p.at(i).second;
        }
        i++;
    }
    cout << count+1 << endl;
    return 0;
}