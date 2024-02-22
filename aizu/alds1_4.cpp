#include <bits/stdc++.h>

using namespace std;

int binn_search(vector<int> &s, int l, int r, int target){
    if(l > r) return 0;
    int mid = (l + r) / 2;
    if(s.at(mid) == target) return 1;
    if(s.at(mid) < target) l = mid + 1;
    else r = mid-1;
    return binn_search(s, l, r, target);
}

int main (){
    int n,q;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s.at(i);
    cin >> q;
    vector<int> t(q);
    for(int i = 0; i < q; i++) cin >> t.at(i);

    sort(s.begin(), s.end());

    int ans = 0;
    for(int i = 0; i < q; i++){
        ans += binn_search(s, 0, n-1, t.at(i));
    }
    cout << ans << endl;
    return 0;
}