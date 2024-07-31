#include <bits/stdc++.h>

using namespace std;

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
        vector<int> a;
        for(int i = 0; i < n; ++i){
            int v;
            cin >> v;
            a.push_back(v);
        }
        int ans = 0;
        for(int i = n - 2; i >= 0; --i){
            if(a[i + 1] < a[i]){
                ans = max(ans, a[i]);
            }
        }
        cout << ans << '\n';
    }
}
