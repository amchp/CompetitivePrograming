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

vi twrs[3];
map<int, ii> lct;
vector<ii> ans;

void mv(int st, int dst){
    assert(sz(twrs[st]));
    int val = twrs[st].back();
    if(dst > 0){
        assert(!sz(twrs[dst]) || twrs[dst].back() > val);
    }
    twrs[st].pop_back();
    lct[val] = {dst, sz(twrs[dst])};
    twrs[dst].pb(val);
    ans.pb({st, dst});
}

void clear(int val, int dst){
    if(sz(twrs[dst]) == 0 || twrs[dst].back() > val)return;
    int op = dst == 1 ? 2 : 1;
    int cnt = 0;
    while(sz(twrs[dst]) > 1 && twrs[dst][sz(twrs[dst]) - 2] < val){
        while(sz(twrs[op]) && twrs[dst].back() > twrs[op].back()){
            ++cnt;
            mv(op, 0);
        }
        ++cnt;
        mv(dst, 0);
    }
    while(sz(twrs[op]) && twrs[dst].back() > twrs[op].back()){
        ++cnt;
        mv(op, 0);
    }
    mv(dst, op);
    forn(i, cnt){
        mv(0, op);
    }
}

int getmx(int twr, int st){
    int mx = 0;
    fore(i, st, sz(twrs[twr]) - 1){
        mx = max(mx, twrs[twr][i]);
    }
    return mx;
}

void sol(int val, int dst){
    auto [twr, ind] = lct[val];
    if(twr == 0){
        while(ind < sz(twrs[twr]) - 1){
            int mx = getmx(twr, ind + 1);
            int op = dst == 1 ? 2 : 1;
            sol(mx, op);
        }
        clear(val, dst);
        mv(twr, dst);
        return;
    }
    if(twr == 1){
        assert(dst == 2);
        while(ind != sz(twrs[twr]) - 1){
            mv(1, 0);
        }
        mv(twr, dst);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    forn(_, n){
        int v;
        cin >> v;
        lct[v] = {0, sz(twrs[0])};
        twrs[0].pb(v);
    }
    fored(i, 1, n){
        sol(i, 2);
    }
    assert(sz(ans) <= 2*n*n);
    cout << sz(ans) << el;
    for(auto& [st, ed] : ans){
        cout << st + 1 << ' ' << ed + 1 << el;
    }
}