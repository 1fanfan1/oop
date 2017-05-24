#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// ���������� �����
struct point
{
	double x;
	double y;
};

// ��������� ����������� ��� � createShape
// vector<point> & coord ������ ��������� ������
// point & center ���������� ������
// int dots ���������� �����
// string figure �������� ������
void create(vector<point> & coord, point & center, int dots, string figure)
{
	point temp;
	//cout<< "Input " << dots << " coords of " << figure << " (x, y): " << endl;
	// ������ ���������� ������
	for (int i = 0; i < dots; ++i) {
		//cin >> temp.x;
		//cin >> temp.y;
		coord.push_back(temp);
	}
	//cout<< "Inpute coords of center (x, y): " << endl;
	// ������ ���������� ������
	//cin >> center.x;
	//cin >> center.y;
}

class Shape
{
private:
	string color = "";
protected:
	int area = 0;
public:
	//void setColor(string);
	//string getColor();

	// ������ ����������� ������ �� ������, ��������, ��������������
	// � ������ ��������������, �� � ����������
	virtual void moveTo() = 0;
	virtual void rotateOn(double) = 0;
	virtual void scaleOn(double) = 0;
	virtual void draw() = 0;
	virtual ~Shape() {}

// ���������� ���� ������
void Shape::setColor(string color)
{
	this->color = color;
}

// �������� ���� ������
string Shape::getColor()
{
	return this->color;
}

bool operator==(const Shape &rhs) const {
	return area == rhs.area;
}

bool operator!=(const Shape &rhs) const {
	return !(rhs == *this);
}

bool operator<(const Shape &rhs) const {
	return area < rhs.area;
}

bool operator>(const Shape &rhs) const {
	return rhs < *this;
}

bool operator<=(const Shape &rhs) const {
	return !(rhs < *this);
}

bool operator>=(const Shape &rhs) const {
	return !(*this < rhs);
}

static string compare(const Shape &left, const Shape &right) {//��� �������� ������� (���)
	string answer = ""; //������������ ��������� ����� �� �������
	if (left == right) {
		answer = "areas are equal";
	}
	else if (left > right) {
		answer = "first area more then second";
	}
	else {
		answer = "second area more then first";
	}

	return answer;
}

};

class Rectangle : public Shape
{
private:
	vector<point> coord;
	point center;
public:
	// ����������� ������������
	Rectangle(vector<point> & coord, point & center)
	{
		for (int i = 0; coord.size() && i < coord.size(); ++i) {
			this->coord.push_back(coord[i]);
		}
		this->center.x = center.x;
		this->center.y = center.y;
	}
	// ����� ������������
	void draw() {
		//cout<< "Info about rectangle:\n";
		for (int i = 0; i < this->coord.size(); ++i) {
			//cout<< this->coord[i].x << " : " << this->coord[i].y << "\n";
		}
		//cout<< "center x: " << this->center.x << ", y: " << this->center.y << "\n";
	}
	// ����� ������������
	void moveTo() {
		this->coord.clear();
		point temp;
		//cout<< "Input 3 coords of rectangle (x, y): " << endl;
		for (int i = 0; i < 3; ++i) {
			//cin >> temp.x;
			//cin >> temp.y;
			this->coord.push_back(temp);
		}
		//cin >> this->center.x;
		//cin >> this->center.y;
	}
	// ������� ������������
	void rotateOn(double angle) {
		double x_help = this->center.x;
		double y_help = this->center.y;
		this->center.x = (x_help * cos(angle)) - (y_help * sin(angle));
		this->center.y = (x_help * sin(angle)) + (y_help * cos(angle));
		for (int i = 0; i < this->coord.size(); ++i) {
			x_help = this->coord[i].x;
			y_help = this->coord[i].y;
			this->coord[i].x = (x_help * cos(angle)) - (y_help * sin(angle));
			this->coord[i].y = (x_help * sin(angle)) + (y_help * cos(angle));
		}
	}
	// ��������������� ������������
	void scaleOn(double coef) {
		for (int i = 0; i < this->coord.size(); ++i) {
			this->coord[i].x *= coef;
			this->coord[i].y *= coef;
		}
		this->center.x *= coef;
		this->center.y *= coef;
	}

