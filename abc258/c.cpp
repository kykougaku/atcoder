#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> type(q);
    vector<int> data(q);
    for(int i=0; i<q; i++){
        cin>>type.at(i);
        cin>>data.at(i);
    }

    int sum1 = 0;
    for(int i=0; i<q; i++){
        if(type.at(i)==1){
            sum1+=data.at(i);
        }
        else{
            sum1 %= n;
            int temp = data.at(i)-1-sum1+n;
            cout << s.at(temp%n) << endl;
        }
    }
    return 0;
}