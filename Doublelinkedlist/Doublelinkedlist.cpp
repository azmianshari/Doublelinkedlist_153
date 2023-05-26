#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class Doublelinkedlist {
private:
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nama;
	cout << "\nEnter the roll number of the student :";
	cin >> nim;
	cout << "\nEnter the name of student :";
	cin >> nama;
	Node* newNode = new Node(); //Step 1
	newNode->noMhs = nim; //Step 2
	newNode->nama = nama; 

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; 
		if (START != NULL)
			START->prev = newNode; 
		newNode->prev = NULL; 
		START = newNode; 
		return;
	}

	Node* current = START;
	Node* previous = NULL;
	while 
}