	void calculateArea() {//�������
		double sides[3] = { 0 };
		double semiPerimetr = 0;

		// ������� ����� ���� ������
		sides[0] = sqrt(pow(this->coord[0].x - this->coord[1].x, 2.0) +
			pow(this->coord[0].y - this->coord[1].y, 2.0));
		sides[1] = sqrt(pow(this->coord[0].x - this->coord[2].x, 2.0) +
			pow(this->coord[0].y - this->coord[2].y, 2.0));
		sides[2] = sqrt(pow(this->coord[1].x - this->coord[2].x, 2.0) +
			pow(this->coord[1].y - this->coord[2].y, 2.0));

		// ���������� ������������
		for (int i = 0; i < this->coord.size(); ++i) {
			semiPerimetr += sides[i];
		}
		semiPerimetr /= 2;
		//std::cout << "semiper = " << semiPerimetr << std::endl;

		// ������� ������� ����� ������� � ������������
		this->area = sqrt(semiPerimetr * (semiPerimetr - sides[0]) *(semiPerimetr - sides[1]) * (semiPerimetr - sides[2]));
	}
};

class Circle : public Shape
{
private:
	vector<point> coord;
	point center;
public:
	// ����������� �����
	Circle(vector<point> & coord, point & center)
	{
		for (int i = 0; coord.size() && i < coord.size(); ++i) {
			this->coord.push_back(coord[i]);
		}
		this->center.x = center.x;
		this->center.y = center.y;
	}
	// ����� �����
	void draw() {
		//cout<< "Info about circle:\n";
		for (int i = 0; i < this->coord.size(); ++i) {
			//cout<< this->coord[i].x << " : " << this->coord[i].y << "\n";
		}
		//cout<< "center x: " << this->center.x << ", y: " << this->center.y << "\n";
	}
	// ����� �����
	void moveTo() {
		this->coord.clear();
		point temp;
		//cout<< "Input 2 coords of rectangle (x, y): " << endl;
		for (int i = 0; i < 2; ++i) {
			//cin >> temp.x;
			//cin >> temp.y;
			this->coord.push_back(temp);
		}
		//cin >> this->center.x;
		//cin >> this->center.y;
	}
	// ������� �����
	void rotateOn(double angle) {
		double x_help = this->center.x;
		double y_help = this->center.y;
		this->center.x = (x_help * cos(angle)) - (y_help * sin(angle));
		this->center.y = (x_help * sin(angle)) + (y_help * cos(angle));
		for (int i = 0; i < this->coord.size(); ++i) {
			x_help = this->coord[i].x;
			y_help = this->coord[i].y;
			this->coord[i].x = (x_help * cos(angle)) - (y_help * sin(angle));
			this->coord[i].y = (x_help * sin(angle)) + (y_help * cos(angle));
		}
	}
	// ��������������� �����
	void scaleOn(double coef) {
		for (int i = 0; i < this->coord.size(); ++i) {
			this->coord[i].x *= coef;
			this->coord[i].y *= coef;
		}
		this->center.x *= coef;
		this->center.y *= coef;
	}

	void calculateArea() {//�������
		// ������� ���������, ��� ��� ���� ��� ����� �������� ������ �� ���
		double diagonal = sqrt(pow(this->coord[0].x - this->coord[1].x, 2.0) +
			pow(this->coord[0].y - this->coord[1].y, 2.0));

		//std::cout << "diagonal = " << diagonal << std::endl;
		//std::cout << "PI = " << M_PI << std::endl;
		// � �� �������� ������� ������� �������
		this->area = pow((diagonal / 2), 2.0) * 3.1415;
	}
};

class Trapezium : public Shape
{
private:
	vector<point> coord;
	point center;
public:
	// ����������� ��������
	Trapezium(vector<point> & coord, point & center)
	{
		for (int i = 0; coord.size() && i < coord.size(); ++i) {
			this->coord.push_back(coord[i]);
		}
		this->center.x = center.x;
		this->center.y = center.y;
	}
	// ����� ��������
	void draw() {
		//cout<< "Info about trapezium:\n";
		for (int i = 0; i < this->coord.size(); ++i) {
			//cout<< this->coord[i].x << " : " << this->coord[i].y << "\n";
		}
		//cout<< "center x: " << this->center.x << ", y: " << this->center.y << "\n";
	}
	// ����� ��������
	void moveTo() {
		this->coord.clear();
		point temp;
		//cout<< "Input 4 coords of rectangle (x, y): " << endl;
		for (int i = 0; i < 4; ++i) {
			//cin >> temp.x;
			//cin >> temp.y;
			this->coord.push_back(temp);
		}
		//cin >> this->center.x;
		//cin >> this->center.y;
	}
	// ������� ��������
	void rotateOn(double angle) {
		double x_help = this->center.x;
		double y_help = this->center.y;
		this->center.x = (x_help * cos(angle)) - (y_help * sin(angle));
		this->center.y = (x_help * sin(angle)) + (y_help * cos(angle));
		for (int i = 0; i < this->coord.size(); ++i) {
			x_help = this->coord[i].x;
			y_help = this->coord[i].y;
			this->coord[i].x = (x_help * cos(angle)) - (y_help * sin(angle));
			this->coord[i].y = (x_help * sin(angle)) + (y_help * cos(angle));
		}
	}
	// ��������������� ��������
	void scaleOn(double coef) {
		for (int i = 0; i < this->coord.size(); ++i) {
			this->coord[i].x *= coef;
			this->coord[i].y *= coef;
		}
		this->center.x *= coef;
		this->center.y *= coef;
	}

