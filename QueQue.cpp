#include <iostream>
#include <string> // tipe data string di c++ itu tidak ada secara default, makanya kita perlung panggil library dulu
using namespace std;

// Jika di contoh modul menggunakan logika dengan front yang maju (dari index 0 ke 1 dst)
//  maka di code saya yang maju adalah antrian nya (rear -- dan front tetap == 0)
#define MAX 5 // MAX adalah jumlah index maksimal untuk mengisi data Queue
string antrian_Belanja[MAX]; // untuk menyimpan antrian sebelum di proses
// variable ini akan menyimpan 5 data dengan index 0 1 2 3 4
int front = -1,rear = -1; /*Jika kita ibaratkan, front ini sebagai resepsonis yang menunggu antrian
dan rear adalah antrian terakhir di data
pada logika saya, rear lah yang akan maju menghampiri frot, agar ketika kita ingin memasukkan data lagi
cukup kita proses Queue pertama maka otomatis Queue terakhir akan kosong dan dapat di isi*/

bool isFull(){ // di function dengan tipe data boolean, apabila nilainya sesuai dengan kondisi, akan bernilai 1 (T)
    return rear == MAX-1; // seperti yang diketahui tadi, bahwa rear adalah jumlah antriannya
    // jika rear == 4, maka antrian sudah penuh. Lalu kenapa nilai MAX-1?
    // jarena index dimulai dai 0
}
bool isEmpty(){
    return front == -1 || front > rear; // di sini kita menggunaka  logika OR, dimana salah satunya T maka hasilnya akan T
    // di function ini kita ingin mengetaui apakah antriannya kosong
    // dengan indikasi front ==-1 atau front lebih dari rear
    // apabila salah satunya terpenuhi, maka akan menghasilkan output 1 (T) secara otomatis
}
// sebelumnya di stcak kita pengenah istilah push
//EnQueue berperan sama yakni sebagai alah untuk mengisi data antrian
void EnQueue(string data){ // kita menggunakan void karena ditak mengembaikan nilai apapun
    // didalam function kita menggunakan parameter data dengan tipe data string
    if(isFull()){ // pertama yang harus dilakukan adalah cek apakah antrian penuh
        cout<<"Antrian Penuh"<<endl; // jika penuh akan menampilkan ini
        return; // return disini hanya berfungsi seperti break
    }
    if(front == -1){
        front = 0; // tadi diatas kita deklarasikan front == -1
        // karena aturan index yang memulai angka dari 0, maka kita perlu ubah dulu
        // dengan kondisi jika front == -1,  kita ubah jadi 0
    }
    rear ++; // begitupun dengan rear, kita pelu ubah ke 0, agar index dapat digunakan
    antrian_Belanja[rear] = data; // simpan data berdasarkan index rear
    cout<<"Atas nama "<<data<<" telah masuk ke antrian"<<endl; // jika antrian berhasil disimpan, akan menampilkan datanya
}

// DeQueue berfungsi untuk melayani atau memproses antrian
// antrian pertama adalah index ke-0, antrian yang sudah di proses akan di hapus (mirip pop di stack)
//setelah itu index ke-1 akan maju, dan seterusnya
void DeQueue(){
    if(isEmpty()){ // cek dulu apakah antrian kosong menggunakan parameter dari function isEmpty
        cout<<"Data Kosong"<<endl; // jika antrian kosong, makan akan mencetak data kosong
        return; // return disini bukan untuk mengembalikan nilai/data, tapi lebih berfungsi sebagai break
    }

    cout <<"Antrian atas nama "<< antrian_Belanja[0]<<" telah selesai mengantri" <<endl; // antrian dimulai dengan index rear ke-0
    for(int i = 0; i <rear;i++){
        antrian_Belanja[i] = antrian_Belanja[i+1]; // lalu antrian akan berlanjut ke index selanjutnya
        // karena index 0 sudah d poses di line 53, dan loop di mulai dari index 0, makan indexnya kita tambah 1
    }
    rear --; // nah disini bedanya
    // pada contoh modul front ++, karena logika aku rear yang menuju ke front, makan rear --
    if(rear == -1){front = -1;}// jika rear sudah kosong atau rear == -1, kita akna mengintruksikan frong untuk ke nilai -1 juga
    // karena sudah tidak ada lagi antian yang akan di proses
}

