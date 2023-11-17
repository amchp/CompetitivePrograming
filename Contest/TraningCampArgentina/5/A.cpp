#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<ii> a(n);
    forn(i, n){
        int v;
        cin >> v;
        a[i] = make_pair(v, i);
    }
    sort(all(a));
    queue<int> q;
    int days = 1;
    vi ans(n);
    ans[a[0].second] = 1;
    q.push(0);
    for1(i, n - 1){
        if(a[i].first - a[q.front()].first > d){
            ans[a[i].second] = ans[a[q.front()].second];
            q.pop();
            q.push(i);
            continue;
        }
        days++;
        ans[a[i].second] = days;
        q.push(i);
    }
    cout << days << el;
    forn(i, n)cout << ans[i] << ' ';
    cout << el;
}