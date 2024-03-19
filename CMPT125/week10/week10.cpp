#include <iostream>
using namespace std;

class Employee{
private:
    string firstName, lastName;

protected:
    double salary;

public:
    // Constructors
    Employee();
    Employee(const string&, const string&, const double&);
    Employee(const Employee&);

    // Deconstructor
    ~Employee();

    // Assignment operator
    Employee& operator=(const Employee&);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    double getSalary() const;

    // Setters
    void setFirstName(const string&);
    void setLastName(const string&);
    void setSalary(const double&);

    // Additional member functions
    void readInfo(istream&);
    void printInfo(ostream&) const;

    // Friend functinos
    friend istream& operator >> (istream&, Employee&);
    friend ostream& operator << (ostream&, const Employee&);
};

Employee::Employee() : firstName("N/A"), lastName("N/A"), salary(0.00) {
    cout << "Inside employee default constructor" << endl;
}

Employee::Employee(const string& f, const string& l, const double& s): firstName(f), lastName(l), salary(s) {
    cout << "Inside employee non-default constructor" << endl;
}

Employee::Employee(const Employee& e): firstName(e.getFirstName()), lastName(e.getLastName()), salary(e.getSalary()) {
    cout << "Inside employee copy constructor" << endl;
}

Employee::~Employee() {
    cout << "Employee object destructed" << endl;
}

Employee& Employee::operator=(const Employee& e) {
    this->firstName = e.getFirstName();
    this->lastName = e.getLastName();
    this->salary = e.getSalary();
    return *this;
}

string Employee::getFirstName() const {
    return this->firstName;
}

string Employee::getLastName() const {
    return this->lastName;
}

double Employee::getSalary() const {
    return this->salary;
}

void Employee::setFirstName(const string& f) {
    this->firstName = f;
}

void Employee::setLastName(const string& l) {
    this->lastName = l;
}

void Employee::setSalary(const double& s) {
    this->salary = s;
}

void Employee::readInfo(istream& in) {
    cout << endl;
    cout << "\tEnter first Name: ";
    in >> this->firstName;
    cout << "\tEnter last name: ";
    in >> this->lastName;
    cout << "\tEnter salary: ";
    in >> this->salary;
}

void Employee::printInfo(ostream& out) const {
    out << endl;
    out << "\tFull Name = " << this->getFirstName() << " " << this->getLastName() << endl;
    out << "\tSalary = " << salary << endl;
}

istream& operator >> (istream& in, Employee& e) {
    e.readInfo(in);
    return in;
}

ostream& operator << (ostream& out, const Employee& e) {
    e.printInfo(out);
    return out;
}

int main() {
    Employee e1, e2("Jack", "Malcom", 1500.00);
    Employee e3(e2), e4;
    e4 = e2;
    cout << "Enter an employee ";
    cin >> e1;
    cout << "Employee 1 " << e1 << endl;
    cout << "Employee 2 " << e2 << endl;
    cout << "Employee 3 " << e3 << endl;
    cout << "Employee 4 " << e4 << endl;

    e1.~Employee();
    e2.~Employee();
    e3.~Employee();
    e4.~Employee();

    system("Pause");
    return 0;
}
