#include<iostream>
using namespace std;

template <typename T>
struct Node {
	Node() { this->next = NULL; this->prev = NULL; };
	Node(T value, Node* next, Node* prev)
	{
		this->next = next;
		this->prev = prev;
		this->value = value;
	}
	Node(T value)
	{
		this->value = value;
		this->next = NULL;
		this->prev = NULL;

	}
	T value;
	Node* next;
	Node* prev;
};

template <typename T>
class BaseCycleList {
public:
	/*������ ����� ������,���������� ���*/
	static Node<T>* create(Node<T>* node);
	/*�����, ��������� ����� ���� �� ��������� val, ����� ���� nodeOfClist
	�  ��������������� ����������� ������
	���������� ��������� �� ����� ��������� ����
	*/
	static Node<T>* add(Node<T>* nodeOfClist, T value);
	/*�����, ��������� ���� node, ����� ���� nodeOfClist
	�  ��������������� ����������� ������
	���������� ��������� �� ����� ����������� ����
	*/
	static Node<T>* add(Node<T>* nodeOfClist, Node<T>* node);
	/*�����, ������� ���� node ��
	�  ���������������� ������������ ������
	���������� ��������� �� �������� ����*/
	static Node<T>* erase(Node<T>* nodeOfClist);
	/*�����, ���� ���� �� ��������� value �
	�  ��������������� ����������� ������, ������� � ����n odeOfClist
	���������� ��������� ��������� ���� ��� NULL*/
	static Node<T>* find(Node<T>* nodeOfClist, T value);
	/* ���������� �������� ��� ����*/
	static T  get(Node<T>*);
	/* ������������� �������� ��� ����
   ���������� ������ �� ����*/
	static Node<T>* set(Node<T>*, T);
	/*��������� ������ �� ��������� �� nodeOfClist ����*/
	static  Node<T>* next(Node<T>* nodeOfClist);
	/*��������� ������ �� ���������� �� nodeOfClist ����*/
	static  Node<T>* prev(Node<T>* nodeOfClist);

};
/*������ ����� ������,���������� ���*/
template <typename T>
Node<T>* BaseCycleList<T>::create( Node<T>* node)
{
	node->next=node ;
	node->prev = node;
	return node;
}
/*�����, ��������� ����� ���� �� ��������� val, ����� ���� nodeOfClist
�  ��������������� ����������� ������
���������� ��������� �� ����� ��������� ����*/
template <typename T>
Node<T>* BaseCycleList<T>::add(Node<T>* nodeOfClist, T val)
{
	Node<T>* node = new Node<T>(val);
	return BaseCycleList::add(nodeOfClist, node);
}
/*�����, ��������� ���� node, ����� ���� nodeOfClist
�  ��������������� ����������� ������
���������� ��������� �� ����� ����������� ����*/
template <typename T>
Node<T>* BaseCycleList<T>::add(Node<T>* nodeOfClist, Node<T>* node)
{
	Node<T>* next = nodeOfClist->next;

	node->prev = nodeOfClist;
	node->next = next;

	next->prev = node;
	nodeOfClist->next = node;
	return node;
}
/*�����, ������� ���� node ��
�  ���������������� ������������ ������
���������� ��������� �� �������� ����*/
template <typename T>
Node<T>* BaseCycleList<T>::erase(Node<T>* node)
{
	Node<T>* next = node->next;
	Node<T>* prev = node->prev;

	next->prev = prev;
	prev->next = next;

	return node;
}
/*�����, ���� ���� �� ��������� value �
�  ��������������� ����������� ������, ������� � ����n odeOfClist
���������� ��������� ��������� ���� ��� NULL*/
template <typename T>
Node<T>* BaseCycleList<T>::find(Node<T>* nodeOfClist, T value)
{
	Node<T>* it = nodeOfClist;
	do
	{
		if (it->value == value)
			return it;
		it = it->next;
	} while (it != nodeOfClist);
	return NULL;
}
/* ���������� �������� ��� ����*/
template <typename T>
T BaseCycleList<T>::get(Node<T>* node)
{
	return node->value;
}
/* ������������� �������� ��� ����
���������� ������ �� ����*/
template <typename T>
Node<T>* BaseCycleList<T>::set(Node<T>* node, T value)
{
	node->value = value;
	return node;
}
/*��������� ������ �� ��������� �� nodeOfClist ����*/
template <typename T>
 Node<T>* BaseCycleList<T>::next(Node<T>* nodeOfClist)
{
	return nodeOfClist->next;
}
/*��������� ������ �� ���������� �� nodeOfClist ����*/
template <typename T>
 Node<T>* BaseCycleList<T>::prev(Node<T>* nodeOfClist)
{
	return nodeOfClist->prev;
}


