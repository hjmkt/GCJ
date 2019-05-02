#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        string N;
        cin >> N;

        string A = "";
        string B = "";

        for(int j=0; j<N.length(); j++){
            if(N[j]=='0'){
                A = A + '0';
                B = B + '0';
            }
            else if(N[j]=='5'){
                A = A + '3';
                B = B + '2';
            }
            else{
                A = A + to_string((int)(N[j]-'0')-1);
                B = B + '1';
            }
        }
        while(A.length()>1 && A[0]=='0'){
            A = A.substr(1);
        }
        while(B.length()>1 && B[0]=='0'){
            B = B.substr(1);
        }

        cout << "Case #" << i << ": " << A << " " << B << endl;
    }
}
