#include <bits/stdc++.h>

using namespace std;

int main (){
    int h,w,n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s.at(i);

    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s.at(i).at(j) == '#') continue;
            int ni = i, nj = j;
            for(int l=0; l<n; l++){
                if(ni<0 || ni>=h || nj<0 || nj>=w) break;
                if(s.at(ni).at(nj) == '#') break;
                if(t.at(l) == 'U') ni--;
                if(t.at(l) == 'D') ni++;
                if(t.at(l) == 'L') nj--;
                if(t.at(l) == 'R') nj++;
                if(l == n-1 ){
                    if(ni>=0 && ni<h && nj>=0 && nj<w && s.at(ni).at(nj) == '.') ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}