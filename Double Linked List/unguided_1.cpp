#include <iostream>

using namespace std;

int menu;
char ya_tidak;
bool keluar = false;
string isi_data;

void menu_keluar ();
void menu_lanjut_nc ();
void menu_lanjut_ci ();
void menu_nc ();
void menu_ci ();
int main ();

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

/*          DOUBLE LINKED LIST NON CIRCULAR         */

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

/*          DOUBLE LINKED LIST CIRCULAR         */

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

/*          MAIN PROGRAM NON CIRCULAR       */

void menu_nc () {
    cout << "Linked List Non Circular" << endl;
    cout << "1. Tambah Depan\n";
    cout << "2. Tambah Belakang\n";
    cout << "3. Hapus Depan\n";
    cout << "4. Hapus Belakang\n";
    cout << "5. Tampil Data\n";
    cout << "6. Keluar\n";
    cout << "Silahkan pilih menu : ";
    cin >> menu;

    if (menu == 1)
    {
        cout << "Tambah Depan" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahDepan_nc(isi_data);
        menu_lanjut_nc ();
    }
    else if (menu == 2)
    {
        cout << "Tambah Belakang" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahBelakang_nc(isi_data);
        menu_lanjut_nc ();
    }
    else if (menu == 3)
    {
        cout << "Hapus Depan" << endl;
        hapusDepan_nc();
        cout << "Data terhapus" << endl;
        menu_lanjut_nc ();
    }
    else if (menu == 4)
    {
        cout << "Hapus Belakang" << endl;
        hapusBelakang_nc();
        cout << "Data terhapus" << endl;
        menu_lanjut_nc ();
    }
    else if (menu == 5)
    {
        cout << "Tampil Data" << endl;
        tampilData_nc();
        cout << endl;
        menu_lanjut_nc ();
    }
    else if (menu == 6)
    {
        system("clear");
        main();
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }
}

/*          MAIN PROGRAM CIRCULAR           */

void menu_ci () {
    cout << "Linked List Circular" << endl;
    cout << "1. Tambah Depan\n";
    cout << "2. Tambah Belakang\n";
    cout << "3. Hapus Depan\n";
    cout << "4. Hapus Belakang\n";
    cout << "5. Tampil Data\n";
    cout << "6. Keluar\n";
    cout << "Silahkan pilih menu : ";
    cin >> menu;

    if (menu == 1)
    {
        cout << "Tambah Depan" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahDepan_ci(isi_data);
        menu_lanjut_ci ();
    }
    else if (menu == 2)
    {
        cout << "Tambah Belakang" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahBelakang_ci(isi_data);
        menu_lanjut_ci ();
    }
    else if (menu == 3)
    {
        cout << "Hapus Depan" << endl;
        hapusDepan_ci();
        cout << "Data terhapus" << endl;
        menu_lanjut_ci ();
    }
    else if (menu == 4)
    {
        cout << "Hapus Belakang" << endl;
        hapusBelakang_ci();
        cout << "Data terhapus" << endl;
        menu_lanjut_ci ();
    }
    else if (menu == 5)
    {
        cout << "Tampil Data" << endl;
        tampilData_ci();
        cout << endl;
        menu_lanjut_ci ();
    }
    else if (menu == 6)
    {
        system("clear");
        main();
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }
}

/*          MAIN OTHER          */

void menu_keluar () {
    cout << "Keluar (y/t) ?";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || ya_tidak == 'Y') {
        cout << "Sampai Jumpa Kembali" << endl;
        keluar = true;
    } else {
        system ("clear");
    }
}

void menu_lanjut_nc () {
    cout << "Lanjut (y/t) ? : ";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || 'Y') {
        keluar = true;
        if (keluar == true) {
            system("clear");
            menu_nc ();
        }
    }
}

void menu_lanjut_ci () {
    cout << "Lanjut (y/t) ? : ";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || 'Y') {
        keluar = true;
        if (keluar == true) {
            system("clear");
            menu_ci ();
        }
    }
}

/*          MAIN PROGRAM        */

int main () {

    inisialisasi ();

    cout << "Program Double Linked List" << endl;
    cout << "1. Linked List Non Circular" << endl;
    cout << "2. Linked List Circular" << endl;
    cout << "3. Keluar" << endl;
    cout << "Silahkan pilih menu (1 - 2) :  ";
    cin >> menu;

    system("clear");

    switch (menu) {
        case 1:
            menu_nc ();
            break;

        case 2:
            menu_ci ();
            break;

        case 3:
            menu_keluar ();
            break;
        
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
    }

    return 0;
}