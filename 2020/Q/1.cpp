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
        vvll m(N, vll(N, 0));
        rep(j, N) rep(k, N) cin >> m[j][k];

        ll trace = 0;
        rep(j, N) trace += m[j][j];

        ll rows = 0;
        rep(j, N){
            vll rflags(N, 0);
            rep(k, N){
                if(rflags[m[j][k]-1]>0){
                    ++rows;
                    break;
                }
                else rflags[m[j][k]-1] = 1;
            }
        }

        ll cols = 0;
        rep(j, N){
            vll cflags(N, 0);
            rep(k, N){
                if(cflags[m[k][j]-1]>0){
                    ++cols;
                    break;
                }
                else cflags[m[k][j]-1] = 1;
            }
        }

        cout << "Case #" << (i+1) << ": " << trace << " " << rows << " " << cols << endl;
    }
}
