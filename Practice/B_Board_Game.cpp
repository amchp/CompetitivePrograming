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
typedef pair<ll,ll> ii;
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

typedef ll T;
const T is_query=-(1LL<<62);
struct line {
	T m,b;
	mutable multiset<line>::iterator it,end;
	const line *succ(multiset<line>::iterator it)const {
		return (++it == end ? nullptr : &*it);
	}
	bool operator < (const line &rhs) const {
		if(rhs.b!=is_query) return m < rhs.m;
		const line *s = succ(it);
		if(!s) return 0;
		return b-s->b < (ld)(s->m-m)*rhs.m;
	}
};
struct CHT : public multiset<line> {
	bool bad(iterator y) {
		iterator z = next(y);
		if(y==begin()) {
			if(z==end())return false;
			return y->m == z->m && y->b <= z->b;
		}
		iterator x = prev(y);
		if(z == end()) return y->m==x->m&&y->b==x->b;
		return (ld)(x->b-y->b)*(z->m-y->m)>=(ld)(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(T m, T b) {
		iterator y = insert((line){m,b});
		y->it = y; y->end = end();
		if(bad(y)){ erase(y); return; }
		while(next(y)!=end() && bad(next(y))) erase(next(y));
		while(y!=begin() && bad(prev(y)))erase(prev(y));
	}
	T eval(T x) { /// max
		line l = *lower_bound((line){x,is_query});
		return l.m*x+l.b;
	}
};

struct pt{
	ll x, y;
	int ind;
	pt(){}
	pt(ll x, ll y, int ind): x(x), y(y), ind(ind){}
};

struct node{
	int l, r, m;
	vector<pt> vec;
	node() {}
	node(int l, int r): l(l), r(r){
		m = l + (r - l) / 2;
		vec = vector<pt>();
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vector<pt> pts(n);
    forn(i, n){
		cin >> pts[i].x >> pts[i].y;
		// cout << pts[i].x << ' ' << pts[i].y << el;
		pts[i].ind = i;
	}
    int m;
    cin >> m;
    vector<line> lines(m);
    forn(i, m){
        cin >> lines[i].m >> lines[i].b;
		// cout << lines[i].m << ' ' << lines[i].b << el;
    }
	vector<node> prv;
	prv.pb(node(0, m + 1));
	forn(i, n)prv.back().vec.pb(pts[i]);
	vector<node> cur;
	vector<vector<pt>> ans(m + 1);
	CHT cht = CHT();
    while(sz(prv)){
		// d(sz(prv));
		int ind = 0;
		node& cn = prv[ind];
        forn(i, m + 1){
			if(i == cn.m){
				// d(i);
				// d(cn.l);
				// d(cn.m);
				// d(cn.r);
				int pl = -1;
				if(cn.l + 1 < cn.m){
					pl = sz(cur);
					cur.pb(node(cn.l, cn.m));
				}
				int pr = -1;
				if(cn.m + 1 < cn.r){
					pr = sz(cur);
					cur.pb(node(cn.m, cn.r));
				}
				for(pt& p : cn.vec){
					if(p.y < cht.eval(p.x)){
						if(cn.l + 1 < cn.m)cur[pl].vec.pb(p);
						else ans[cn.l].pb(p);
					}else{
						if(cn.m + 1 < cn.r)cur[pr].vec.pb(p);
						else ans[cn.m].pb(p);
					}
				}
				++ind;
				if(ind == sz(prv))break;
				cn = prv[ind];
			}
			if(i < m){
				// d(lines[i].m);
				// d(lines[i].b);
				cht.add(lines[i].m, lines[i].b);
			}
		}
		swap(prv, cur);
		cur.clear();
		cht.clear();
    }
	forn(i, m){
		cout << sz(ans[i]) << ' ';
		for(pt& p : ans[i])cout << p.ind + 1 << ' ';
		cout << el;
	}
}