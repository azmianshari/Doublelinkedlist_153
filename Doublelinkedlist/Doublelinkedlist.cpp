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
		newNode->next = START; //Step 3
		if (START != NULL)
			START->prev = newNode; //Step 4
		newNode->prev = NULL;  //Step 5
		START = newNode; //Step 6
		return;
	}
	//Inserting a Node in a begining of Double linked list
	Node* current = START;
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim) {
		previous = current;
		current = current->next;
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newNode->next = current->next; //Step 4
	newNode->prev = current; //Step 5
	if (current->next != NULL)
		current->next->prev = newNode; //Step 6
	current->next = newNode;
}
bool Doublelinkedlist::search