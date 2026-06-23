#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

int main(){

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

    return 0;
}