template <typename T>
class Deque {


private: Node<T>* head;
	   int _size;

public:
	Deque();
	Deque(const Deque&);
	void print(Node<T>* head);
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
	~Deque();


};
template <typename T>
Deque<T>::Deque()
{
	_size = 0;
	head = BaseCycleList<T>::create(new Node<T>());
}
template <typename T>
Deque<T>::Deque(const Deque& k) :Deque()
{
	/*
	����� ���������:
	Deque <int> a;
	Deque<int> b;
	a = b;
	�������� � ���-��� �� ��������
	function(a);
	���������� �� ������� �� ��������
	return a;
	*/
	_size = k._size;
	BaseCycleList::set(head, k.head->value);

	Node* source, * copy;
	source = k.head;
	copy = head;
	for (int i = 1; i < k._size; i++)
	{
		source = source->next;
		copy = BaseCycleList::add(copy, source->value);
	}
}
template <typename T>
void Deque<T>::print(Node<T>* head)
{
	if (empty()) return;
	Node* temp = head;

	do
	{
		cout << BaseCycleList::get(temp) << " ";
		temp = BaseCycleList::next(temp);
	} while (temp != head);
	cout << "\n";
}
template <typename T>
void Deque<T>::insert(int pos, T val)
{
	if (pos > _size) {
		cout << "Error: Out of range";
		return;
	}
	if (pos == 0) push_top(val);
	else if (pos == _size) push_back(val);
	else
	{
		Node* temp = head;
		//todo: ����� �����������, ���� ������ �� ������ � ������, 
		//�� � � �����, ����� ��� �����
		for (int i = 0; i < pos - 1; ++i)
			temp = BaseCycleList::next(temp);
		BaseCycleList::add(temp, val);
		_size++;
	}

}
template <typename T>
void Deque<T>::push_back(T val)
{
	if (_size == 0) BaseCycleList<T>::set(head, val);
	else BaseCycleList<T>::add(BaseCycleList<T>::prev(head), val);
	_size++;
}
template <typename T>
void Deque<T>::push_top(T val)
{
	push_back(val);
	head=BaseCycleList<T>::prev(head);
}
template <typename T>
void Deque<T>::pop()
{
	if (_size!=0 )
	{
		if (_size > 1) 
			delete BaseCycleList<T>::erase(BaseCycleList<T>::prev(head));
		_size--;
	}

	else
	{
		cout << "Error: Out of range";
		return;
	}
}
template <typename T>
void Deque<T>::pop_front()
{
	head = BaseCycleList<T>::next(head);
	pop();
}
template <typename T>
T Deque<T>::top()
{
	if (empty())
	{
		cout << "Error: Deque is empty!";
		return NULL;
	}

	return BaseCycleList<T>::get(head);

}

template <typename T>
int Deque<T>::size()
{
	return _size;
}
template <typename T>
bool Deque<T>::empty()
{
	return _size == 0;
}

template <typename T>
T Deque<T>::get(int  pos)
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
	Node<T>* temp;
	if (pos < _size / 2) {
		temp = head;

		for (int i = 0; i < pos; i++)
		{
			temp=BaseCycleList<T>::next(temp);
		}
	}
	else
	{
		temp = head;
		for (int i = _size; i > pos; i--)
		{
			temp = BaseCycleList<T>::prev(temp);
		}
	}
	return BaseCycleList<T>::get(temp);

}
template <typename T>
void Deque<T>::erase(int  pos)
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
			temp = BaseCycleList::next(temp);
		}
	}
	else
	{
		temp = head;
		for (int i = _size; i > pos; i--)
		{
			temp = BaseCycleList<T>::prev(temp);
		}
	}
	delete BaseCycleList<T>::erase(temp);
	_size--;

}
template <typename T>
Deque<T>::~Deque()
{
	while (_size > 0)
	{
		Node<T>* temp = head;
		head = BaseCycleList<T>::next(head);
		delete temp;
		_size--;
	}
}
int main()
{
	Deque <int> polka;
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