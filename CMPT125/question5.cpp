#include <iostream>
#include <string>
using namespace std;

// string nthElementHelper(const string a, const string b, int n) {
//     if (n==2) {
//         return b;
//     }
//     return nthElementHelper(b, a+b, --n);
// }

// string nthElement(const int n) {
//     return nthElementHelper("a", "b", n);
// }

sting nthElement(const int n) {
    if (n == 1) {
        return "a";
    } else if (n == 2) {
        return "b";
    } else {
        return nthElement(n-2) + nthElement(n-1);
    }
}

int main() {
    int n;
    cout << "Input n:";
    cin >> n;
    cout << nthElement(n) << endl;
    system("Pause");
    return 0;
}
