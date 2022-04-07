#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll T;
    cin >> T;

    rep(t, T){
        cout << "Case #" << t+1 << ": ";
        ll CMYKs[4][3];
        rep(i, 3) rep(j, 4) cin >> CMYKs[j][i];
        ll max_cmyk[4], max_total = 0;
        rep(i, 4) max_total += max_cmyk[i] = *min_element(CMYKs[i], CMYKs[i]+3);

        if(max_total>=1000000){
            ll cmyk[4] = {}, total = 0;
            rep(i, 4){
                if(total==1000000) break;
                ll d = min(1000000-total, max_cmyk[i]-cmyk[i]);
                cmyk[i] += d;
                total += d;
            }
            cout << cmyk[0] << " " << cmyk[1] << " " << cmyk[2] << " " << cmyk[3] << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }
}
