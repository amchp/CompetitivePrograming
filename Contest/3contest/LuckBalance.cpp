#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, luck;
    cin >> n >> k;
    int L[n], T[n];
    vector<int> imp;
    for(int i = 0; i < n; ++i){
        cin >> L[i] >> T[i];
    }
    for(int i = 0; i < n; ++i){
        if(T[i] == 1){
            imp.push_back(L[i]);
        }else luck += L[i];
    }
    std::sort(imp.begin(), imp.end());
    for(auto i = imp.end() - 1; i != imp.begin() - 1; --i){
        if(k > 0) {
            luck += *i;
            k--;
        }
        else luck -= *i;
    }
    cout << luck << endl;
}


