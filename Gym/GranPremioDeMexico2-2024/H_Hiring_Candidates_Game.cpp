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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, r, c;
    cin >> n >> r >> c;
    vi a(n);
    forn(i, n){
        a[i] = i + 1;
    }
    int s1 = 0, s2 = n - 1;
    vi ans;
    while(sz(a) > 2){
        // db(sz(a));
        // db(s1);
        // db(s2);
        int ns1 = (s1 + (r - 1)) % sz(a);
        int ns2 = ((s2 - (c - 1)) % sz(a) + sz(a)) % sz(a);
        // db(ns1);
        // db(ns2);
        if(ns1 == ns2){
            ans.pb(a[ns1]);
            a.erase(a.begin() + ns1);
            s1 = ns1;
            s2 = ((ns2 - 1) % sz(a) + sz(a)) % sz(a);
        }else{
            if(ns1 > ns2){
                a.erase(a.begin() + ns1);
                a.erase(a.begin() + ns2);
                --ns1;
            }else{
                a.erase(a.begin() + ns2);
                a.erase(a.begin() + ns1);
                --ns2;
            }
            --ns2;
            ns1 = (ns1 % sz(a) + sz(a)) % sz(a);
            ns2 = (ns2 % sz(a) + sz(a)) % sz(a);
            s1 = ns1;
            s2 = ns2;
        }
    }
    for(int& v : a){
        ans.pb(v);
    }
    sort(all(ans));
    for(int& v : ans)cout << v << ' ';
    cout << el;
}