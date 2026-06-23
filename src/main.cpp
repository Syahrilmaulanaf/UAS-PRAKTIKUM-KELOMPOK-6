#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

int main(){

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