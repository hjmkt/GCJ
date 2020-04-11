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
        string s;
        cin >> s;

        string t = s;
        IREP(j, 10, 1){
            rep(k, t.length()){
                if(t[k]=='0'+j){
                    ll l = k;
                    ll balance = 0;
                    for(; l<t.length() && t[l]!='0'; ++l){
                        if(t[l]=='(') ++balance;
                        else if(t[l]==')') --balance;
                        else t[l] -= 1;
                        if(balance<0) break;
                    }
                    t = t.substr(0, k) + "(" + t.substr(k, l-k) + ")" + t.substr(l, t.length()-l);
                    k += 2;
                }
            }
        }
        ll idx = 0;
        rep(j, t.length()){
            while((t[j]<'0' || t[j]>'9') && j<t.length()) ++j;
            if(j>=t.length()) break;
            t[j] = s[idx];
            ++idx;
        }

        cout << "Case #" << (i+1) << ": " << t << endl;
    }
}
