#include <iostream>

using namespace std;

class ComplexNumber{
    private:
        double a, b;
    public:
        ComplexNumber();
        ComplexNumber(const double &a, const double &b);

        double getImaginary() const;
        double getReal() const;

        void setImaginary(const double &a);
        void setReal(const double &b);

        ComplexNumber operator + (const ComplexNumber &c) const;
        ComplexNumber operator ++ (int DUMMY);
        ComplexNumber& operator ++ ();
        ComplexNumber operator - () const;

        friend ostream &operator << (ostream &out, const ComplexNumber &c);
};

ComplexNumber::ComplexNumber() {
    this->a = 0;
    this->b = 0;
}

ComplexNumber::ComplexNumber(const double &a, const double &b) {
    this->a = a;
    this->b = b;
}

double ComplexNumber::getImaginary() const {
    return this->b;
}

double ComplexNumber::getReal() const {
    return this->a;
}

void ComplexNumber::setImaginary(const double &a) {
    this->a = a;
}

void ComplexNumber::setReal(const double &b) {
    this->b = b;
}

ComplexNumber ComplexNumber::operator + (const ComplexNumber &c) const {
    ComplexNumber temp_c(this->a + c.getReal(), this->b + c.getImaginary());
    return temp_c;
}

ComplexNumber ComplexNumber::operator ++ (int DUMMY) {
    ++this->a;
    return *this;
}

ComplexNumber& ComplexNumber::operator ++ () {
    this->a++;
    return *this;
}

ComplexNumber ComplexNumber::operator - () const {
    ComplexNumber temp_c(-(this->a), -(this->b));
    return temp_c;
}

ostream &operator << (ostream &out, const ComplexNumber &c) {
    out << c.getReal() << "+" << c.getImaginary() << "i";
    return out;
}

int main () {
    ComplexNumber c1;
    const ComplexNumber c2(1.4, -2.5);

    cout << "c1 real part is " << c1.getReal() << endl;
    cout << "c1 imaginary part is " << c1.getImaginary() << endl;

    cout << "c1 is " << c1 << endl;
    cout << "c2 is " << c2 << endl;

    ComplexNumber *c3 = new ComplexNumber(c1 + c2);
    cout << "*c3 is " << *c3 << endl;

    ComplexNumber c4 = c2 + c1;
    cout << "c4 is " << c4 << endl;

    ComplexNumber c5 = -c2;
    cout << "c5 is " << c5 << endl;

    ++c1;
    cout << "After ++c1, now c1 is " << c1 << endl;

    c5 = c4++;
    cout << "After c5 = c4++, c5 is " << c5 << " and c4 is " << c4 << endl;

    system("Pause");
    return 0;
}
