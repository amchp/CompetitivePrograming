#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr << #x << ' ' << x << el;
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int nax = 1e5 + 10;
const int mod = 1e9 + 7;
const int sqnax = 632;

int fact[nax];

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

int b, p, k, s;
int crt, ncrt;
int dp[nax][sqnax];

int sol(int sm, int nadd){
    if(sm == s){
        return 1;
    }
    if(sm > s)return 0;
    int& ans = dp[sm][nadd];
    if(ans != -1)return ans;
    ans = 0;
    if(nadd < k){
        ans = add(mlt(sol(sm + nadd, nadd), ncrt), mlt(sol(sm + nadd + 1, nadd + 1), crt));
    }else{
        ans = mlt(sol(sm + nadd, nadd), add(crt, ncrt));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for1(i, nax - 1)fact[i] = mlt(fact[i - 1], i);
    cin >> b >> p >> k >> s;
    int sq = min(k, int(sqrt(s)));
    crt = comb(p, b);
    ncrt = sbt(binpow(2, p), crt);
    forn(i, sqnax){
        dp[s][i] = 1;
    }
    fored(sm, 1, s - 1){
        fored(nadd, 1, sqnax){
            if(sm + nadd > s){
                dp[sm][nadd] = 0;
                continue;
            }
            if(nadd == k){
                dp[sm][nadd] = mlt(dp[sm + nadd][nadd], add(crt, ncrt));
                continue;
            }
            dp[sm][nadd] = add(mlt(dp[sm + nadd][nadd], ncrt), mlt(dp[sm + nadd + 1][nadd + 1], crt));
        }
    }
    int ans = mlt(dp[1][1], crt);
    cout << ans << el;
}