#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int sbt(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int mlt(int a, int b){
    return 1LL*a*b % mod;
}

int binpow(int b, ll e) {
	int ans = 1;
	for (; e; b = mlt(b, b), e /= 2)
		if (e&1) ans = mlt(ans, b);
	return ans;
}

pll flr(ll a){
    ll l = ceil(a / 2.0);
    ll r = floor(a / 2.0);
    return {l, r};
}

int sm1(ll a){
    if(a & 1){
        return mlt(((a + 1) / 2) % mod, (a) % mod);
    }
    return mlt((a / 2) % mod, (a + 1) % mod);
}

int smlr(ll l, ll r){
    return sbt(sm1(r), sm1(l - 1));
}

int tms(ll l, ll r){
    return mlt(sbt(binpow(2, l), 1), sbt(binpow(2, r), 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll, ll> dp;
        queue<ll> q;
        int ans = ;
        priority_queue<ll> pq;
        ll c = 1;
        dp[n] = 1;
        pq.push(n);
        while(!pq.empty()){
            ll cur = pq.top();
            pq.pop();
            d(cur);
            if(cur != 1){
                ll l, r;
                tie(l, r)  = flr(cur);
                ans = add(ans, mlt(tms(l, r), smlr(c, c + dp[cur] - 1)));
                c = c + dp[cur];
                dp[l] = add(dp[l], dp[cur]);
                dp[r] = add(dp[r], dp[cur]);
                pq.push(l);
                pq.push(r);
            }
            while(!pq.empty() && cur == pq.top())pq.pop();
        }
        cout << ans << el;
    }
}
