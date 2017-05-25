#include "stdafx.h"
#include "Shape.h"
class Rectangle : public Shape {
private:
	double SideX, SideY;
	Rectangle(const Rectangle&);
	void Rectangle::operator=(const Rectangle&);
	double startAngle;
public:
	Rectangle(double, double, double, double, double, int, string);
	Rectangle(double, double);
	void init();
	friend ostream&operator<<(ostream&a, const Rectangle&b){
		a << "ID ������: id=" << b.getId() << "\n";
		a << "����� ������: x=" << b.getX() << "; y=" << b.getY() << "\n";
		a << "����: " << b.getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b.getAngle() << "\n";
		a << "�������: ������=" << b.getScale() << "\n";
		a << "����� ������ � ������ �������: �������������� �������=" << b.SideX*b.getScale() << " ������������ ������� = " << b.SideY*b.getScale() << "\n";
		b.outPoint(a,4);
		return a;
	}
	friend ostream&operator<<(ostream&a, const Rectangle*b) {
		a << "ID ������: id=" << b->getId() << "\n";
		a << "����� ������: x=" << b->getX() << "; y=" << b->getY() << "\n";
		a << "����: " << b->getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b->getAngle() << "\n";
		a << "�������: ������=" << b->getScale() << "\n";
		a << "����� ������ � ������ �������: �������������� �������=" << b->SideX*b->getScale() << " ������������ ������� = " << b->SideY*b->getScale() << "\n";
		b->outPoint(a,4);
		return a;
	}
	~Rectangle();
};
