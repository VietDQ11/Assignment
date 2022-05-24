#include <iostream>
using namespace std;
class CFraction
{
public:
    double num;
    double den;
public:
    void nhap()
    {
        cout << "\n nhap tu so :"; cin >> num;
        cout << " nhap mau so :"; cin >> den;
    }
    void xuat()
    {
        cout << " " << num << "/" << den;
    }
    CFraction operator +(CFraction p2)
    {
        CFraction p;
        p.num = num*p2.den + den*p2.num;
        p.den = den*p2.den;
        return p;
    }
    CFraction operator -(CFraction p2)
    {
        CFraction p;
        p.num = num*p2.den - den*p2.num;
        p.den = den*p2.den;
        return p;
    }
    CFraction operator *(CFraction p2)
    {
        CFraction p;
        p.num = num * p2.num;
        p.den = den * p2.den;
        return p;
    }
    CFraction operator / (CFraction p2)
    {
        CFraction p;
        p.num = num * p2.den;
        p.den = den * p2.den;
        return p;
    }
};
int main()
{
    CFraction p, p1, p2;;
    cout << "Nhap vao so thu nhat: "; p1.nhap();
    cout << "\nNhap vao so thu hai: "; p2.nhap();
  cout << "\nTong phan so la:";
    p = p1.operator +(p2); p.xuat();
  cout << "\nHieu phan so la:";
    p = p1.operator -(p2); p.xuat();
  cout << "\nTich phan so la:";
    p = p1.operator *(p2); p.xuat();
  cout << "\nThuong phan so la:";
    p = p1.operator /(p2); p.xuat();
}