	void Trapezium::calculateArea() {//�������
		std::vector<double> sides;
		double semiPerimetr = 0;
		std::vector<double> x;
		std::vector<double> y;
		double a = 0, b = 0, c = 0, d = 0;

		// ���������� ���� ������
		sides.push_back(sqrt(pow(this->coord[0].x - this->coord[1].x, 2.0) +
			pow(this->coord[0].y - this->coord[1].y, 2.0)));
		sides.push_back(sqrt(pow(this->coord[0].x - this->coord[2].x, 2.0) +
			pow(this->coord[0].y - this->coord[2].y, 2.0)));
		sides.push_back(sqrt(pow(this->coord[0].x - this->coord[3].x, 2.0) +
			pow(this->coord[0].y - this->coord[3].y, 2.0)));

		sides.push_back(sqrt(pow(this->coord[1].x - this->coord[2].x, 2.0) +
			pow(this->coord[1].y - this->coord[2].y, 2.0)));
		sides.push_back(sqrt(pow(this->coord[1].x - this->coord[3].x, 2.0) +
			pow(this->coord[1].y - this->coord[3].y, 2.0)));

		sides.push_back(sqrt(pow(this->coord[2].x - this->coord[3].x, 2.0) +
			pow(this->coord[2].y - this->coord[3].y, 2.0)));

		// ������� �������� ����� ��� ������ �������
		x.push_back(abs(this->coord[0].x - this->coord[1].x));
		x.push_back(abs(this->coord[0].x - this->coord[2].x));
		x.push_back(abs(this->coord[0].x - this->coord[3].x));

		x.push_back(abs(this->coord[1].x - this->coord[2].x));
		x.push_back(abs(this->coord[1].x - this->coord[3].x));

		x.push_back(abs(this->coord[2].x - this->coord[3].x));

		// ������� �������� ������� ��� ������ �������
		y.push_back(abs(this->coord[0].y - this->coord[1].y));
		y.push_back(abs(this->coord[0].y - this->coord[2].y));
		y.push_back(abs(this->coord[0].y - this->coord[3].y));

		y.push_back(abs(this->coord[1].y - this->coord[2].y));
		y.push_back(abs(this->coord[1].y - this->coord[3].y));

		y.push_back(abs(this->coord[2].y - this->coord[3].y));

		// ������� ���������
		// (� ��� � ��������������� ����� ���� ����� �������� � ����� ����� ���������)
		for (int i = 0; i < sides.size(); ++i) {
			for (int j = 0; j < sides.size(); ++j) {
				if (i != j && (x[i] == x[j] || y[i] == y[j])) {
					a = std::max(sides[i], sides[j]);
					b = std::min(sides[i], sides[j]);
				}
			}
		}

		// ���������
		std::sort(sides.begin(), sides.end(), [](double &a, double &b) {
			return a < b;
		});

		// ������� ���������
		sides.erase(sides.end() - 2, sides.end());

		// ������� ���������
		sides.erase(std::remove_if(
			sides.begin(), sides.end(), [&](double side) {
			return side != a && side != b;
		}));

		// ����������� ������� �������
		c = sides[0];
		d = sides[1];

		semiPerimetr = (a + b + c + d) / 2;

		//std::cout << a << ", " << b << ", " << c << ", " << d << std::endl;
		//std::cout << semiPerimetr << " = semiPer" << std::endl;

		this->area = (a + b) * sqrt((semiPerimetr - a)
			* (semiPerimetr - b)
			* (semiPerimetr - a - c)
			* (semiPerimetr - a - d))
			/ abs(a - b);
	}
};

// ������� ��������
class Factory
{
public:
	virtual Shape* createShape() = 0;
	virtual ~Factory() {}
};

// ������� ������� �������������
class RectangleFactory : public Factory
{
public:
	Shape* createShape() {
		vector<point> coord;
		point center;
		create(coord, center, 3, "rectangle");
		return new Rectangle(coord, center);
	}
};

// ������� ������� ������
class CircleFactory : public Factory
{
public:
	Shape* createShape() {
		vector<point> coord;
		point center;
		create(coord, center, 2, "circle");
		return new Circle(coord, center);
	}
};

// ������� ������� ��������
class TrapeziumFactory : public Factory
{
public:
	Shape* createShape() {
		vector<point> coord;
		point center;
		create(coord, center, 4, "trapezium");
		return new Trapezium(coord, center);
	}
};