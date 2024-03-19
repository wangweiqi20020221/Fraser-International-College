#include <iostream>
#include <string>

using namespace std;

struct RationalNumber{
    int a, b;
};

int getNumerator(const RationalNumber &r) {
    return r.a;
}

int getDenominator(const RationalNumber &r) {
    return r.b;
}

void setNumerator(RationalNumber &r, const int &numerator) {
    r.a = numerator;
}

void setDenominator(RationalNumber &r, const int &denominator) {
    r.b = denominator;
}

double toDouble(const RationalNumber &r) {
    double a = 1.0 * getNumerator(r);
    double b = static_cast<double>(getDenominator(r));
    return a/b;   
}

void standardize(RationalNumber &r) {
    if (r.b < 0){
        r.a *= -1;
        r.b *= -1;
    }
}

void reduce(RationalNumber &r) {
    if (r.a == 0) {
        r.b = 1;
    } else {
        int m = abs(r.a), n = abs(r.b);
        int gcd = m < n ? m : n;
        while (m % gcd != 0 || n % gcd != 0) {
            gcd--;
        }
        r.a /= gcd;
        r.b /= gcd;
    }
}

RationalNumber operator+(const RationalNumber &r1, const RationalNumber &r2) {
    RationalNumber ans;
    ans.a = r1.a * r2.b + r1.b * r2.a;
    ans.b = r1.b * r2.b;
    standardize(ans);
    reduce(ans);
    return ans;
}

RationalNumber operator-(const RationalNumber &r1, const RationalNumber &r2) {
    RationalNumber ans;
    ans.a = r1.a * r2.b + r1.b * r2.a;
    ans.b = r1.b * r2.b;
    standardize(ans);
    reduce(ans);
    return ans;
}

RationalNumber operator*(const RationalNumber &r1, const RationalNumber &r2) {
    RationalNumber ans;
    ans.a = r1.a * r2.a;
    ans.b = r1.b * r2.b;
    standardize(ans);
    reduce(ans);
    return ans;
}

RationalNumber operator/(const RationalNumber &r1, const RationalNumber &r2) {
    RationalNumber ans;
    ans.a = r1.a * r2.b;
    ans.b = r1.b * r2.a;
    standardize(ans);
    reduce(ans);
    return ans;
}

bool operator==(const RationalNumber &r1, const RationalNumber &r2) {
    return bool = (toDouble(r1)==toDouble(r2)) ? true : false;
}

int stringToInteger(const string &s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++)
        num = 10*num + s[i] - 48;
    return num;
}

string getSubstring(const string &s, const int startIndex, const int length) {
    string ans;
    for (int i = startIndex; ans.length() < length && i < s.length(); i++)
        ans += s[i];
    return ans;
}

void operator=(RationalNumber &r, const string &s) {
    // RationalNumber r = "1/5683", instead of using the setter
     // Split the string by /
    int index = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == "/") {
            index = i;
        }
    }
    string num_str = getSubstring(s, 0, index);
    string denum_str = getSubstring(i+1, s.length() - index - 1);
    r.a = stringToInteger(num_str);
    r.b = stringToInteger(denum_str);
    return r;
}

int main() {
    RationalNumber r1 = "1/3";
    RationalNumber r2 = "1/4";
    cout << r1 + r2 << endl;
    RationalNumber r;
    setNumerator(r, 3);
    setDenominator(r, 4);
    cout << "r is " << getNumerator(r) << "/" << getDenominator(r) << endl;
    cout << "In the double dormat, r = " << toDouble(r) << endl;
    RationalNumber r1, r2;
    setNumerator(r1, 3);
    setDenominator(r1, 4);
    setNumerator(r2, 1);
    setDenominator(r2, 4);
    RationalNumber r3;
    r3 = r1 + r2;
    cout << "3/4 + 1/4 = " << getNumerator(r3) << "/" << getDenominator(r3) << endl;
    system("Pause");
    return 0;
}
