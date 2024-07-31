#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define sz(x)(int) x.size()
#define fi first
#define se second
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;


ll sum (vll & pref, int l,int r){
    return pref[r] - (l > 0 ? pref[l-1] : 0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<ll> pref(n+2), suf(n+2);
    vector<ll> a(n+2);
    bool prend = 1;
    a[0] = 0, a[n+1] = m;
    for1(i,n){
        cin>>a[i];
        
        pref[i] = pref[i-1];
        if(i & 1){
            pref[i] += a[i] - a[i-1];
        }
    }
    pref[n+1] = pref[n];
    if((n+1) & 1)
        pref[n+1] += a.back() - a[n];

    ll ans = pref[n+1];
    for1(i,n+1){
        int l = i-1, r = i;
        ll cur = a[r] - a[l] - 1 + pref[l];
        cur += (a.back() - a[r]); 
        cur -= sum(pref, r, n+1);
        // cerr<<i<<el;
        // cerr<<ans<<el;
        ans = max(ans, cur);
    }
    cout<<ans<<el;
}
