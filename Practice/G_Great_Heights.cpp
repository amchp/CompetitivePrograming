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
#define d(x) cout<< #x<< " " << x<<el
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
typedef array<int, 4> a4;


const int inf = 2e9 + 100;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
vector<a3> edgs;
int hgts[nax];

int incresing(int y, int x){
  return y - x;
}

int decreasing(int y, int x){
  return y + x;
}

void sol(vector<a4>& pt, auto f){
  set<a3> st;
  for(auto& [h, l, r, ind] : pt){
    int b1 = f(h, l);
    int b2 = f(h, r);
    int bli = min(b1, b2);
    int bri = max(b1, b2);
    auto its = st.upper_bound(a3{bli, inf, inf});
    auto ite = st.upper_bound(a3{bri, inf, inf});
    if(its != st.begin())--its;
    auto it = its;
    for(; it != ite;){
      auto& [blj, brj, jnd] = (*it);
      int itl = max(blj, bli);
      int itr = min(brj, bri);
      if(itl <= itr){
        assert(ind != jnd);
        edgs.pb({abs(hgts[jnd] - hgts[ind]), ind, jnd});
      }
      ++it;
    }
    it = its;
    
    for(; it != ite;){
      auto [blj, brj, jnd] = (*it);
      int itl = max(blj, bli);
      int itr = min(brj, bri);
      auto pit = it;
      ++it;
      if(itl <= itr){
        st.erase(pit);
        if(itl != blj)st.insert({blj, itl - 1, jnd});
        if(itr != brj)st.insert({itr + 1, brj, jnd});
      }
    }
    st.insert(a3{bli, bri, ind});
  }
}

int p[nax], szs[nax];

int find(int x){
  if(x == p[x])return x;
  return p[x] = find(p[x]);
}

ll ans = 0;

void merge(int u, int v, int w){
  u = find(u);
  v = find(v);
  if(u == v)return;
  ans += w;
  if(szs[u] < szs[v])swap(u, v);
  szs[u] += szs[v];
  p[v] = u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n;
    vector<a4> pt(n + 1);
    hgts[0] = 0;
    pt[0] = {0, -inf, inf, 0};
    for1(i, n){
      int h, l, r;
      cin >> h >> l >> r;
      pt[i] = a4{h, l, r, i};
      hgts[i] = h;
    }
    sort(all(pt));
    vector<a4> rpt = pt;
    reverse(all(rpt));
    sol(pt, incresing);
    sol(pt, decreasing);
    sol(rpt, incresing);
    sol(rpt, decreasing);
    sort(all(edgs));
    forn(i, n + 1){
      p[i] = i;
      szs[i] = 1;
    }
    for(auto& [w, i, j] : edgs){
      merge(i, j, w);
    }
    int cmp = find(0);
    forn(i, n + 1)assert(find(i) == cmp);
    cout << ans << el;
}