#ifndef LAB2_PARALLELOGRAM_H
#define LAB2_PARALLELOGRAM_H

#include <vector>
#include <cmath>
#include "Shape.h"

class Parallelogram : public Shape {
public:
	// �� ������� �������� � ����
	Parallelogram(std::string color, double angle, double a, double b);
	void applyForAnyPoint(std::function<void(Point&)> const & f) override;
	std::string toString() const override;
	double getA();
	double getB();

protected:
	void onTransformed() override;
	explicit Parallelogram(std::string color);
	std::vector<Point> pts;
	double a; // ������� ��� ����� � �-��
private:
	double b; // ��� ����� �� �����
};
#endif //LAB2_PARALLELOGRAM_H