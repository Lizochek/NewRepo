#include<iostream>
using namespace std;
void rec2(int n)
{
	if (n==0)
		return ;
	rec2(n / 10);
	cout<< n % 10<<" ";
		
	//sum = n % 10 + (n / 10) % 10 + (n / 10 / 10) % 10 + ... + 0;
}
int main()
{
	int n;
	cin >> n;
	//rec(n);
	rec2(n);
}