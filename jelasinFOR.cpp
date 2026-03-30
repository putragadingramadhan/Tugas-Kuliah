#include <iostream>

int main(){
    // Membuat bintang segitiga (tanpa AI)

    int input = 5;//ini adalah nilai awal

    for(int i = 1;i<input;i++){
        // for pertama berfungsi untuk membuat berapa banyak baris kebawah
        for(int s =0;s<=(input-i);s++){// for kedua berfungsi untulk mewmbuat sepasi
            // dengan spasi pertama ini 5 (sesuai dengan nilai awal) kemudia akan terus dikurangi satu
            std::cout<<" ";
        }
        for (int j = 0;j<(i*2)-1;j++){
            // for keduaberfungsi untuk print {*} dengan panjang ke samping
            std::cout<<"*";
        }
        std :: cout<<std::endl;
    }
    /*Cara kerja lengkapnya
    1. Kita masukkan input awal
    2. Setelah itu aka di proses
        -for pertama berfungsi untuk membuat baris ke bawah, jadi banyaknya for i akan di cout ke bawah
        -for kedua berfungsi untuk memnbuat bintang ke samping, dengan rumus (i*2)-1 yang akan selalu menghasilkan bilangan ganjil
        -lalu kita cetak * sebagai pengganti dari angka
    3. cout terakhir berfungsi seperti entar, setial selsai 1 siklus, siklus berikutnya akan di cetak di bawah
    */
    return 0;
}