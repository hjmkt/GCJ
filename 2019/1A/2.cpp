#include <iostream>
#include <vector>

using namespace std;


int mod(int a, int m){
    return (a%m + m) % m;
}

int ext_gcd(int a, int b, int &p, int &q){
    if (b == 0) { p = 1; q = 0; return a; }
    int d = ext_gcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

int chinese_rem(const vector<int> &b, const vector<int> &m){
    long long r = 0, M = 1;
    for (int i=0; i<b.size(); ++i) {
        int p, q;
        int d = ext_gcd(M, m[i], p, q);
        if ((b[i]-r) % d != 0) return 0;
        int tmp = (b[i]-r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return r;
}

int main(){
    int T, N, M;
    cin >> T >> N >> M;
    vector<int> nblades = {18, 17, 13, 11, 7, 5};
    vector<int> mblades(6);
    for(int i=0; i<T; ++i)
    {
        for(int j=0; j<6; ++j){
            for(int k=0; k<17; ++k){
                cout << nblades[j] << " ";
            }
            cout << nblades[j] << endl;

            int m = 0;
            for(int k=0; k<18; ++k){
                int blades;
                cin >> blades;
                m += blades;
            }
            m %= nblades[j];
            mblades[j] = m;
        }
        for(int j=0; j<N-6; ++j){
            for(int k=0; k<17; ++k){
                cout << nblades[0] << " ";
            }
            cout << nblades[0] << endl;
            for(int k=0; k<18; ++k){
                int blades;
                cin >> blades;
            }
        }
        int res = chinese_rem(mblades, nblades);
        cout << res << endl;
        int judge;
        cin >> judge;
    }
    return 0;
}
