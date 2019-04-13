#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        int N;
        cin >> N;
        N = 2*(N-1);
        string path;
        cin >> path;
        stringstream res;
        for(int j=0; j<N; j++){
            res << (path[j]=='S'? "E" : "S");
        }
        cout << "Case #" << i << ": " << res.str() << endl;
    }
}

