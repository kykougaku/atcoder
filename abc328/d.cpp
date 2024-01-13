#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    string ans;


    for (int i = 0; i < s.size(); i++){
        ans.push_back(s[i]);
        if(ans.size() >= 3 && ans.substr(ans.size()-3, 3) == "ABC"){
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
    }

    cout << ans << endl;
    return 0;
}