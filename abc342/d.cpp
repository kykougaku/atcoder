#include <bits/stdc++.h>

using namespace std;

bool check_heihou(int a){
    int b = sqrt(a);
    if(b*b == a) return true;
    else return false;
    }


int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(check_heihou(a.at(i)*a.at(j))) cnt++;
            else continue;
        }
    }
    cout << cnt << endl;
    return 0;
}