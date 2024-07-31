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
const int nax = 2000+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int p[nax];
int szs[nax];

int find(int x){
    return p[x] =  x == p[x] ? x : find(p[x]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(szs[u] < szs[v])swap(u, v);
    szs[u] += szs[v];
    p[v] = u;
}

void sol(){
    int n;
    cin >> n;
    vi a(n);
    forn(i, n){
        p[i] = i;
        szs[i] = 1;
        cin >> a[i];
    }
    vector<vector<vi>> bkt(n - 1);
    forn(i, n - 1){
        int div = i + 1;
        bkt[i] = vector<vi>(div);
        forn(j, n){
            bkt[i][a[j] % div].pb(j);
        }
    }
    ford(i, n - 1){
        int div = i + 1;
        int cu = -1, cv = -1;
        vi 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}