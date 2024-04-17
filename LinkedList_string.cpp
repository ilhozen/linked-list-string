#include "LinkedList_string.h"

LinkedList::LinkedList() :head(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
{
	if (other.head == nullptr) {
		this->head = nullptr;
		return;
	}
	head = new Node(other.head->data);
	Node* w = other.head->next;
	Node* last = head;
	while (w != nullptr) {
		last->next = new Node(w->data);
		last = last->next;
		w = w->next;
	}
}

LinkedList::~LinkedList()
{
	Node* p;
	while (head != nullptr) {
		p = head;
		head = head->next;
		delete p;
	}
}

string& LinkedList::at(int index) {
	Node* w = head;
	int cnt = 0;
	while (w->next != nullptr) {
		if (cnt == index) {
			break;
		}
		w = w->next;
	}
	return w->data;
}

string& LinkedList::front()
{
	return head->data;
}

string& LinkedList::back() {
	Node* last = head;
	while (last->next != nullptr) {
		last = last->next;
	}
	return last->data;
}

void LinkedList::push_back(const string& value) {
	Node* p = new Node(value);

	if (head == nullptr) {
		head = p;
		return;
	}

	Node* last = head;
	while (last->next != nullptr) {
		last = last->next;
	}
	last->next = p;
}

void LinkedList::pop_back() {
	if (head != nullptr) {
		Node* last = head;
		Node* prev = nullptr;
		while (last->next != nullptr) {
			prev = last;
			last = last->next;
		}
		if (prev == nullptr) {
			delete head;
			head = nullptr;
		}
		else {
			prev->next = nullptr;
			delete last;
		}
	}
	else {
		return;
	}

}

void LinkedList::push_front(const string& value)
{
	Node* p = new Node(value);
	p->next = head;
	head = p;
}

void LinkedList::pop_front()
{
	Node* p;
	p = head;
	head = head->next;
	delete p;
}

void LinkedList::insert_at(int index, const string& value) {
	if (index < 0 || index > this->size()) {
		cout << "Invalid index.\n" << endl;
		return;
	}
	if (head != nullptr && index == 0) {
		this->push_front(value);
	}
	else {
		Node* p = new Node(value);
		Node* w = head;
		Node* prev = nullptr;
		int cnt = 0;
		while (w != nullptr) {
			if (index == cnt) {
				break;
			}
			prev = w;
			w = w->next;
			cnt++;
		}
		if (w == nullptr) {
			prev->next = p;
			return;
		}
		p->next = w;
		prev->next = p;
		cout << "String inserted into list!\n" << endl;
		return;
	}
}

void LinkedList::insert_after(int index, const string& val)
{
	if (index < 0 || index >= this->size()) {
		cout << "Invalid index.\n" << endl;
		return;
	}
	Node* w = head;
	Node* p = new Node(val);
	int cnt = 0;
	while (w != nullptr) {
		if (index == cnt) {
			break;
		}
		w = w->next;
		cnt++;
	}
	if (w == nullptr) {
		return;
	}
	p->next = w->next;
	w->next = p;
	cout << "String inserted into list!\n" << endl;
}

void LinkedList::erase_at(int index) {
	if (index < 0 || index >= this->size()) {
		cout << "Invalid index.\n" << endl;
		return;
	}
	if (head != nullptr && index == 0) {
		this->pop_front();
	}
	else {
		Node* w = head;
		Node* prev = nullptr;
		int cnt = 0;
		while (w != nullptr) {
			if (index == cnt) {
				break;
			}
			prev = w;
			w = w->next;
			cnt++;
		}
		if (w == nullptr) {
			cout << "String was not found in the list!\n" << endl;
			return;
		}
		prev->next = w->next;
		delete w;
		cout << "String removed from list!\n" << endl;
	}
}


void LinkedList::erase(const string& e)
{
	if (head == nullptr) {
		return;
	}
	else {
		Node* w = head;
		Node* prev = nullptr;
		while (w != nullptr) {
			if (w->data == e) {
				break;
			}
			prev = w;
			w = w->next;
		}
		if (w == nullptr) {
			cout << "String was not found in the list!\n" << endl;
			return;
		}
		prev->next = w->next;
		delete w;
		cout << "String removed from list!\n" << endl;
	}
}

void LinkedList::clear()
{
	while (head != nullptr) {
		this->pop_back();
	}
}

int LinkedList::size() const
{
	Node* w = head;
	int cnt = 0;
	while (w != nullptr) {
		w = w->next;
		cnt++;
	}
	return cnt;
}

bool LinkedList::empty() const {
	return head == nullptr;
}

Node* LinkedList::findMiddleNode() {
	if (this->empty()) {
		return nullptr;
	}else{
		int cnt = 0;
		int middle = this->size() / 2;
		Node* w = head;
		while (w != nullptr) {
			if (middle == cnt) {
				break;
			}
			w = w->next;
			cnt++;
		}
		return w;
	}
}

Node* LinkedList::getSmallestNode() {
	if (this->empty()) {
		return nullptr;
	}
	else {
		Node* w = head;
		Node* min = head;
		while (w != nullptr) {
			if (w->data < min->data) {
				min = w;
			}
			w = w->next;
		}
		return min;
	}
}

void LinkedList::moveSmallestToFront() {
	if (this->empty()) {
		cout << "List is empty, cannot move any element.\n" << endl;
		return;
	}
	else if (this->size() == 1) {
		cout << "The list has only one element. Nothing has changed.\n" << endl;
		return;
	}
	else {
		Node* w = head;
		Node* prev = nullptr;
		Node* min = head;
		Node* prev_min = nullptr;
		while (w != nullptr) {
			if (w->data < min->data) {
				min = w;
				prev_min = prev;
			}
			prev = w;
			w = w->next;
		}
		if (prev_min != nullptr) {
			prev_min->next = min->next;
			min->next = head;
			head = min;
		}
		cout << "Smallest Node moved to front!\n" << endl;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& lhs)
{
	this->clear();
	Node* w_lhs = lhs.head;
	while (w_lhs != nullptr) {
		push_back(w_lhs->data);
		w_lhs = w_lhs->next;
	}
	return *this;
}

bool LinkedList::operator==(const LinkedList& lhs) const
{
	if (this->size() != lhs.size()) {
		return false;
	}
	Node* w = this->head;
	Node* w_lhs = lhs.head;
	while (w != nullptr) {
		if (w->data != w_lhs->data) {
			return false;
		}
		w = w->next;
		w_lhs = w_lhs->next;
	}
	return true;
}

ostream& operator<<(ostream& out, const LinkedList& list) {
	Node* w = list.head;
	while (w != nullptr) {
		out << w->data << " ";
		w = w->next;
	}
	return out;
}