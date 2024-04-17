#include "LinkedList_string.h"
#include <iostream>
using namespace std;

int main() {
	int choice, index;
	bool skip = false;
	string val;
	LinkedList list;

	do {
		cout << "Welcome to the Linked List Program!\n\n"
			<< "Menu:\n"
			<< "1.  Add an element\n"
			<< "2.  Remove an element by value\n"
			<< "3.  Access an element at index\n"
			<< "4.  Insert an element at index\n"
			<< "5.  Insert an element after index\n"
			<< "6.  Remove an element at index\n"
			<< "7.  Print the linked list\n"
			<< "8.  Print the size of the linked list\n"
			<< "9.  Check if the linked list is empty\n"
			<< "10. Clear the linked list\n"
			<< "11. Find the middle node of the list\n"
			<< "12. Get smallest node\n"
			<< "13. Move smallest node to front\n"
			<< "14. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
		{
			cout << "\nPlease enter a string to add it to the Linked list: ";
			getline(cin, val);

			while (!skip) {
				cout << "\nPlease choose where to add the element:\n"
					<< "1. At the end of the list.\n"
					<< "2. At the beginning of the list.\n"
					<< "Enter your choice: ";
				cin >> choice;
				cin.ignore();
				switch (choice) {
				case 1:
				{
					list.push_back(val);
					skip = true;
					break;
				}
				case 2:
				{
					list.push_front(val);
					skip = true;
					break;
				}
				default:
				{
					cout << "Invalid choice. Please try again.\n" << endl;

				}
				}
			}
			cout << "String added to list!" << endl;
			cout << endl;
			skip = false;
			break;
		}
		case 2:
		{
			if (list.empty()) {
				cout << "List is empty cannot remove anything.\n" << endl;
				break;
			}
			cout << "Please enter the string value you wish to remove from the Linked list: ";
			getline(cin, val);
			list.erase(val);
			break;
		}
		case 3:
		{
			if (list.empty()) {
				cout << "List is empty cannot access anything.\n" << endl;
				break;
			}
			cout << "Please enter the index of the string value you wish to access: ";
			cin >> index;
			if (index < 0 || index >= list.size()) {
				cout << "Invalid index.\n" << endl;
				break;
			}
			cout << "String at index " << index << ": " << list.at(index) << endl << endl;
			break;
		}
		case 4:
		{
			cout << "\nPlease enter a string to add it to the Linked List: ";
			getline(cin, val);
			cout << "Please enter the index you wish to insert a string at: ";
			cin >> index;
			list.insert_at(index, val);
			break;
		}
		case 5:
		{
			cout << "\nPlease enter a string to add it to the Linked List: ";
			getline(cin, val);
			cout << "Please enter the index you wish to insert a string after: ";
			cin >> index;
			list.insert_after(index, val);
			break;
		}
		case 6:
		{
			if (list.empty()) {
				cout << "List is empty cannot remove anything.\n" << endl;
				break;
			}
			cout << "Please enter the index you wish to remove a string from: ";
			cin >> index;
			list.erase_at(index);
			break;
		}
		case 7:
		{
			if(list.empty()){
				cout << "The list is empty!\n" << endl;
			}
			else {
				cout << endl << list << endl << endl;
			}
			break;
		}
		case 8:
		{
			cout << "Size: " << list.size() << endl << endl;
			break;
		}
		case 9:
		{
			if (list.empty()) {
				cout << "List is empty.\n" << endl;
			}
			else {
				cout << "List is not empty.\n" << endl;
			}
			break;
		}
		case 10:
		{
			list.clear();
			cout << "List has been cleared.\n" << endl;
			break;
		}
		case 11:
		{
			if (list.empty()) {
				cout << "List is empty, there is no middle node.\n" << endl;
				break;
			}
			cout << "The middle node of the list:" << *list.findMiddleNode() << endl << endl;
			break;
		}
		case 12:
		{
			if (list.empty()) {
				cout << "List is empty, there is no smallest node.\n" << endl;
				break;
			}
			cout << "Lexicographically smallest Node in the list is:\n" << *list.getSmallestNode() << endl << endl;
			break;
		}
		case 13:
		{
			list.moveSmallestToFront();
			break;
		}
		case 14:
		{
			cout << "\nExiting Linked List Program..." << endl;
			break;
		}
		default:
		{
			cout << "\nInvalid choice. Please try again.\n";
		}
		}
	} while (choice != 14);

	return 0;
}