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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        // d(n);
        // d(x);
        vi a(n + 1);
        vi p(n + 1);
        for1(i, n){
            cin >> p[i];
            a[p[i]] = i;
        }
        if(x == 1){
            if(a[x] == 1){
                cout << 0 << el;
                continue;
            }
            cout << 1 << el;
            cout << 1 << ' ' << a[x] << el;
            swap(p[1], p[a[x]]);
            int l = 1;
            int r = n + 1;
            while(l + 1 < r){
                int m = (l + r) / 2;
                if(p[m] <= x)l = m;
                else r = m;
            }
            assert(p[l] == x);
            continue;
        }
        vector<ii> ans;
        int l = 1;
        int r = n + 1;
        while(l + 1 < r){
            int m = (l + r) / 2;
            if(p[m] <= x)l = m;
            else r = m;
        }
        if(p[l] == x){
            cout << 0 << el;
            continue;
        }
        cout << 1 << el;
        cout << l << ' ' << a[x] << el;
        swap(p[l], p[a[x]]);
        l = 1;
        r = n + 1;
        while(l + 1 < r){
            int m = (l + r) / 2;
            if(p[m] <= x)l = m;
            else r = m;
        }
        assert(p[l] == x);
    }
}