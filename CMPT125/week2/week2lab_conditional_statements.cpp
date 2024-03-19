#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int question1a() {
    // 5 is not equal to 3
    // 5 is greater than 3
    int a = 5, b = 3;
    if (a == b)
        cout << a << " is equal to " << b << endl;
    if (a != b)
        cout << a << " is not equal to " << b << endl;
    if (a < b)
        cout << a << " is less than " << b << endl;
    if (a > b)
        cout << a << " is greater than " << b << endl;
    return 0;
}

int question1b() {
    // 5 is not equal to 3
    int a = 5, b = 3;
    if (a == b)
        cout << a << " is equal to " << b << endl;
    else if (a != b)
        cout << a << " is not equal to " << b << endl;
    else if (a < b)
        cout << a << " is less than " << b << endl;
    else
        cout << a << " is greater than " << b << endl;
    return 0;
}

int question3() {
    double a, b, c;
    cout << "Input a, b and c:";
    cin >> a >> b >> c;
    if(b*b-4*a*c > 0) {
        cout << "Might be 2 solutions" << endl;
    } else if (b*b-4*a*c == 0) {
        cout << "Might be 1 solutions" << endl;
    } else {
        cout << "Might be 0 solutions" << endl;
    }
    return 0;
}

int question11() {
    srand(time(0));
    int num = rand() % 3;
    // int num = rand();
    // cout << num << endl;
    num %= 3;
    if(num == 0) {
        cout << "Yes" << endl;
    } else if(num == 1) {
        cout << "No" << endl;
    } else {
        cout << "Not sure" << endl;
    }
    return 0;
}

int main() {
    // question1a();
    // question1b();
    // question3();
    question11();
    system("Pause");
    return 0;
}