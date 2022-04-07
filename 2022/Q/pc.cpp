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
        ll R, C;
        cin >> R >> C;
        cout << "Case #" << t+1 << ":" << endl;

        vector<string> p(R*2+1, string(C*2+1, '.'));
        rep(r, R*2+1) rep(c, C*2+1){
            if(r%2==0) p[r][c] = c%2==0? '+' : '-';
            else if(c%2==0) p[r][c] = '|';
        }
        p[0][0] = p[0][1] = p[1][0] = '.';

        rep(r, R*2+1) cout << p[r] << endl;
    }
}
