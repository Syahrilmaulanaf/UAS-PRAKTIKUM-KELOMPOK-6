#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

struct Kamar {
    int nomorKamar;
    string tipeKamar;
    int hargaPerMalam;
    bool isTerisi;
    Kamar* next;
};

class ManajemenKamar {
private:
    Kamar* head;

public:
    ManajemenKamar() { head = nullptr; }

    void tambahKamar(int nomor, string tipe, int harga) {
        Kamar* kamarBaru = new Kamar;
        kamarBaru->nomorKamar = nomor;
        kamarBaru->tipeKamar = tipe;
        kamarBaru->hargaPerMalam = harga;
        kamarBaru->isTerisi = false;
        kamarBaru->next = nullptr;

        if (head == nullptr) {
            head = kamarBaru;
        } else {
            Kamar* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = kamarBaru;
        }
    }

    void tampilkanKamar() {
        if (head == nullptr) {
            cout << "\n[!] Belum ada kamar yang terdaftar di sistem.\n";
            return;
        }
        cout << "\n===================================================================\n";
        cout << "                        DAFTAR KAMAR HOTEL                         \n";
        cout << "===================================================================\n";
        cout << left << setw(12) << " No. Kamar"
             << " | " << setw(15) << "Tipe Kamar"
             << " | " << setw(18) << "Harga Per Malam"
             << "| " << "Status" << endl;
        cout << "-------------------------------------------------------------------\n";

        Kamar* temp = head;
        while (temp != nullptr) {
            cout << " " << left << setw(11) << temp->nomorKamar
                 << " | " << setw(15) << temp->tipeKamar
                 << " | Rp " << setw(14) << temp->hargaPerMalam
                 << " | " << (temp->isTerisi ? "TERISI" : "KOSONG") << endl;
            temp = temp->next;
        }
        cout << "===================================================================\n";
    }

    bool isiKamar(int nomor) {
        Kamar* temp = head;
        while (temp != nullptr) {
            if (temp->nomorKamar == nomor && !temp->isTerisi) {
                temp->isTerisi = true;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

struct Tamu {
    string namaTamu;
    string nomorIdentitas;
};

int main() {
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

        switch (pilihan) {
            case 1:
                hotel.tampilkanKamar();
                break;

            case 2: {
                Tamu tamuBaru;
                cout << "\n--- Tambah Antrean Tamu ---\n";
                cout << "Nama Tamu        : ";
                cin.ignore();
                getline(cin, tamuBaru.namaTamu);
                cout << "No. Identitas/KTP: ";
                getline(cin, tamuBaru.nomorIdentitas);

                antreanLobi.push(tamuBaru);
                cout << "[Sukses] " << tamuBaru.namaTamu << " telah ditambahkan ke antrean lobi.\n";
                break;
            }

            case 3: {
                if (antreanLobi.empty()) {
                    cout << "\n[!] Lobi kosong. Tidak ada antrean tamu yang perlu diproses.\n";
                } else {
                    Tamu tamuSekarang = antreanLobi.front();
                    cout << "\n--- Memproses Tamu Terdepan ---\n";
                    cout << "Nama Tamu: " << tamuSekarang.namaTamu << endl;

                    int noKamarPilihan;
                    bool checkInSukses = false;

                    do {
                        hotel.tampilkanKamar();
                        cout << "Masukkan Nomor Kamar yang Ingin Ditempati: ";
                        cin >> noKamarPilihan;

                        if (hotel.isiKamar(noKamarPilihan)) {
                            cout << "\n[Sukses] Check-In Berhasil! Kamar " << noKamarPilihan
                                 << " resmi ditempati oleh " << tamuSekarang.namaTamu << ".\n";
                            antreanLobi.pop();
                            checkInSukses = true;
                        } else {
                            cout << "\n[Gagal] Kamar " << noKamarPilihan << " tidak tersedia atau nomor salah.\n";
                            char ulang;
                            cout << "Apakah ingin memilih nomor kamar lain? (y/n): ";
                            cin >> ulang;
                            if (ulang != 'y' && ulang != 'Y') {
                                cout << "\n[Info] Pemrosesan check-in untuk " << tamuSekarang.namaTamu << " ditunda.\n";
                                break;
                            }
                        }
                    } while (!checkInSukses);
                }
                break;
            }
            case 4:
                cout << "\n[Info] Jumlah tamu yang mengantre di lobi saat ini: "
                     << antreanLobi.size() << " orang.\n";
                break;

            case 5:
                cout << "\nKeluar dari sistem. Terima kasih, Cap!\n";
                break;

            default:
                cout << "\n[!] Pilihan tidak tersedia. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
