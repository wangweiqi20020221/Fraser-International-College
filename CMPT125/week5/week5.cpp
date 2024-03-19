#include <iostream>

using namespace std;

int main() {
    int *a = new int[];
    for (int i = 0; i<100; i++) {
        a[i] = i;
    }
    system("Pause");
    return 0;
}

