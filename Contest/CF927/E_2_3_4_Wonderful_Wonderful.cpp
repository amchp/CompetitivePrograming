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
const int nax = 2e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

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

int binpow(int b, int e){
    int ans = 1;
    for(; e; b = mlt(b, b), e /= 2){
        if(e&1)ans = mlt(ans, b);
    }
    return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int fact[nax];

int C(int n, int k){
    return mlt(fact[n], inv(mlt(fact[n - k], fact[k])));
}

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    fact[0] = 1;
    for1(i, nax - 1)fact[i] = mlt(fact[i - 1], i);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for1(k, (n - 1) / 2){
            int ans = 0;
            for(int x = n; x >= 1; x -= 2*k){
                ans = add(ans, sbt(C(n, x), C(x + 2*k - 1, 2*k - 1)));
            }
            cout << ans << ' ';
        }
        cout << el;
    }
}
