#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    int takahashi = 0;
    int aoki = 0;
    for(int i = 0; i < n; i++){
        int t, a;
        cin >> t >> a;
        takahashi += t;
        aoki += a;
    }
    if(takahashi > aoki)
        cout << "Takahashi" << endl;
    else if(takahashi < aoki)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}