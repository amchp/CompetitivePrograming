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

const int inf = 1e9 + 10;
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
        int n;
        cin >> n;
        vector<ii> ab(n);
        map<int, int> bi;
        set<int> bc;
        forn(i, n){
            cin >> ab[i].first >> ab[i].second;
            bi[ab[i].second]++;
        }
        sort(all(ab));
        int ans = inf;
        for(auto &[a, b] : ab){
            bi[b]--;
            if(bi[b] == 0)bi.erase(b);
            int mb = -1;
            if(bi.size() != 0){
                mb = (*bi.rbegin()).first;
                ans = min(ans, abs(a - mb));
            }
            auto it = bc.upper_bound(a);
            if(it != bc.begin()){
                it--;
                if(mb < (*it)){
                    ans = min(ans, abs(a - (*it)));
                }
            }
            auto it2 = bc.lower_bound(a);
            if(it2 != bc.end() && mb < (*it2)){
                ans = min(ans, abs(a - (*it2)));
            }
            bc.insert(b);
        }
        cout << ans << el;
    }
}
