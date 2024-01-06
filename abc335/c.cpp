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

    vector<int> atamax;
    vector<int> atamay;
    atamax.push_back(1);
    atamay.push_back(0);
    int s = 0;
    for(int i=0; i<q; i++){
        if(a.at(i) == 1){
            s++;
            if(b.at(i) == 'L'){
                atamax.push_back(atamax.back() - 1);
                atamay.push_back(atamay.back());
            }
            else if(b.at(i) == 'R'){
                atamax.push_back(atamax.back() + 1);
                atamay.push_back(atamay.back());
            }
            else if(b.at(i) == 'U'){
                atamax.push_back(atamax.back());
                atamay.push_back(atamay.back() + 1);
            }
            else if(b.at(i) == 'D'){
                atamax.push_back(atamax.back());
                atamay.push_back(atamay.back() - 1);
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