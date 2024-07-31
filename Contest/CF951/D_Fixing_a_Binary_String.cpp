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


int n, k;
vi a;

void print(vi& x){
    for(int& v : x)cout << v << ' ';
    cout << el;
}

int check(vi& xa){
    for1(i, n - 1){
        if(i % k == 0){
            if(xa[i] == xa[i - 1])return i - 1;
        }else{
            if(xa[i] != xa[i - 1]){

                
            }
        }
    }
    return n;
}

int sol(int x){
    if(x == n)return n;
    vi tmp = vi(n);
    forn(i, n - 1 - x){
        tmp[i] = a[i + x + 1];
    }
    forn(i, x + 1){
        tmp[i + (n - 1 - x)] = a[i];
    }
    // reverse(tmp.begin() + (n - 1 - x), tmp.end());
    // print(tmp);
    int ans = check(tmp);
    // db(ans);
    if(ans == n)return x + 1;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20) << fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a = vi(n);
        forn(i, n){
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        int lst = 0;
        fored(i, n - k - 1, n - 1){

        }
        // print(a);
        int chk = check(a);
        // db(chk);
        cout << sol(chk) << el;
    }
}