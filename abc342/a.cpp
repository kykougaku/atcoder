#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    int i1 = 0, i2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[0]) {
            cnt1++;
            i1 = i;
        }
        else{
            cnt2++;
            i2 = i;}
    }
    if(cnt1>cnt2) cout << i2+1 << endl;
    else cout << i1+1 << endl;
    return 0;
}