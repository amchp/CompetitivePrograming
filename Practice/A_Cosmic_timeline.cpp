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

struct stree{
  ll neutro = 0, val;
  int n, l, r, pos;  vl t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){}
  inline ll oper(ll a, ll b){ return a > b ? a : b; }
  ll query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = max(t[v], val);  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vl cmpr;
    vector<vl> evn(n, vl(3));
    forn(i, n){
        cin >> evn[i][0] >> evn[i][1] >> evn[i][2];
        cmpr.pb(evn[i][0]);
    }
    sort(cmpr.begin(), cmpr.end());
    cmpr.erase(unique(all(cmpr)), cmpr.end());
    int sn = sz(cmpr);
    stree st(sn);
    ll mx = 0;
    forn(i, n){
        ll lf = evn[i][0] - evn[i][2];
        int pos = lower_bound(all(cmpr), evn[i][0]) - cmpr.begin();
        int l = lower_bound(all(cmpr), lf) - cmpr.begin();
        ll ans = evn[i][1];
        // d(l);
        // d(pos);
        if(l <= pos){
            ans += st.query(l, pos);
            
        }
        st.upd(pos, ans);
        mx = max(mx, ans);
    }
    cout << mx << el;
}
