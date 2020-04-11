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


vector<string> split(string str, char del){
    vector<string> res;
    string sub = "";
    for(char c : str){
        if(c==del){
            res.push_back(sub);
            sub = "";
        }
        else sub += c;
    }
    res.push_back(sub);
    return res;
}


int main(){
    cout << setprecision(20);

    ll T;
    cin >> T;

    rep(i, T){
        ll N;
        cin >> N;

        vector<string> p(N);
        rep(j, N) cin >> p[j];

        vector<string> prefixes, suffixes;
        vector<vector<string>> middles;

        for(string s : p){
            auto subs = split(s, '*');
            prefixes.push_back(subs[0]);
            suffixes.push_back(subs[subs.size()-1]);
            middles.push_back(subs.size()>=3? vector<string>(subs.begin()+1, subs.end()-1) : vector<string>{});
        }

        bool possible = true;
        string prefix = "", suffix = "";
        rep(j, prefixes.size()){
            if(prefixes[j].length()>prefix.length()){
                possible &= prefixes[j].substr(0, prefix.length()) == prefix;
                prefix = prefixes[j];
            }
            else possible &= prefix.substr(0, prefixes[j].length()) == prefixes[j];
            if(suffixes[j].length()>suffix.length()){
                possible &= suffixes[j].substr(suffixes[j].length()-suffix.length(), suffix.length()) == suffix;
                suffix = suffixes[j];
            }
            else possible &= suffix.substr(suffix.length()-suffixes[j].length(), suffixes[j].length()) == suffixes[j];
            if(!possible) break;
        }

        stringstream ss;
        ss << prefix;
        for(auto mm : middles) for(auto m : mm) ss << m;
        ss << suffix;

        if(possible) cout << "Case #" << (i+1) << ": " << ss.str() << endl;
        else cout << "Case #" << (i+1) << ": " << "*" << endl;
    }
}

