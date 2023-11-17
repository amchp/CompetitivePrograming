#include <iostream>

using namespace std;

int main(){
    int n, p, pages, page, middle;
    cin >> n >> p;
    pages = n / 2 + 1;
    page = p / 2 + 1;
    middle = pages /2;
    if(page <= middle) cout << (page - 1) << endl;
    else cout << pages - page << endl;

}