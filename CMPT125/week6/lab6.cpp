#include <iostream>
using namespace std;

struct Map{
    int a[], SIZE;
};

ostream & operator << (ostream &out, const Map &m) {
    cout << "[";
    for(int i = 0; i < m.SIZE; i++) {
        cout << m.a[i];
        if(i < m.SIZE - 1) {
            cout << ","
        }
    }
    cout << "]";
}

int main() {
    int size = 5;
    Map m[size];
    m.a[0] = 1;
    m.SIZE = size;
    cout << m.a[0] << endl;
    system("Pause");
    return 0;
}
