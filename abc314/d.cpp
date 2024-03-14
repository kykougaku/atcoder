#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n;
    vector<char> s(n);
    for(int i=0; i<n; i++) cin >> s.at(i);
    cin >> q;
    vector<int> t(q), x(q);
    vector<char> c(q);
    for(int i=0; i<q; i++) cin >> t.at(i) >> x.at(i) >> c.at(i);
    int lasti = 0;
    for(int i=0; i<q; i++){
        if(t.at(i)!=1){
            lasti = i;
        }
    }
        for(int i=0; i<lasti; i++){
            if(t.at(i) == 1){
                s.at(x.at(i)-1) = c.at(i);
            }
        }
        if (t.at(lasti) == 2){
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
        else if (t.at(lasti) == 3){
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
        else if (t.at(lasti) == 1){
            s.at(x.at(lasti)-1) = c.at(lasti);
        }
    for(int i = lasti+1; i<q; i++){
        if(t.at(i) == 1){
            s.at(x.at(i)-1) = c.at(i);
        }
    }
    for(int i=0; i<n; i++) cout << s.at(i);
    cout << endl;

    return 0;
}