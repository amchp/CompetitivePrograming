#include<bits/stdc++.h>


#define d(x) cerr<<#x<<" "<<x<<el
#define RAYA cerr<<"=========="<<el
#define el '\n'
#define forn(i,n) for(int i = 0; i< (int)n;++i)
#define ford(i,n) for(int i = n-1; i>=0;--i)
#define for1(i,n) for(int i = 1; i<= (int)n;++i)
#define fore(i,l,r)for(int i = l; i<= r; ++i)
#define fored(i,l, r) for(int i = r; i>= (int) l;--i)
#define all(a) a.begin(), a.end()
#define fi first
#define sz(a) (int)a.size()
#define se second
#define pb push_back
using namespace std;

typedef long double ld;
typedef vector<int> vi;
typedef long long ll;
typedef array<int, 2> v2;
typedef pair<ld, ld> pld;

typedef pair<int,int> ii;
typedef vector<ii>  vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tuple<ll, int ,int> iii;



int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

const ld inf = 2e20;
const ld eps = 1e-12;
struct pt{
    ld x,y;
    pt(int x, int y): x(x), y(y){}
    pt(ld x, ld y): x(x), y(y){}
    pt(){}
    pt operator+(pt p){return pt(x+p.x, y+p.y);}
    ld operator*(pt p){return p.x*x + p.y*y;}
    ld norm2(){return *this**this;}
    ld norm(){return sqrt(norm2());}
    pt operator-(pt p){return pt(x-p.x, y-p.y);}
    ld operator%(pt p){return x * p.y - p.x * y;}
    pt operator/(ld t){ return pt(x/t, y/t); }

    ld side(pt p, pt q){ return (q-p) % (*this-p); }// C is: >0 L, ==0 on AB, <0 R
	bool left(pt p, pt q){ // Left of directed line PQ? (eps == 0 if integer)
		return side(p, q) > eps; 
    } // (change to >= -eps to accept collinear)
};
typedef array<pt, 4> pt4;
typedef array<pt, 3> pt3;
typedef array<pt, 2> ppt;
using Func = pt(*)(pt, pt, ld);

pt seg(pt p1, pt p2, ld lambda){
    return {lambda * (p2.x - p1.x) + p1.x, lambda * (p2.y - p1.y) + p1.y};
}

pt circ(pt r, pt p, ld lambda){
    return pt{p.x + r.x*cos(lambda), p.y + r.x*sin(lambda)};
}

// void print_ppt(ppt param){
//     auto [p1, p2] = param;
//     cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << el;
// }

// void print_ppt2(ppt params[2]){
//     print_ppt(params[0]);
//     print_ppt(params[1]);
//     cout << el;
// }

ld ternary2(pt p, ld L, ld R, ppt params, Func func);
ld ternary1(ld L[2], ld R[2], ppt params[2], Func func[2]){
    // cout << L[0] << ' ' << R[0] << ' ' << L[1] << ' ' << R[1] << el;
    // print_ppt2(params);
    
    ld lo = L[0], hi = R[0];
    auto [param1, param2] = params[0];
    while(hi - lo > eps){
        ld m1 = lo + (hi - lo) * 3/7;
        ld m2 = hi - (hi - lo) * 3/7;
        pt p1 = func[0](param1, param2, m1);
        pt p2 = func[0](param1, param2, m2);
        if(ternary2(p1, L[1], R[1], params[1], func[1]) < ternary2(p2, L[1], R[1], params[1], func[1])) hi = m2;
        else lo = m1;
    }
    pt p1 = func[0](param1,param2, lo);
    return sqrt(ternary2(p1, L[1], R[1], params[1], func[1]));
}

ld f(pt p1, pt p2){
    return (p2-p1).norm2();
}

ld ternary2(pt p, ld L, ld R, ppt params, Func func){
    ld lo = L, hi = R;
    auto [param1, param2] = params;
    
    while(hi - lo > eps){
        ld m1 = lo + (hi - lo) * 3/7;
        ld m2 = hi - (hi - lo) * 3/7;
        pt p1 = func(param1, param2, m1);
        pt p2 = func(param1, param2, m2);
        if(f(p, p1) < f(p, p2)) hi = m2;
        else lo = m1;
    }
    return f(func(param1, param2, lo), p);
}
struct circle{
    pt r;
    pt p;
    circle(){}
    circle(int x, int y, int r) : p(pt(x, y)),r(pt(r, 0)){}
};

const int nax = 2e6;
// const int nax = 2e3;
const ld pi = acos(-1);
typedef pair<ld, int> pldi;
vector<pldi> g[nax];

ld solve_ternary(vector<pld> b1, vector<pld> b2, vector<ppt> params1, vector<ppt> params2, Func func[2]){
    ld ans = inf;
    assert(sz(b1) == sz(params1));
    assert(sz(b2) == sz(params2));
    forn(i, sz(b1)){
        auto& [l1, r1] = b1[i];
        auto& param1 = params1[i];
        forn(j, sz(b2)){
            auto& [l2, r2] = b2[j];
            auto& param2 = params2[j];
            ppt params[2] = {param1, param2};
            ld L[2] = {l1, l2};
            ld R[2] = {r1, r2};
            ans = min(ans, ternary1(L, R, params, func));
        }
    }
    return ans;
}
int shapeType[nax];
int N;
ld dijkstra(vi& ss){
  vector<ld> dst(N, inf);
  
  priority_queue <pldi, vector <pldi>, greater<pldi> > q;
  for(int& s : ss){
    q.push({0, s});
    dst[s] = 0;
  }
  ld ans = inf;
  while(sz(q)){
    auto [dist, u] = q.top();  q.pop();
    if(dist > dst[u]) continue;
    if(shapeType[u] != 0 && shapeType[u] != shapeType[ss[0]]){ans = min(dist, ans);}
    for(auto& [w, v]: g[u]){
      if (dst[u] + w < dst[v]){
        dst[v] = dst[u] + w;
        q.push(pldi(dst[v], v));
      }
    }
  }
  return ans;
}

