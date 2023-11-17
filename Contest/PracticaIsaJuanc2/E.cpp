#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

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
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll fun(ll k)
{
    return k * (k + 1) / 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        ll k, x;
        cin >> k >> x;
        if (x > (k * (k - 1)) + k)
        {
            cout << k + k - 1 << el;
        }
        else if (x <= fun(k))
        {
            ll l = 1, r = k + 1;
            while (l + 1 < r)
            {
                ll mid = (l + r) / 2;
                if (fun(mid) <= x)
                    l = mid;
                else
                    r = mid;
            }
            if (fun(l) < x)
                cout << r << el;
            else
                cout << l << el;
        }
        else
        {
            x -= fun(k);
            ll l = 1, r = k;
            while (l + 1 < r)
            {
                ll mid = (l + r) / 2;
                if (fun(k - 1) - fun(k - mid) <= x)
                    l = mid;
                else
                    r = mid;
            }
            if (fun(k - 1) - fun(k - l) > x)
                cout << k + r << el;
            else
                cout << k + l << el;
        }
    }
}