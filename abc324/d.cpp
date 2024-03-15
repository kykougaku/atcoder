#include <bits/stdc++.h>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector<long long> s(10, 0);
    for(long long i=0; i<n; i++){
        char temp;
        cin >> temp;
        s.at(temp - '0')++;
    }
    long long ans = 0;
    for(long long i=0; i<10000000; i++){
        long long sq = i*i;
        vector<long long> sql(10, 0);
        //sqのj桁目を取り出す   
        string sqs = to_string(sq);
        for(long long j=0; j<sqs.size(); j++){
            sql.at(sqs.at(j) - '0')++;
        }
        if(n> sqs.size()){
            sql.at(0) += n-sqs.size();
        }

        bool flag = true;
        for(long long j=0; j<10; j++){
            if(s.at(j) != sql.at(j)){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}