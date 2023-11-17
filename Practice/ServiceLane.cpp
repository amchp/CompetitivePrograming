#include <iostream>

using namespace std;

int main(){
    int n, t, i, j, width;
    cin >> n >> t;
    int lane[n];
    for(int k = 0; k < n; ++k){
        cin >> lane[k];
    }
    while(t--){
        cin >> i >> j;
        width = 3;
        for(int k = i; k <= j; ++k){
            if(width > lane[k]) width = lane[k];
            if(width == 1) break;
        }
        cout << width << endl;
    }
}