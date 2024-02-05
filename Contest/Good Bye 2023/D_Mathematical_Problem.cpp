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
    vector<vector<string>> ans(50);
    ans[0] = {"1"};
    ans[1] = {"169", "196", "961"};
    for(int i = 5; i <= 99; i += 2){
        int ind = i / 2;
        ans[ind] = ans[ind - 1];
        for(string& s : ans[ind]){
            s.pb('0');
            s.pb('0');
        }
        ans[ind].pb("1");
        forn(j, ind - 1)ans[ind].back().pb('0');
        ans[ind].back().pb('6');
        forn(j, ind - 1)ans[ind].back().pb('0');
        ans[ind].back().pb('9');
        ans[ind].pb("9");
        forn(j, ind - 1)ans[ind].back().pb('0');
        ans[ind].back().pb('6');
        forn(j, ind - 1)ans[ind].back().pb('0');
        ans[ind].back().pb('1');
    }
    while(t--){
        int n;
        cin >> n;
        for(string& s : ans[n / 2]){
            cout << s << el;
        }
    }
}
