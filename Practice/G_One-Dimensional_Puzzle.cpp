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
const int nax = 4e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int fact[nax];

int binpow(int b, int e){
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int C(int n, int r){
    return 1LL * fact[n] * inv(1LL * fact[r] * fact[n - r] % mod) % mod;
}

int calc(int n1, int n2, int n3, int n4) {
    return (1LL *C(n1 + n3 - 1, n3) * C(n2 + n4 - 1, n4)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    fact[0] = 1;
    for1(i, nax - 1)fact[i] = 1LL*fact[i - 1] * i % mod;
    int t;
    cin >> t;
    while(t--){
        int n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;
        if (n1 + n2 == 0) {
            cout << (n3 == 0 || n4 == 0 ? 1 : 0) << '\n';
            continue;
        }
        if(abs(n1 - n2) > 1){
            cout << 0 << el;
            continue;
        }
        int ans = 0;
        if (n1 <= n2) {
            ans += calc(n1 + 1, n2, n3, n4);
            ans %= mod;
        }
        if (n2 <= n1) {
            ans += calc(n1, n2 + 1, n3, n4);
            ans %= mod;
        }
        cout << ans << el;
    }
}
