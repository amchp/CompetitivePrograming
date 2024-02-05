#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define sz(x) x.size()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vll a(6);
    forn(i, 6)cin >> a[i];
    sort(all(a));
    map<ll, int> dst;
    for1(i, 5){
        ++dst[a[i] - a[i - 1]];
    }
    if(sz(dst) == 2){
        ll ans = -1;
        ll dstf = (*dst.begin()).fi;
        ll ddst = (*dst.rbegin()).fi;
        assert(2*dstf == ddst);
        for1(i, 5){
            if(ddst == a[i] - a[i - 1]){
                ans = a[i - 1] + dstf;
            }
        }
        assert(ans != -1);
        cout << ans << el;
        return 0;
    }
    ll rdst = (*dst.rbegin()).fi;
    set<ll> ans;
    if(a[0] - rdst > 0)ans.insert(a[0] - rdst);
    ans.insert(a[5] + rdst);
    for(ll v : ans)cout << v << el;
    return 0;
}