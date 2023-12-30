#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin >> c.at(i).at(j);
        }
    }

    int N;
    if(h<=w) N = h;
    else N = w;
    vector<int> r(N,0);

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if(c.at(i).at(j) == '#'){
                int size = 0;
                for(int k=0; k<N; k++){
                    if(i+k+1 >= h || j+k+1 >= w) {
                        size = k/2;
                        break;
                    }
                    if(c.at(i+k).at(j+k) != '#'){
                        size = (k-1)/2;
                        break;
                    }
                }

                r.at(size-1)++;

                for(int k=0; k<=size; k++){
                    c.at(i+size+k).at(j+size+k) = '.';
                    c.at(i+size+k).at(j+size-k) = '.';
                    c.at(i+size-k).at(j+size+k) = '.';
                    c.at(i+size-k).at(j+size-k) = '.';
                }


            }
        }
    }

    for (int i=0; i<N; i++){
        cout << r.at(i)<<" ";
    }
    return 0;
}