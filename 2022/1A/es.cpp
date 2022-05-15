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
        ll N;
        cin >> N;
        vll A(N);
        ll n = 1;
        rep(i, N){
            A[i] = n;
            if(n*2<=1000000000){
                n *= 2;
            }
            else{
                ++n;
            }
        }
        rep(i, N-1) cout << A[i] << " ";
        cout << A[N-1] << endl;
        vll B(N);
        rep(i, N) cin >> B[i];
        sort(all(B));
        vll C(2*N);
        rep(i, N) C[i] = A[i];
        rep(i, N) C[i+N] = B[i];
        vll ans;
        ll l=0, r=0;
        irep(i, 2*N){
            if(l>=r){
                r += C[i];
            }
            else{
                l += C[i];
                ans.push_back(C[i]);
            }
        }
        rep(i, (ll)ans.size()-1) cout << ans[i] << " ";
        cout << ans.back() << endl;
    }
}
