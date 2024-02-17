#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,q;
    cin >> n >> q;
    vector<int>qt(q),ql(q),qr(q), s_r(n-1);
    string s;
    cin >> s;
    for(int i=0; i<q; i++) cin >> qt.at(i) >> ql.at(i) >> qr.at(i);

    for(int i=0; i<n-1; i++){
        int tempp = s.at(i+1) - '0';
        int temp = s.at(i) - '0';
        s_r.at(i) = abs(tempp - temp);
    }

    for(int q_i=0; q_i<q; q_i++){
        if(qt.at(q_i) == 1){
            if(ql.at(q_i) > 1){
                if(s_r.at(ql.at(q_i)-2) == 0){
                    s_r.at(ql.at(q_i)-2) = 1;
                }
                else{
                    s_r.at(ql.at(q_i)-2) = 0;
                }
            }

            if(qr.at(q_i) < n){
                if(s_r.at(qr.at(q_i)-1) == 0){
                    s_r.at(qr.at(q_i)-1) = 1;
                }
                else{
                    s_r.at(qr.at(q_i)-1) = 0;
                }
            }
        }
        else{
            string ans = "Yes";
            for(int i=ql.at(q_i)-1; i<qr.at(q_i)-1; i++){
                if(s_r.at(i) == 0){
                    ans = "No";
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}