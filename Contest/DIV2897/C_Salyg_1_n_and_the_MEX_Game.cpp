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
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<ii> nS;
        int prv, cur;
        cin >> prv;
        if(prv != 0){
            nS.insert({0, prv - 1});
        }
        forn(i, n - 1){
            cin >> cur;
            if(cur - prv != 1){
                nS.insert({prv + 1, cur - 1});
            }
            prv = cur;
        }
        if(prv != (int)1e9){
            nS.insert({prv + 1, 1e9});
        }
        int res;
        do{
            set<ii>::iterator it = nS.begin();
            int first = (*it).first;
            int second = (*it).second;
            cout << first << endl;
            nS.erase(it);
            if(first != second){
                nS.insert({first + 1, second});
            }
            cin >> res;
            if(res < 0)break;
            nS.insert({res, res});
        }while(res > -1);
    }
}
