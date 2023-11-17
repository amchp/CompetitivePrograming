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

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, v, ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        int a[3] = {0,0,0};
        for(int i = 0; i < n; ++i){
            cin >> v;
            a[v % 3]++;
        }
        v = distance(a, max_element(a, a + 3));
        ans += a[v] - (n/3);
        a[((v+1) % 3)] += a[v] - (n/3);
        ans += a[((v+1) % 3)] - (n/3);
        cout << ans << el;
    }
}