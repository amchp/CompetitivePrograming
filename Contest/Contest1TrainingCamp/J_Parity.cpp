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
    int b, k, v, odd = 0;
    cin >> b >> k;
    for(int i = 0; i < k; ++i){
        cin >> v;
        if((b % 2 == 1 || i == k - 1) && v % 2 == 1)odd++;
    }
    if(odd % 2 == 1)cout << "odd" << el;
    else cout << "even" << el;
}