#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,q;
    cin >> n >> q;
    vector<int> a(q);
    vector<int> b(q);
    vector<char> c(q);
    for(int i=0; i<q; i++){
        cin >> a.at(i);
        if(a.at(i) == 1){
            cin >> c.at(i);
        }
        else{
            cin >> b.at(i);
        }
    }
    deque<pair<int, int>> dragon;
    for(int i=0; i<n; i++){
        dragon.push_back(make_pair(i+1, 0));
    }

    for(int i=0; i<q; i++){
        if(a.at(i) == 1){
            int temp_x = dragon.at(0).first;
            int temp_y = dragon.at(0).second;

            if(c.at(i) == 'R'){
                dragon.push_front(make_pair(temp_x+1, temp_y));
            }
            else if(c.at(i) == 'L'){
                dragon.push_front(make_pair(temp_x-1, temp_y));
            }
            else if(c.at(i) == 'U'){
                dragon.push_front(make_pair(temp_x, temp_y+1));
            }
            else if(c.at(i) == 'D'){
                dragon.push_front(make_pair(temp_x, temp_y-1));
            }
            dragon.pop_back();
        }
        else{
            cout << dragon.at(b.at(i)-1).first << " " << dragon.at(b.at(i)-1).second << endl;
        }
    }
    return 0;
}