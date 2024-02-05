#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define el '\n'

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 2*n;
    forn(i, n + 1){
        forn(j, n + 1){
            ll val = (1LL*a*i + 1LL*b*j);
            if(val >= n && val % n == 0LL)ans = min(1LL*i + j, ans);
        }
    }
    // assert(ans >= 2);
    // assert(ans <= 2*n);
    cout << ans << el;
    return 0;
}