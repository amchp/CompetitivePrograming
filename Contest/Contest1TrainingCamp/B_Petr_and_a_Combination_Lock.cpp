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

bool aux(vi a, int i, int v){
    if(i == a.size())return v == 0;
    return aux(a, i+1, (360+v+a[i])%360) || aux(a, i+1, (360+v-a[i])%360);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    if(aux(a, 0, 0))cout << "YES" << el;
    else cout << "NO" << el;

}