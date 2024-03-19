#include <iostream>
#include <cmath>
using namespace std;

int func(int a, int b, double c) {
    return a+b+c;
}

void func_return_nothing() {
    // do not need a return in this function
}

double triangleArea(double a, double b, double c)
{
    double s = (a+b+c)/2.0;
    double answer=sqrt(s*(s-a)*(s-b)*(s-c));
    return answer;
}

int main() {
    // do something
    double s1, s2, s3;
    cout << "Enter the lengths of the three sides of a triangle:";
    cin >> s1 >> s2 >> s3;
    if(s1<=0 || s2<=0 || s3<=0) {
        cout << "Each side of a triangle must have a positive length.Bye." << endl;
    }
    else if(s1+s2<=s3 || s1+s3<=s2 || s2+s3<=s1) {
        cout << "These numbers do not satisfy triangle inequality.Bye." << endl;
    }
    else {
        double result = triangleArea(s1,s2,s3);
        cout << "The area of the triangle is " << result << endl;
    }
    system("Pause");
    return 0;
}
