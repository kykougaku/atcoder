#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> ans(n,0);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        tmp--;
        if(tmp == -2) ans.at(0) = i;
        else a.at(tmp) = i;
    }

    for(int i = 0; i < n-1; i++){
        ans.at(i+1) = a.at(ans[i]);
    }
    for(int i = 0; i < n; i++){
        cout<<ans.at(i)+1<<" ";
    }

}