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
#define db(x) cerr<< #x<< " " << x<<el
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

struct checkpoint{
    map<int, int> hero, rd;
    checkpoint(){}
    checkpoint(int n){
        forn(i, n){
            hero[i] = i;
            rd[i] = i;
        }
    }
    void change(int u, int v){
        int ru = hero[u], rv = hero[v];
        // db(ru);
        // db(rv);
        swap(rd[ru], rd[rv]);
        swap(hero[u], hero[v]);
    }
    int hquery(int u){
        return hero[u];
    }
    int rquery(int u){
        return rd[u];
    }
};

struct road{
    set<int> abrgd, bbrgd;
    road(){}
    int brglst(int x, set<int>& brgd){
        auto it = brgd.lower_bound(x);
        if(it == brgd.begin())return -1;
        --it;
        return (*it);
    }
    ii lst(int ind){
        int lsta = brglst(ind, abrgd);
        int lstb = brglst(ind, bbrgd);
        return {lsta, lstb};
    }
    void aadd(int b){
        abrgd.insert(b);
    }
    void badd(int b){
        bbrgd.insert(b);
    }
};

vi idxs;
vector<checkpoint> checkpoints;
vector<road> roads;

int check_road(int a, int st){
    int cura = a;
    int curb = st;
    int lstchk = upper_bound(all(idxs), st) - idxs.begin() - 1;
    int val = idxs[lstchk];
    assert(val <= st);
    while(curb != val){
        ii lst = roads[cura].lst(curb);
        int mxlst = max(lst.fi, lst.se);
        if(mxlst < val){
            curb = val;
            continue;
        }
        if(lst.fi < lst.se){
            curb = lst.se;
            ++cura;
        }else{
            curb = lst.fi;
            --cura;
        }
    }
    return checkpoints[lstchk].rquery(cura);
}

void change(int a, int b){
    int ha = check_road(a, b);
    int ha1 = check_road(a + 1, b);
    int nxtchk = lower_bound(all(idxs), b) - idxs.begin();
    // db(ha);
    // db(ha1);
    // db(nxtchk);
    fore(i, nxtchk, sz(idxs) - 1){
        // db(i);
        checkpoints[i].change(ha, ha1);
    }
    roads[a].badd(b);
    roads[a + 1].aadd(a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m, q;
    cin >> n >> m >> q;
    int sq = sqrt(m);
    roads.resize(n);
    for(int i = 0; i < m; i += sq){
        idxs.pb(i);
        checkpoints.pb(checkpoint(n));
    }
    idxs.pb(m);
    checkpoints.pb(checkpoint(n));
    // db(sz(idxs));
    // db(sz(checkpoints));
    forn(_, q){
        int op, a;
        cin >> op >> a;
        --a;
        if(op == 1){
            int b;
            cin >> b;
            --b;
            change(a, b);
        }else{
            cout << checkpoints.back().hquery(a) + 1 << el;
        }
    }
}