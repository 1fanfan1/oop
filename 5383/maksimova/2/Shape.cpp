#include "Shape.h"
#include <utility>


size_t Shape::counter = 0; // ������������� ������������ ����

//�������� ������
std::ostream& operator <<(std::ostream& OS, const Shape& smth)//�������� ������
{
	smth.print(OS);
	return OS;
}
//���������� ����
void Shape::set_color(Color color) {//���������� ����

	this->color = color;

}

//�������� ���� ������
Color Shape::get_color() const { //�������� ����

	return color;

}
//�������� ����
size_t Shape::getId() const
{
	return id;
}

//�����������
void Shape::move(Dot &new_v0) {
	double dx = corners[0].x - new_v0.x;
	double dy = corners[0].y - new_v0.y;
	for (int i = 0; i < corners.size(); i++) {
		corners[i].x -= dx;
		corners[i].y -= dy;
	}
}
//����������
void  Shape::scale(double scale) {
	if (scale < 0) {
		throw std::invalid_argument("������� �� ����� ���� �������������");
	}
	for (int i = 0; i < corners.size(); i++) {
		corners[i].x *= scale;
		corners[i].y *= scale;
	}
}
//��������� ������
void Shape::rotate(double new_angle) {
	Dot old_v0 = corners[0];
	move(Dot(0, 0));

	for (int i = 0; i < corners.size(); i++) {
		corners[i].rotate(new_angle);
	}
	move(old_v0);
}

//������������ ������� 
//�������� �� ������ �����
bool Shape::common_side(Shape* other) {

	//std::vector<Dot>common_dots; // ����� �����
	Dot cdot1;
	Dot cdot2;
	int dots = 0;
	//std::vector<Dot>old_this_corners = this->corners; // ������ �������
	//std::vector<Dot>old_other_corners = other->corners;

	bool flag1 = false;
	bool flag2 = false;

	for (int i = 0; i < this->corners.size(); i++) {
		for (int j = 0; j < other->corners.size(); j++)
		{
			//������� ����� �����
			if (this->corners[i] == other->corners[j]) {
				if (dots == 0) {
					cdot1 = corners[i];
					++dots;
				}
				else if (dots == 1) {
					cdot2 = corners[i];
					++dots;
				}
			}
		}
	}
	if (dots != 2) {
		return false; // ���� �� �����, �� ������� �� ������������
	}

	for (int i = 0; i < other->corners.size(); i++) {
		if ((corners[i] == cdot1 && corners[(i + 1) % corners.size()] == cdot2) ||
			(corners[i] == cdot2 && corners[(i + 1) % corners.size()] == cdot1)) {
			flag1 = true;
		}
	}

	for (int i = 0; i < other->corners.size(); i++) {
		if ((other->corners[i] == cdot1 && other->corners[(i + 1) % corners.size()] == cdot2) ||
			(other->corners[i] == cdot2 && other->corners[(i + 1) % corners.size()] == cdot1)) {
			flag2 = true;
		}
	}

	return (flag1 && flag2);

	//Dot base = min_y(common_dots[0], common_dots[1]) = Dot(0, 0); // ������ �����
	//double dx = 0 - base.x; // ������������ � � ������ ���������
	//double dy = 0 - base.y;
	//for (int i = 0; i < this->corners.size(); i++) {
	//	this->corners[i].x += dx; // ����� �� ��� �������� ������� ������
	//	this->corners[i].y += dy;
	//}
	//for (int i = 0; i < other->corners.size(); i++) {
	//	other->corners[i].x += dx;// � ������ � ������� ����������
	//	other->corners[i].y += dy;
	//}
	//base = max_y(common_dots[0], common_dots[1]);
	//base.x += dx;
	//base.y += dy;
	//rotate(atan(base.x / base.y)); // �������� ���� ��� ������� ����� � ������������ ���������

	////���������� ��������� ������������ ��� �����
	//for (int i = 0; i < this->corners.size(); i++) { // ���� ������
	//	if (this->corners[i].x > 0) {
	//		flag1 = true;
	//	}
	//	else {
	//		flag1 = false;
	//		break;
	//	}
	//}
	//for (int i = 0; i < other->corners.size(); i++) { // �� � ������� ����������
	//	if (other->corners[i].x > 0) {
	//		flag2 = true;
	//	}
	//	else {
	//		flag2 = false;
	//		break;
	//	}
	//}

	//this->corners = old_this_corners;
	//other->corners = old_other_corners;

	//if (flag1 != flag2) {
	//	return true;
	//}
	//else {
	//	return false;
	//}
}
Dot& Shape::min_y(Dot& a, Dot& b) const {
	if (a.y < b.y) {
		return a;
	}
	else {
		return b;
	}
}
Dot& Shape::max_y(Dot& a, Dot& b) const {
	if (a.y > b.y) {
		return a;
	}
	else {
		return b;
	}
}