vector<ppt> getShapeParams(vector<pt>& shp){
    int szs = sz(shp);
    vector<ppt> params(szs);
    forn(id, szs){
        params[id] = {shp[id], shp[(id+1)%szs]};
    }
    return params;
}

pt rot90cw(pt a) {
  return pt(a.y, -a.x);
};

void solve(){
    int C, Q, T;
    cin>>C>>Q>>T;
    vector<circle> circles(C);
    vector<vector<pt>> squ(Q);
    vector<vi> indices(3);
    vector<vector<pt>> tri(T);
    N = C + Q + T;
    forn(i,C){
        shapeType[i] = 0;
        int x,y,r;
        cin>>x>>y>>r;
        circles[i] = {x,y,r};
        indices[0].pb(i);
    }
    forn(i,Q){
        int x1, y1, x2, y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        pt a = {x1, y1};
        pt c = {x2, y2};
        pt o = (a+c)/2;
        pt b = o + rot90cw((a-c)/2);
        pt d = o - rot90cw((a-c)/2);
        shapeType[i+C] = 1;
        indices[1].pb(i + C);
        squ[i] = {a,b,c,d};
    }
    forn(i,T){
        int x1, y1, x2, y2, x3,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        shapeType[i+C+Q] = 2;
        indices[2].pb(i + C + Q);
        tri[i] = {pt{x1,y1},pt{x2,y2},pt{x3,y3}};
    }
    vector<pld> b1 = {{0, pi}, {pi, 2*pi}};
    vector<pld> b2 = {{0, pi}, {pi, 2*pi}};

    forn(i,C){
        vector<ppt> params1 = vector<ppt>(2,{circles[i].r, circles[i].p});
        forn(j,i){
            Func func[2] = {(Func) circ, (Func) circ};
            ppt params2 = {circles[j].r, circles[j].p};
            ld w = solve_ternary(b1, b2, params1, vector<ppt> (2,params2), func);

            g[indices[0][i]].pb({w, indices[0][j]});
            g[indices[0][j]].pb({w, indices[0][i]});
        }
    }

    b1 = {{0, pi}, {pi, 2*pi}};
    b2 = vector<pld>(4, {0, 1});
    forn(i,C){
        vector<ppt> params1 = vector<ppt>(2,{circles[i].r, circles[i].p});
        forn(j, Q){
            Func func[2] = {(Func) circ, (Func) seg};
            vector<ppt> params2 = getShapeParams(squ[j]);
            ld w = solve_ternary(b1, b2, params1, params2, func);

            g[indices[0][i]].pb({w, indices[1][j]});
            g[indices[1][j]].pb({w, indices[0][i]});
        }
    }

    b1 = {{0, pi}, {pi, 2*pi}};
    b2 = vector<pld> (3, {0,1});
    forn(i,C){
        vector<ppt> params1 = vector<ppt>(2,{circles[i].r, circles[i].p});
        forn(j, T){
            vector<ppt> params2 = getShapeParams(tri[j]);
            Func func[2] = {(Func) circ, (Func) seg};

            ld w = solve_ternary(b1, b2, params1, params2, func);
            assert(w > eps);
            g[indices[0][i]].pb({w, indices[2][j]});
            g[indices[2][j]].pb({w, indices[0][i]});
        }
    }

    b1 = vector<pld> (4, {0,1});
    b2 = vector<pld> (3, {0,1});
    ld ans = inf;
    forn(i, Q){
        vector<ppt> params1 = getShapeParams(squ[i]);
        forn(j,T){
            vector<ppt> params2 = getShapeParams(tri[j]);
            Func func[2] = {(Func) seg, (Func) seg};
            ld w = solve_ternary(b1, b2, params1, params2, func);

            ans = min(ans, w);
        }
    }

    if(T < Q){
        b1 = vector<pld> (3, {0,1});
        b2 = vector<pld> (3, {0,1});
        forn(i, T){
            vector<ppt> params1 = getShapeParams(tri[i]);
            forn(j,i){
                if(i == j)continue;
                vector<ppt> params2 = getShapeParams(tri[j]);
                Func func[2] = {(Func) seg, (Func) seg};
                ld w = solve_ternary(b1, b2, params1, params2, func);

                g[indices[2][i]].pb({w, indices[2][j]});
                g[indices[2][j]].pb({w, indices[2][i]});
            }
        }
    }else{
        b1 = vector<pld> (4, {0,1});
        b2 = vector<pld> (4, {0,1});
        forn(i, Q){
            vector<ppt> params1 = getShapeParams(squ[i]);
            forn(j,i){
                vector<ppt> params2 = getShapeParams(squ[j]);
                Func func[2] = {(Func) seg, (Func) seg};
                ld w = solve_ternary(b1, b2, params1, params2, func);

                g[indices[1][i]].pb({w, indices[1][j]});
                g[indices[1][j]].pb({w, indices[1][i]});
            }
        }
    }


    ans = min(ans, dijkstra(indices[1 + (T < Q)]));
    assert(ans < inf);
    cout<<ans<<el;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.precision(20);
  int tt = 1;
//   cin>>tt;
  while(tt--){solve();}
    return 0;
}