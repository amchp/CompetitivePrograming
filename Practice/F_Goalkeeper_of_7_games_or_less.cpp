#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<int, 3> a3;


const int inf = 1e9 + 100;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct stree{
  a3 neutro = {inf, inf, inf};
  int n, l, r, pos, val;
  vector<a3> t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline a3 oper(a3 a, a3 b){ 
    int i = 0;
    int j = 0;
    a3 c;
    forn(k, 3){
        if(a[i] < b[j]){
            c[k] = a[i];
            ++i;
        }else{
            c[k] = b[j];
            ++j;
        }
    }
    return c;
  }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = {a[tl], inf, inf};  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  a3 query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = {val, inf, inf};  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  a3 query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, q;
    cin >> n >> q;
    vi a(n);
    map<int, set<int>> mp;
    map<int, int> pv;
    vi nxt(n);
    vi prv(n);
    forn(i, n){
        cin >> a[i];
        if(!pv.count(a[i])){
            prv[i] = -1;
        }else{
            nxt[pv[a[i]]] = i;
            prv[i] = pv[a[i]];
        }
        pv[a[i]] = i;
        mp[a[i]].insert(i);
    }
    for(auto& [x, lst] : pv){
        nxt[lst] = n;
    }
    stree st(nxt);
    while(q--){
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        if(op == 0){
            int lft = prv[l];
            int rgt = nxt[l];
            if(lft > -1){
                nxt[lft] = rgt;
                st.upd(lft, nxt[lft]);
            }
            if(rgt < n)prv[rgt] = lft;
            mp[a[l]].erase(l);

            a[l] = r;
            auto it = mp[r].upper_bound(l);
            rgt = it != mp[r].end() ? (*it) : n;
            if(it != mp[r].begin()){
                --it;
                lft = (*it);
            }else lft = -1;
            if(rgt < n)prv[rgt] = l;
            if(lft > -1){
                nxt[lft] = l;
                st.upd(lft, nxt[lft]);
            }

            prv[l] = lft;
            nxt[l] = rgt;
            mp[r].insert(l);
            st.upd(l, nxt[l]);
        }
        if(op == 1){
            --r;
            a3 rgts = st.query(l, r);
            vector<ii> ans;
            auto check = [&](){
                vector<ii> inter;
                forn(i, 3){
                    if(rgts[i] <= r){
                        inter.pb({prv[rgts[i]], rgts[i]});
                    }
                }
                forn(i, sz(inter)){
                    fore(j, i + 1, sz(inter) - 1){
                        if(inter[i].se != inter[j].fi){
                            ans = {inter[i], inter[j]};
                            return true;
                        }
                    }
                }
                return false;
            };
            if(check()){
                for(auto& [fir, snd] : ans)cout << fir + 1 << ' ' << snd + 1 << ' ';
                cout << el;
            }else{
                cout << -1 << el;
            }
        }
    }
}