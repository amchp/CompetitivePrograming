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
const int nax = 5e3 + 100;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MODS[] = { 1001864327, 1001265673 };
const ii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, const int& mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int& mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int& mod) { return 1ll*a*b%mod; }
inline ll operator ! (const ii a) { return (ll(a.fi)<<32)|ll(a.se); }
inline ii operator + (const ii a, const ii b) {
  return {add(a.fi, b.fi, MODS[0]), add(a.se, b.se, MODS[1])};
}
inline ii operator - (const ii a, const ii b) {
  return {sbt(a.fi, b.fi, MODS[0]), sbt(a.se, b.se, MODS[1])};
}
inline ii operator * (const ii a, const ii b) {
  return {mul(a.fi, b.fi, MODS[0]), mul(a.se, b.se, MODS[1])};
}

ii base[nax];
void prepare() {
  base[0] = ONE;
  for1(i,nax-1) base[i] = base[i-1]*BASE;
}
template <class type>
struct hashing {   /// HACELEEE PREPAREEEE!!!
  vector<ii> code;
  hashing(type &t) {
    code.resize(sz(t)+1);
    code[0] = ZERO;
    for1(i,sz(t))
      code[i] = code[i-1]*BASE + ii{t[i-1], t[i-1]};
  }
  ii query(int l, int r) { ///  [l,r]
    return code[r+1] - code[l]*base[r-l+1];
  }
};

int dp[nax][nax];
int pal[nax][nax];

int sol(int l, int r){
    int& ans = dp[l][r];
    if(l > r)return 0;
    if(ans != -1)return ans;
    if(l == r){
        return ans = pal[l][r];
    }
    return ans = sol(l + 1, r) + sol(l, r - 1) + pal[l][r] - sol(l + 1, r - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    memset(dp, -1, sizeof(dp));
    memset(pal, 0, sizeof(pal));
    prepare();
    string s;
    cin >> s;
    hashing hs = hashing(s);
    reverse(all(s));
    hashing rHs = hashing(s);
    int n = sz(s);
    forn(l, n){
        fore(r, l, n - 1){
            int mid = l + (r - l) / 2;
            int rR = n - (r + 1);
            int rMid = n - (mid + (r - l) % 2 + 1);
            if(hs.query(l, mid) == rHs.query(rR, rMid)){
                pal[l][r] = 1;
            }
        }
    }
    // forn(i, n){
    //     forn(j, n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << el;
    // }
    cout << el;
    sol(0, n - 1);
    // forn(i, n){
    //     forn(j, n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << el;
    // }
    int q;
    cin >> q;
    forn(i, q){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << dp[l][r] << el;
    }
}
