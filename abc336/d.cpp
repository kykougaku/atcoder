#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);
    

    l.at(0) = 1;
    r.at(n-1) = 1;

    for(int i = 0; i < n-1; i++){
        l.at(i+1) = min(l.at(i)+1, a.at(i+1));
    }
    for(int i = n-1; i > 0; i--){
        r.at(i-1) = min(r.at(i)+1, a.at(i-1));
    }

    int min_ans = 0;
    for(int i = 0; i < n; i++){
        int l_r = min(l.at(i), r.at(i));
        min_ans = max(min_ans, l_r);
    }
    cout << min_ans << endl;

    return 0;
}