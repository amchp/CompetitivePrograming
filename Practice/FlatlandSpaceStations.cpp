#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[m];
    int nM[n];
    for(int i = 0; i < n; ++i){
        nM[i] = 10000000;
    }
    for(int i = 0; i < m; ++i){
        cin >> arr[i];
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            nM[j] = min(nM[j], abs(j - arr[i]));
        }
    }
    int maxi = 0;
    for(int i = 0; i < n; ++i){
        maxi = max(maxi, nM[i]);
    }
    cout << maxi << endl;
}