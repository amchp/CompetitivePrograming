#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int a, b, l;
        cin >> a >> b >> l;
        vi ftr;
        for(int i = 1; i*i <= l; ++i){
            if(l % i == 0){
                int j = l / i;
                ftr.pb(i);
                if(i != j)ftr.pb(j);
            }
        }
        sort(all(ftr));
        int ans = 0;
        for(int& f : ftr){
            int fo = l / f;
            int ps = false;
            int xa = 1;
            int xb = 1;
            while(xa * xb <= fo){
                while(xa * xb <= fo){
                    if(xa * xb == fo){
                        ps = true;
                        break;
                    }
                    xb *= b;
                }
                if(ps)break;
                xb = 1;
                xa *= a;
            }
            if(ps)++ans;
        }
        assert(ans <= sz(ftr));
        cout << ans << el;
    }
}
