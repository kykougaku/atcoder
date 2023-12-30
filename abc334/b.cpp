#include <bits/stdc++.h>

using namespace std;

int main (){
    int64_t A,M,L,R;
    cin >> A >> M>> L >> R;
    int64_t ans;

    if(L==R){
        if((L-A)%M==0)
            ans = 1;
        else
        ans = 0;
    }
    else{
        if(L>A){
            ans =(R-A)/M -(L-A)/M ;
            
        }
        else if(R<A){
            ans =  (A-L)/M -(A-R)/M ;
        }
        else{
ans = (A-L)/M + (R-A)/M +1;
        }
        
    }

    cout << ans<< endl;

    return 0;
}