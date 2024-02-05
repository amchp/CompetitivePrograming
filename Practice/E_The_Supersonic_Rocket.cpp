#include<bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define fored(i, l, r) for(int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define d(x) cerr<<#x<<" "<<x<<el
#define el '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, int> ldi;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int kax = 4;
typedef array<ll, kax> vk;

const ld eps = 1e-9;
const ld inf = 1e18;
const ld pi = acos(-1);
struct pt{
  ll x, y;
  pt(){}
  pt(ll x, ll y): x(x), y(y){}
  ll operator*(pt p){return x*p.x + y*p.y;}
  ll norm2(){ return *this**this; }
  ld norm(){return sqrt(norm2());}
  bool operator<(pt p)const{ // for sort, convex hull/set/map
		return x < p.x || (x == p.x && y < p.y); }

  pt operator-(pt p){return pt(x - p.x, y - p.y);}
  ll operator%(pt p){return x * p.y - y * p.x;}
  ll side(pt p, pt q){return (q - p) % (*this - p);}
  bool operator==(pt p){return x == p.x && y == p.y;}
};
/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const vk MOD = { 1001864327, 1001265673,  1000777121, 999727999};
const int N = 6e5;
const vk BASE{601961, 399989,402697, 202339	}, ZERO{0,0,0,0}, ONE{1,1,1,1};
inline int add(int a, int b, int mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, int mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, int mod) { return ll(a) * b % mod;} 
inline ll operator ! (const ii a) { return (ll(a.fi) << 32) | a.se; }
inline vk operator + (const vk& a, const vk& b) {
    vk arr;
    forn(i,kax){arr[i] = add(a[i], b[i], MOD[i]);}
    return arr;
}
inline vk operator - (const vk& a, const vk& b) {
    vk arr;
    forn(i,kax){arr[i] = sbt(a[i], b[i], MOD[i]);}
    return arr;
}
inline vk operator * (const vk& a, const vk& b) {
    vk arr = ZERO;
    forn(i,kax){arr[i] = mul(a[i], b[i], MOD[i]);}
    return arr;
}


vk base[N]{ONE};
void prepare() { for1(i, N-1) base[i] = base[i-1] * BASE; }
template <class type>
struct hashing {   /// HACELEEE PREPAREEEE!!!
  vector<vk> ha;
  hashing(type &t): ha(sz(t)+1, ZERO){
    for1(i, sz(t)) ha[i] = ha[i-1] * BASE + vk{t[i-1], t[i-1], t[i-1], t[i-1]};
  }
  vk query(int l, int r){ return ha[r+1] - ha[l] * base[r-l+1]; } //[l,r]
};
// CCW order, excludes collinear points
// Change .side(r[sz(r)-2], p[i]) > 0 to include collinear
vector<pt> chull(vector<pt>& p){ 
  if(sz(p) < 3) return p;
  vector<pt> r;
  sort(all(p));  // first x, then y
  forn(i, sz(p)){ // lower hull
    while(sz(r) > 1 && r.back().side(r[sz(r)-2], p[i]) >= 0) r.pop_back();
    r.pb(p[i]);
  }
  r.pop_back();
  int k = sz(r);
  fored(i, 0, sz(p)-1){ // upper hull
    while(sz(r) > k+1 && r.back().side(r[sz(r)-2], p[i]) >= 0) r.pop_back();
    r.pb(p[i]);
  }
  r.pop_back();
  return r;
}
vector<ll> getNorms(vector<pt> &a){
    int n = sz(a);
    vector<ll> norms(3*n);
    forn(i, n){
        pt v1 = a[(i+1) % n] - a[i];
        pt v2 = a[(i+2) % n] - a[(i+1) % n];
        norms[3*i] = (v1).norm2();
        norms[3*i + 1] = (v1 * v2);
        norms[3*i + 2] = (v1 % v2);
    }
    return norms;
}

bool compare(vector<pt> &a, vector<pt> &b){
    if(sz(a) != sz(b)) return 0;
    if(sz(a) == 1) return 1;
    int n = 3*sz(a);
    vector<ll> normsA = getNorms(a), normsB = getNorms(b);
    vector<ll> ar;
    for(ll x : normsA) ar.pb(x);
    for(ll x : normsB) ar.pb(x);
    sort(all(ar));
    ar.erase(unique(all(ar)),ar.end());

    for(ll &x : normsA) x = lower_bound(all(ar), x) - ar.begin();
    vector<ll> newA = normsA;
    for(ll x : normsA) newA.pb(x);


    for(ll &x : normsB) x = lower_bound(all(ar), x) - ar.begin();
    vector<ll> newB = normsB;
    for(ll x : normsB) newB.pb(x);

    hashing<vector<ll>> hA(newA), hB(newB);
    assert((sz(newA) == 2*n));
    assert((sz(newB) == 2*n));
    vector<pair<vk,int>> hashes;
    forn(i,n){
        hashes.pb({hA.query(i,i+n-1),i});
    }
    sort(all(hashes));
    hashes.erase(unique(all(hashes)), hashes.end());
    auto eq = [&](vector<ll> &w, vector<ll> &y, int sizz, int idxA, int idxB)->bool{
        forn(i,sizz){
            if(w[idxA + i] != y[idxB + i])return false;
        }
        return true;
    };

    forn(i,n){
        vk q =  hB.query(i, i+n-1);
        int idx = lower_bound(all(hashes), pair<vk,int>{q,-1}) - hashes.begin();
        // d(idx);
        if(idx != sz(hashes) && hashes[idx].fi == q){
            assert(eq(newA, newB, n, hashes[idx].se, i));
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << setprecision(20) << fixed;
    prepare();
    int n, m;
    cin >> n >> m;
    vector<pt> a(n),b(m);
    forn(i,n){
        ll x,y;
        cin>>x>>y;
        a[i] = pt(x,y);
    }
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        b[i] = pt(x,y);
    }

    vector<pt> cha = chull(a), chb = chull(b);
    // cha.erase(unique(all(cha)),cha.end());
    // chb.erase(unique(all(chb)),chb.end());

    if(compare(cha, chb)){
        cout<<"YES"<<el;
    }else cout<<"NO"<<el;

    return 0;
}