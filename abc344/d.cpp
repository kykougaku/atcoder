#include <bits/stdc++.h>

using namespace std;
const int INF = 1<<30;

int main (){
    string t; int n;
    cin >> t >> n;
    vector<int> a(n);
    vector<vector<string>> ss(n, vector<string>());
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        for(int j = 0; j < a.at(i); j++){
            string temp;
            cin >> temp;
            ss.at(i).push_back(temp);
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(t.size()+1, INF));
    dp.at(0).at(0) = 0;
    int sssize;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=t.size(); j++){
            dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));

            for(int k = 0; k<a.at(i-1); k++){
                //袋iまで使い末尾がss.at(i).at(k)であるようなSを作りTのj文字目まで一致させる
                sssize = ss.at(i-1).at(k).size();
                if(j-sssize < 0)continue;
                if(t.substr(j-sssize,sssize) == ss.at(i-1).at(k) and dp.at(i-1).at(j-sssize) < INF){
                    dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j-sssize)+1);
                }
            }
        }
    }
    if(dp.at(n).at(t.size()) >= INF) cout << -1 << endl;
    else  cout << dp.at(n).at(t.size()) << endl;
    return 0;
}