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
        int mn = 0, mx = 1e9;
        vector<int> s;
        for(int i = 0; i < n; ++i){
            int o, x;
            cin >> o >> x;
            if(o == 1){
                mn = max(mn, x);
            }
            if(o == 2){
                mx = min(mx, x);
            }
            if(o == 3)s.push_back(x);
        }
        if(mx < mn){
            cout << 0 << '\n';
            continue;
        }
        int ans = mx - mn + 1;
        sort(s.begin(), s.end());
        auto it = lower_bound(s.begin(), s.end(), mn);
        while(it != s.end() && (*it) <= mx){
            --ans;
            it++;
        }
        cout << ans << '\n';
    }
}