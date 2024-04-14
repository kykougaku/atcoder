#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        cin >> a.at(i);
        sum -= a.at(i);
    }
    cout << sum << endl;
    return 0;
}