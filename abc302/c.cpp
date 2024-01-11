#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> ite(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
        ite[i] = i;
    }
    do{
        for(int i=0;i<n-1;i++){
            int sameflag = 0;
            for(int j=0;j<m;j++){
                if(s[ite[i]][j] == s[ite[i+1]][j]){
                    continue;
                }
                else{
                    sameflag++;
                }
            }
            if(sameflag == 1){
                if(i == n-2){
                    cout << "Yes" << endl;
                    return 0;
                }
                continue;
            }
            else{
                break;
            }
        }
    }while(next_permutation(ite.begin(),ite.end()));
    cout << "No" << endl;
    return 0;
}