#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void addNode(Node** head, int data) {
	Node* new_node = new Node();
	Node* last = *head;
	new_node->data = data;
	new_node->next = nullptr;
	if (*head == nullptr) {
		*head = new_node;
		return;
	}
	while (last->next != nullptr) {
		last = last->next;
	}
	last->next = new_node;
	return;
	
}
void circular_list(Node** head) {
	if (head == nullptr) {
		cout << "Linked list is empty" << endl;
		return;
	}
	Node* temp = *head;
	while (temp->next != nullptr) {
		cout << temp->data << "-> ";
		temp = temp->next;
	}
	cout << temp->data << "-> " << (*head)->data;
} 

void delete_node(Node** head, int elem) {
	Node* prev = *head;
	Node* curr = (*head)->next;
	if (prev->data == elem) {
		*head = (*head)->next;
		delete prev;
		return;
	}
	while (curr != nullptr) {
		if (curr->data == elem) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
}

void print_list(Node* head) {
	while (head != nullptr) {
		cout << head->data << endl;
		head = head->next;
	}
}





int main() {
	Node* head = nullptr;

	addNode(&head, 5);
	addNode(&head, 6);
	addNode(&head, 7);
	addNode(&head, 8);
	circular_list(&head);
	cout << endl << endl;
	print_list(head);
	delete_node(&head, 8);
	cout << endl << endl;
	print_list(head);
}
