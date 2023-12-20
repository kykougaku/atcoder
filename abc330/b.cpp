#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> x(n);
/*
    for(int i = 0; i < n; i++){
        int flag = 0;
        for (int j= l; j<= r; j++){
            for(int y=l; y<=r; y++){
                if( abs(j-a[i]) <= abs(y-a[i]) ){
                    flag = 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                x[i] = j;
            }
        }
    }
*/

    for(int i = 0; i < n; i++){
        if(a[i] < l){
            x[i] = l;
        }
        else if(a[i] > r){
            x[i] = r;
        }
        else {
            x[i] = a[i];
        }
    }

    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }

    return 0;
}