#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++){
        cin >> x.at(i);
        if(x.at(i) == n) x.at(i) = 0;
    }
    return 0;
}