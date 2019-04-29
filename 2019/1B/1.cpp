#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=1; i<=T; ++i){
        int P, Q;
        cin >> P >> Q;
        vector<int> cx(Q+1, 0), cy(Q+1, 0);
        for(int j=0; j<P; ++j){
            int x, y;
            char d;
            cin >> x >> y >> d;
            if(d=='N'){
                for(int k=y+1; k<=Q; ++k) ++cy[k];
            }
            else if(d=='S'){
                for(int k=0; k<y; ++k) ++cy[k];
            }
            else if(d=='E'){
                for(int k=x+1; k<=Q; ++k) ++cx[k];
            }
            else{
                for(int k=0; k<x; ++k) ++cx[k];
            }
        }
        int mx = 0, my = 0;
        int mcx = 0, mcy = 0;
        for(int k=0; k<=Q; ++k){
            if(cx[Q-k]>=mcx){ mcx = cx[mx=Q-k]; }
            if(cy[Q-k]>=mcy){ mcy = cy[my=Q-k]; }
        }
        cout << "Case #" << i << ": " << mx << " " << my << endl;
    }
}
