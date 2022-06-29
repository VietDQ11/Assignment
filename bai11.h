#pragma once
#include<iostream>
#include <Windows.h>
using namespace std;
class CShape {
private:
    int color;
public:
    virtual void draw(int x, int y) = 0;
};
class CRectangle : public CShape {
public:
    int width, height;
public:
    void draw(int x, int y);
    CRectangle(int input_width, int input_height);
};
class CLine : public CShape
{
private:
    int length;
public:
    void draw(int x, int y);
    CLine(int length);
};
class CCircle : public CShape
{
private:
    int radium;
public:
    void draw(int x, int y);



    CCircle(int radium);
};