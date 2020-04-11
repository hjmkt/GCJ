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

int main(){
    cout << setprecision(20);

    ll T;
    cin >> T;

    rep(i, T){
        ll N;
        cin >> N;

        vvll walk;
        ll sum = 0, rem = max(N-34, 1ll), p = 0;
        bool left = true;
        rep(j, 35){
            if(rem&1){
                if(left) rep(k, j+1) walk.push_back({j+1, k+1});
                else irep(k, j+1) walk.push_back({j+1, k+1});
                left = !left;
                sum += 1<<p;
            }
            else{
                walk.push_back({j+1, left? 1 : j+1});
                ++sum;
            }
            ++p;
            rem >>= 1;
            if(rem==0) break;
        }

        ll r = sum - N;
        if(r<0){
            vll last = walk[walk.size()-1];
            REP(j, 1, abs(r)+1) walk.push_back({last[0]+j, last[1]==1? 1 : (last[1]+j)});
            r = 0;
        }
        vvll res = {walk[0]};
        REP(j, 1, walk.size()){
            if(r==0){
                REP(k, j, walk.size()) res.push_back(walk[k]);
                break;
            }
            else{
                if((walk[j][1]==1 || walk[j][1]==walk[j][0]) &&
                   (walk[j][0]==res[res.size()-1][0] || j==walk.size()-1 || walk[j+1][0]==walk[j][0])) --r;
                else res.push_back(walk[j]);
            }
        }

        cout << "Case #" << (i+1) << ":" << endl;
        rep(j, res.size()){
            cout << res[j][0] << " " << res[j][1] << endl;
        }
    }
}
