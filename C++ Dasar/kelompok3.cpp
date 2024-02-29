#include <iostream>
using namespace std;


//membuat fungsi menggunakan struct
struct daftar
{
    string nama;
    string paket;
    int malam;
};
daftar room[30][15];
char pilihan;


//Fungsi untuk output awalan
void opening()
{

    cout << endl;
    cout << "\t\t===============================================================================" << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t\t\t\t SELAMAT DATANG DI HOTEL DIMS                          " << endl;
    cout << "\t\t\t\t TEMPAT TERNYAMAN UNTUK ISTIRAHAT DENGAN TENANG                " << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t===============================================================================" << endl;
    cout << endl;

}

//Fungsi untuk menampilkan bantuan atau penjelasan kecil
void bantuan()
{

    cout << "\t\t===============================================================================" << endl;
    cout << "\t\t\t\tINFORMASI BANTUAN UNTUK BOOKING HOTEL\n";
    cout << "\n\t\t\t\t## Hotel ini mempunyai 30 lantai dan 15 kamar di setiap lantai\n";
    cout << "\t\t\t\t## Lantai 1 - 15 untuk Reguler dan Lantai 16 - 30 untuk VIP\n";
    cout << "\t\t\t\t## Sistem Pembayaran di hitung 1 malam\n";
    cout << "\t\t\t\t## Permalam untuk Reguler 100$ dan untuk VIP 200$\n";
    cout << "\n\t\t\t\t## Ketik B untuk : Membooking atau memesan kamar";
    cout << "\n\t\t\t\t## Ketik C untuk : Mengecek info kamar";
    cout << "\n\t\t\t\t## Ketik T untuk : Mencari nama pemesan kamar";
    cout << "\n\t\t\t\t## Ketik H untuk : Mencari informasi kamar dan harga hotel";
    cout << "\n\t\t\t\t## Ketik K untuk : Keluar dari program\n";
    cout << "\t\t===============================================================================" <<endl<<endl;

}

//Fungsi untuk memasukkan data yang dibutuhkan ke array
void booking(string nama, string nama_b, int malam, int lantai, int kamar)
{
    string nama_p;

    if(lantai <= 14 and lantai >= 0)
    {
        nama_p = "Reguler";
    } else if(lantai <= 29 and lantai >= 15) {

        nama_p = "VIP";

    }

    room[lantai][kamar] = {nama, nama_p, malam};
    kamar += 1;
    lantai += 1;
    cout << "\t\t\t\tKamar " << kamar << " di lantai " << lantai << " sudah di isi atas nama " << nama << " " << nama_b;
    cout << "\n\t\t\t\tDengan paket " << nama_p << " Selama " << malam << " malam";
    cout << "\n\n\t\t\t\t\t\tPemesanan sudah berhasil!!!";
    cout << "\n\t\t===============================================================================" << endl;
    cout << "\n\t\t\t\tApa yang ingin kamu lakukan selanjutnya?";
    cout << endl;

}

//fungsi untuk mengecek isi di dalam array (lantai dan kamar)
void cek_k()
{
    int lantai;
    int kamar;

        cout << "\t\t\t\tSilahkan Isi Form ini untuk Cek data kamar\n";
        cout << "\t\t\t\t\tMasukkan lantai berapa (1 - 30): ";
        cin >> lantai;

        if(lantai > 30 or lantai < 1)
        {

            cout << "\t\t\t\t\tHotel ini hanya ada 30 Lantai\n";
            cout << "\t\t\t\t\tCoba lagi\n";
            cout << "\t\t===============================================================================" << endl;
            return;

        }

        cout << "\t\t\t\t\tMasukkan kamar ke berapa (1 - 15): ";
        cin >> kamar;

        if(kamar > 15 or kamar < 1)
        {

            cout << "\t\t\t\t\tKamar di setiap lantai hanya ada 15\n";
            cout << "\t\t\t\t\tCoba Lagi\n";
            cout << "\t\t===============================================================================" << endl;
            return;

        }

        lantai -= 1;
        kamar -= 1;

        if(room[lantai][kamar].malam == 0)

        {
            cout << "\n\t\t\t\tKamar yang anda pilih saat ini sedang kosong\n\n";
            cout << "\t\t===============================================================================" <<endl;

        } else {

            cout << "\n\t\t  Kamar yang anda sebutkan saat ini sedang di isi oleh Tuan / Nyonya " << room[lantai][kamar].nama;
            cout << "\n\n\t\t===============================================================================" <<endl;
            cout << "\n\t\t\t\tApa yang ingin kamu lakukan selanjutnya?\n";
        }

}

