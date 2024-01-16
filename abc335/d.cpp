#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n,0));

    int temp = 1;
    for(int i = n; i>1; i-=2){
        for(int j = (n-i)/2; j < (n+i)/2; j++){
            a[(n-i)/2][j] = temp;
            temp++;
        }
        for(int j = (n-i+2)/2; j < (n+i)/2; j++){
            a[j][(n+i-2)/2] = temp;
            temp++;
        }
        for(int j = (n+i-4)/2; j >= (n-i)/2; j--){
            a[(n+i-2)/2][j] = temp;
            temp++;
        }
        for(int j = (n+i-4)/2; j >= (n-i+2)/2; j--){
            a[j][(n-i)/2] = temp;
            temp++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j  && i == (n-1)/2) {cout << "T "; continue;}
            if(j == n-1) cout << a[i][j] << endl;
            else cout << a[i][j] << " ";
        }
    }
    return 0;
}