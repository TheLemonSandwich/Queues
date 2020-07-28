#include <iostream>
#include <string>

using namespace std;

class Queues
{
	int numofitems;
	int arraysize;
	int* queuearray;
	int front, rear;
public:
	Queues(int s);
	~Queues();
	void Enqueue();
	int Dequeue();
	void Clear();
	bool IsEmpty();
	bool IsFull();

};
void CLS();
int main()
{
	cout << "Enter the size of Queue: ";
	int s;
	cin >> s;
	Queues q(s);
	bool invalid = false;
	do
	{
		invalid = false;
		while (!invalid)
		{
			cout << "1. Enqueue\n";
			cout << "2. Dequeue\n";
			cout << "3. Clear\n";
			cout << "4. Exit\n";

			int option;
			cin >> option;
			CLS();
			switch (option)
			{
			case 1:
				q.Enqueue();
				CLS();
				break;
			case 2:
				if (!q.IsEmpty())
					cout << "Deleted " << q.Dequeue() << endl;
				else
					q.Dequeue();
				CLS();
				break;
			case 3:
				q.Clear();
				CLS();
				break;
			case 4:
				invalid = true;
				return false;
				break;
			default:
				cout << "Choose from the following\n";
				invalid = true;
				break;
			}
		}
	} while (true);

}
void Queues::Enqueue()
{
	if (IsFull())
		cout << "Queue is full\n";
	else
	{
		rear = (rear + 1) % arraysize;
		cout << "Enter the data:-\n";
		cin >> queuearray[rear];
		numofitems++;
	}
}
int Queues::Dequeue()
{
	if (IsEmpty())
		cout << "Queue is Empty\n\n";
	else
	{
		int num = queuearray[front+1];
		queuearray[front+1] = NULL;
		front = (front + 1) % arraysize;
		numofitems--;
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		return num;
	}
}

bool Queues::IsEmpty()
{
	if (numofitems)
		return false;
	else true;
}
bool Queues::IsFull()
{
	if (numofitems < arraysize)
		return false;
	else
		return true;
}
Queues::Queues(int s)
{
	queuearray = new int[s];
	for (int i = 0; i < s; i++)
		queuearray[i] = NULL;
	front = -1;
	rear = -1;
	arraysize = s;
	numofitems = 0;
}
Queues::~Queues()
{
	delete[] queuearray;
}
void Queues::Clear()
{
	while (!IsEmpty())
	{
		cout << Dequeue() << endl;
	}
	front = -1;
	rear = -1;
}

void CLS()
{
	system("pause");
	system("cls");
}