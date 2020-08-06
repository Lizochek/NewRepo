#include"Source.cpp"
#include<iostream>
using namespace std;
int main()
{
	List <int> polka;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int type,number;
		cin >> type;
		switch (type)
		{
		case 1: 
			cin >> number;
			polka.push_top(number);
			break;
		case 2:
			cin >> number;
			polka.push_back(number);
			break;
		case 3:
			cout << polka.top()<<" " ;
			polka.pop_front();
			break;
		case 4:
			cout << polka.get(polka.size() - 1)<<" ";
			polka.pop(); 
			break;
		}
		
	}

}