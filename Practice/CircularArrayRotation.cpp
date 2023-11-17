#include <iostream>

using namespace std;

int main(){
    int n, k, q, v;
    cin >> n >> k >> q;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[(i+k) % n];

    for(int i = 0; i < q; ++i){ 
        cin >> v; 
        cout << arr[v] << endl;
    }
}