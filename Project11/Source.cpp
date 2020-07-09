#include<iostream>
#include<exception>

using namespace std;

class Stack {
	Stack() :_top(NULL), _size(0) {}

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

	void push_back(const int el)
	{

		if (_top != NULL)
		{
			Node* temp = new Node(el, _top);//������ ����� ���, �������������� ��� ���������� el � �� ��������� �� _top(������� ����� �����)
			_top = temp; //����� ������� ������ ���������
		}
		else
		{
			_top = new Node(el); //������ ����� ��� � �������������� ��� ���������� el	
		}
		_size++;
	}
	void Pop()
	{

		if (_top == NULL) cout << "Error: Out of range";

		Node* temp = _top; //��������� ��������� ������� �� ��������� ����������
		_top = _top->next; //�������������(���,�� ������� ��������� ���������) ������� ������ ���������
		delete temp; //������� ��������� �������
		_size--;
	}

	int& top()
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
		return _size == 0 ? true : false;
	}
};
int main()
{
	int top, size;
	cin >>
		Stack st()
}