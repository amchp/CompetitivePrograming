#include <iostream>

using namespace std;

int main(){
    int n, k, max, potion;
    cin >> n >> k;
    int j[n];
    max = 0;
    for(int i = 0; i < n; ++i){
        cin >> j[i];
        if(max < j[i]) max = j[i];
    }
    potion = max - k;

    if(potion > 0) cout << potion << endl;
    else cout << 0 << endl;

}