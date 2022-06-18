#include <iostream>

using namespace std;

struct dlinkedlist
{
	dlinkedlist * prev;
	string data;
	dlinkedlist * next;
};

dlinkedlist * head;
dlinkedlist * tail;
dlinkedlist * vertex;

void inisialisasi()
{
	head = NULL;
	tail = NULL;
}

bool dLinkKosong()
{
	if (head == NULL && tail == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tambahDepan_ci(string dataUser)
{
	if (dLinkKosong() == true)
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		head = vertex;
		tail = vertex;
		head->prev = tail;
		tail->next = head;
	}
	else
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->next = head;
		head->prev = vertex;
		head = vertex;
		head->prev = tail;
		tail->next = head;
	}
}

void tambahBelakang_ci(string dataUser)
{
	if (dLinkKosong() == true)
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		head = vertex;
		tail = vertex;
		head->prev = tail;
		tail->next = head;
	}
	else
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->prev = tail;
		tail->next = vertex;
		tail = vertex;
		tail->next = head;
		head->prev = tail;
	}
}

void hapusDepan_ci()
{
	if (dLinkKosong() == true)
	{
		cout << "Kosong...!!!" << endl;
	}
	else
	{
		dlinkedlist * helper;
		helper = head;
		if (head == tail)
		{
			tail->next = NULL;
			head->prev = NULL;
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			head = head->next;
			head->prev = tail;
			tail->next = head;
			helper->next = NULL;
			delete helper;
		}
	}
}

void hapusBelakang_ci()
{
	if (dLinkKosong() == true)
	{
		cout << "Kosong...!!!" << endl;
	}
	else
	{
		if (head == tail)
		{
			dlinkedlist * helper;
			helper = head;
			head->prev = NULL;
			tail->next = NULL;
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			dlinkedlist * helper;
			helper = tail;
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;
			helper->prev = NULL;
			helper->next = NULL;
			delete helper;
		}
	}
}

void tampilData_ci()
{
	if (dLinkKosong() == true)
	{
		cout << "Kosong...!!!" << endl;
	}
	else
	{
		dlinkedlist * helper;
		helper = head;
		do { 	cout << helper->data << " ";
			helper = helper->next;
		} while (helper != head);
	}
}

int main()
{
	inisialisasi();

	tambahDepan_ci("Bandung");
	tambahDepan_ci("Aceh");
	tambahBelakang_ci("Ciamis");
	hapusDepan_ci();
	hapusBelakang_ci();
	hapusBelakang_ci();
	
	tampilData_ci();

	return 0;
}