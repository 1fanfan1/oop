#include "stdafx.h"
#include "Shape.h"
class Pentagon : public Shape {
private:
	double  Side;
	Pentagon(const Pentagon&);
	void Pentagon::operator=(const Pentagon&);
public:
	Pentagon(double, double, double, double, int, string);
	Pentagon(double);
	void init();
	friend ostream&operator<<(ostream&a, const Pentagon*b){
		a << "ID ������: id=" << b->getId() << "\n";
		a << "����� ������: x=" << b->getX() << "; y=" << b->getY() << "\n";
		a << "����: " << b->getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b->getAngle() << "\n";
		a << "�������: ������=" << b->getScale() << "\n";
		a << "����� ������ � ������ �������: ������� �������������=" << b->Side*b->getScale() << "\n";
		b->outPoint(a,5);
		return a;
	}
	friend ostream&operator<<(ostream&a, const Pentagon&b) {
		a << "ID ������: id=" << b.getId() << "\n";
		a << "����� ������: x=" << b.getX() << "; y=" << b.getY() << "\n";
		a << "����: " << b.getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b.getAngle() << "\n";
		a << "�������: ������=" << b.getScale() << "\n";
		a << "����� ������ � ������ �������: ������� �������������=" << b.Side*b.getScale() << "\n";
		b.outPoint(a,5);
		return a;
	}
	~Pentagon();
};
