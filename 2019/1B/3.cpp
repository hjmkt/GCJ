#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    for(int i=1; i<=T; ++i){
        int N, K;
        cin >> N >> K;
        vector<int> c(N);
        vector<int> d(N);
        for(int j=0; j<N; ++j){
            cin >> c[j];
        }
        for(int j=0; j<N; ++j){
            cin >> d[j];
        }
        long count = 0;
        for(int j=0; j<N; ++j){
            for(int k=j; k<N; ++k){
                int cmax = 0;
                int dmax = 0;
                for(int l=j; l<=k; ++l){
                    if(c[l]>cmax) cmax = c[l];
                    if(d[l]>dmax) dmax = d[l];
                }
                if(abs(cmax-dmax)<=K) ++count;
            }
        }
        cout << "Case #" << i << ": " << count << endl;
    }
}
