#include <bits/stdc++.h>

#define el '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--){
        double n;
        cin >> n;
        cout << (n * 1.15) << el;
    }
}