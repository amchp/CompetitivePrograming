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
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int nax = 5032107;
const int sqnax = sqrt(nax) + 3;

struct stree{
  int neutro = 1e9, n, l, r, pos, val;  vi t;
  stree(int n): n(n), t(n << 2, neutro){}
  inline int oper(int a, int b){ return a < b ? a : b; }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = min(t[v], val);  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20);
    int n, q;
    cin >> n >> q;
    vector<bool> sv(sqnax + 1, false);
    vi primes;
    fore(i, 2, sqnax){
        if(sv[i])continue;
        primes.pb(i);
        for(int j = i + i; j <= sqnax; j += i){
            sv[j] = true;
        }
    }
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    vector<vi> aprms(n, vi());
    forn(i, n){
        int tmp = a[i];
        for(int& p : primes){
            int cnt = 0;
            while(tmp % p == 0){
                tmp /= p;
                ++cnt;
            }
            if(cnt&1)aprms[i].pb(p);
        }
        if(tmp != 1)aprms[i].pb(tmp);
    }
    vector<vi> rgts(nax + 1, vi(9, -1));
    vector<vector<ii>> inter(18);
    ford(i, n){
        int bts = sz(aprms[i]);
        int bsz = 1 << bts;
        // d(i);
        ford(j, bsz){
            int num = 1;
            int cnt = bts;
            forn(k, bts){
                if(j & (1 << k)){
                    num *= aprms[i][k];
                    --cnt;
                }
            }
            forn(k, 9){
                int r = rgts[num][k];
                if(r == -1)continue;
                // cout << i << ' ' << r << ' ' << cnt + k << el;
                // cout << cnt + k << el;
                inter[cnt + k].pb({i, r});
            }
            rgts[num][cnt] = i;
        }
        // cout << "#####" << el;
    }
    vector<ii> qrs(q);
    forn(i, q){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        qrs[i] = {l, r};
    }
    vi ans(q, inf);
    forn(i, 18){
        stree st = stree(n);
        for(auto& [l, r] : inter[i]){
            // cout << l << ' ' << r << el;
            st.upd(l, r);
        }
        // d(i);
        forn(j, q){
            if(ans[j] != inf)continue;
            auto& [l, r] = qrs[j];
            int mr = st.query(l, r);
            // d(l);
            // d(r);
            // d(mr);
            // cout << el;
            if(mr <= r){
                ans[j] = i;
            }
        }
        // cout << "#####" << el;
    }
    for(int& v : ans){
        assert(v != inf);
        cout << v << el;
    }
}