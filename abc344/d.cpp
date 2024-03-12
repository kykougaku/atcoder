#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main (){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string>> s (n, vector<string>());
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i); 
        for(int j = 0; j < a.at(i); j++){
            string temp;
            cin >> temp;
            s.at(i).push_back(temp);
        }
    }
    vector<vector<int>> dp(101, vector<int>(101, INF));

    dp.at(0).at(0) = 0;

    for(int j = 1; j<n; j++){
        for(int i = 0; i<=t.size(); i++){
            dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(j-1));
        }

        for(int i = 0; i<=t.size(); i++){
            for(auto si: s.at(j)){
                if(t.substr(i, si.size()) == si){
                    dp.at(i+si.size()).at(j) = min(dp.at(i+si.size()).at(j), dp.at(i).at(j-1) + 1);
                }
            }
        }
    }
    cout << dp.at(t.size()).at(n-1) << endl;

    return 0;
}