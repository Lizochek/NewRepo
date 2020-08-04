#include<iostream>
using namespace std;
template <typename T>
class List {

public: struct Node {
	Node() {};
	Node(T value, Node* next)
	{
		this->next = next;
		this->value = value;
	}
	T value;
	Node* next;
};
private: Node* head;
public:
	List();
	List(const List&);
	void print();
	void push_top(T val);
	void push_back(T val);
	T top();
	T get(int pos);
	T erase(int pos);
	int size();
	bool empty();
	~List();

};
void print(Node* head);
void add(Node* head, int val);
int main()
{
	Node* head = new Node(1, new Node(2, new Node(5, new Node(3, new Node(4, NULL)))));

	/*head = new Node;
	head->value = 1;
	head->next = NULL;
	add(head, 2);
	add(head, 5);
	add(head, 3);
	add(head, 4);*/

	/*head = new Node;
	head->value = 1;
	head->next = new Node;
	head->next->value = 2;
	head->next->next = new Node;
	head->next->next->value = 5;
	head->next->next->next = new Node;
	head->next->next->next->value = 3;
	head->next->next->next->next = new Node;
	head->next->next->next->next->value = 4;
	head->next->next->next->next->next = NULL;*/
	print(head);

}
void print(Node* head)
{

	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}

}
void add(Node* head, int val)
{


	while (head->next != NULL)
	{

		head = head->next;
	}
	head->next = new Node;
	head->next->value = val;
	head->next->next = NULL;
}