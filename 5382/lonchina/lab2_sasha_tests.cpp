#include "gtest\gtest.h"
#include "shapes.h"

// �������������� ������ �����
vector<Shape*> v;

// �������������� ������� ������ �� �����
RectangleFactory* rectangle_factory = new RectangleFactory;
CircleFactory*  circle_factory = new CircleFactory;
TrapeziumFactory*  trapezium_factory = new TrapeziumFactory;

//��������� ������� ������ �� ����� � �������������� ������� EXPECT_EQ

TEST(lab2, Rectangle){
	v.push_back(rectangle_factory->createShape());
	v[0]->setColor("red");
	EXPECT_EQ(v[0]->getColor(), "red");
}

TEST(lab2, Circle){
	v.push_back(circle_factory->createShape());
	v[1]->setColor("yellow");
	EXPECT_EQ(v[1]->getColor(), "yellow");
}

TEST(lab2, Trapezium){
	v.push_back(trapezium_factory->createShape());
	v[2]->setColor("green");
	EXPECT_EQ(v[2]->getColor(), "green");
}

TEST(lab2, compare_test){//��������� ��������
	EXPECT_EQ(Shape::compare(*v[0], *v[1]), "areas are equal");
}