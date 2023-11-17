#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define forn(i, n) for(int i=0; i< (int)n; ++i)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define el '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;

const double EPS=1e-6;

struct pt {  // for 3D add z coordinate
	double x,y;int id;
	pt(double x, double y, int id=-1):x(x),y(y),id(id){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(t*x,t*y);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;} // 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};

vector<pt> chull(vector<pt> p){
	if(sz(p)<3)return p;
	vector<pt> r;
	sort(all(p)); // first x, then y
	forn(i,sz(p)){ // lower hull
		while(sz(r) >=2 && r.back().left(r[sz(r)-2], p[i]))
      r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k = sz(r);
	for(int i = sz(p)-1 ; i>=0 ; --i){ // upper hull
		while(sz(r) >= k+2 && r.back().left(r[sz(r)-2], p[i]))
      r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pt> p(n);
    forn(i, n)
    {
        ll x, y;
        cin >> x >> y;
		p[i] = pt(x, y, i + 1);
    }
    vector<pt> ch = chull(p);
    vi ans;
    for (pt &a : ch)
    {
        ans.pb(a.id);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()),ans.end());
    for (int i : ans)
        cout << i << " ";
    cout << el;
}