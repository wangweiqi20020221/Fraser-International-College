#include <iostream>
#include <cmath>

using namespace std;

int question3() {
    double height, base;
    cout << "Input the height:";
    cin >> height;
    cout << "Input the base:";
    cin >> base;
    cout << "The area is: " << height * base / 2 << endl;
    return 0;
}

int question4() {
    double a, b, c;
    cout << "Input a, b, c, get b^2-4ac" << endl;
    cout << "Input a:";
    cin >> a;
    cout << "Input b:";
    cin >> b;
    cout << "Input c:";
    cin >> c;
    cout << "The discriminant is: " << b * b - 4 * a * c;
    return 0;
}

int question5() {
    double amount, interest_rate, period;
    cout << "This is a simple interest calculator." << endl;
    cout << "Input the amount: ";
    cin >> amount;
    cout << "Input the interest rate: ";
    cin >> interest_rate;
    cout << "Input the period ";
    cin >> period;
    cout << "The interest rate is: " << amount * interest_rate * period << endl;
    return 0;
}

int question6() {
    int day1, day2;
    cout << "input day 1:";
    cin >> day1;
    cout << "input day 2:";
    cin >> day2;
    // A negative number in unsigned int probably be a great positive number that greater than 31
    while (day1>31 || day2>31) {
        cout << "Two days must less than 32 and greater to 0" << endl;
        cout << "input day 1:";
        cin >> day1;
        cout << "input day 2:";
        cin >> day2;
    }
    cout << abs(day1-day2) << endl;
    return 0;
}

int get_days(int month) {
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
        return 31;
    } else if(month == 2) {
        return 28;
    } else {
        return 30;
    }
}

int question7() {
    /*
    * A month can't be simply 30 days as in the question. So I wrote a get_days function above.
    */
    int month1, month2, sum_days;
    cout << "input month 1:";
    cin >> month1;
    cout << "input month 2:";
    cin >> month2;
    // A negative number in unsigned int probably be a great positive number that greater than 31
    while(month1>12 || month2>12) {
        cout << "Two months must less than 13 and greater to 0" << endl;
        cout << "input month 1:";
        cin >> month1;
        cout << "input month 2:";
        cin >> month2;
    }
    sum_days = 0;
    while(month1 != month2) {
        sum_days += get_days(month1);
        cout << sum_days << endl;
        if(month1 == 13) {
            month1 = 1;
        } else {
            month1++;
        }
    }
    cout << "Days betweens is:" << sum_days << endl;
    return 0;
}

int main() {
    cout << "Week1 Lab Work" << endl;
    // question3();
    // question4();
    // question5();
    // question6();
    question7();
    system("Pause");
    return 0;
}
