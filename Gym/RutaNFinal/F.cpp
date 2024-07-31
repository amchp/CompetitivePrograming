#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define sz(x) x.size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    while(cin >> n){
        cin >> m;
        vi a(n);
        vector<ll> pre(n + 1);
        pre[0] = 0;
        ll mn = 0LL;
        forn(i, n){
            cin >> a[i];
            pre[i + 1] = pre[i] + (ll)a[i];
            mn = min(mn, pre[i + 1]);
        }
        // cout << pre[n] << ' ' << m << ' ' << abs(mn) << el;
        ll sol2 = max(m - pre[n], 0LL);
        cout << abs(mn) << ' ' << sol2 << el;
    }
}