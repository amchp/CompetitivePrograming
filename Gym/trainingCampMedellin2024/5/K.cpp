#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

void sol(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    ll ans = 0;
    vi bkt(k);
    forn(i, n){
        cin >> a[i];
        ans += a[i] / k;
        ++bkt[a[i] % k];
    }
    ll pre = 0;
    for1(i, k - 1){
        if(k - i < i)break;
        pre += bkt[k - i];
        if(k - i == i)break;
        ll add = min(pre, (ll)bkt[i]);
        ans += add;
        bkt[i] -= add;
        pre -= add;
    }
    ans += pre / 2;
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}