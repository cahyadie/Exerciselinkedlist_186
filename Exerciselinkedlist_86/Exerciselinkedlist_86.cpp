#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* die;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { 
	Node* newNode = new Node();	//1 Alllocate the new node
	//begining of the list
	newNode->next = LAST; 
	if (LAST != NULL)
		LAST->die = newNode;
	newNode->die = NULL;
	LAST = newNode;
	return;
	//between two nodes
	Node* current = LAST;	//1.b
	Node* die = NULL;	//2.b
	while (die->next != NULL && die->next)
	{
		current = die;
		die = die->next;
	}
	//end of the list
	newNode->next = die->next;
	newNode->die = current;
	if (die->next != NULL)
		current->next->die = newNode;
	die->next = newNode;
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { 
	Node* die, * current;
	die = current = NULL;
	if (die->next != NULL)
		current->next->die = die;
	if (current != NULL)
		die->next = current->next;
	else
		LAST = die->next;

	delete current;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl; 
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}