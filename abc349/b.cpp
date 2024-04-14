#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(26, 0), b(n+1, 0);
    for(int i = 0; i < n; i++){
        a.at(s.at(i) - 'a')++;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < 26; i++){
        if(a.at(i) == 0) continue;
        b.at(a.at(i))++;
    }
    for(int i = 0; i < n+1; i++){
        if(b.at(i) == 1 or b.at(i)>2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}