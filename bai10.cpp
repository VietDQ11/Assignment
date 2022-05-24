#include<iostream>
using namespace std;

class String
{
public:
	char* str;
	//String();
	friend String operator + (const String&, const String&);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
};
String operator+ (const String&str1, const String&str2)
{
   int i,j;
   String str_sum =str1;
   for(i=0; str_sum.str[i]!='\0'; ++i); 
   for(j=0; str2.str[j]!='\0'; ++j, ++i)
   {
      str_sum.str[i]=str2.str[j];
   }
   str_sum.str[i]='\0';
   cout<<"Kết quả là: "<<str_sum.str;
}
istream& operator >> (istream& is, String& obj)
{
	obj.str = new char[100];
	is >> obj.str;
	return is;
}
ostream& operator << (ostream& os,String& obj)
{
    os << obj.str;
    return os;
}

int main() {
	String str1,str2,str;
	cout<<"Nhập vào chuỗi thứ nhất: ";		
	cin>>str1;
	cout<<"Nhập vào chuỗi thứ hai: ";
	cin>>str2;
	
	cout << "\nResult: ";
	str = str1 + str2;
	cout << str;
	
	return 0;
}