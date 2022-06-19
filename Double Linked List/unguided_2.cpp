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

void tambahTengah_nc (string dataUser) {
    //dlinkedlist * bantu;
    vertex = new dlinkedlist;
    vertex->data = dataUser;
    vertex->prev = NULL;
    vertex->next = NULL;
	head->next=vertex;
	tail->prev=vertex;
	vertex->prev=head;
	vertex->next=tail;
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

int main () {
	inisialisasi ();

	tambahDepan_nc ("Purwokerto");
	tambahBelakang_nc ("Surabaya");
	tambahTengah_nc ("Madiun");
	
	tampilData_nc ();

	return 0;
}
