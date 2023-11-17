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

set<ii> s;
void remove_from_set(int v){
    auto it = s.upper_bound({v,inf});
    if(it == s.begin())return;
    it--;
    if((*it).second >= v){
        int first = (*it).first;
        int second = (*it).second;
        s.erase(it);
        if(first <= v - 1)s.insert(ii{first, v - 1});
        if(v + 1 <= second)s.insert(ii{v + 1, second});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        vi a(n);
        s.clear();
        s.insert(ii{0, p -1});
        forn(i, n){
            int v;
            cin >> v;
            a[i] = v;
            remove_from_set(v);
        }
        // for(ii pr : s){
        //     cout << pr.first << ' ' << pr.second << el;
        // }
        auto it = s.upper_bound({a.back(), inf});
        int ans;
        if(it == s.begin()){
            if(it == s.end())ans = 0;
            else{
                auto rt = s.rbegin();
                ans = (*rt).second - a.back();
            }
        }else{
            ans = p - a.back();
            int i = n - 2;
            while(i >= 0 && a[i] == p - 1){
                remove_from_set(0);
                i--;
            }
            if(i >= 0)remove_from_set(a[i] + 1);
            else remove_from_set(1);
            it = s.upper_bound({a.back() - 1, inf});
            if(it != s.begin()){
                it--;
                ans += (*it).second;
            }
        }
        cout << ans << el;
    }
}
