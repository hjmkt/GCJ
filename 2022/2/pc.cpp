#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

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
        ll R;
        cin >> R;

        vvll p1(2*R+1, vll(2*R+1, 0)), p2(2*R+1, vll(2*R+1, 0));
        REP(y, -R, R+1){
            REP(x, -R, R+1){
                if(round(sqrt(x*x+y*y))<=R){
                    p1[y+R][x+R] = 1;
                }
            }
        }

        REP(r, 0, R+1){
            REP(x, -r, r+1){
                ll y = round(sqrt(r*r-x*x));
                p2[y+R][x+R] = 1;
                p2[-y+R][x+R] = 1;
                p2[x+R][y+R] = 1;
                p2[x+R][-y+R] = 1;
            }
        }

        ll ans = 0;
        rep(y, 2*R+1){
            rep(x, 2*R+1){
                if(p1[y][x]!=p2[y][x]) ++ans;
            }
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
}
