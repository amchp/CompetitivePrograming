#include <bits/stdc++.h>

using namespace std;

const int nax = 100;

int a[nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)cin >> a[i];
        sort(a, a + n);
        long long ans = 0;
        for(int i = 1; i < n; ++i){
            ans += a[i] - a[i - 1];
        }
        cout << ans << '\n';
    }
}
