#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n, t;
    cin >> n >> t;
    vector<long long> a(t), b(t);
    for(long long i = 0; i < t; i++){
        cin >> a.at(i) >> b.at(i);
    }
    map<long long, long long> p;
    vector<long long> v(n, 0);
    p[0] = n;
    for(long long i = 0 ; i < t; i++){
        p[v.at(a.at(i)-1)] -= 1;
        if(p[v.at(a.at(i)-1)] == 0){
            p.erase(v.at(a.at(i)-1));
        }
        long long a_p = v.at(a.at(i)-1)+b.at(i);
        v.at(a.at(i)-1) += b.at(i);
        if(p.count(a_p)){
            p[a_p] += 1;
        }
        else{
            p[a_p] = 1;
        }
        cout << p.size() << endl;
    }
    return 0;
}