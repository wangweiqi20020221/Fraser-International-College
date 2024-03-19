#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
	string firstName, lastName;
protected:
	double salary;
public:
	//Constructors
	Employee();
	Employee(const string&, const string&, const double&);
	Employee(const Employee&);
	//Destructor
	~Employee();
	//Assignment operator
	Employee& operator=(const Employee&);
	//Getters
	string getFirstName() const;
	string getLastName() const;
	double getSalary() const;
	virtual string getType() const;
	//Setters
	void setFirstName(const string&);
	void setLastName(const string&);
	void setSalary(const double&);
	//Additional member functions
	void readInfo(istream&);
	virtual void printInfo(ostream&) const;
	//Friend functions
	friend istream& operator>>(istream&, Employee&);
	friend ostream& operator<<(ostream&, const Employee&);
};
Employee::Employee() : firstName("N/A"), lastName("N/A"), salary(0.00)
{
	cout << "Inside employee default constructor"<< endl;
}
Employee::Employee(const string& f, const string& l, const double& s) : firstName(f), lastName(l), salary(s)
{
	cout << "Inside employee non-default constructor"<< endl;
}
Employee::Employee(const Employee& e) : firstName(e.firstName), lastName(e.lastName), salary(e.salary)
{	
	cout << "Inside employee copy constructor"<< endl;
}
Employee::~Employee()
{
	cout << "Employee object destructed" << endl;
}
Employee& Employee::operator=(const Employee& e)
{
	firstName = e.firstName;
	lastName = e.lastName;
	salary = e.salary;
	return *this;
}
string Employee::getFirstName() const
{
	return firstName;
}
string Employee::getLastName() const
{
	return lastName;
}
double Employee::getSalary() const
{
	return salary;
}
string Employee::getType() const
{
	return "Employee";
}
void Employee::setFirstName(const string& f)
{
	firstName = f;
}
void Employee::setLastName(const string& l)
{
	lastName = l;
}
void Employee::setSalary(const double& s)
{
	salary = s;
}
void Employee::readInfo(istream& in)
{
	cout << endl;
	cout << "\tEnter first name: ";
	in >> firstName;
	cout << "\tEnter last name: ";
	in >> lastName;
	cout << "\tEnter salary: ";
	in >> salary;
}
void Employee::printInfo(ostream& out) const
{
	out << "\tFull Name = " << firstName << " " << lastName << endl;
	out << "\tSalary = " << salary << endl;
}
istream& operator>>(istream& in, Employee& e)
{
	e.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, const Employee& e)
{
	e.printInfo(out);
	return out;
}
class Manager : public Employee
{
private:
	int num; //number of subordinates
public:
	//Constructors
	Manager();
	Manager(const string&, const string&, const double&, const int&);
	Manager(const Manager&);
	//Destructor
	~Manager();
	//Assignment operator
	Manager& operator=(const Manager&);
	//Getters
	int getSubordinates() const;
	virtual string getType() const;
	//Setters
	void setSubordinates(const int&);
	//Additional member functions
	void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};
Manager::Manager() : Employee(), num(0)
{
	cout << "Inside manager default constructor" << endl;
}
Manager::Manager(const string& f, const string& l, const double& s, const int& n) : Employee(f, l, s), num(n)
{
	cout << "Inside manager non-default constructor" << endl;
}
Manager::Manager(const Manager& m) : Employee(m), num(m.num)
{
	cout << "Inside manager copy constructor" << endl;
}
Manager::~Manager()
{
	cout << "Manager object destructed" << endl;
}
Manager& Manager::operator=(const Manager& m)
{
	this->Employee::operator=(m);
	num = m.num;
	return *this;
}
int Manager::getSubordinates() const
{
	return num;
}
string Manager::getType() const
{
	return "Manager";
}
void Manager::setSubordinates(const int& n)
{
	num = n;
}
void Manager::readInfo(istream& in)
{
	this->Employee::readInfo(in);
	cout << "\tEnter number of subordinates: ";
	in >> this->num;
}
void Manager::printInfo(ostream& out) const
{
	this->Employee::printInfo(out);
	out << "\tNumber of subordinates = " << this->num << endl;
}

int main()
{
	//Construct an Employee and a Manager objects
	cout << "Constructing an Employee object" << endl;
	Employee e("Tom", "Mark", 1200.00);

	cout << endl << "Constructing a Manager object" << endl;
	Manager m("Jack", "Jones", 2800.00, 5);
	cout << endl;

	//Print the objects
	cout << "Object e is " << e.getType() << endl << e << endl;
	cout << "Object m is " << m.getType() << endl << m << endl;

	//Declare a pointer of Employee type
	Employee* p;

	//Point the pointer to the Employee object
	p = &e;
	//Print the Employee object pointed to by the pointer p using printInfo member function
	cout << "p is pointing to " << p->getType() << endl;
	p->printInfo(cout);

	//Point the pointer to the Manager object
	p = &m;
	//Print the Manager object pointed to by the pointer p using printInfo member function
	cout << "p is pointing to " << p->getType() << endl;
	p->printInfo(cout);

	//Declare an Employee type reference to the Employee object
	Employee& r1 = e;
	//Print the Employee object referenced by the reference r1 using printInfo member function
	cout << "r1 is a reference to " << r1.getType() << endl;
	r1.printInfo(cout);

	//Declare an Employee type reference to the Manager object
	Employee& r2 = m;
	//Print the Manager object referenced by the reference r2 using printInfo member function
	cout << "r2 is a reference to " << r2.getType() << endl;
	r2.printInfo(cout);

	system("Pause");
	return 0;
}