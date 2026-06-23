#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

struct Tamu {
    string namaTamu;
    string nomorIdentitas;
};

int main(){
    ManajemenKamar hotel;
    queue<Tamu> antreanLobi;
    hotel.tambahKamar(101, "Single Room", 350000);
    hotel.tambahKamar(102, "Single Room", 350000);
    hotel.tambahKamar(201, "Deluxe Room", 600000);
    hotel.tambahKamar(202, "Deluxe Room", 600000);
    hotel.tambahKamar(301, "Suite Room ", 1200000);

    int pilihan;
    do {
        cout << "\n==================================================\n";
        cout << "        SISTEM MANAJEMEN HOTEL - KELOMPOK 6      \n";
        cout << "==================================================\n";
        cout << "1. Lihat Daftar dan Status Kamar\n";
        cout << "2. Tambah Tamu ke Antrean Lobi (Queue)\n";
        cout << "3. Proses Check-In Tamu (FIFO)\n";
        cout << "4. Lihat Jumlah Antrean Sekarang\n";
        cout << "5. Keluar Aplikasi\n";
        cout << "==================================================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[!] Input tidak valid! Masukkan angka antara 1-5.\n";
            continue;
        }


    return 0;
}