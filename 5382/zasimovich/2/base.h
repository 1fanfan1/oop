#pragma once

#include "point.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Shape
{   protected:
        Point Centre;
	    Point Vertex[4];
	    string Color; 

    public:
        
        static  int ID;
        int Id;
	    Shape() 
		{   cout << "������� ������ ";
		    Centre=(0,0);Vertex[0]=(1,1);Vertex[1]=(-1,1);Vertex[2]=(-1,-1);Vertex[3]=(1,-1);
			Color="�����";
			Id = ID;
	        ID++;
		}//����������� ������
		void printShape();//����� ����������
	    void move(const double& x,const double& y);//�����������
	    void Mahtab(const double& P);// ��������������
	    void Turn(const double& R);//������� 
        void SetColorFigure(const string &color);//��������� �����
	    string  GetColorFigure();//����� �����
	    bool CommonSide(const Shape& shape2);//�������. ������������, ���������� �� ������� ����� ������ � ������
		//������� ������� ��������� ������,
	    virtual ~Shape() { cout << "������� ������ ";}//���������� ������
};






