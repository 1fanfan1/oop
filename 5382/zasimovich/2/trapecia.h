#pragma once
#include <string>
#include "base.h"
#include <iostream>
#include <math.h>
using namespace std;

class Trapecia:public Shape
{
	public:
		Trapecia( ){
			 double angle=180;
		     this->Centre = Point(0,0);
			 this->Vertex[0] = Point(1,1);
			 this->Vertex[1] = Point(-1,1);
			 this->Vertex[2] = Point(-1,-1);
			 this->Vertex[3] = Point(1,-1);
		};
		Trapecia(const Point& centre,const Point& vertex1,const Point& vertex2,const Point& vertex3,const Point& vertex4)
		{   if((Distance(vertex2,vertex1))/(Distance(vertex3,vertex4))!=(Distance(centre,vertex1))/(Distance(vertex3,centre))!=
		    (Distance(centre,vertex2))/(Distance(vertex4,centre)))
			throw invalid_argument("������ ��������� � ����� ����������� ������ �������� �� 2 ����� � ����� ������������ �����, ��� ����������� ����� �����������");
			double angle=180;
	        cout << "��������\n";
	        this->Centre = centre;
	        this->Vertex[0] = vertex1;//������� ������ �������
	        this->Vertex[1] = vertex2;//������� �����
	        this->Vertex[0] = vertex3;//������ �����
	        this->Vertex[1] = vertex4;//������ ������
	       
         }

		~Trapecia(){cout << "��������\n";}
   
};

