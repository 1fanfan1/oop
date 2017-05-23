#pragma once
#include <iostream>
#include "Dot.h"
#include <vector>

struct Color {
	unsigned char R, G, B;
	Color(unsigned char _R = 0, unsigned char _G = 0, unsigned char _B = 0) : R(_R), G(_G), B(_B) {}
};

class Shape {
protected:
	std::vector<Dot> corners; //�.� ��� ������ ����������������
	double angle;// ����

	static size_t counter;// ���-�� �����
	size_t id;//���� ������ ������

	Color color;//����
	

	virtual void print(std::ostream& OS) const = 0; // �����

public:
	Shape(std::vector<Dot> points, Color color, double angle) :
		id(counter++), angle(angle), color(color), corners(points) {} //������������

	virtual ~Shape() {}//����������

	void move(Dot &new_center);//�����������
	void scale(double scale );//����������
	void rotate(double new_angle);//���������

	Color get_color() const; //�������� ����
	void set_color(Color color);//���������� ����
	Dot get_center();//�������� ����
	size_t getId() const;//�������� ����
	Dot& min_y(Dot& a, Dot& b) const;
	Dot& max_y(Dot& a, Dot& b) const;
	friend std::ostream& operator << (std::ostream& OS, const Shape& smth); // �������� ������

	//�������
	bool common_side( Shape* other);

};

template <typename T>
bool float_comparison(T f1, T f2) {
	return (fabs(f1 - f2) <= std::numeric_limits<T>::epsilon());
}