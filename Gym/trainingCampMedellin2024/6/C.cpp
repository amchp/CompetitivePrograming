#include <bits/stdc++.h>

#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define el '\n'
#define fi first
#define se second
#define db(x) cerr<<#x<<" "<<x<<el
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


ll lcm(ll a, ll b){
    return 1LL*a*b/__gcd(a,b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];

    int N = 1<<n;

    ll ans = 0;
    for1(mask,N-1){
        ll lc = 1, cnt = 0;
        forn(i, n){
            if((1<<i) & mask){
                ++cnt;
                // if(lc == -1) lc = a[i];
                lc = lcm(a[i], lc);
                if(lc > x)break;
            }
        }
        if(lc > x)continue;
        if(cnt & 1) ans += x/lc;
        else ans -= x/lc;
    }
    cout<<ans<<el;
}