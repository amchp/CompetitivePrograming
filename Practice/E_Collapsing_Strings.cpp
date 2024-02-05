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

const static int N = 2e6, alpha = 26;
int to[N][alpha], cnt[N], sz;
inline int conv(char ch){ return ch - 'a'; }  //  CAMBIAR
// AGREGAR LO QUE HAYA QUE RESETEAR !!!!
void init(){ 
  forn(i, sz+1) cnt[i] = 0, memset(to[i], 0, sizeof to[i]);
  sz = 0;
}
void add(const string &s){
  int u = 0;
  for(char ch: s){
    int c = conv(ch);
    if(!to[u][c]) to[u][c] = ++sz;
    u = to[u][c];
    cnt[u]++;
  }
}

ll dfs(const string &s){
    ll ans = 0;
    int u = 0;
    for(char ch : s){
        int c = conv(ch);
        if(!to[u][c])break;
        u = to[u][c];
        ans += cnt[u];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vector<string> words(n);
    ll ans = 0;
    forn(i, n){
        cin >> words[i];
        ans += 2LL*sz(words[i])*n;
        add(words[i]);
    }
    // d(ans);
    forn(i, n){
        reverse(all(words[i]));
        // d(words[i]);
        ll tst = dfs(words[i]);
        // d(tst);
        ans -= 2LL*tst;
    }
    cout << ans << el;
}
