#include <iostream>
#include <string>
using namespace std;

struct hp {
    string brand;
    string kondisi;
    int storage;
    int stok;
    int harga;
    hp* next;
};


hp* head = NULL;
hp* current = NULL;


void tampilkanlist() {
    current = head;
    while (current != NULL) {
        cout << "Nama Hp: " << current->brand << endl;
        cout << "Kondisi: " << current->kondisi << endl;
        cout << "Storage: " << current->storage << "GB" << endl;
        cout << "Stok: " << current->stok << endl;
        cout << "Harga: Rp." << current->harga << endl;
        cout << "----------------------------------" << endl;
        current = current->next;
    }
}
void buatlist(string brand, string kondisi, int storage, int stok, int harga) {
    hp* newHp = new hp{brand, kondisi, storage, stok, harga, NULL};
    head = newHp;
}

void tambahakhir(string brand, string kondisi, int storage, int stok, int harga) {
    hp* newHp = new hp{brand, kondisi, storage, stok, harga, NULL};
    if (head == NULL) {
        head = newHp;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newHp;
    }
}

void hapusawal() {
    if (head != NULL) {
        hp* temp = head;
        head = head->next;
        delete temp;
    }
}

void hapusakhir() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    current = head;
    while (current->next != NULL && current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

void cariHp(string brand) {
    current = head;
    while (current != NULL) {
        if (current->brand == brand) {
            cout << "Nama Hp: " << current->brand << endl;
            cout << "Kondisi: " << current->kondisi << endl;
            cout << "Storage: " << current->storage << "GB" << endl;
            cout << "Stok: " << current->stok << endl;
            cout << "Harga: Rp." << current->harga << endl;
            cout << "----------------------------------" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Hp dengan nama " << brand << " tidak ditemukan.\n";
}

void sorting(int pilihan) {
    int data = 0;
    current = head;
    while (current != NULL) {
        data++;
        current = current->next;
    }

    hp* arr[data];
    current = head;
    for (int i = 0; i < data; i++) {
        arr[i] = current;
        current = current->next;
    }

    for (int i = 0; i < data - 1; i++) {
        for (int j = i + 1; j < data; j++) {
            bool daftar = false;
            switch (pilihan) {
                case 1:
                    daftar = arr[j]->harga < arr[i]->harga;
                    break;
                case 2:
                    daftar = arr[j]->stok < arr[i]->stok;
                    break;
            }
            if (daftar) {
                hp* temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < data; i++) {
        cout << "Nama Hp: " << arr[i]->brand << endl;
        cout << "Kondisi: " << arr[i]->kondisi << endl;
        cout << "Storage: " << arr[i]->storage << "GB" << endl;
        cout << "Stok: " << arr[i]->stok << endl;
        cout << "Harga: Rp." << arr[i]->harga << endl;
        cout << "----------------------------------" << endl;
    }
}

int main() {
    buatlist("Iphone XR", "sec ex inter", 64, 5, 3200000);
    tambahakhir("Iphone XR", "sec ex ibox", 128, 5, 6800000);
    tambahakhir("Iphone 11 pro", "sec ex inter", 64, 4, 5350000);
    tambahakhir("Iphone 11", "sec ex ibox", 64, 5, 5700000);
    tambahakhir("Iphone 12", "sec ex inter", 128, 2, 5800000);
    tambahakhir("Iphone 13", "sec ex ibox", 128, 2, 9000000);
    tambahakhir("Iphone 13", "sec ex ibox", 256, 2, 10000000);
    tambahakhir("Iphone 14", "sec ex ibox", 128, 2, 10300000);
    tambahakhir("Iphone 15", "New ibox", 128, 2, 13600000);

    short pilihan;
    while (true) {
        cout << "*****FIRM STORE******\n";
        cout << "1. Tampilkan Semua Stok\n";
        cout << "2. Tambah stok\n";
        cout << "3. Kurangi stok\n";
        cout << "4. Cari stok\n";
        cout << "5. Urutkan stok\n";
        cout << "6. Keluar Program\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanlist();
                break;
            case 2: {
                string brand, kondisi;
                int storage, stok, harga;
                cin.ignore();
                cout << "Nama Hp        : "; getline(cin, brand);
                cout << "Kondisi        : "; getline(cin, kondisi);
                cout << "Storage        : "; cin >> storage;
                cout << "Stok           : "; cin >> stok;
                cout << "Harga          : "; cin >> harga;

                tambahakhir(brand, kondisi, storage, stok, harga);
                cout << "\nStok berhasil ditambahkan\n\n";
                break;
            }
            case 3:
                cout << "1. Hapus Data Awal\n";
                cout << "2. Hapus Data Akhir\n";
                cin >> pilihan;
                cout << endl;

                if (pilihan == 1) {
                    hapusawal();
                    cout << "Stok dihapus dari awal\n";
                }
                else if (pilihan == 2) {
                    hapusakhir();
                    cout << "Stok dihapus dari akhir\n";
                }
                break;
            case 4: {
                string brand;
                cin.ignore();
                cout << "Masukkan nama Hp: "; getline(cin, brand);
                cariHp(brand);
                break;
            }
            case 5:
                cout << "1. Urutkan Berdasarkan Harga\n";
                cout << "2. Urutkan Berdasarkan Stok\n";
                cout << "Pilih opsi: ";
                cin >> pilihan;
                if (pilihan >= 1 && pilihan <= 2) {
                    sorting(pilihan);
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
                break;
            case 6:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }
}
