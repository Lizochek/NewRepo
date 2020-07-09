#include<iostream>
#include<exception>

using namespace std;

class Stack {
	struct Node
	{
		Node(int el) :data(el) {}
		Node(int el, Node* node) :data(el), next(node) {}
		Node* next;
		int data;
	};
private:
	Node* _top;
	int _size;
public:
	Stack() :_top(NULL), _size(0) {}
	void push(const int el)
	{

		if (_top != NULL)
		{
			Node* temp = new Node(el, _top);//создаЄм новый нод, инициализируем его переменной el и он указывает на _top(текущий конец стека)
			_top = temp; //новый элемент делаем последним
		}
		else
		{
			_top = new Node(el); //создаЄм новый нод и инициализируем его переменной el	
		}
		_size++;
	}
	void pop()
	{

		if (_top == NULL)
		{
			cout << "Error: Out of range";
			return;
		}

		Node* temp = _top; //сохран€ем последний элемент во временную переменную
		_top = _top->next; //предпоследний(тот,на который указывает последний) элемент делаем последним
		delete temp; //удал€ем последний элемент
		_size--;
	}

	int top()
	{
		if (_top == NULL) cout << "Error: Stack is empty!";

		return _top->data;
	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}
};


int get(Stack st, int  i);

int main()
{
	Stack  st;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cout << get(st, a) << endl;
	}

}
int get(Stack st, int  i)
{
	int s = 0, n;
	Stack st1;
	n = st.size() - i - 1;

	for (int j = 0; j < n; j++)
	{
		st1.push(st.top());
		st.pop();
	}
	s = st.top();
	for (int j = 0; j < n; j++)
	{
		st.push(st1.top());
		st1.pop();
	}
	return s;
}