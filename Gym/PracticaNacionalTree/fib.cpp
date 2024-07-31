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

using namespace std;

typedef long long ll;

int main(){
    ll f1 = 1;
    ll f2 = 2;
    ll tmp;
    for(int i = 0; i < 11; ++i){
        tmp = f2;
        f2 = f1 + f2;
        f1 = tmp;
    }
    cout << f1 << ' ' << f2 << '\n';
}