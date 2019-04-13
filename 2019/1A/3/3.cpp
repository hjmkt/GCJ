#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        int R, C;
        cin >> R >> C;

        if(R+C>6){
            cout << "Case #" << (i+1) << ": POSSIBLE" << endl;

            vector<pair<int, int>> res;
            bool transpose = R>C;
            if(R>C) swap(R, C);
            if(R==4 && C==4){
                for(int k=0; k<C-1; k++){
                    res.push_back({1, k%C+1});
                    res.push_back({2, (k+2)%C+1});
                    res.push_back({3, (k+4)%C+1});
                    res.push_back({4, (k+6)%C+1});
                }
                res.push_back({3, 4});
                res.push_back({4, 2});
                res.push_back({1, 4});
                res.push_back({2, 2});
            }
            else{
                int start_col = 0;
                int row_offset = 0;
                if(R%2!=0){
                    if(C==5){
                        for(int j=0; j<C; j++){
                            res.push_back({1, 3*j%C+1});
                            res.push_back({2, (3*j+2)%C+1});
                            res.push_back({3, (3*j+4)%C+1});
                        }
                        start_col = 1;
                    }
                    else{
                        for(int j=0; j<C; j++){
                            res.push_back({1, j%C+1});
                            res.push_back({2, (j+2)%C+1});
                            res.push_back({3, (j+4)%C+1});
                        }
                        start_col = 3;
                    }
                    row_offset = 3;
                }
                for(int j=0; j<(R-row_offset)/2; j++){
                    for(int k=0; k<C; k++){
                        res.push_back({row_offset+j*2+1, (start_col+2+k)%C+1});
                        res.push_back({row_offset+j*2+2, (start_col+2+k+3)%C+1});
                    }
                }
            }
            for(int j=0; j<res.size()-1; j++){
                if(res[j].first==res[j+1].first || res[j].second==res[j+1].second || res[j].first-res[j].second==res[j+1].first-res[j+1].second || res[j].first+res[j].second==res[j+1].first+res[j+1].second){
                    cout << "assert " << "(" << res[j].first << "," << res[j].second << "), (" << res[j+1].first << "," << res[j+1].second << ")" << endl;
                }
            }
            if(transpose){
                for(auto p : res){
                    cout << p.second << " " << p.first << endl;
                }
            }
            else{
                for(auto p : res){
                    cout << p.first << " " << p.second << endl;
                }
            }
        }
        else{
            cout << "Case #" << (i+1) << ": IMPOSSIBLE" << endl;
        }
    }
}
