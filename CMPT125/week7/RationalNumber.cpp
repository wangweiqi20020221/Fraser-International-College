#include <iostream>
#include <string>

using namespace std;

class RationalNumber{
    private:
        int numerator, denominator;
    public:
        RationalNumber();
        RationalNumber(const int &a, const int &b);

        double toDouble();

        int getDenominator() const;
        int getNumerator() const;

        void reduce();
        void setDenominator(const int &b);
        void setNumerator(const int &a);
        void standardize();

        static int stringToInteger(const string &s);
        static string getSubstring(const string &s, const int startIndex, const int length);

        RationalNumber operator + (const RationalNumber &r) const;
        RationalNumber &operator = (const string &s);
};


RationalNumber::RationalNumber() {
    // 无参构造函数
}

RationalNumber::RationalNumber(const int &a, const int &b) {
    // 有参构造函数
    this->numerator = a;
    this->denominator = b;
}

double RationalNumber::toDouble() {
    double a = 1.0 * this->getNumerator();
    double b = static_cast<double>(this->getDenominator());
    return a/b;   
}

int RationalNumber::getDenominator() const {
    return this->denominator;
}

int RationalNumber::getNumerator() const {
     return this->numerator;
}

void RationalNumber::reduce() {
    if (this->numerator == 0) {
        this->denominator = 1;
    } else {
        int m = abs(this->numerator), n = abs(this->denominator);
        int gcd = m < n ? m : n;
        while (m % gcd != 0 || n % gcd != 0) {
            gcd--;
        }
        this->numerator /= gcd;
        this->denominator /= gcd;
    }
}

void RationalNumber::setDenominator(const int &b) {
    if(b == 0) {
        throw "The denominator can't be 0!";
    }
    else {
        this->denominator = b;
    }
}

void RationalNumber::setNumerator(const int &a) {
    this->numerator = a;
}

void RationalNumber::standardize() {
    if (this->denominator < 0){
        this->denominator *= -1;
        this->numerator *= -1;
    }
}

int RationalNumber::stringToInteger(const string &s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++)
        num = 10*num + s[i] - 48;
    return num;
}

string RationalNumber::getSubstring(const string &s, const int startIndex, const int length) {
    // c++ can't do str[startIndex:endIndex], so sad
    string ans;
    for (int i = startIndex; ans.length() < length && i < s.length(); i++)
        ans += s[i];
    return ans;
}

RationalNumber RationalNumber::operator + (const RationalNumber &r) const {
    int a;
    a = this->denominator * r.numerator
} 

RationalNumber &RationalNumber::operator = (const string &s) {
    // RationalNumber r = "1/5683", instead of using the setter
     // Split the string by /
    int index = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '/') {
            index = i;
        }
    }
    string num_str = this->getSubstring(s, 0, index);
    string denum_str = this->getSubstring(s, index+1, s.length() - index - 1);
    this->numerator = this->stringToInteger(num_str);
    this->denominator = this->stringToInteger(denum_str);
    return *this;
}

int main() {
    RationalNumber r;
    r = "3/4";
    // r(1, 1);
    cout << r.getNumerator() << endl;
    system("Pause");
    return 0;
}
