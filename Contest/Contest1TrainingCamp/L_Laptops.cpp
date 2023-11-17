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
    int n, a, b, hq;
    bool pass = false;
    cin >> n;
    vi v(n+1, 0);
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        v[a] = max(v[a], b);
    }
    hq = 0;
    for(int i = 1; i < n+1; ++i){
        if(v[i] < hq){
            pass = true;
            break;
        }
        hq = max(hq, v[i]);
    }
    if(pass)cout << "Happy Alex" << el;
    else cout << "Poor Alex" << el;
}