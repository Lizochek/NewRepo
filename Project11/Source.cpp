#include<iostream>
#include<exception>

using namespace std;

template <typename T>
class Stack {
public:
	Stack() : _top(NULL), _size(0) {}

	struct Node
	{
		Node(T el) :data(el) {}
		Node(T el, Node* node) :data(el), next(node) {}
		Node* next;
		T data;
	};

	void push(const T);
	void pop();
	T& top();
	int size();
	bool empty();

private:
	Node* _top;
	int _size;
};
template <typename T>
void Stack<T>::push(const T el)
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
template <typename T>
void Stack<T>::pop()
{

	if (_top == NULL) cout << "Error: Out of range";

	Node* temp = _top; //сохран€ем последний элемент во временную переменную
	_top = _top->next; //предпоследний(тот,на который указывает последний) элемент делаем последним
	delete temp; //удал€ем последний элемент
	_size--;
}
template <typename T>
T& Stack<T>::top()
{
	if (_top == NULL) cout << "Error: Stack is empty!";

	return _top->data;

}
template <typename T>
int Stack<T>::size()
{
	return _size;
}
template <typename T>
bool Stack<T>::empty()
{
	return _size == 0 ? true : false;
}

int get(Stack <int> st, int  i);
int main()
{
	Stack<int> st;
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
int get(Stack <int> st, int  i)
{
	int s = 0, n;
	Stack <int> st1;
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

	}
	return s;
}
