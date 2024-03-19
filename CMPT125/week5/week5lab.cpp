#include <iostream>
using namespace std;



int main() {
    // a[][]是数列
    // a[]存储的是a[][]的内存地址
    // a存储的是a[]的内存地址
    // a在main stack(栈)里
    // a[]和a[][]在heap(堆)里
    int **a = new int*[5];
    for (int i = 0; i < 5; i++) {
        a[i] = new int[5];
    }
    for (int i = 0; i < 25; i++) {
        a[25/i][25%i] = i;
    }
    delete a;
    system("Pause");
    return 0;
}
