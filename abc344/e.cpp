#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, vector<long long>> llist;
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++){
        long long before, after;
        if(i == 0){
            before = 0;
            llist.at(0).at(1) = a.at(i);
            llist.at(a.at(i)).at(0) = 0;
            llist.at(a.at(i)).at(1) = a.at(i+1);
        }
        else if (i == n-1){
            after = 0;
            llist.at(a.at(i)).at(0) = a.at(i-1);
        }
        else{
            before = a.at(i-1);
            after = a.at(i+1);
            llist.at(a.at(i)).at(0) = before;
            llist.at(a.at(i)).at(1) = after;
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        long long qu, x, y;
        cin >> qu;
        if(qu == 1){
            cin >> x>> y;
            llist.at(llist.at(x).at(1)).at(0) = y;
            llist.at(y).at(1) = llist.at(x).at(1);
            llist.at(x).at(1) = y;
            llist.at(y).at(0) = x;
        }
        else{
            cin >> x;
            long long before = llist.at(x).at(0);
            long long after = llist.at(x).at(1);
            llist.at(before).at(1) = after;
            llist.at(after).at(0) = before;
        }
    }
    long long now = llist.at(0).at(1);
    while(true){
        cout << now << endl;
        now = llist.at(now).at(1);
        if(now == 0){
            break;
        }
    }
    return 0;
}