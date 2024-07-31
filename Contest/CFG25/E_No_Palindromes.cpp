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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MOD[] = { 1001864327, 1001265673 }, N = 1e6 + 100;
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
  hashing(){}
  hashing(type &t): ha(sz(t)+1, ZERO){
    for(int i = sz(t) - 1; i >= 0; --i) ha[i] = ha[i+1] * BASE + ii{t[i], t[i]};
  }
  ii query(int l, int r){ return ha[l] - ha[r+1] * base[r-l+1]; } //[l,r]
};

int n;
string s;
hashing<string> hs, rhs;

bool check_palindrome(int l, int r){
    int szs = r - l + 1;
    int ml = l + ((szs - 1) / 2);
    int mr = ml + !(szs&1);
    return hs.query(l, ml) == rhs.query(n - 1 - r, n - 1 - mr);
}

int sol(){
    for1(i, n - 2){
        if(!check_palindrome(0, i) && !check_palindrome(i + 1, n - 1)){
            return i;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    prepare();
    while(t--){
        cin >> s;
        n = sz(s);
        hs = hashing<string>(s);
        reverse(all(s));
        rhs = hashing<string>(s);
        reverse(all(s));
        if(!check_palindrome(0, n - 1)){
            cout << "YES" << el;
            cout << 1 << el;
            cout << s << el;
            continue;
        }
        int ans = sol();
        if(ans == -1){
            cout << "NO" << el;
            continue;
        }
        cout << "YES" << el;
        cout << 2 << el;
        cout << s.substr(0, ans + 1) << ' ' << s.substr(ans + 1) << el;
    }
}