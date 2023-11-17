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
#include <tuple>


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
    int n, m, l, r, mid;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i)cin >> a[i];
    for(int i = 0; i < m; ++i)cin >> b[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < m; ++i){
        l = 0;
        r = n - 1;
        while(l + 1 < r){
            mid = (l + r)/2;
            if(a[mid] <= b[i])l = mid;
            else r = mid;
        }
        if(a[r] <= b[i])cout << r+1 << " ";
        else if(r == 1 && a[0] > b[i]) cout << 0 << " ";
        else cout << r << " "; 
    }
    cout << el;
}