#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,q;
    cin >> n >> q;
    vector<int> a(q);
    vector<char> b(q);
    for(int i=0; i<q; i++){
        cin >> a.at(i) >> b.at(i);
    }

    vector<int> atamax(q);
    vector<int> atamay(q);
    atamax.at(0) = 1;
    atamay.at(0) = 0;
    int s = 0;
    for(int i=0; i<q; i++){
        if(a.at(i) == 1){
            s++;
            if(b.at(i) == 'L'){
                atamax.at(s) = atamax.at(s-1) - 1;
                atamay.at(s) = atamay.at(s-1);
            }
            else if(b.at(i) == 'R'){
                atamax.at(s) = atamax.at(s-1) + 1;
                atamay.at(s) = atamay.at(s-1);
            }
            else if(b.at(i) == 'U'){
                atamax.at(s) = atamax.at(s-1);
                atamay.at(s) = atamay.at(s-1) + 1;
            }
            else if(b.at(i) == 'D'){
                atamax.at(s) = atamax.at(s-1);
                atamay.at(s) = atamay.at(s-1) - 1;
            }
        }
        else if(a.at(i) == 2){
            int bui = int(b.at(i)-'0');
            if(s<bui){
                cout << bui-s << " "<<0<<endl;
            }
            else{
                cout << atamax.at(s-bui+1) << " " << atamay.at(s-bui+1) << endl;
            }

        }
    }
    return 0;
}