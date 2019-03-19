#include "Shape.h"

class Rectangle : public Shape {

private:

	double length;
	double width;

public:

	Rectangle(double _length, double _width, point _centre) : Shape(_centre) {

		length = _length;
		width = _width;
		make_coordinates();
	}

	void scale(double coefficient) {

		length = length * coefficient;
		width = width * coefficient;
		make_coordinates();
	}

	~Rectangle() {

		coordinates.clear();
	}


private:

	void make_coordinates() {

		coordinates.clear();
		coordinates.push_back({ centre.x - length / 2, centre.y + width / 2 });
		coordinates.push_back({ centre.x + length / 2, centre.y + width / 2 });
		coordinates.push_back({ centre.x + length / 2, centre.y - width / 2 });
		coordinates.push_back({ centre.x - length / 2, centre.y - width / 2 });

		rotate(ang);
	}

	void print(ostream& out) {

		out << "�������������" << endl;
		out << "Id: " << id << endl;
		out << "���������� ������� �����: ";

		for (unsigned int i = 0; i < coordinates.size(); ++i) {

			out << "(" << coordinates[i].x << ", " << coordinates[i].y << ") ";
		}

		out << endl << "����: ";

		switch (clr) {

		case RED:
			out << "�������" << endl;
			break;
		case ORANGE:
			out << "���������" << endl;
			break;
		case GREEN:
			out << "�������" << endl;
			break;
		case BLUE:
			out << "�������" << endl;
			break;
		case YELLOW:
			out << "������" << endl;
			break;
		case NO_COLOR:
			out << "�� ���������" << endl;
			break;
		}
	}

};