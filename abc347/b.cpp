#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    long long ans = 0;
    for(int i = 1; i <= s.size(); i++){
        vector<bool> check(s.size()-i+1, false);
        for(int j = 0; j < s.size()-i+1; j++){
            if(check.at(j)){
                continue;
            }
            for(int k = j+1; k < s.size()-i+1; k++){
                if(s.substr(j, i) == s.substr(k, i)){
                    check.at(k) = true;
                }
            }
            ans++;
        }
    }
    cout << ans << endl;    
    return 0;
}