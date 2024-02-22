#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n, vector<int>());
    vector<vector<int>> y(n, vector<int>());

    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        for(int j = 0; j < a.at(i); j++){
            int b, c;
            cin >> b >> c;
            b--;
            x.at(i).push_back(b);
            y.at(i).push_back(c);
        }
    }

    int ans = 0;
    for(int i = 0; i<(1<<n); i++){
        int cnt = 0;
        bool ookk = true;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                for(int k = 0; k < a.at(j); k++){
                    cnt++;
                    if(y.at(j).at(k) == 1){
                        if(!(i & (1<<x.at(j).at(k)))){
                            ookk = false;
                        }
                    }
                    else if(y.at(j).at(k) == 0){
                        if((i & (1<<x.at(j).at(k)))){
                            ookk = false;
                        }
                    }
                }
            }
        }
        if(ookk) ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}