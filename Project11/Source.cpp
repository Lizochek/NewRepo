#include<iostream>
using namespace std;
int rec2(int n)
{
	if (n==0)
		return 0;
	return n % 10 + rec2(n / 10);
	//sum = n % 10 + (n / 10) % 10 + (n / 10 / 10) % 10 + ... + 0;
}
int main()
{
	int n;
	cin >> n;
	//rec(n);
	cout<<rec2(n);
}