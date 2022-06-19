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

void tambahDepan_nc(string dataUser)
{
	if (dLinkKosong() == true)
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->prev = NULL;
		vertex->next = NULL;
		head = vertex;
		tail = vertex;
	}
	else
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->prev = NULL;
		vertex->next = NULL;
		vertex->next = head;
		head->prev = vertex;
		head = vertex;
	}
}

void tambahBelakang_nc(string dataUser)
{
	if (dLinkKosong() == true)
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->prev = NULL;
		vertex->next = NULL;
		head = vertex;
		tail = vertex;
	}
	else
	{
		vertex = new dlinkedlist;
		vertex->data = dataUser;
		vertex->prev = NULL;
		vertex->next = NULL;
		tail->next = vertex;
		vertex->prev = tail;
		tail = vertex;
	}
}

void hapusDepan_nc()
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
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
			helper->next = NULL;
			delete helper;
		}
	}
}

void hapusBelakang_nc()
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
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			dlinkedlist * helper;
			helper = tail;
			tail = tail->prev;
			tail->next = NULL;
			helper->prev = NULL;
			delete helper;
		}
	}
}

void tampilData_nc()
{
	if (dLinkKosong() == true)
	{
		cout << "Kosong...!!!" << endl;
	}
	else
	{
		dlinkedlist * helper;
		helper = head;
		while (helper != NULL)
		{
			cout << helper->data << " ";
			helper = helper->next;
		}
	}
}

int main()
{
	inisialisasi();

	tambahDepan_nc("Bandung");
	tambahDepan_nc("Aceh");
	tambahBelakang_nc("Ciawi");
	hapusDepan_nc();
	tambahDepan_nc("Ambon");
	hapusBelakang_nc();
	hapusDepan_nc();
	hapusBelakang_nc();
	hapusBelakang_nc();
	
	tampilData_nc();

	return 0;
}