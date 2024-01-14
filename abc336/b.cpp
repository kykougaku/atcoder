#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    bitset<32> b(n);
    for(int i = 0; i < 32; i++){
        if(b[i] == 1){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}