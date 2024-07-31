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

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    n -= n % 2;
    cout << ceil((double)n / 4) * floor((double)n / 4) << '\n';
}