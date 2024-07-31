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

const static int N = 2e6, alpha = 26, B = 30; // MAX: abecedario, bits
int to[N][alpha], cnt[N], sz;
inline int conv(char ch){ return ch - 'a'; }  //  CAMBIAR
string to_bin(int num, int bits){  // B: Max(bits),  bits: size 
  return bitset<B>(num).to_string().substr(B - bits);}
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    init();
    int n;
    cin >> n;
    forn(i, n){
        string s;
        cin >> s;
        add(s);
    }
    ll ans = 0;
    forn(i, N){
        int& v = cnt[i];
        ans += 1LL*v*(v - 1) / 2;
    }
    cout << ans << el;
}