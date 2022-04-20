/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

// Hàm kiểm tra năm nhuận
bool LaNamNhuan(int Nam);

// Hàm trả về số ngày trong tháng thuộc năm cho trước
int TinhSoNgayTrongThang(int Thang, int Nam);

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool LaNgayHopLe(int Ngay, int Thang, int Nam);

// Hàm tìm ngày hôm trước của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void TimNgayHomTruoc(int& Ngay, int& Thang, int& Nam);

// Hàm tìm ngày hôm sau của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void TimNgayHomSau(int& Ngay, int& Thang, int& Nam);

int main()
{
	int Ngay, Thang, Nam;
	cout << "Day: ";
	cin >> Ngay;

	cout << "Month: ";
	cin >> Thang;

	cout << "Year: ";
	cin >> Nam;

	if (LaNgayHopLe(Ngay, Thang, Nam))
	{
		int tmpDay = Ngay;
		int tmpMonth = Thang;
		int tmpYear = Nam;

		TimNgayHomTruoc(tmpDay, tmpMonth, tmpYear);
		cout << "Yesterday: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;

		tmpDay = Ngay;
		tmpMonth = Thang;
		tmpYear = Nam;

		TimNgayHomSau(tmpDay, tmpMonth, tmpYear);
		cout << "Tomorrow: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;
	}
	else
	{
		cout << "Ngay khong hop le." << endl;
	}
	return 0;
}

bool LaNamNhuan(int Nam)
{
	if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
	{
		return true;
	}
	return false;
}

int TinhSoNgayTrongThang(int Thang, int Nam)
{
	int nNumOfDays;

	switch (Thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		nNumOfDays = 31;
		break;

	case 4: case 6: case 9: case 11:
		nNumOfDays = 30;
		break;

	case 2:
		if (LaNamNhuan(Nam))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}
	return nNumOfDays;
}

bool LaNgayHopLe(int Ngay, int Thang, int Nam)
{
	bool bResult = true;

	if (!(Nam > 0 && Thang))
	{
		bResult = false;
	}

	if (!(Thang >= 1 && Thang <= 12))
	{
		bResult = false;
	}

	if (!(Ngay >= 1 && Ngay <= TinhSoNgayTrongThang(Thang, Nam)))
	{
		bResult = false;
	}
	return bResult;
}

void TimNgayHomTruoc(int& Ngay, int& Thang, int& Nam)
{
	Ngay--;
	if (Ngay == 0)
	{
		Thang--;
		if (Thang == 0)
		{
			Thang = 12;
			Nam--;
		}

		Ngay = TinhSoNgayTrongThang(Thang, Nam);
	}
}

void TimNgayHomSau(int& Ngay, int& Thang, int& Nam)
{
	Ngay++;
	if (Ngay > TinhSoNgayTrongThang(Thang, Nam))
	{
		Ngay = 1;
		Thang++;
		if (Thang > 12)
		{
			Thang = 1;
			Nam++;
		}
	}
}