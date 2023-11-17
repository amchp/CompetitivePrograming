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

ll sol(int num, int dem){
    if(num == 0)return 0;
    if(num == 1){
        return (1LL << ((int)log2(dem))) - 1; 
    }
    if(num & 1 == 0){
        return 2LL*sol(num / 2, dem);
    }
    return sol(1, dem) + 2LL*sol(num / 2, dem / 2);
}

int a, b;

ll sol2(int num){
    if(num == 0)return 0;
    if(num < b){
        return sol2(2*num)+num;
    }
    return sol2(num % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int gcd = __gcd(a, b);
        int gb = b / gcd;
        if(log2(gb) != (int)log2(gb)){
            cout << -1 << el;
            continue;
        }
        a %= b;
        cout << sol2(a) << el;
    }
}
