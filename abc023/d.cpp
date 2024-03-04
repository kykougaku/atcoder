#include <bits/stdc++.h>

using namespace std;

bool check(long long H, vector<long long> h, vector<long long> s, int n){
    vector<long long> t(n);
    bool flag = true;
    for(int j = 0; j < n; j++){
        if(h.at(j) > H){
            flag = false;
            break;
        }
        t.at(j) = (H - h.at(j)) / s.at(j);
    }
    if(!flag) return false;
    sort(t.rbegin(), t.rend());
    for(int time = 0; time < n; time++){
        if(t.back() >= time){
            t.pop_back();
            continue;
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag) return false;
    return true;
}

vector<long long> binary_search(long long left, long long right, vector<long long> h, vector<long long> s, int n){
    vector<long long> ans;
    while(right - left > 1){
        long long mid = left + (right - left) / 2;
        if(check(mid, h, s, n)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    ans.push_back(right);
    ans.push_back(left);
    return ans;
}

int main (){
    int n;
    cin >> n;
    vector<long long> h(n), s(n);
    for (int i = 0; i < n; i++){
        cin >> h.at(i) >> s.at(i);
    }
    vector<long long> ans = binary_search(0, 1e18, h, s, n);
    if(check(ans.at(0), h, s, n)){
        cout << ans.at(0) << endl;
    }
    else{
        cout << ans.at(1) << endl;
    }
}