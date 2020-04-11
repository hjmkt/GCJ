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


template<typename A, typename B>
struct pair_hash{
    inline size_t operator()(const pair<A, B> &p) const{
        const auto h1 = hash<A>()(p.first);
        const auto h2 = hash<B>()(p.second);
        return h1^(h2<<18);
    }
};


int main(){
    cout << setprecision(20);

    ll T;
    cin >> T;

    rep(i, T){
        ll R, C;
        cin >> R >> C;
        vvll s(R, vll(C, 0));
        rep(r, R) rep(c, C) cin >> s[r][c];
        vvvll d(R, vvll(C, vll(4, 0)));
        rep(r, R) rep(c, C){
            d[r][c][0] = c>0? (c-1) : -1;
            d[r][c][1] = r>0? (r-1) : -1;
            d[r][c][2] = c<C-1? (c+1) : -1;
            d[r][c][3] = r<R-1? (r+1) : -1;
        }

        ll total = 0;
        unordered_set<pair<ll, ll>, pair_hash<ll, ll>> rem, cands;
        rep(r, R) rep(c, C) rem.insert({r, c});
        rep(r, R) rep(c, C) cands.insert({r, c});
        ll last = 0;
        ll interest = 0;
        rep(r, R) rep(c, C) interest += s[r][c];
        while(true){
            total += interest;
            last = interest;
            unordered_set<pair<ll, ll>, pair_hash<ll, ll>> losers;
            for(auto p : cands){
                if(rem.find(p)==rem.end()) continue;
                ll r = p.first;
                ll c = p.second;
                ll left = d[r][c][0];
                ll above = d[r][c][1];
                ll right = d[r][c][2];
                ll below = d[r][c][3];
                ll tmp = 0, count = 0;
                if(left>=0){
                    tmp += s[r][left];
                    ++count;
                }
                if(above>=0){
                    tmp += s[above][c];
                    ++count;
                }
                if(right>=0){
                    tmp += s[r][right];
                    ++count;
                }
                if(below>=0){
                    tmp += s[below][c];
                    ++count;
                }
                if(count>0 && count*s[r][c]<tmp){
                    losers.insert({r, c});
                    interest -= s[r][c];
                }
            }
            cands.clear();
            for(auto l : losers){
                rem.erase(l);
                ll r = l.first;
                ll c = l.second;
                ll left = d[r][c][0];
                ll above = d[r][c][1];
                ll right = d[r][c][2];
                ll below = d[r][c][3];
                if(left>=0){
                    d[r][left][2] = d[r][c][2];
                    cands.insert({r, left});
                }
                if(above>=0){
                    d[above][c][3] = d[r][c][3];
                    cands.insert({above, c});
                }
                if(right>=0){
                    d[r][right][0] = d[r][c][0];
                    cands.insert({r, right});
                }
                if(below>=0){
                    d[below][c][1] = d[r][c][1];
                    cands.insert({below, c});
                }
            }
            if(last==interest) break;
            last = interest;
        }

        cout << "Case #" << (i+1) << ": " << total << endl;
    }
}
