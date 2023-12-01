#include <iostream>
using namespace std;



struct daftar
{
    string nama;
    string paket;
    int malam;
};
daftar room[5][3] = {{{"k","k", 0}, {"k", "k", 0}, {"k", "k", 0}}, {{"k","k", 0}, {"k", "k", 0}, {"k", "k", 0}}, {{"k","k", 0}, {"k", "k", 0}, {"k", "k", 0}}, {{"k","k", 0}, {"k", "k", 0}, {"k", "k", 0}}, {{"k","k", 0}, {"k", "k", 0}, {"k", "k", 0}}};
char pilihan;



void opening()
{
    cout << "Selamat datang\n";
}

void pengunjung(string nama, string paket, int malam, int lantai, int kamar)
{

    if(room[lantai][kamar].nama != "k")

    {
        cout << "Maaf Tuan / Nyonya " << nama;
        cout << "\nKamar sudah terisi coba lagi\n";

    } else {

        room[lantai][kamar] = {nama, paket, malam};
        kamar += 1;
        lantai += 1;
        cout << "Kamar " << kamar << " di lantai " << lantai << " sudah di isi atas nama " << nama;
        cout << "\nDengan paket " << paket << " Selama " << malam << " malam";
        cout << "\nPendataan sudah berhasil\nApa yang ingin kamu lakukan selanjutnya?";
        cout << endl;
    }

}

void data_p()
{
    int lantai;
    int kamar;

        cout << "Masukkan lantai berapa : ";
        cin >> lantai;
        cout << "Masukkan kamar ke berapa : ";
        cin >> kamar;

        lantai -= 1;
        kamar -= 1;

        if(room[lantai][kamar].nama == "k")

        {
            cout << "Kamar yang anda sebutkan saat ini sedang kosong\n"; 

        } else {

            cout << "Kamar yang anda sebutkan saat ini sedang di isi oleh Tuan / Nyonya " << room[lantai][kamar].nama;
            cout << "\nApa yang ingin kamu lakukan selanjutnya?\n";
        }

}

void harga(string paket, int malam)
{
    int total;
        if(paket == "VIP" || paket == "vip")

        {
            total = malam * 200;
            cout << "Harga paket VIP adalah 200$. Biaya Penginapan mu : " << total << "$\n";

        } else if(paket == "Reguler" || paket == "REGULER" || paket == "reguler") {

            total = malam * 100;
            cout << "Harga paket Reguler adalah 100$. Biaya Penginapan mu : " << total << "$\n";
        }

}

void pemilihan()
{
    cout << "Mendaftar[M]    Cek[C]    Keluar[K] : ";
    cin >> pilihan;
}

void penutup()
{
    cout << "Terima kasih sudah memakai jasa pelayanan kami";
    cout << "\nSemoga hari mu menyenangkan";
}



int main()
{
    string nama;
    string paket;
    int malam;
    int lantai;
    int kamar;
    
    opening();

    while(true)
    {

        pemilihan();

        if(pilihan == 'M' or pilihan == 'm')

        {
        cout << "Masukkan nama anda : ";
        cin >> nama;
        cout << "Masukkan paket : ";
        cin >> paket;
        cout << "Masukkan lantai berapa : ";
        cin >> lantai;
        cout << "Masukkan kamar ke berapa : ";
        cin >> kamar;
        cout << "Lama menginap : ";
        cin >> malam;

        lantai -= 1;
        kamar -= 1;

        harga(paket, malam);
        pengunjung(nama, paket, malam, lantai, kamar);
        continue;

        }
        if(pilihan == 'C' or pilihan == 'c')
        {
            data_p();
            continue;

        } else if(pilihan == 'M' or pilihan == 'm') {
            continue;
            
        } else if(pilihan == 'K' or pilihan == 'k') {

            penutup();
            break;

        } else {

            cout << "Huruf tidak valid\nSelamat Tinggal!";
            break;

        }

    }

    return 0;

}