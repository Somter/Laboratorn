// Laboratorn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;    

class Queue
{	
	int* Wait;
	int MaxQueueLength;
	int QueueLength;

public:
	Queue(int m);
	~Queue();	
	void Add(int c);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
};

void Queue::Show() {

	cout << Wait[0] << " " << endl;	
}

Queue::~Queue()
{
	delete[]Wait;
}

Queue::Queue(int m)
{	
	MaxQueueLength = m;	
	Wait = new int[MaxQueueLength];
	QueueLength = 0;
}

void Queue::Clear()
{
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	return QueueLength;
}

void Queue::Add(int c)
{
	if (!IsFull())
		Wait[QueueLength++] = c;	
}

int Queue::Extract()
{
	if (!IsEmpty()) {
		int temp = Wait[0];

		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		Wait[QueueLength - 1] = temp;	

		return temp;
	}

	else
		return -1;
}

int main()
{
	srand(time(0));
	int start;
	cout << "1 - start the game!\n";
	cout << "Start: ";
	cin >> start;
	if (start == 1) {

		Queue QU(5);
		Queue QU2(5);
		Queue QU3(5);
		int rez1, rez2, rez3; 
		bool winOrLose = false;
		int ContinueGame = 0;
		for (int i = 0; i < 10; i++)
		{
			QU.Add(rand() % 5);
		}
		for (int i = 0; i < 10; i++)
		{
			QU2.Add(rand() % 5);
		}
		for (int i = 0; i < 10; i++)
		{
			QU3.Add(rand() % 5);
		}
		do {
			cout << "Drum rotation...\n";	
			int drum = 2 + rand() % 5;	
			for (int i = 0; i < drum; i++) {
				if (i == drum - 1) {	
					cout << "Rezult: \n";
				}
				cout << "1: ";
				QU.Show();	
				QU.Extract();
				cout << "2: ";	
				QU2.Show();
				QU2.Extract();
				cout << "3: ";		
				QU3.Show();	
				QU3.Extract();	
				cout << endl;	
			}
			rez1 = QU.Extract();	
			rez2 = QU2.Extract();
			rez3 = QU3.Extract();

			if (rez1 == rez2 && rez2 == rez3)
			{
				cout << "You win! yoyr present: 12  in OOP ";	
			}
			else {	
				cout << "You lose :/\n";
			}

			cout << "Do you want to continue playing? 1-yes/2-No";
			cin >> ContinueGame;
		} while (ContinueGame == 1);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
