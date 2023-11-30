#include <iostream>
using namespace std;

// Struktur untuk kamar hotel
struct Room {
    int roomNumber;
    bool isAvailable;
    double price;
};

// Fungsi untuk memilih lantai dan ruangan
void selectRoom(Room hotelRooms[], int floors, int roomsPerFloor) {
    int selectedFloor, selectedRoom;

    cout << "Pilih lantai (1-" << floors << "): ";
    cin >> selectedFloor;

    if (selectedFloor < 1 || selectedFloor > floors) {
        cout << "Lantai tidak valid." << endl;
        return;
    }

    cout << "Pilih ruangan (1-" << roomsPerFloor << ") di lantai " << selectedFloor << ": ";
    cin >> selectedRoom;

    if (selectedRoom < 1 || selectedRoom > roomsPerFloor) {
        cout << "Ruangan tidak valid." << endl;
        return;
    }

    int roomIndex = (selectedFloor - 1) * roomsPerFloor + selectedRoom - 1;

    if (hotelRooms[roomIndex].isAvailable) {
        cout << "Reservasi untuk Kamar " << hotelRooms[roomIndex].roomNumber << " berhasil." << endl;
        hotelRooms[roomIndex].isAvailable = false;
    } else {
        cout << "Kamar tidak tersedia." << endl;
    }
}

int main() {
    const int numberOfFloors = 3;
    const int roomsPerFloor = 5;
    const int totalRooms = numberOfFloors * roomsPerFloor;
    Room hotelRooms[totalRooms];

    // Inisialisasi informasi kamar
    for (int i = 0; i < totalRooms; ++i) {
        hotelRooms[i].roomNumber = i + 1;
        hotelRooms[i].isAvailable = true;
        hotelRooms[i].price = 100.0; // Harga kamar
    }

    // Contoh penggunaan fungsi selectRoom
    selectRoom(hotelRooms, numberOfFloors, roomsPerFloor);

    return 0;
}
