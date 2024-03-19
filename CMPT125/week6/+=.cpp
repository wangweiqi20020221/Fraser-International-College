#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int &b = a;
    int *c;
    c = &b;
    cout << b << endl;
    cout << *c << endl;
    return 0;
}
