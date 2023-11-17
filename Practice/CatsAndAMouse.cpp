#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, catA, catB, mouse;
    cin >> n;
    while(n--){
        cin >> catA >> catB >> mouse;
        catA = abs(mouse - catA);
        catB = abs(mouse - catB);
        if(catA < catB) cout << "Cat A" << endl;
        else if(catB < catA) cout << "Cat B" << endl;
        else cout << "Mouse C" << endl;
    }
}