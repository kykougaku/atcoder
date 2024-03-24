#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n-1; i++){
        cout << a.at(i) *a.at(i+1)<< " ";
    }
    return 0;
}