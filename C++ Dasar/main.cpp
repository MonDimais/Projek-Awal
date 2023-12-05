#include <iostream>
using namespace std;

//membuat fungsi menggunakan struct
struct daftar
{
    string nama;
    string paket;
    int malam;
};

//daftar kamar dan lantai yang akan diinput
daftar room[30][15];
char pilihan;

//output selamat datang
void opening()
{
    cout << endl;
    cout << "\t\t===============================================================================" << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t\t\t\t   SELAMAT DATANG DI HOTEL DIMS                          " << endl;
    cout << "\t\t\t\t   TEMPAT TERNYAMAN UNTUK ISTIRAHAT DENGAN TENANG                " << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t===============================================================================" << endl;
}

void bantuan()
{

    cout << "INFORMASI BANTUAN UNTUK BOOKING HOTEL\n";
    cout << "\n## Hotel ini mempunyai 30 lantai dan 15 kamar setiap lantai\n";
    cout << "## Lantai 1 - 15 untuk Reguler dan Lantai 16 - 30 untuk VIP\n";
    cout << "## Sistem Pembayaran di hitung 1 malam\n";
    cout << "## Permalam untuk Reguler 100$ dan untuk VIP 200$\n";

}

//menggunakan if else untuk menentukan paket/kamar/lantai serta tipe kamar vip/reguler
void pengunjung(string nama, int malam, int lantai, int kamar)
{
    string nama_p;

    if(lantai <= 15 and lantai >= 1)
    {
        nama_p = "Reguler";
    } else {
        nama_p = "VIP";
    }

    if(room[lantai][kamar].malam != 0)

    {
        cout << "\n\t\t\t\tMaaf Tuan / Nyonya " << nama;
        cout << "\n\t\t\t\tKamar sudah terisi coba lagi\n";
        cout << "\t\t===============================================================================" <<endl;

    } else {

        room[lantai][kamar] = {nama, nama_p, malam};
        kamar += 1;
        lantai += 1;
        cout << "\t\t\t\tKamar " << kamar << " di lantai " << lantai << " sudah di isi atas nama " << nama;
        cout << "\n\t\t\t\tDengan paket " << nama_p << " Selama " << malam << " malam";
        cout << "\n\n\t\t\t\t\t\tPemesanan sudah berhasil!!!";
        cout << "\n\t\t===============================================================================" << endl;
        cout << "\n\t\t\t\tApa yang ingin kamu lakukan selanjutnya?";
        cout << endl;
    }

}

//fungsi untuk menujukkan nama yang ada di lantai dan kamar
void data_k()
{
    int lantai;
    int kamar;

        cout << "\t\t\t\t\tMasukkan lantai berapa : ";
        cin >> lantai;
        cout << "\t\t\t\t\tMasukkan kamar ke berapa : ";
        cin >> kamar;

        lantai -= 1;
        kamar -= 1;

        if(room[lantai][kamar].malam == 0)

        {
            cout << "\n\t\t\t\tKamar yang anda pilih saat ini sedang kosong\n";
            cout << "\t\t===============================================================================" <<endl;

        } else {

            cout << "\n\t\t\tKamar yang anda sebutkan saat ini sedang di isi oleh Tuan / Nyonya " << room[lantai][kamar].nama;
            cout << "\n\t\t===============================================================================" <<endl;
            cout << "\n\t\t\t\tApa yang ingin kamu lakukan selanjutnya?\n";
        }

}

void data_p()
{
    int lantai;
    string nama;

    cout << "Ingin mencari kamar atas nama Siapa? ";
    cin >> nama;
    cout << "Ingin mencari di lantai berapa (1 - 30) ";
    cin >> lantai;

    lantai -= 1;

    for(int i = 0; i <= 15; i++){
        if(room[lantai][i].nama == nama)
        {

            i += 1;
            lantai += 1;
            cout << "Kamar No " << i << " di lantai " << lantai;
            cout << "\nSaat ditempati oleh Tuan/Nyonya " << nama;
            i = 0;
            break;

        } else if(i == 15) {

            cout << "Sepertinya tidak ada tamu atas nama " << nama << " di Lantai ini";
            cout << "\nSilahkan Coba Lagi";
            i = 0;
            break;

        }
    }

    cout << "\nApa yang ingin anda lakukan selanjutnya? ";

}

//fungsi untuk menghitung harga dan memunculkan harga total
void harga(int lantai, int malam)
{
    int total;

    if(lantai <= 15 and lantai >= 1)
    {
        total = malam * 100;
        cout << "Kamar yang kamu pilih adalah kamar Reguler\n";
        cout << "Harga total penginapan selama " << malam << " adalah : " << total;

    } else if(lantai >= 16 and lantai <= 30) {
        total = malam * 200;
        cout << "Kamar yang kamu pilih adalah kamar VIP\n";
        cout << "Harga total penginapan selama " << malam << " adalah : " << total;

    }

    cout << endl;

}

//fungsi untuk memilih menu aksi
void pemilihan()
{
    cout << "\t\t\t\tSilahkan pilih menu yang anda inginkan" << endl;
    cout << "\t\t\tBooking kamar[B]   Cek kamar[C]   Cari Tamu[T]   Bantuan [H]   Keluar[K] : ";
    cin >> pilihan;
}

//output terima kasih
void penutup()
{
    cout << "\t\t===============================================================================" <<endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t\t\tTERIMA KASIH TELAH MEMILIH HOTEL DIMS " << endl;
    cout << "\t\t\tSEBAGAI TEMPAT PERISTIRAHATAN ANDA" << endl;
    cout << "\t\twwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    cout << "\t\t===============================================================================" <<endl<<endl;
}

int main()
{
    string nama;
    int malam;
    int lantai;
    int kamar;

    opening();

    while(true)
    {

        pemilihan();

        if(pilihan == 'B' or pilihan == 'b')

        {

        cout << "\t\t\t\t\tMasukkan nama anda : ";
        cin >> nama;
        cout << endl;
        cout << "\t\t\t\tSilahkan mengisi form berikut: " << endl;
        cout << "\t\t\t\t\tMasukkan lantai berapa (1 - 30): ";
        cin >> lantai;
        cout << "\t\t\t\t\tMasukkan kamar ke berapa (1 - 15): ";
        cin >> kamar;
        cout << "\t\t\t\t\tLama menginap (permalam): ";
        cin >> malam;
        cout << endl;

        lantai -= 1;
        kamar -= 1;

        harga(lantai, malam);
        pengunjung(nama, malam, lantai, kamar);
        continue;

        }

        if(pilihan == 'C' or pilihan == 'c')
        {
            data_k();
            continue;

        } else if(pilihan == 'B' or pilihan == 'b') {

            continue;

        } else if(pilihan == 'T' or pilihan == 't') {

            data_p();
            continue;

        } else if(pilihan == 'K' or pilihan == 'k') {

            penutup();
            break;

        } else if(pilihan == 'H' or pilihan == 'h') {

            bantuan();
            continue;

        } else {

            cout << "Huruf tidak valid\nSelamat Tinggal!";
            break;
        }
    }

    return 0;
}
