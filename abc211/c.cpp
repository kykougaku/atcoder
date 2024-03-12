#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    long long n = s.size();
    string chokudai = "chokudai";

    vector<vector<long long >> dp(s.size()+1, vector<long long>(8, 0));
    for(long long i = 1; i<=n; i++){
        for(int j = 0; j<8; j++){
            dp.at(i).at(j) = dp.at(i-1).at(j) % 1000000007;
            if(j==0){
                if(s.at(i-1) == chokudai.at(j)){
                    dp.at(i).at(j) += 1 % 1000000007;
                }
            }
            else{
                if(s.at(i-1) == chokudai.at(j)){
                    dp.at(i).at(j) += dp.at(i-1).at(j-1) % 1000000007;
                }
            }
        }
    }

    cout << dp.at(s.size()).at(7)%1000000007 << endl;

    return 0;
}