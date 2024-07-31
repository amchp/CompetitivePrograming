#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr << #x << ' ' << x << el;
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int nax = 1000 + 200;
const int mod = 1e9 + 7;

int fact[nax];

int mlt(int a, int b){
    return 1LL*a*b%mod;
}

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int comb(int n, int k){
    return mlt(fact[n], inv(mlt(fact[n - k], fact[k])));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for1(i, nax - 1)fact[i] = mlt(fact[i - 1], i);
    int n, m, k;
    cin >> n >> m >> k;
    vi a(m + 1);
    forn(i, n){
        int v;
        cin >> v;
        ++a[v];
    }
    map<int, int> cnt;
    forn(i, m + 1){
        if(a[i] == 0)continue;
        ++cnt[a[i]];
    }
    vi arr;
    for(auto& [key, val] : cnt){
        arr.pb(key*val);
    }
    int i = 0;
    int pre = 0;
    while(i < sz(arr) && pre + arr[i] <= k){
        pre += arr[i];
        ++i;
    }
    // d(i);
    if(i == sz(arr)){
        cout << 1 << el;
        return 0;
    }
    // d(pre);
    int dif = k - pre;
    // d(arr[i]);
    // d(dif);
    // d(comb(arr[i], dif));
    // d(dif);
    int ans = comb(arr[i], dif);
    cout << ans << el;
}