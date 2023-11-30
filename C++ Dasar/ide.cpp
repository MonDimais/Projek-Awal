#include <iostream>
using namespace std;

string room[5][3] = {{"k", "k", "k"}, {"k", "k", "k"}, {"k", "k", "k"}, {"k", "k", "k"}, {"k", "k", "k"}};
char pilihan;

void opening()
{
    cout << "Selamat datang\n";
}

void pengunjung(string nama, int lantai, int kamar)
{

    if(room[lantai][kamar] != "k")
    {
        cout << "Maaf Tuan / Nyonya " << nama;
        cout << "\nKamar sudah terisi coba lagi\n";
    }
    else
    {
        room[lantai][kamar] = nama;
        kamar += 1;
        lantai += 1;
        cout << "Kamar " << kamar << " di lantai " << lantai << " sudah di isi atas nama " << nama;  
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

    if(room[lantai][kamar] == "k")
    {
        cout << "Kamar yang anda sebutkan saat ini sedang kosong\n"; 
    } else {
        cout << "Kamar yang anda sebutkan saat ini sedang di isi oleh Tuan / Nyonya " << room[lantai][kamar];
        cout << "\nApa yang ingin kamu lakukan selanjutnya?\n";
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
    int lantai;
    int kamar;
    
    opening();

    while(true)
    {
        cout << "Masukkan nama anda : ";
        cin >> nama;
        cout << "Masukkan lantai berapa : ";
        cin >> lantai;
        cout << "Masukkan kamar ke berapa : ";
        cin >> kamar;

        lantai -= 1;
        kamar -= 1;

        pengunjung(nama, lantai, kamar);

        pemilihan();


        while (true)
        {
            if(pilihan == 'C' or pilihan == 'c')
            {

                data_p();
                pemilihan();
                continue;
            
            } else {
                break;
            }
        }

        if(pilihan == 'M' or pilihan == 'm')
        {
            continue;
        }

        else if(pilihan == 'K' or pilihan == 'k')
        {
            penutup();
            break;
        }

        else
        {
            cout << "Huruf tidak valid\nSelamat Tinggal!";
        }

    }

    return 0;

}