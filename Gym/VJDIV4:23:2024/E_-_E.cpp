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

bool sol(){
    int n;
    cin >> n;
    vector<ii> a(n);
    forn(i, n){
        int u, v;
        cin >> u >> v;
        --u, --v;
        a[i] = {min(u, v), max(u, v)};
    }
    int N = 2*n;
    vector<ii> ops(2*N, {-1, -1});
    forn(i, n){
        auto& [u, v] = a[i];
        int d1 = v - u;
        int d2 = u + (N - v);
        if(d1 <= d2){
            ops[u].fi = 0;
            ops[u].se = i;
            ops[v].fi = 1;
            ops[v].se = i;
            ops[u + N].fi = 0;
            ops[u + N].se = i;
            ops[v + N].fi = 1;
            ops[v + N].se = i;
        }else{
            ops[v].fi = 0;
            ops[v].se = i;
            ops[u + N].fi = 1;
            ops[u + N].se = i;
        }
    }
    stack<int> st;
    forn(i, 2*N){
        auto& [op, idx] = ops[i];
        if(op == -1)continue;
        if(op == 0)st.push(idx);
        if(op == 1){
            if(st.top() != idx)return true;
            st.pop();
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    if(sol())cout << "Yes" << el;
    else cout << "No" << el; 
}