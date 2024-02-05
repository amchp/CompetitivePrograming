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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set; 
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
        int n;
        cin >> n;
        vector<vi> events(2*n, vi(3));
        vi a(n);
        vi b(n);
        forn(i, n){
            cin >> events[2*i][0];
            cin >> events[2*i+1][0];
            events[2*i][1] = 0;
            events[2*i + 1][1] = 1;
            events[2*i][2] = i;
            events[2*i + 1][2] = i;
            a[i] = events[2*i][0];
            b[i] = events[2*i+1][0];;
        }
        sort(all(events));
        ordered_set os;
        ll ans = 0;
        for(vi& vec : events){
            int v = vec[0], e = vec[1], i = vec[2];
            if(e == 0){
                os.insert(v);
            }else{
                ans += os.order_of_key(a[i]);
                os.erase(a[i]);
            }
        }
        cout << ans << el;
    }
}
