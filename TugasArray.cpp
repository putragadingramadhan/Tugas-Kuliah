#include <iostream>
#include <string>
#include <iomanip>

// using namespace std;
int main(){

    /*
    sebuah kelas ingin menata pasangan meja dan kursi secara berurutan dengan metode array dua dimensi
    semua mahasiswa sepakat untuk menyusun meja dan kursi menjadi 2 baris kebelakang dan 5 baris kesamping,
    kemudian untuk melakukanya mahasiswa menggunakan array dua dimensi untuk melakukan pemetaan*/
    int latihan [2][5];
    for (int b = 0;b<2;b++){
        for(int k=0;k<5;k++){
            std :: cout<<"Baris meja ke : "<<b+1<<" kolom meja ke : "<<k+1 << " : ";
            std :: cin>>latihan[b][k];
        }
        std :: cout<<std :: endl;
    }
    /*
    Cara kerja nested for atau LOGIKA UNDER-THE-HOOD
    jadi for pertama akan bekerja dan menghasilkan ouput 0, lalu ke for ke dua, nah disini akan di proses hingga kodisi foe kedua sudah habis
    setelah itu akan kembali ke for pertama, lalu ke for kedua lagi sampai prosesnya selesai
    Ibarat kita mengisi satu baris kursi sampai penuh dari kiri ke kanan, 
    baru pindah ke baris di belakangnya.
    */
    
    // untuk cetak 
    for(int b=0;b<2;b++){
        for(int k=0;k<5;k++){
            std :: cout<< std:: setw(5)<<latihan[b][k];//untuk membuat output seperti tabel dengan 5 kolom ke samping
        }
        std :: cout<<std :: endl;//pindah baris setelah kolom ke 5
    }
    return 0;
}