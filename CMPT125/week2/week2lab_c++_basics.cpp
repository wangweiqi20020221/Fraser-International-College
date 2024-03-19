#include <iostream>
using namespace std;

int question1() {
    // Returns bcbc
    char a, b, c;
    a = 'b';
    b = 'c';
    c = a;
    cout << a << b << c << 'c' << endl;
    return 0;
}

int question2() {
    // Enter an integer 2
    // The sum is -739757454
    int a, b;
    cout << "Enter an integer ";
    cin >> a;
    int sum = a + b;
    cout << "The sum is " << sum << endl;
    b = 0;
    int quotient = a / b;
    cout << "The quotient is " << quotient << endl;
    return 0;
}

int question4() {
    /*
     * This program reads the radius of a sphere from the user and then prints the volume of the sphere.
     * Recall that the volume of a sphere is given by the formula (4/3)*PI*r^3
     */
    // Enter the radius of a sphere: 5
    // The volume of the sphere is 392.5
    double radius;
    cout << "Enter the radius of a sphere: ";
    cin >> radius;
    double volume = (4/3) * 3.14 * radius * radius * radius;
    cout << "The volume of the sphere is " << volume << endl;
    return 0;
}

int question5() {
    // 6, 7
    // 6, 9
    // 6, 8
    // 6, 8
    // 15
    // 17
    // 17
    // -5
    // -1
    int a = 5, b = 7;
    // ++a先被执行，然后显示++a的内容；而b先被显示，而后程序再b++（不显示，因为已经显示了b），所以显示了6, 7
    cout << ++a << ", " << b++ << endl;
    // a先被显示，此时a的值为6，而后a--（不显示）；此时b的值是8，程序先执行++b，而后显示了9
    cout << a-- << ", " << ++b << endl;
    cout << ++a << ", " << --b << endl;
    cout << a-- << ", " << b++ << endl;
    cout << ++a+ b++ << endl;
    cout << a--+ ++b << endl;
    int c = a++ + ++b;
    cout << c << endl;
    c = a-- - --b;
    cout << c << endl;
    c = c++ - ++a + --b;
    cout << c << endl;
    return 0;
}

int question6() {
    // 6
    // 6.25
    // 6.25
    // 6.25
    // 6
    // 25, 4
    // 6
    // 6
    // 6
    // 6
    // 6.25 6
    int a = 25;
    int b = 4;
    cout << a / b << endl;
    cout << static_cast<float>(a) / b << endl;
    cout << a / static_cast<float>(b) << endl;
    cout << static_cast<float>(a) / static_cast<float>(b) << endl;
    cout << static_cast<float>(a / b) << endl;
    cout << a << ", " << b << endl;
    float result = a / b;
    cout << result << endl;
    result = static_cast<float>(a / b);
    cout << result << endl;
    int c = static_cast<float>(a) / b;
    cout << c << endl;
    c = a / static_cast<float>(b);
    cout << c << endl;
    result = static_cast<float>(a) / static_cast<float>(b);
    c = static_cast<float>(a) / static_cast<float>(b);
    cout << result << " " << c << endl;
    return 0;
}

int question7() {
    // A
    // A
    // A
    // A
    char c1 = 65;
    char c2 = 321;
    char c3 = -191;
    char c4 = 'A';
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    return 0;
}

int question8() {
    // 144
    // -144
    // 144

    // -112
    // 112
    int a = 144;
    // b = 10010000 -> 10001111 -> 01110000 = 112  -> -112
    char b = 144;
    cout << a << endl;
    cout << -a << endl;
    cout << +a << endl;
    cout << b << endl;
    cout << +b << endl;
    cout << -b << endl;
    return 0;
}

int question9() {
    // A
    // F
    char c1 = 'A';
    char c2 = c1 + 5;
    cout << c1 << endl;
    cout << c2 << endl;
    return 0;
}

int main() {
    // The program starts here
    // question1();
    // question2();
    // question4();
    // question5();
    // question6();
    // question7();
    // question8();
    question9();
    system("Pause");
    return 0;
}
