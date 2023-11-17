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

int n, k;
int a[nax];
int level[nax];
bool visited[nax];
bool ans;

void dfs(int i, int& depth){
    level[i] = ++depth;
    if(!visited[a[i]] && level[a[i]] != -1){
        int loop = depth - level[a[i]] + 1;
        ans &= k == loop;
        visited[i] = true;
        return;
    }
    if(!visited[a[i]])dfs(a[i], depth);
    visited[i] = true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans = true;
        forn(i, n){
            cin >> a[i];
            a[i]--;
            level[i] = -1;
            visited[i] = false;
        }
        if(k == 1){
            forn(i, n){
                if(i != a[i]){
                    ans = false;
                    break;
                }
            }
            if(ans){
            cout << "YES" << el;
            }else{
                cout << "NO" << el;
            }
            continue;
        }
        forn(i, n){
            int depth = 0;
            // cout << visited[i] << ' ';
            if(visited[i] == false){
                dfs(i, depth);
            }
        }
        // cout << el;
        if(ans){
            cout << "YES" << el;
        }else{
            cout << "NO" << el;
        }
    }
}