// disini, saya ingin menambahkan function count
// count berfungsi agar kita mengetahui antrian sudah sampai maan, dengan menggunakan rumus (rear-front)+1
void count(){
    cout<<"Jumlah antrian saat ini "<<(rear-front)+1<<endl;
    // misal rear di index 4 (full) dan frong tetap di 0
    // makan (4-0) = 0 + 1 = 5, ini adalah buktu rumusnya
}

// fungsi clear berfungsi untuk menghapus seluruh antrian
void Clear(){
    if(isEmpty()){ // cek dulu apakah data kosong, kalo kosong apa yang mau di hapus?
        cout<<"Sudah tidak ada antrian"<<endl;
        return;
    }
    // sebetulnya kita bisa saja langsung merubah front dan rear == -1
    // akan tetapi saya takut kalo datany tidak benar-benar terhapus
    // oleh karena ini, saya ingin menghapus datanay secara satu persatu dari belakang
    for(int i = rear; i>=0;i--){ // isalkan rear == 4, makan akan menghasilkan 4,3,2,1,0
        cout<<antrian_Belanja[i]; // kita hapus dari index ke 4 dahulu, kemudian ke index yang lebih kecil
        if(i == 0){cout<<", ";} // kalo sudah di index 0, aku pengan ada tanda ',' sebagai pemisah
    }
    rear = -1; // baru setelah itu rear dan front kita ubah kosong kan, menjadi = -1
    front = -1;
    cout<<"Semua antrian sudah dihapus"<<endl;
}

// function display berfungsi untuk menapilkan seluruh antrian
void Display(){
    if(isEmpty()){ // cek apakah datanya kosong, kalo kosong apanya yang mau di tempilkan?
        cout<<"Antrian kosong"<<endl;
        return;
    }
    cout<<"\n"<<endl;

    // sesuai dengan prinsip FIFO, maka yang akan kita tampilkan dari index ke 0 dahulu
    for(int i =0;i<=rear;i++){ // nilai rear maksimal sampai 4
        cout<<"Data antrian ke ["<<i+1<<"] atas nama "<< antrian_Belanja[i]<<endl; // mencetak semua antrian dari index ke 0
        // kenapa i+1? seperti yang sudah dijelaskan bahwa kita akan menampilkan antrian ke 0, agar tidak menampilkan 0, kita tambahkan i dengan 1 agar dimulai dari 1
    }
}

// function kodisi bertujuan untuk mengetahui sisan antrean yang tersedia
void kondisi(){
    if(!isFull()){ // kita cek apakah antrean belum full
        cout<<"Masih ada antrian yang kosong "<<(MAX-1)-rear<<endl; // jika tidak makan akan menampilkan ini
        // kenapa (MAX -1)-rear?
        // max itu bernilai 5
        // karena index dari 0 - 4, maka MAX kita kurangkan dengan 1
        // misal rear == 3. (5-1) - 3 = 1
        // dan sisa antrean adalah 1
    }else{
        cout<<"Antrian Penuh"<<endl; // jika penuh, akan mencetak ini
    }
}

int main(){
    //kemudian tinggal kita panggil parameter dari masing-masing fungtion
    cout<<"Antrian Bank"<<endl;
    EnQueue("Bambang");
    EnQueue("Tri Ratmo");
    EnQueue("Slamet");
    kondisi();
    Display();
    // DeQueue();
    Clear();
    Display();
    EnQueue("Bambang");
    EnQueue("Tri Ratmo");
    EnQueue("Slamet");
    kondisi();
    Display();
    count();
    return 0;
}