#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Trie{
public:
    char c;
    vector<Trie*> nexts;

    Trie(char c) : c(c){}

    void append(string s){
        auto it = find_if(this->nexts.begin(), this->nexts.end(), [&](Trie* t){
            return (s=="" && t->c==0) || s[0]==t->c;
        });
        if(it == this->nexts.end()){
            if(s=="") this->nexts.push_back(new Trie(0));
            else{
                Trie* next = new Trie(s[0]);
                this->nexts.push_back(next);
                next->append(s.substr(1));
            }
        }
        else if(s!="") (*it)->append(s.substr(1));
    }

    int reduce(int* total){
        if(this->nexts.size()==0) return 1;
        int count = 0;
        this->nexts.erase(remove_if(this->nexts.begin(), this->nexts.end(), [&](Trie* t){
            int tmp = t->reduce(total);
            count += tmp;
            return tmp==0;
        }), this->nexts.end());
        if(count<2) return count;
        *total += 2;
        return count-2;
    }
};

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int N;
        cin >> N;

        Trie* root = new Trie(0);
        for(int j=0; j<N; j++){
            string buf;
            cin >> buf;
            reverse(buf.begin(), buf.end());
            root->append(buf);
        }
        int total = 0;
        for(auto it = root->nexts.begin(); it!=root->nexts.end(); ++it){
            (*it)->reduce(&total);
        }
        cout << "Case #" << (i+1) << ": " << total << endl;
    }
}
