#include "bai11.h"
CRectangle::CRectangle(int input_width, int input_height)
{
    width = input_width;
    height = input_height;
}
CLine::CLine(int input_length)
{
    length = input_length;
}
CCircle::CCircle(int input_radium)
{
    radium = input_radium;
}
void CRectangle::draw(int x, int y) {
    HPEN hPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
    SelectObject(device_context, hPen);
    Rectangle(device_context, x, y, x + width, y + height);
    ReleaseDC(console_handle, device_context);
}
void CLine::draw(int x, int y)
{
    HPEN hPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
    SelectObject(device_context, hPen);
    LineTo(device_context, x + length, y);
}
void CCircle::draw(int x, int y)
{
    HPEN hPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
    SelectObject(device_context, hPen);
    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}
int main() {
    int x;
    int y;
    cout << "Nhap vao toa do hinh ve x va y:" << endl;
    cin >> x;
    cin >> y;
    CRectangle cRectangle(30, 60);
    CLine cLine(50);
    CCircle cCircle(100);
    cRectangle.draw(x, y);
    cLine.draw(x, y);
    cCircle.draw(x, y);
}