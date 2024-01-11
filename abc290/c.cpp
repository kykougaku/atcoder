#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    int max_mex = 0;
    for(int i=0;i<n;i++){
        if(a.at(i) == max_mex){
            max_mex++;
            if(max_mex >= k){
                cout << k << endl;
                return 0;
            }
        }
        else if(a.at(i) < max_mex) continue;
        else if(a.at(i) > max_mex) break;
    }
    cout << max_mex << endl;
    return 0;
}