//Fungsi untuk mencari nama yang ada di dalam array
void cek_t() {
    int lantai = 0;
    int kamar = 0;
    string nama;

    cout << "\t\t\t\tSilahkan Isi Form ini untuk Mencari kamar tamu\n";
    cout << "\t\t\t\tIngin mencari kamar atas nama Siapa? ";
    cout << "\n\t\t\t\tMasukkan nama depan tamu yang ingin dicari : ";
    cin >> nama;

    for (lantai = 0; lantai <= 30; lantai++) {
        for (kamar = 0; kamar <= 15; kamar++) {

            if (room[lantai][kamar].nama == nama) {

                kamar += 1;
                lantai += 1;
                cout << "\t\t\t\tKamar No " << kamar << " di lantai " << lantai;
                cout << "\n\t\t\t\tSaat ditempati oleh Tuan/Nyonya " << nama;
                cout << "\n\t\t===============================================================================" << endl;
                cout << "\n\t\t\t\tApa yang ingin anda lakukan selanjutnya? \n";
                return;

            }

        }

    }

    cout << "\t\t\t\tNama tidak ditemukan dalam daftar kamar." << endl;
    cout << "\t\t===============================================================================" << endl;
    cout << "\t\t\t\tApa yang ingin anda lakukan selanjutnya? \n\n";

}

//Fungsi untuk menghitung harga dan memunculkan harga total
void harga(int lantai, int malam)
{
    int total;
    lantai += 1;

    if(lantai <= 15 and lantai >= 1)
    {

        total = malam * 100;
        cout << "\t\t\t\tKamar yang kamu pilih adalah kamar Reguler\n";
        cout << "\t\t\t\tHarga total penginapan anda adalah sebanyak : " << total;

    } else if(lantai <= 30 and lantai >= 16) {

        total = malam * 200;
        cout << "\t\t\t\tKamar yang kamu pilih adalah kamar VIP\n";
        cout << "\t\t\t\tHarga total penginapan anda adalah sebanyak : " << total;

    }

    cout << endl;

}

//Fungsi untuk memilih menu aksi
void pemilihan()
{

    cout << "\t\t\t\tSilahkan pilih menu yang anda inginkan" << endl;
    cout << "\t\t  Booking kamar[B]   Cek kamar[C]   Cari Tamu[T]   Bantuan [H]   Keluar[K] : ";
    cin >> pilihan;
    cout << "\t\t===============================================================================" <<endl;
    cout << endl;

}

//Fungsi untuk output terima kasih
void penutup()
{
    cout << "\t\t===============================================================================" <<endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t\t\t\tTERIMA KASIH TELAH MEMILIH HOTEL DIMS " << endl;
    cout << "\t\t\t\t\t  SEBAGAI TEMPAT PERISTIRAHATAN ANDA" << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t===============================================================================" <<endl<<endl;
}


int main()
{
    string nama;
    string nama_b;
    int malam;
    int lantai;
    int kamar;

    opening();
    cout << "\t\t===============================================================================" <<endl;

    while(true)
    {

        pemilihan();

        if(pilihan == 'B' or pilihan == 'b')

        {

            cout << "\t\t\t\tSilahkan Isi Form ini untuk Booking kamar\n";
            cout << "\t\t\t\tMasukkan nama depan anda : ";
            cin >> nama;
            cout << "\t\t\t\tMasukkan nama belakang anda : ";
            cin >> nama_b;
            cout << endl;
            cout << "\t\t\t\t\tMasukkan lantai berapa (1 - 30): ";
            cin >> lantai;

            if(lantai > 30 or lantai < 1)
            {

                cout << "\t\t\t\t\tHotel ini hanya ada 30 Lantai\n";
                cout << "\t\t\t\t\tCoba lagi\n";
                cout << "\t\t===============================================================================" << endl;
                continue;

            }

            cout << "\t\t\t\t\tMasukkan kamar ke berapa (1 - 15): ";
            cin >> kamar;

            if(kamar > 15 or kamar < 1)
            {

                cout << "\t\t\t\t\tKamar di setiap lantai hanya ada 15\n";
                cout << "\t\t\t\t\tCoba Lagi\n";
                cout << "\t\t===============================================================================" << endl;
                continue;

            }

            lantai -= 1;
            kamar -= 1;

            if(room[lantai][kamar].malam != 0)

            {
                cout << "\n\t\t\t\tMaaf Tuan / Nyonya " << nama;
                cout << "\n\t\t\t\tKamar sudah terisi coba lagi\n";
                cout << "\t\t===============================================================================" <<endl;

                continue;
            }

            cout << "\t\t\t\t\tLama menginap (permalam): ";
            cin >> malam;
            cout << endl;

            harga(lantai, malam);
            booking(nama, nama_b, malam, lantai, kamar);
            continue;

        }

        if(pilihan == 'C' or pilihan == 'c')
        {

            cek_k();
            continue;

        } else if(pilihan == 'T' or pilihan == 't') {

            cek_t();
            continue;

        } else if(pilihan == 'H' or pilihan == 'h') {

            bantuan();
            continue;

        } else if(pilihan == 'K' or pilihan == 'k') {

            penutup();
            break;

        } else {

            cout << "\t\t\t\t\tHuruf tidak valid\n\t\t\t\t\tCoba Lagi\n\n";
            cout << "\t\t===============================================================================\n\n";
            continue;

        }
    }

    return 0;

}
