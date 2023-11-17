#include <iostream>

using namespace std;

int main(){
    int t, n, k, count;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n];
        count = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(a[i] <= 0) count++;
        }
        if(count >= k) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}