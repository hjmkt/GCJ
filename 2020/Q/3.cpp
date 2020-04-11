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
        vvll t(N, vll{0, 0, 0});
        rep(i, N){
            cin >> t[i][0] >> t[i][1];
            t[i][2] = i;
        }
        sort(all(t), [](auto x, auto y){ return x[0]<y[0]; });
        ll C = 0, J = 0;
        stringstream ss;
        bool possible = true;
        rep(i, N){
            if(t[i][0]>=C){
                ss << "C";
                C = t[i][1];
            }
            else if(t[i][0]>=J){
                ss << "J";
                J = t[i][1];
            }
            else{
                possible = false;
                break;
            }
        }
        if(possible){
            string assign = ss.str();
            vll order(N);
            rep(i, N) order[t[i][2]] = i;
            stringstream ans;
            rep(i, N) ans << assign[order[i]];
            cout << "Case #" << (i+1) << ": " << ans.str() << endl;
        }
        else cout << "Case #" << (i+1) << ": " << "IMPOSSIBLE" << endl;
    }
}
