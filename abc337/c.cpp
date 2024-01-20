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
        if(tmp == -2) ans[0] = i;
        a[tmp] = i;
    }

    for(int i = 0; i < n; i++){
        ans[i+1] = a[ans[i]];
    }
    for(int i = 0; i < n; i++){
        printf("%d ",ans[i]+1);
    }

}