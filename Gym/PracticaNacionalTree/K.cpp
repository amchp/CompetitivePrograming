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

long double X, T;

long double eps = 2e-6;

long double fun(long double t){
    if(t < 0)return 0;
    if(t < T / 6.0){
        return ((6.0*X)/T)*t;
    }if(t < T / 3.0){
        return ((6.0*(100 - X)) / T) * t + (2*X - 100);
    }
    return 100;
}

long double f(long double t){
    return (T - t)*fun(t);
}

long double ternary_search(long double l, long double r){
    while(r - l > eps){
        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        long double f1 = f(m1), f2 = f(m2);
        if(f1 < f2)l = m1;
        else r = m2;
    }
    return f(l);
}

int main(){
    cout << setprecision(20) << fixed;
    cin >> X >> T;
    cout << max(ternary_search(0, T/6), ternary_search(T/6, T/3)) << '\n';
}