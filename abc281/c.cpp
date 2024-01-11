#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    int64_t t;
    cin >> n >> t;
    vector<int> a(n);
    int64_t sum = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    t %= sum;
    for(int i=0;i<n;i++){
        if (t < a[i]){
            cout << i+1 <<" "<< t << endl;
            return 0;
        }
        t -= a[i];
    }
    return 0;
}