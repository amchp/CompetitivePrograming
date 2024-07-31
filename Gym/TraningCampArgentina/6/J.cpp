#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define all(v) v.begin(), v.end()
#define el '\n'

using namespace std;

typedef vector<int> vi;


typedef pair<int, int> ii;

#define pb push_back//0 possible, 1 ambiguo 2 impossible 
int check(vi &a){
    int n = a.size();
    if(n == 1)return 0;
    int cnt = 0;
    int tam2 = 0,tammayor2 = 0;
    int prev = -1;
    int j = 0;
    bool mayorauno = 1;
    bool ret1 = 0;
    int intervmayordos = 0;
    while(j<n){
        while(j<n &&a[j] != 1){
            j++;
        }
        if(j == n )break;
        int idxx = j;
        while(j<n && a[j] == 1){j++;}
        if(j - idxx >= 5){
            ret1 = 1;
        }
        if(j-idxx >= 2){
            intervmayordos++;
        }
        if(j-idxx>1)mayorauno = 0;
    }
    forn(i,n){
        cnt+= a[i] == 1;
        tam2 += a[i] == 2;
        prev = a[i];
        tammayor2 += a[i] > 2;
    }

    if(a[0] != a[1] && a[n-2] != a[n-1] && a[0] == 1 && a[1] == 1 && mayorauno ){
        return 2;
    }
    if(ret1){
        return 1;
    }
    if(tam2 >= 1 && tammayor2>=1){
        return 1;
    }
    if(intervmayordos >= 3){
        return 1;
    }
    int prev = -1;
    bool sepunos = 1;
    int i = 0;
    while(i<n){
        int j = i+1;
        while(j<n && a[j] == a[j-1]){
            j++;
        }
        if(j - i > 1){
            while(j+1<n && a[j] != a[j+1]){
                
            }
        }

    }
    if(sepunos){

    }

}
int main(){
    int n;cin>>n;
    vi v(n);
    forn(i,n){
        cin>>v[i];
    }
    vector<vi> arr;
    vi a;
    bool prevCarro = 0;
    for (int i = 0; i < n;)
    {
        if(i == n-1){
            a.pb(i);
            arr.pb(a);
            continue;
        }
        int j = i+1;
        while(j<n && v[j]-1000 <= v[j-1] || v[j] - 2000 >= v[j-1]){
            j++;
        }
        if(j-i > 3 ){
            cout<<"impossible\n";
            return;
        }
        if(j-i == 3 || (prevCarro && j-i>=2)){
            prevCarro = 1;
            arr.pb(a);
            a = vi();
            if(j-i == 2){
                a.pb(2);
            }
        }else{
            if(j-i==2){
                prevCarro = 1;
            }else prevCarro = 0;
            a.pb(j-i);
        }
        i = j;
    }
    int trail = 0, noTrail = 0;
    if(a.size())
        arr.pb(a);
    forn(i,arr.size()){
        int val = check(arr[i]);
        if(val == 0){

        }else if (val == 1){

        }else{

        }
    }
}