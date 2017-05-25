#pragma once
#include "stdafx.h"
#include "string"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Point.h"
#include <iostream>
#include <vector>
using namespace std;
class Shape{
private:
	double koeff = M_PI/180;
	double X = 0;
	double Y = 0;//����� ������
	int Angle = 0; //���� ��������
	double Scale = 1; // ����������� �������
	string Color = "�����";//���� ������
	int Id; //������������� �������
	Point *Tops;
	int type;
public:
	static  int ID;  
	virtual ~Shape();
	void setAngle(int);
	int getAngle()const;
	void setScale(double);
	double getScale()const;
	void setId(int);
	int getId()const;
	double getX()const;
	double getY()const;
	void setType(int);
	int getType()const;
	double getKoeff()const;
	void setPoints(Point*);
	Point* getPoints()const;
	void MoveFigure(double, double); //����������
	void TurnFigure(int); //�������
	void ScaleFigure(double); //�������
	string getColorFigure()const;  //�������� ����
	void setColorFigure(string); //������ ����
	bool hasCommonSide(const Shape&);
	friend ostream&operator<<(ostream&, const Shape&); //����� ������
	friend ostream&operator<<(ostream&, const Shape*); //����� ������
	void outPoint(ostream&,int)const;
	virtual void init()=0;
	
};
