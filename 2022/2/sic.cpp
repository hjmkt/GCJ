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
        ll N, K;
        cin >> N >> K;

        ll r = N*N-1-K;
        if(r%2==1 || K<N-1){
            cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
            continue;
        }

        ll skip = 4*(N-1)-3;
        ll step = N-1;
        ll cur = N+1;
        vector<pair<ll, ll>> skips = {{4*(N-1)-1, 1}};
        while(skip>1){
            rep(_, 2){
                skips.push_back({skip, cur});
                cur += step;
                skip -= 2;
            }
            --step;
        }
        vector<pair<ll, ll>> ans;
        for(auto [skip, cur]: skips){
            if(!ans.empty() && ans.back().second>cur) continue;
            if(skip-1<=r){
                r -= skip-1;
                ans.push_back({cur, cur+skip});
            }
            if(r==0) break;
        }
        cout << "Case #" << t+1 << ": " << ans.size() << endl;
        for(auto p: ans) cout << p.first << " " << p.second << endl;
    }
}
