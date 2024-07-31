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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int MOD[] = { 1001864327, 1001265673 }, N = 3e5 + 100;
const ii BASE(2, 2), ZERO(0, 0), ONE(1, 1);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    prepare();
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        forn(i, n){
            forn(j, m){
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        int ans = -1;
        string mvs = "";
        map<ii, int> mp;
        forn(j, m){
            string cur = "";
            ii hs = {0, 0};
            if(a[0][j] == 1)cur.pb('0');
            else{
                hs = hs + base[0];
                cur.pb('1');
            }
            for1(i, n - 1){
                if(a[i][j] == 0)cur.pb('0');
                else{
                    hs = hs + base[i];
                    cur.pb('1');
                }
            }
            // db(hs.fi);
            // db(hs.se);
            ++mp[hs];
            if(ans < mp[hs]){
                ans = mp[hs];
                mvs = cur;
            }
            for1(i, n - 1){
                if(cur[i - 1] == '1'){
                    cur[i - 1] = '0';
                    hs = hs - base[i - 1];
                }else{
                    cur[i - 1] = '1';
                    hs = hs + base[i - 1];
                }
                if(cur[i] == '0'){
                    cur[i] = '1';
                    hs = hs + base[i];
                }else{
                    cur[i] = '0';
                    hs = hs - base[i];
                }
                
                // db(hs.fi);
                // db(hs.se);
                ++mp[hs];
                if(ans < mp[hs]){
                    ans = mp[hs];
                    mvs = cur;
                }
            }
        }
        cout << ans << el;
        cout << mvs << el;
    }
}