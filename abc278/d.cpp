#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;
    vector<int> B(Q), C(Q), D(Q);
    for(int i = 0; i < Q; i++){
        cin >> B[i] >> C[i];
        if(B[i] == 2) cin >> D[i];
    }

    int s = 0;
    for(int i = 0; i < Q; i++){
        if(B[i] == 1){
            s = C[i];
        }
        else if(B[i] == 2){
            A.at(C[i]-1) += D[i];
        }
        else if(B[i] == 3){
            cout << A.at(C[i]-1) + s << endl;
        }
    }
    return 0;
}