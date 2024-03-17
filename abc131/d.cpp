#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i) >> b.at(i);
        p.at(i) = make_pair(b.at(i), i);
    }
    sort(p.begin(), p.end());
    long long nowtime = 0;
    string ans = "Yes";
    for(int i = 0; i<n; i++){
        int idx = p.at(i).second;
        nowtime += a.at(idx);
        if(nowtime > b.at(idx)){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}