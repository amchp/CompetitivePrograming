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

vi parent((int)(1e5)+1);
vector<vi> g((int)(1e5)+1);

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < g[i].size(); ++j)union_sets(a, b);
    }
}