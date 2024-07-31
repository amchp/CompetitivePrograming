#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, int> index;
unordered_map<int, int> knockOver;
vector<vector<int> > dominos;

void go(int ind){
    vector<int> v = dominos[index[ind]];
    for(int i = 1; i < v.size(); ++i){
        if(knockOver[v[i]] != 3){
            knockOver[v[i]] = 3;
            go(v[i]);
            knockOver[v[i]] = 2;
        }
    }
}

int main(){
    int t, n, l, d, nD, count;
    cin >> t;
    while(t--){
        cin >> n >> l;
        count = 0;
        for(int i = 0; i < l; ++i){
            cin >> d >> nD;
            if(index[d] != 0){
                dominos[index[d]].push_back(nD);
            }
            else{
                vector<int> v;
                v.push_back(d);
                v.push_back(nD);
                dominos.push_back(v);
                index[d] = dominos.size() - 1;
            }
        }
        int cur;
        for(int i = 0; i < dominos.size(); ++i){
            cur = dominos[i][0];
            if(knockOver[cur] == 0) {
                knockOver[cur] = 1;
                go(cur);
            }
        }
        count = 0;
        for(auto const& [key, val] : knockOver){
            if(val == 1) count++;
        }
        count += n - knockOver.size();
        cout << count << endl;
    }
}