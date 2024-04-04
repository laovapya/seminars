#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


class Shape {
protected:
	double x, y;

public:
	//Shape() {}
	Shape(double x, double y) : x(x), y(y) {}
	virtual double area() const = 0;
	//virtual ~Shape() {}
};
class Circle : public Shape {
private:
	double radius;
	const double Pi = 3.14;
public:
	Circle(double x, double y, double radius) :Shape(x, y) {
		this->radius = radius;
	}
	//~Circle();
	double area() const override {
		return Pi * radius * radius;
	}
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle(double x, double y, double width, double height) : Shape(x, y) {
		this->width = width;
		this->height = height;
	}
	//~Rectangle();
	double area() const override {
		return width * height;
	}
};

vector<Shape*> V;
int main() {
	Circle c = Circle(0, 0, 5);
	cout << "area " << c.area() << endl;
	Rectangle r = Rectangle(0, 0, 10, 2);
	cout << r.area();
	V.push_back(&c);
	V.push_back(&r);
	for (Shape* s : V) {
		s->area();
	}

	return 0;
}