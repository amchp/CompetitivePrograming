#include <bits/stdc++.h>

#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define el '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        // cout << la << ' ' << ra << ' ' << lb << ' ' << rb << el;
        la = max(la, ra - 10);
        lb = max(lb, rb - 10);
        int ans = 0;
        fore(i, la, ra){
            fore(j, lb, rb){
                ll x = i + j;
                string s = to_string(x);
                int mx = 0;
                for(char& c : s){
                    mx = max(c - '0', mx);
                }
                ans = max(ans, mx);
            }
        }
        cout << ans << el;
    }
}