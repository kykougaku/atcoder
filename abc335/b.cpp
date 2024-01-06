#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j=0; j<=n-i; j++){
            for(int k=0; k<=n-i-j; k++){
                    cout << i << " " << j << " " << k << endl;
            }
        }
    }
    return 0;
}