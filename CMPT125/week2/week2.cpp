#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // srand函数使用当前的时间重新生成种子，所以下面的rand函数会基于当前的时间生成随机数
    // https://stackoverflow.com/questions/4736485/srandtime0-and-random-number-generation
    srand(time(0));
    cout << "Generating 5 random integers in the range [0, RAND_MAX)" << endl;
    int a = rand();
    cout << a << endl;
    a = rand();
    cout << a << endl;
    a = rand();
    cout << a << endl;
    a = rand();
    cout << a << endl;
    a = rand();
    cout << a << endl;
    
    cout << "The value of RAND_MAX is" << RAND_MAX << endl;

    system("Pause");
    return 0;
}
