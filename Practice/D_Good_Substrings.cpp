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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    string s;
    cin >> s;
    string good;
    cin >> good;
    int k;
    cin >> k;
    set<ii> ans;
    string cAns;
    int bad = 0;
    forn(i, s.size()){
        cAns = "";
        bad = 0;
        // cout << i << el;
        ii code = ZERO;
        fore(j, i,s.size() - 1){
            cAns.pb(s[j]);
            if(good[s[j] - 'a'] == '0')bad++;
            if(bad > k)break;
            code = code*BASE + ii{s[j], s[j]};
            ans.insert(code);
        }
    }
    cout << ans.size() << el;
}
