#include <iostream>

void kuadrat (int *hasil){
    *hasil = (*hasil) * (*hasil);
}
void tambah (int angka, int number, int *hasil){
    *hasil = angka + number;
    kuadrat(&(*hasil));
}
void tuker (int *x,int *y){
    int temp = *x;
    *x = *y;
    *y=temp;
}


int main(){
    int angka,number,hasil;
    int *C = &hasil; // (*) buat pointer, (&) alamat
    angka = 5;
    number = 5;
    tambah(angka,number,C);
    std :: cout<< "Hasil : " << *C << " dari alamt " << C<<std::endl; 

    //konsep new dan delete di pointer
    int * ptr = new int;
    while (true){
        int pilihan;
        std :: cout << "Masukkan angka : " ;
        std :: cin >> pilihan;
        if (pilihan < 100){
            *ptr = 100;
            std :: cout << "Lahan sudah dipesan " << ptr<< std :: endl;
            continue;
        }else{
            delete ptr;
            std :: cout << "Lahan sudah dijual " << ptr <<std :: endl;
            break;
        }
    }
    return 0;
}