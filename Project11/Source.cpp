#include<iostream>
using namespace std;
void rec2(int b,int a)
{
	cout << a << " ";
	if (a==b) return;
	rec2(b,(a>b?a-1:a+1));
}
int main()
{
	int b,a;
	cin >> a>>b;
	//rec(n);
	rec2(b,a);
}