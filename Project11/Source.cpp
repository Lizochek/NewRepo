#include<iostream>
using namespace std;
template <typename T>
class List {

public: struct Node {
	Node() { this->next = NULL; this->prev = NULL; };
	Node(T value, Node* next, Node* prev)
	{
		this->next = next;
		this->prev = prev;
		this->value = value;
	}
	Node(T value)
	{
		Node(value, NULL, NULL);

	}
	T value;
	Node* next;
	Node* prev;
};
private: Node* head;
	   int _size;

public:
	List();
	List(const List&);
	void print(Node* head);
	void insert(int pos, T val);
	void push_top(T val);
	void push_back(T val);
	void pop_front();
	void pop();
	T top();
	T get(int pos);
	void erase(int pos);
	int size();
	bool empty();
	~List();


};
template <typename T>
List<T>::List()
{
	_size = 0;
	head = NULL;
}
template <typename T>
List<T>::List(const List& k)
{
	/*
	когда вызвается:
	List <int> a;
	List<int> b;
	a = b;
	передаем в фун-цию по значению
	function(a);
	возвращаем из функции по значению
	return a;
	*/
	_size = k._size;

	if (k.head == NULL) return;

	head = new Node(k.head->value);
	Node* source, * copy;
	source = k.head;
	copy = head;
	for (int i = 1; i < k._size; i++)
	{
		source = source->next;
		copy->next = new Node(source->value, NULL, copy);
		copy = copy->next;
	}
	copy->next = head;
	head->prev = copy;
}
template <typename T>
void List<T>::print(Node* head)
{
	if (head == NULL) return;
	Node* temp = head;

	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << "\n";
}
template <typename T>
void List<T>::insert(int pos,T val)
{
	if (pos > _size) {
		cout<<"Error: Out of range";
		return;
	}
	if (pos == 0) push_top(val);
	else if (pos == _size) push_back(val);
	else 
	{
		Node* temp = head;
		for (int i = 0; i < pos-1; ++i)
			temp = temp->next;
		Node* node = new Node(val, temp->next, temp);
		temp->next = node;
		node->next->prev = node;
		_size++;
	}

}
template <typename T>
void List<T>::push_back(T val)
{
	if (head != NULL)
	{
		Node* temp = new Node();
		temp->value = val;
		temp->next = head;
		temp->prev = head->prev;
		head->prev = temp;
		temp->prev->next = temp;

	}
	else //Если список пустой
	{

		head = new Node();
		head->value = val;
		head->prev = head;
		head->next = head;
	}
	_size++;
}
template <typename T>
void List<T>::push_top(T val)
{
	push_back(val);
	head = head->prev;
}
template <typename T>
void List<T>::pop()
{
	if (head != NULL)
	{
		Node* temp = head->prev;
		head->prev = temp->prev;
		temp->prev->next = head;
		delete temp;
		_size--;
		if (_size == 0)
			head = NULL;
	}
	
	else
	{
		cout << "Error: Out of range";
		return;
	}
}
template <typename T>
void List<T>::pop_front()
{
	if (_size > 0)
	{
		Node* temp = head;
		head = head->next;
		head->prev = temp->prev;
		temp->prev->next = head;
		delete temp;
		_size--;
		if (_size == 0)
			head = NULL;
	}
	else
	{

		cout << "Error: Out of range";
		return;
	}
}
template <typename T>
T List<T>::top()
{
	if (head == NULL)
	{
		cout << "Error: List is empty!";
		return NULL;
	}

	return head->value;

}

template <typename T>
int List<T>::size()
{
	return _size;
}
template <typename T>
bool List<T>::empty()
{
	return _size == 0;
}

template <typename T>
T List<T>::get(int  pos)
{

	if (pos == 0)
	{
		return top();
	}
	if (pos >= _size)
	{
		cout << "Error";
		return NULL;
	}
	Node* temp;
	if (pos < _size / 2) {
		temp = head;

		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = head;
		for (int i = _size; i > pos; i--)
		{
			temp = temp->prev;
		}
	}
	return temp->value;

}
template <typename T>
void List<T>::erase(int  pos)
{
	if (pos == 0)
	{
		return pop_front();
	}
	if (pos == _size - 1) return pop();
	if (pos >= _size)
	{
		cout << "Error";
		return;
	}
	Node* temp;
	if (pos < _size / 2) {
		temp = head;

		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = head;
		for (int i = _size; i > pos; i--)
		{
			temp = temp->prev;
		}
	}
	Node* prev = temp->prev;
	Node* next = temp->next;
		prev->next = next;
		next->prev = prev;

	delete temp;
	_size--;

}
template <typename T>
List<T>::~List()
{
	while (_size>0)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		_size--;
	}
}
int main()
{
	List <int> polka;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int type, number;
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
			cout << polka.top() << " ";
			polka.pop_front();
			break;
		case 4:
			cout << polka.get(polka.size() - 1) << " ";
			polka.pop();
			break;
		}

	}

}