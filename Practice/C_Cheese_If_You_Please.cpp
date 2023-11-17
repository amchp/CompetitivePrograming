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
#define sz(v) ((int)v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;
void pivot(int x,int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	forn(i,m)if(i!=y)A[x][i]/=A[x][y];
	A[x][y]=1/A[x][y];
	forn(i,n)if(i!=x&&abs(A[i][y])>eps){
		b[i]-=A[i][y]*b[x];
		forn(j,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	forn(i,m)if(i!=y)c[i]-=c[y]*A[x][i];
	c[y]=-c[y]*A[x][y];
}
double simplex( // maximize c^T x s.t. Ax<=b, x>=0
		vector<vector<double> > _A, vector<double> _b, vector<double> _c){
	// returns pair (maximum value, solution vector)
	A=_A;b=_b;c=_c;
	n=sz(b);m=sz(c);z=0.;
	X=vector<int>(m);Y=vector<int>(n);
	forn(i,m)X[i]=i;
	forn(i,n)Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		double mn=-eps;
		forn(i,n)if(b[i]<mn)mn=b[i],x=i;
		if(x<0)break;
		forn(i,m)if(A[x][i]<-eps){y=i;break;}
		assert(y>=0); // no solution to Ax<=b
		pivot(x,y);
	}
	while(1){
		double mx=eps;
		int x=-1,y=-1;
		forn(i,m)if(c[i]>mx)mx=c[i],y=i;
		if(y<0)break;
		double mn=1e200;
		forn(i,n)if(A[i][y]>eps&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
		assert(x>=0); // c^T x is unbounded
		pivot(x,y);
	}
	// vector<double> r(m);
	// forn(i,n)if(Y[i]<m)r[Y[i]]=b[i];
	return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> m;
    // cout << n << ' ' << m << el;
    vector<double> b(n); 
    forn(i, n){
        int v;
        cin >> v;
        b[i] = v;
    }
    vector<double> c(m);
    vector<vector<double>> A(n, vector<double>(m));
    forn(i, m){
        forn(j, n){
            cin >> A[j][i];
            A[j][i] /= 100.0;
        }
        cin >> c[i];
    }
    double ans = simplex(A, b, c);
    cout << round(ans*100) / 100.0 << el;
}
