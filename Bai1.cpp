#include<stdio.h>
#include <iostream>
using namespace std;
 
int main()
{
    int n,r,sum=0,temp;
 
    cout << "Nhap so: ";
     cin >> n;
 
    for(temp=n;n!=0;n=n/10)
    {
         r=n%10;
         sum=sum*10+r;
    }
    if(temp==sum)
         cout << temp << " la so doi xung ";
    else
         cout << temp << " khong phai so doi xung ";
 
    return 0;
}