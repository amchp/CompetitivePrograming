#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, k, pages, inicialPage, problem, special;
    cin >> n >> k;
    int chapter[n+1];
    for(int i = 1; i < n+1; ++i){
        cin >> chapter[i];
    }
    pages = 1;
    special = 0;
    for(int i = 1; i < n+1; ++i){
        inicialPage = pages;
        pages += ceil((double) chapter[i] / k);
        problem = 1;
        for(int j = inicialPage; i <  pages; ++j){
            if(j < problem && j > problem + k)special++;
        }
    }
    cout << special << endl;
    
}