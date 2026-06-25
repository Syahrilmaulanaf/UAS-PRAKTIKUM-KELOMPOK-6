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

int main(){



    return 0;
}