#include<iostream>
using namespace std;
void rec2(string s)
{
	cout << s << endl;
	if (s.size() <= 1 )
	{
		cout << "yes";
		return;
	}
	if (s[0] != s[s.size() - 1])
	{
		cout << "no";
		return;
	}
	rec2(s.substr(1, s.size()-2));
	
		
	//sum = n % 10 + (n / 10) % 10 + (n / 10 / 10) % 10 + ... + 0;
}
int main()
{
	string s;
	cin >> s;
	//rec(n);
	rec2(s);
}