#include <bits/stdc++.h>

using namespace std;


int solve(int n,int si, vector<int>& a, vector<int>& dp, int l, int r){
    

}
int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);
    for(int si= 0; si < n; si++){
        //index a_i = (dp_i + (si+1))%n
        vector<int> dp(n+1, 0);
    }
    return 0;
}