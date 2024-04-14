#include <bits/stdc++.h>

using namespace std;

int main (){
    long long l, r;
    cin >> l >> r;
    vector<pair<long long, long long>> q;
    int i = 0;
    while(true){
        if(l==r) break;
        long long mod = pow(2,i+1);
        if(l%mod != 0){
            q.push_back(make_pair(l,l+pow(2,i)));
            l = l+pow(2,i);
        }
        else if(l==0){
            q.push_back(make_pair(0,1));
            if(r>1) q.push_back(make_pair(1,2));
        }
        if(r%mod != 0){
            q.push_back(make_pair(r-pow(2,i),r));
            r = r-pow(2,i);
        }
    }
    sort(q.begin(), q.end());
    cout << q.size() << endl;
    for(int i = 0; i < q.size(); i++){
        cout << q.at(i).first << " " << q.at(i).second << endl;
    }
    return 0;
}