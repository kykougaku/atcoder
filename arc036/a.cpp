#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> t(N);
    for(int i=0;i<N;i++){
        cin >> t[i];
    }
    for(int i=2;i<N;i++){
        if(t[i-2]+t[i-1]+t[i]<K){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}