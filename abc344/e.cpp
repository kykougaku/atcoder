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
    int q;
    cin >> q;
    vector<long long> t(q), x(q), y(q);
    for(int i = 0; i < q; i++){
        cin >> t.at(i);
        if(t.at(i) == 1){
            cin >> x.at(i) >> y.at(i);
        }
        else{
            cin >> x.at(i);
        }
    }

    if(n == 1){
        llist[0] = vector<long long>{-1, a.at(0)};
        llist[a.at(0)] = vector<long long>{0, -1};
    }
    else{
        llist[0] = vector<long long>{-1, a.at(0)};
        llist[a.at(0)] = vector<long long>{0, a.at(1)};
        for(int i = 1; i<n-1; i++){
            llist[a.at(i)] = vector<long long>{a.at(i-1), a.at(i+1)};
        }
        llist[a.at(n-1)] = vector<long long>{a.at(n-2), -1};
    }

    for(int i = 0; i<q; i++){
        if(t.at(i) == 1){
            long long ix = x.at(i); long long iy = y.at(i);
            long long ixn = llist[ix].at(1);

            llist[ix].at(1) = iy;
            llist[iy] = vector<long long>{ix, ixn};
            if(ixn!=-1) llist[ixn].at(0) = iy;
        }
        else{
            long long ix = x.at(i);
            long long ixb = llist[ix].at(0); long long ixn = llist[ix].at(1);
            if(ixb!=-1) llist[ixb].at(1) = ixn;
            if(ixn!=-1) llist[ixn].at(0) = ixb;
        }
    }

    long long next = llist[0].at(1);
    while(next != -1){
        cout << next << " ";
        next = llist[next].at(1);
    }   
    return 0;
}