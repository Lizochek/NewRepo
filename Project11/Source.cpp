#include<iostream>
using namespace std;
void rec(int n)
{
	if (n < 1) return;
	cout << n << " ";
	rec(n-1);
	 
}

int main()
{
	int n;
	cin >> n;
	rec(n);
}