#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r)for(int i = l; i <= (int)r; ++i)
#define fored(i, l, r)for(int i = r; i >= (int)l; --i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef array<int, 4> a4;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
const ll INF=1e18;//for maximum set INF to 0, and negate costs
bool zero(ll x){return x == 0;}//change to x==0, for ints/ll
struct Hungarian{
    int n; vector<vll> cs; vi L, R;
    Hungarian(int N, int M):n(max(N,M)),cs(n,vll(n)),L(n),R(n){
        forn(x,N)forn(y,M)cs[x][y]=INF;
    }
    void set(int x,int y,ll c){cs[x][y]=c;}
	ll assign() {
		int mat = 0; vll ds(n), u(n), v(n); vi dad(n), sn(n);
		forn(i,n)u[i]=*min_element(all(cs[i]));
		forn(j,n){v[j]=cs[0][j]-u[0];for1(i,n - 1)v[j]=min(v[j],cs[i][j]-u[i]);}
		L=R=vi(n, -1);
		forn(i,n)forn(j,n)
			if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		for(;mat<n;mat++){
		    int s=0, j=0, i;
		    while(L[s] != -1)s++;
		    fill(all(dad),-1);fill(all(sn),0);
		    forn(k,n)ds[k]=cs[s][k]-u[s]-v[k];
		    for(;;){
		        j = -1;
		        forn(k,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
		        sn[j] = 1; i = R[j];
		        if(i == -1) break;
		        forn(k,n)if(!sn[k]){
		            auto new_ds=ds[j]+cs[i][k]-u[i]-v[k];
		            if(ds[k] > new_ds){ds[k]=new_ds;dad[k]=j;}
		        }
		    }
		    forn(k,n)if(k!=j&&sn[k]){auto w=ds[k]-ds[j];v[k]+=w,u[R[k]]-=w;}
		    u[s] += ds[j];
		    while(dad[j]>=0){int d = dad[j];R[j]=R[d];L[R[j]]=j;j=d;}
		    R[j]=s;L[s]=j;
		}
		ll value=0;forn(i,n)value+=cs[i][L[i]];
		return value;
	}
};

struct pt{
    int x, y;
    pt(){}
    pt(int x, int y): x(x), y(y){}
    ll dst(pt p){return abs(x - p.x) + abs(y - p.y); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(21);
    int n, m;
    cin >> m >> n;
    vector<pt> crs(n), wn(m);
    forn(j, m)cin >> wn[j].x >> wn[j].y;
    forn(i, n)cin >> crs[i].x >> crs[i].y;
    pt rst = pt();
    cin >> rst.x >> rst.y;
    int N = n + m - 1;
    int M = m;
    Hungarian hug = Hungarian(N, M);

    forn(i, n){
        forn(j, m){
            hug.set(i, j, crs[i].dst(wn[j]));
        }
    }
    ll ans = 0;
    forn(j, m){
        ans += rst.dst(wn[j]);
    }
    forn(i, m - 1){
        forn(j, m){
            hug.set(i + n, j, rst.dst(wn[j]));
        }
    }
    ans += hug.assign();
    cout << ans << el;
}