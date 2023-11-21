#include <iostream>
using namespace std;

int main(){
	int codefilm;
	int tiket;
	int arm = 35000;
	int dis = 45000;
	int toy = 60000;
	int total = 0;
	int harga;
	char pilih;
	string judul;

	while(true){
		cout << "Selamat Datang!! Mau nonton apa?\n";
		cout << "  Kode Film\tNama Film\tHarga Tiket\n";
		cout << "\t1\tArmagedon\tRp. 35.000\n\t2\tDisneyland\tRp. 45.000\n\t3\tToy Story\tRp. 60.000\n";
		for(int i = 1; i < 55; i++){
			cout << "=";
		}
		cout << "\nMasukkan kode film yang ingin ditonton : ";
		cin >> codefilm;
		if(codefilm > 3 or codefilm < 1){
			cout << "Hanya ada 3 film disini! Coba lagi\n";
			for(int i = 1; i < 55; i++){
			cout << "=";
		}
		cout << endl;
			continue;
		}
		cout << "Banyak tiket yang ingin dibeli : ";
		cin >> tiket;
		for(int i = 1; i < 55; i++){
			cout << "=";
		}

		switch(codefilm){
			case 1 :
			total = arm * tiket;
			harga = 35000;
			judul = "Armagedon";
			break;
			case 2 :
			total = dis * tiket;
			harga = 45000;
			judul = "Disneyland";
			break;
			case 3 :
			total = toy * tiket;
			harga = 60000;
			judul = "Toy Story";
			break;
		}

		cout << endl;
		cout << judul << endl;
		cout << "Harga Tiket : Rp. " << harga << endl;
		cout << "Jumlah Pembelian : " << tiket << endl;
		if(tiket > 5)
        {
            cout << "Harga sebelum diskon : Rp. " << total;
            total *= 0.4;
            cout << "\nHarga setelah diskon : Rp. " << total << "\n(Diskon berlaku dalam pembelian lebih dari 5)" << endl;
        }
        else
        {
            cout << "Harga total : Rp. " << total << "\n(Diskon berlaku dalam pembelian lebih dari 5)" << endl;
        }

		cout << "Apakah anda mau memesan tiket lagi? (Y/N) ";
		cin >> pilih;
		if(pilih == 'Y' or pilih == 'y'){
			continue;
		} else if(pilih == 'N' or pilih == 'n'){
			cout << "Terima kasih sudah memesan tiket";
			break;
		} else {
			cout << "Huruf tidak valid";
			break;
		}
	}

}
