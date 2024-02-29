#include <iostream>
using namespace std;

int main(){
    int umur;
    int *pumur;
    int **ppumur;

    cout << "Masukkan umur kalian : ";
    cin >> umur;

    cout << "\n================================================\n";

    pumur = &umur;
    ppumur = &pumur;

    cout << "Nilai umur dari masukkan : " << umur << endl;
    cout << "Nilai pumur : " << *pumur << endl;
    cout << "Nilai ppumur : " << *ppumur << endl; 
}