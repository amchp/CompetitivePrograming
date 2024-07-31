#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    // freopen("output.txt", "w", stdout);
    int n = 2e5;
    cout << n << ' ' << n << endl;
    for(int i = 0; i < n; ++i){
        if(i == n - 1){
            cout << n << endl;
            continue;
        }
        cout << n << ' ';
    }
    for(int i = 0; i < n; ++i)cout << n << ' ' << 500 << endl;
}