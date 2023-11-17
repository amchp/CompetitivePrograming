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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, dist, count, mCount;
        cin >> n;
        int a[n];
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            m[a[i]]++;
        }
        unordered_map<int, int>::iterator it;
        mCount = INF;
        for(it = m.begin(); it != m.end(); it++){
            dist = 0;
            count = 0;
            for(int i = 0; i < n; ++i){
                if(a[i] == it->first){
                    if(dist == 0)continue;
                    dist = 0;
                    count++;
                }
                else dist++;
            }
            if(dist != 0)count++;
            mCount = min(count, mCount);
        }
        cout << mCount << el;
    }
}