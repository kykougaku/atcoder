#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        a.at(i)--;
        b.at(a.at(i)) = i;
    }
    vector<int> ans1;
    vector<int> ans2;

    for(int i = 0; i < n; i++){
        if(a.at(i) == i){
            continue;
        }
        ans1.push_back(i);
        ans2.push_back(b.at(i));
        int temp1 = b.at(i);
        int temp2 = b.at(a.at(i));
        int temp3 = a.at(i);
        swap(a.at(i), a.at(b.at(i)));
        b.at(temp3) = temp1;
        b.at(i) = temp2;
    }

    cout << ans1.size() << endl;
    for(int i = 0; i < ans1.size(); i++){
        cout << ans1.at(i)+1 << " " << ans2.at(i)+1 << endl;
    }
    return 0;
}