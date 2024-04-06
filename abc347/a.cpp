#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a.at(i)%k == 0){
            cout << a.at(i)/k << " ";
        }
    }
    cout << endl;
    return 0;
}