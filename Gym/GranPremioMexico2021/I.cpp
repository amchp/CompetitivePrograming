#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i <(int)n;++i)
#define fore(i,l,r) for(int i = l ; i<= (int)r; ++i)
#define for1(i,n) for(int i = 1; i <= (int)n;++i)
#define ford(i,n) for(int i = (int)n - 1; i >= 0;--i)
#define el '\n'
#define sz(a) (int)a.size()
#define pb push_back
#define all(a) a.begin(),a.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vl;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, k, t;
    cin >> n >> k >> t;
    vl a(n);
    forn(i, n)cin >> a[i];
    ll ans = 0;
    vector<ll> pre(n);
    pre[0] = 0;
    for1(i, n - 1){
        pre[i] = pre[i - 1] + (a[i] - a[i - 1])*i;
    }
    ans = pre[n - 1];
    // d(ans);
    int ai = -1;
    int aj = -1;
    forn(i, n - 1){
        int nxt = upper_bound(all(a), a[i] + k) - a.begin();
        --nxt;
        if(nxt <= i)continue;
        ll nans = pre[n - 1] - (a[nxt] - a[i])*(i + 1) + t*(i + 1);
        // d(nans);
        if(nans < ans){
            ai = i + 1;
            aj = nxt + 1;
            ans = nans;
        }
    }
    if(ai == -1)cout << -1 << el;
    else cout << ai << ' ' << aj << ' ' << ans << el;
    return 0;
}