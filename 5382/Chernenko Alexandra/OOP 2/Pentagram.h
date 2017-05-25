#include "stdafx.h"
#include "Shape.h"
class Pentagram : public Shape {
private:
	double  Side;
	Pentagram(const Pentagram&);
	void Pentagram::operator=(const Pentagram&);
public:
	Pentagram(double, double, double, double, int, string);
	Pentagram(double);
	void init();
	friend ostream&operator<<(ostream&a, const Pentagram*b){
		a << "ID ������: id=" << b->getId() << "\n";
		a << "����� ������: x=" << b->getX() << "; y=" << b->getY() << "\n";
		a << "����: " << b->getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b->getAngle() << "\n";
		a << "�������: ������=" << b->getScale() << "\n";
		a << "����� ������ � ������ �������: ������� �����������=" << b->Side*b->getScale() << "\n";
		b->outPoint(a,5);
		return a;
	}
	friend ostream&operator<<(ostream&a, const Pentagram&b) {
		a << "ID ������: id=" << b.getId() << "\n";
		a << "����� ������: x=" << b.getX() << "; y=" << b.getY() << "\n";
		a << "����: " << b.getColorFigure() << "\n";
		a << "���� �������� ������: ��=" << b.getAngle() << "\n";
		a << "�������: ������=" << b.getScale() << "\n";
		a << "����� ������ � ������ �������: ������� �����������=" << b.Side*b.getScale() << "\n";
		b.outPoint(a,5);
		return a;
	}
	~Pentagram();
};
