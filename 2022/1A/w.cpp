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
        ll E, W;
        cin >> E >> W;
        vvll X(E, vll(W));
        rep(i, E) rep(j, W) cin >> X[i][j];

        umap<string, umap<string, ll>> m;
        uset<string> s = {""};
        vll vars;
        rep(i, W) rep(j, 3) vars.push_back(i);
        do{
            string t = "";
            rep(i, 3*W){
                t += to_string(vars[i]);
                s.insert(t);
            }
        } while(next_permutation(all(vars)));
        for(string a: s){
            vll ca(W, 0);
            for(char c: a){
                ++ca[c-'0'];
            }
            for(string b: s){
                vll cb(W, 0);
                for(char c: b){
                    ++cb[c-'0'];
                }
                vll cd(W, 0);
                rep(i, W) cd[i] = max(0ll, ca[i]-cb[i]);
                ll n = 0;
                while(true){
                    ll d = 0;
                    rep(i, W) d += cd[i];
                    if(d==0) break;
                    ll m = a[a.length()-n-1] - '0';
                    cd[m] = max(0ll, cd[m]-1);
                    ++n;
                }
                m[a][b] = n + ((ll)b.length()+n-(ll)a.length());
            }
        }
        vector<umap<string, ll>> dp(E);
        for(string a: s){
            ll n = 0;
            for(char c: a){
                ll d = c - '0';
                n += d;
            }
            dp[E-1][a] = n;
        }
        irep(i, E-1){
            for(string a: s){
                if(dp[i].find(a)==dp[i].end()) dp[i][a] = LLONG_MAX;
                vll ca(W, 0);
                for(char c: a){
                    ++ca[c-'0'];
                }
                bool ok = true;
                rep(j, W) ok &= ca[j]==X[i][j];
                if(!ok) continue;
                for(string b: s){
                    dp[i][a] = min(dp[i][a], dp[i+1][b]<LLONG_MAX? dp[i+1][b]+m[b][a] : LLONG_MAX);
                }
            }
        }
        ll ans = LLONG_MAX;
        for(auto a: s){
            ans = min(ans, dp[0][a]);
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
}
