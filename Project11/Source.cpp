#include<iostream>
using namespace std;
int rec2(int n)
{
	static int r = 0;
	if (n==0) return r;
	r = r*10+(n % 10);
	return rec2(n/10);
	
}
int main()
{
	int n;
	cin >> n;
	cout << rec2(n);
}