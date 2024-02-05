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
const int nax = 2e5 + 200;
// const int nax = 1e3 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int addm(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int subm(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int mulm(int a, int b){
    return (1LL*a*b) % mod;
}

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int a){
    return binpow(a, mod - 2);
}

int divm(int a, int b){
    return mulm(a, inv(b));
}

int cnta[27];
int cntb[27];
int sufa[28];
int fact[nax];
int dp[27][nax];

int comb(int n, int r){
    if(n < r)return 0;
    return divm(fact[n], mulm(fact[r], fact[n - r]));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    fact[0] = 1;
    for1(i, nax){
        fact[i] = mulm(fact[i - 1], i);
    }
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;
    for(char& c : s1){
        ++cnta[c - 'A'];
    }
    for(char& c : s2)++cntb[c - 'A'];
    sufa[27] = 0;
    ford(i, 27)sufa[i] = sufa[i + 1] + cnta[i];
    dp[26][0] = 1;
    ford(c, 26){
        int pre[nax];
        pre[0] = 0;
        forn(curCP, nax - 1){
            pre[curCP + 1] = addm(pre[curCP], mulm(comb(cnta[c], curCP), dp[c + 1][curCP]));
        }
        forn(curC, cntb[c] + 1){
            int l = max(0, cnta[c] - (cntb[c] - curC));
            int r = min(cnta[c], cntb[c + 1]) + 1;
            dp[c][curC] = mulm(comb(sufa[c], cnta[c]), subm(pre[r], pre[l]));

        }
    }
    cout << dp[0][0] << el;
}
