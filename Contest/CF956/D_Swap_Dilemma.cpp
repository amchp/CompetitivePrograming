#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

bool sol(){
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, vi> mpa, mpb;
    forn(i, n){
        cin >> a[i];
        mpa[a[i]].pb(i);
    }
    forn(i, n){
        cin >> b[i];
        mpb[b[i]].pb(i);
    }
    vi sa = a, sb = b;
    sort(all(sa));
    sort(all(sb));
    if(sa != sb)return false;
    ll mva = 0;
    ordered_set osa, osb;
    ford(i, n){
        int ind = mpa[sa[i]].back();
        mpa[sa[i]].pop_back();
        int cind = ind - osa.order_of_key(ind);
        assert(cind <= i);
        mva += i - cind;
        osa.insert(ind);
    }
    ll mvb = 0;
    
    ford(i, n){
        int ind = mpb[sb[i]].back();
        mpb[sb[i]].pop_back();
        int cind = ind - osb.order_of_key(ind);
        assert(cind <= i);
        mvb += i - cind;
        osb.insert(ind);
    }
    // db(mva);
    // db(mvb);
    return mva % 2 == mvb % 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "YES" << el;
        else cout << "NO" << el;
    }
}