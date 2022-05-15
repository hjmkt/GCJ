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
        string S;
        cin >> S;
        string u = "";
        char last = -1;
        for(char c: S){
            if(c!=last) u += c;
            last = c;
        }
        vector<bool> next_greater;
        rep(i, (ll)u.length()-1){
            next_greater.push_back(u[i]<u[i+1]);
        }
        next_greater.push_back(false);
        ll idx = -1;
        string ans = "";
        last = -1;
        for(char c: S){
            if(last!=c) ++idx;
            if(next_greater[idx]){
                ans += c;
            }
            ans += c;
            last = c;
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
}
