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
#define db(x) cout<< #x<< " " << x<<el
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

int sol(){
    int n;
    cin >> n;
    vi a(n);
    int sm = 0;
    int mx = 0;
    forn(i, n){
        cin >> a[i];
        sm += a[i];
        mx = max(mx, a[i]);
    }
    vi divs;
    for(int i = 1; i*i <= sm; ++i){
        if(sm % i == 0){
            int j = sm / i;
            divs.pb(i);
            if(i != j)divs.pb(j);
        }
    }
    sort(all(divs));
    reverse(all(divs));
    auto check = [&](int div){
        int trg = sm / div;
        // db(trg);
        if(trg < mx)return false;
        int cur = 0;
        forn(i, n){
            cur += a[i];
            if(cur > trg)return false;
            if(cur == trg)cur = 0;
        }
        if(cur != 0)return false;
        return true;
    };
    for(int& div : divs){
        if(check(div)){
            // db(div);
            return n - div;
        }
    }
    return n - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cout << sol() << el;
    }
}