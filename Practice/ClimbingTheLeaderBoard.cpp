#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    int rank = 1;
    cin >> n;
    int ranked[n], ranks[n];
    for(int i = 0; i < n; ++i){
        cin >> ranked[i];
    }
    cin >> m;
    sort(ranked, ranked + n, greater<int>());

    for(int i = 0; i < n; ++i){
        if(i != 0 && ranked[i] != ranked[i-1]) rank++;
        ranks[i] = rank;
    }
    int player[m], output[m];
    for(int i = 0; i < m; ++i){
        cin >> player[i];
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(player[i] >= ranked[j]) {
                cout << ranks[j] << endl;
                break;
            }
        }
        if(player[i] < ranked[n-1]) cout << rank+1 << endl;
    }
}
