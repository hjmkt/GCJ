#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv)vprint(v);


ll msb(ll n){
    ll count = 0;
    while(n>0){
        n >>= 1;
        ++count;
    }
    return max(count, 1ll);
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll T;
    cin >> T;
    rep(t, T){
        ll X, Y;
        cin >> X >> Y;

        ll xsign = X<0? -1 : 1;
        ll ysign = Y<0? -1 : 1;
        X = abs(X);
        Y = abs(Y);

        ll xbits = msb(X), ybits = msb(Y);
        ll bits = max(xbits, ybits);

        bool found = false;
        vll res;
        for(ll tbits=bits; tbits<bits+2; ++tbits){
            ll rx = X, ry = Y;
            ll step = 1<<(tbits-1);
            vll dirs;
            while(step>0){
                if(abs(rx)>abs(ry)){
                    if(rx<0){
                        dirs.push_back(0);
                        rx += step;
                    }
                    else{
                        dirs.push_back(2);
                        rx -= step;
                    }
                }
                else{
                    if(ry<0){
                        dirs.push_back(1);
                        ry += step;
                    }
                    else{
                        dirs.push_back(3);
                        ry -= step;
                    }
                }
                step >>= 1;
            }
            if(rx==0 && ry==0){
                found = true;
                if(res.size()==0 || res.size()>dirs.size()) res = dirs;
            }
        }
        if(found){
            cout << "Case #" << (t+1) << ": ";
            irep(i, res.size()){
                ll d = res[i];
                if(d==0) cout << (xsign>0? 'W' : 'E');
                else if(d==1) cout << (ysign>0? 'S' : 'N');
                else if(d==2) cout << (xsign>0? 'E' : 'W');
                else cout << (ysign>0? 'N' : 'S');
            }
            cout << endl;
        }
        else cout << "Case #" << (t+1) << ": " << "IMPOSSIBLE" << endl;
    }
}
