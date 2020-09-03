#include<iostream>
using namespace std;
template <typename T>
class List {

public: struct Node {
	Node() { this->next = NULL; this->prev = NULL;};
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
private: Node* head; 
		 int _size;
	   
public:
	List();
	List(const List&);
	void print(Node* head);
	void add(Node* head, int val);
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
	Node* source, *copy;
	source = k.head;
	copy = head;
	for (int i = 1; i < k._size; i++)
	{
		source = source->next;
		copy->next = new Node(source->value,NULL,copy);
		copy = copy->next;
	}
	tail = copy;
	
	
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
	/*while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}*/

}
template <typename T>
void List<T>::push_back(T val)
{
	if (head != NULL)                    
	{
		Node* temp = new Node();
		temp->data = val;
		temp->next = head;
		temp->prev = head->prev;
		head->prev = temp;
		temp->prev->next = temp;
		
	}
	else //Если список пустой
	{
		               
		head = new Node();
		head->data = val;
		head->prev = head;
		head->next = head;
	}
	_size++;
}
	/*
	Node* temp = new  Node;

	
	if (head == NULL)
	{
		head = new Node(val);
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{

		temp = temp->next;
	}
		
	temp->next = new Node;
	temp->next->value = val;
	temp->next->next = NULL;
}*/
template <typename T>
void List<T>::push_top(T val)
{
	if (head != NULL)
	{
		Node* temp = new Node();
		temp->data = val;
		temp->prev = head;
		temp->next = head->next;
		head->next = temp;
	}
	else //Если список пустой
	{

		head = new Node();
		head->data = val;
		head->prev = head;
		head->next = head;
	}
	_size++;
}
template <typename T>
void List<T>::pop()
{
	if (head != NULL)
	{
		Node* temp = new Node();
		temp->data = val;
		temp->prev = head;
		temp->next = head->next;
		head->next = temp;
	}
	else //Если список пустой
	{

		head = new Node();
		head->data = val;
		head->prev = head;
		head->next = head;
	}
	_size++;
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
	return _size == 0 ;
}
template <typename T>
void List<T>::pop_front()
{

	if (head == NULL)
	{
		cout << "Error: Out of range";
		return;
	}

	
	Node* temp = head; //сохраняем последний элемент во временную переменную
	if (head == tail) tail = NULL;
	head = head->next; //предпоследний(тот,на который указывает последний) элемент делаем последним
	
	delete temp; //удаляем последний элемент
	_size--;
}
template <typename T>
T List<T>::get( int  pos)
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
		temp = tail;
		for (int i = _size - 1; i > pos; i--)
		{
			temp= temp->prev;
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
		temp = tail;
		for (int i = _size - 1; i > pos; i--)
		{
			temp = temp->prev;
		}
	}
	Node* prev = temp->prev;
	Node* next = temp->next;
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	
	delete temp;
	_size--;

}
template <typename T>
 List<T>::~List()
{
	 while (head != NULL)
	 {
		 Node* temp = head;
		 head = head->next;
		 delete temp;
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