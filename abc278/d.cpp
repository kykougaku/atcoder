#include <bits/stdc++.h>

using namespace std;

int main(){
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for(int64_t i = 0; i < N; i++) cin >> A[i];
    int64_t Q;
    cin >> Q;
    vector<int64_t> B(Q), C(Q), D(Q);
    for(int64_t i = 0; i < Q; i++){
        cin >> B[i] >> C[i];
        if(B[i] == 2) cin >> D[i];
    }

    stack <int64_t> added_index;
    for(int64_t i = 0; i < N; i++) added_index.push(i);

    int64_t s = 0;
    for(int64_t i = 0; i < Q; i++){
        if(B[i] == 1){
            s = C[i];
            while(!added_index.empty()){
                A.at(added_index.top()) = 0;
                added_index.pop();
            }
            
        }
        else if(B[i] == 2){
            A.at(C[i]-1) += D[i];
            added_index.push(C[i]-1);
        }
        else if(B[i] == 3){
            cout << A.at(C[i]-1) + s << endl;
        }
    }
    return 0;
}