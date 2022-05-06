#include <iostream>

using namespace std;

int *get_even_num(int *arr, int *sz);

int main()
{
    int arr[]{9,8,7,6,5};
    int sz = 0;
    get_even_num(arr, &sz);
    cout << "kich thuoc mang la: " << sz;
}

int *get_even_num(int *arr, int *sz)
{
    int sz_p = *arr;
    arr++;
    for (int i = 0; i < sz_p; i++) 
	{
        if (*arr % 2 == 0) 
		{
            *sz = *sz + 1;
        }
        arr++;
    }
    return 0;
}
