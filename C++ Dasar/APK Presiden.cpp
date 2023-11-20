#include <iostream>

using namespace std;

int main(){
    string nama;
    int tahun;
    int tanggal;
    int bulan;
    int komposit;
    int total;
    string kabisat;

        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "\nMasukkan Tahun : ";
        cin >> tahun;
            if(tahun < 0){
            cout << "Tahun Tidak Valid";
            return 1;
        }
        cout << "\nMasukkan Bulan : ";
        cin >> bulan;
            if(bulan < 0 or bulan > 12){
            cout << "Bulan Tidak Valid (0 - 12)";
            return 1;
        }
        cout << "\nMasukkan Tanggal : ";
        cin >> tanggal;
            if(tanggal < 0 or tanggal > 31){
            cout << "Tanggal Tidak Valid (0 - 31)";
            return 1;
        }
        cout << "\nMasukkan Limit angka yang mau dicari : ";\
        cin >> komposit;



        cout << "Bilangan Komposit dari 1 - " << komposit;
        cout << endl;
        for(int i = 2; i <= komposit; i++){

		int prima = 0;

		for(int p = 2; p * p <= i; p++){

			if(i % p == 0){
				prima = 1;
				break;

			}
		}
		if(prima){
			cout << i << " ";
			total += i;
		}
        }
        cout << "\nTotalnya = "<< total;
        if(tahun % 4 == 0){
            cout << endl << endl<< tahun << " Adalah Tahun Kabisat";
        }
        cout << endl << "Terima Kasih " << nama;
}
