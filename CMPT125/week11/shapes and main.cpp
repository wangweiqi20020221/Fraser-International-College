#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Shape
{
private:
	string color;
public:
	Shape() { color = "None"; }
	Shape(const string& c) { color = c; }
	virtual ~Shape() {} //This is required by some compilers

	string getColor() const { return color; }
	void setColor(const string& c) { color = c; }

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual string getType() const = 0;

	virtual void readInfo(istream &in)
	{
		cout << "\tEnter color: ";
		in >> this->color;
	}
	virtual void printInfo(ostream &out) const
	{
		out << "\tColor = " << this->color << ", Area = " << this->getArea() << ", Perimeter = " << this->getPerimeter() << endl;
	}

	friend istream& operator>>(istream& in, Shape& s) { s.readInfo(in); return in; }
	friend ostream& operator<<(ostream& out, const Shape& s) { s.printInfo(out); return out; }
};

typedef Shape* ShapePtr; //This will be useful later

class Rectangle : public Shape
{
private:
	double length, width;
public:
	Rectangle();
	Rectangle(const double&, const double&, const string&);

	double getLength() const;
	double getWidth() const;
	virtual string getType() const { return "Rectangle"; }

	virtual void setLength(const double&);
	virtual void setWidth(const double&);

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};

Rectangle::Rectangle() : Shape()
{
	length = 0;
	width = 0;
}
Rectangle::Rectangle(const double& len, const double& wid, const string& c) : Shape(c)
{
	length = len;
	width = wid;
}
double Rectangle::getLength() const { return length; }
double Rectangle::getWidth() const { return width; }
void Rectangle::setLength(const double& len) { length = len; }
void Rectangle::setWidth(const double& wid) { width = wid; }
double Rectangle::getArea() const { return length*width; }
double Rectangle::getPerimeter() const { return 2*(length+width); }
void Rectangle::readInfo(istream& in)
{
	cout << "\tEnter length ";
	in >> length;
	cout << "\tEnter width ";
	in >> width;
	this->Shape::readInfo(in);
}
void Rectangle::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tLength = " << length << ", Width = " << width << endl;
	this->Shape::printInfo(out);
}

class Square : public Rectangle
{
public:
	Square();
	Square(const double&, const string&);

	double getSide() const;
	virtual string getType() const { return "Square"; }

	virtual void setLength(const double&);
	virtual void setWidth(const double&);
	void setSide(const double&);

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};

Square::Square() : Rectangle() { }
Square::Square(const double& side, const string& c) : Rectangle(side, side, c) { }
double Square::getSide() const
{
	return getLength();
}
void Square::setLength(const double& len)
{
	setSide(len);
}
void Square::setWidth(const double& wid)
{
	setSide(wid);
}
void Square::setSide(const double& side)
{
	this->Rectangle::setLength(side);
	this->Rectangle::setWidth(side);
}
void Square::readInfo(istream& in)
{
	double temp;
	cout << "\tEnter side ";
	in >> temp;
	this->setSide(temp);
	this->Shape::readInfo(in);
}
void Square::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tSide = " << getSide() << endl;
	this->Shape::printInfo(out);
}

class Triangle : public Shape
{
private:
	double base, height;
public:
	Triangle();
	Triangle(const double&, const double&, const string&);

	double getBase() const;
	double getHeight() const;
	virtual string getType() const { return "Triangle"; }

	void setBase(const double&);
	void setHeight(const double&);

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};

Triangle::Triangle() : Shape()
{
	base = 0;
	height = 0;
}
Triangle::Triangle(const double& b, const double& h, const string& c) : Shape(c)
{
	base = b;
	height= h;
}
double Triangle::getBase() const { return base; }
double Triangle::getHeight() const { return height; }
void Triangle::setBase(const double& b) { base = b; }
void Triangle::setHeight(const double& h) { height = h; }
double Triangle::getArea() const
{
	return 0.5*base*height;
}
double Triangle::getPerimeter() const
{
	return base+height+sqrt(base*base + height*height);
}
void Triangle::readInfo(istream& in)
{
	cout << "\tEnter base ";
	in >> base;
	cout << "\tEnter height ";
	in >> height;
	this->Shape::readInfo(in);
}
void Triangle::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tBase = " << base << ", Height = " << height << endl;
	this->Shape::printInfo(out);
}

class Circle : public Shape
{
private:
	double radius;
public:
	Circle();
	Circle(const double&, const string&);

	double getRadius() const;
	virtual string getType() const { return "Circle"; }

	void setRadius(const double&);

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};
Circle::Circle() : Shape()
{
	radius = 0;
}
Circle::Circle(const double& r, const string& c) : Shape(c)
{
	radius = r;
}
double Circle::getRadius() const
{
	return radius;
}
void Circle::setRadius(const double& r)
{
	radius = r;
}
double Circle::getArea() const
{
	return 3.14*radius*radius;
}
double Circle::getPerimeter() const
{
	return 2*3.14*radius;
}
void Circle::readInfo(istream& in)
{
	cout << "\tEnter radius ";
	in >> radius;
	this->Shape::readInfo(in);
}
void Circle::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tRadius = " << radius << endl;
	this->Shape::printInfo(out);
}

int main()
{
	srand(time(0));
	int size;
	cout << "How many objects would you like to store ";
	cin >> size;
	ShapePtr *S = new ShapePtr[size];
	string color[] = {"Red", "Blue", "Yellow", "Purple", "Green", "Cyan"};
	for (int i = 0; i < size; i++)
	{
		switch(rand() % 4)
		{
			case 0:
				cout << "Constructing a Rectangle object" << endl;
				S[i] = new Rectangle(rand()%11+5, rand()%11+5, color[rand()%6]);
				break;
			case 1:
				cout << "Constructing a Square object" << endl;
				S[i] = new Square(rand()%11+5, color[rand()%6]);
				break;
			case 2:
				cout << "Constructing a Triangle object" << endl;
				S[i] = new Triangle(rand()%11+5, rand()%11+5, color[rand()%6]);
				break;
			default:
				cout << "Constructing a Circle object" << endl;
				S[i] = new Circle(rand()%11+5, color[rand()%6]);
		}
	}
	//Print the objects
	for (int i = 0; i < size; i++)
		cout << *(S[i]) << endl;
	//Destruct the objects
	for (int i = 0; i < size; i++)
		delete S[i];
	delete[] S;

	system("Pause");
	return 0;
}