#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)cin >> a[i];

    int index=0;
    for(int i=0;i<=n;i++){
        if (index==1){
            cout << i << endl;
            return 0;
        }
        index = a[index]-1;
    }
    cout << -1 << endl;
    return 0;
}