#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, W;
    cin >> T >> W;

    for(int i=1; i<=T; ++i){
        long long d[W];
        for(int j=1; j<=W; ++j){
            if(j==1) cout << 50 << endl;
            else if(j==2) cout << 156 << endl;
            else cout << j << endl;
            cin >> d[j-1];
        }
        long long r[6];
        r[0] = d[0] >> 50;
        r[1] = (d[0] >> 25) & 255;
        r[2] = d[1] >> (156/3);
        r[3] = (d[1] >> (156/4)) & 255;
        // r[0]<<50 + r[1]<<25 + r[2]<<16 + r[3]<<12 + r[4]<<10 + r[5]<<8 = d[0]
        // r[2]<<34 + r[3]<<21 + r[4]<<13 + r[5]<<8 = d[1] >> 18
        r[4] = (((d[1]>>18) - d[0] >> 10) + (r[0]<<40) + (r[1]<<15) - ((1<<24) - (1<<6))*r[2] - ((1<<11) - (1<<2))*r[3]) / 7;
        r[5] = (d[0]>>8) - (r[0]<<42) - (r[1]<<17) - (r[2]<<8) - (r[3]<<4) - (r[4]<<2);
        cout << r[0] << " " << r[1] << " " << r[2] << " " << r[3] << " " << r[4] << " " << r[5] << endl;
        long long res;
        cin >> res;
        if(res<0) return 0;
    }
}
