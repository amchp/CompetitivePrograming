#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(a) (int) a.size()
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll inf = 2e18;

/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MOD[] = { 1001864327, 1001265673 }, N = 3e5;
const ii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, int mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, int mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, int mod) { return ll(a) * b % mod;} 
inline ll operator ! (const ii a) { return (ll(a.fi) << 32) | a.se; }
inline ii operator + (const ii& a, const ii& b) {
  return {add(a.fi, b.fi, MOD[0]), add(a.se, b.se, MOD[1])};}
inline ii operator - (const ii& a, const ii& b) {
  return {sbt(a.fi, b.fi, MOD[0]), sbt(a.se, b.se, MOD[1])};}
inline ii operator * (const ii& a, const ii& b) {
  return {mul(a.fi, b.fi, MOD[0]), mul(a.se, b.se, MOD[1])};}

ii base[N]{ONE};
void prepare() { for1(i, N-1) base[i] = base[i-1] * BASE; }
template <class type>
struct hashing {   /// HACELEEE PREPAREEEE!!!
  vii ha;       // ha[i] = t[i]*p0 + t[i+1]*p1 + t[i+2]*p2 + ..
  hashing(type &t): ha(sz(t)+1, ZERO){
    for(int i = sz(t) - 1; i >= 0; --i) ha[i] = ha[i+1] * BASE + ii{t[i], t[i]};
  }
  ii query(int l, int r){ return ha[l] - ha[r+1] * base[r-l+1]; } //[l,r]
};
void show(vi a){
    for(int x: a)cout<<x<<" ";cout<<el;
}
void sol(){
    prepare();
    string s;
    cin>>s;
    int m = sz(s);
    int n;
    cin>>n;
    vector<string> pat;
    vi tam;
    vector<vector<ii>> hashings(m);
    forn(i,n){
        string p;
        cin>>p;
        if(p.size() < m)
            tam.pb(p.size());
        hashing<string> hs(p);
        if(p.size() < m)
            hashings[p.size()].pb(hs.query(0, p.size()-1));
    }
    sort(all(tam));
    tam.erase(unique(all(tam)), tam.end());
    vector<vi> frec(m);
    forn(k, sz(tam)){
        int x = tam[k];
        sort(all(hashings[x]));
        ii prev = {-1,-1};
        int frecAnt= 0;
        forn(i,sz(hashings[x])){
            ii cur = hashings[x][i];
            if(cur == prev){
                ++frec[x].back();
            }else {frec[x].pb(1);}
            prev = cur;
        }
        hashings[x].erase(unique(all(hashings[x])), hashings[x].end());
    }
    
    // show(tam);
    vi cnt(m);
    ll ans = 0;
    hashing <string> str(s);
    forn(i,m){
        ll llegan = i > 0 ? cnt[i-1] : 0;
        for(int x : tam){
            if(i + x-1 >= m)break;
            if(!binary_search(all(hashings[x]), str.query(i, i+x-1)))continue;
            int idx = lower_bound(all(hashings[x]) , str.query(i, i+x-1)) - hashings[x].begin();
            cnt[i+x-1] += frec[x][idx];
            ans += llegan * frec[x][idx];
        }
        // d(ans);
    }
    cout<<ans<<el;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}