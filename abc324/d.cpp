#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
    char temp;
    cin >> temp;
    s.at(i) = temp - '0';
    }
    sort(s.begin(), s.end());

    long long ans = 0;
    do{
        long long num = 0;
        for(int i=0; i<n; i++){
            num = num*10 + s.at(i);
        }
        long long root = sqrt(num);
        if(root*root == num) ans++;
    }while(next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}