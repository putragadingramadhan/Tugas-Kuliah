#include <iostream>
using namespace std;

int maksimal = 10; // maksimal data yang dapat di simpan
int panjang_jalan[10]; // isi index dan untuk simpan data nya
int top = 0; //

bool isFull() {
    return top == maksimal; // jika masih belum penuh, outpunya akan 0, dan akan 1 jika full
}

bool isEmpty() {
    return top == 0; // akan 1 jika datanya kosong
}

void pop() {
    // Cek kosong atau tidak
    if (isEmpty()) {
        cout << "Stack Kosong." << endl;
    } else {
        top--; // Kurangi top untuk ambil data terakhir yang masuk
        cout << "Mengeluarkan data terakhir: " << panjang_jalan[top] << endl;
    }
}

void push(int s) {
    // push untuk memasukkan data ke array
    panjang_jalan[top] = s;
    top++;
}

void display() {
    if (isEmpty()) {
        cout << "\nStack sekarang kosong." << endl;
    } else {
        cout << "\nIsi Stack saat ini (dari atas ke bawah):" << endl;
        for (int i = top-1; i >=0; i--) { // ambil datanya dari index terakhir (Fist in Last Out)
            cout << "Data index [" << i+1 << "] : " << panjang_jalan[i] << endl;
        }
    }
}

void input() {
    int s;

    for(int max = 1;max<=10;max++){
        cout << "\nInput ke-" << max << endl;
        cout << "Masukkan panjang jalan: ";
        cin >> s;

        // selesai jika user input nilai 999, dan  999 tidak akan di simpan ke stack
        if (s == 999) {
            cout<<"Input terdeteksi 999.\n" << "Input dihentikan." << endl;
            break; 
        }

        // jika input >= 60, data di simpan
        else if (s >= 60) {
            if (isFull()) {
                cout << "Stack Penuh! Tidak bisa simpan " << s << endl;
                break; // penuh = selesai
            } else {
                push(s); //tambahka data ke stack
                cout << "Data " << s << " berhasil disimpan ke Stack." << endl;
            }
        } 
        // inputan <60, keluarkan isi data dan berhentika program
        else{
            cout<<"Input <60, terdeteksi"<<endl;
            // push(s);
            if(isEmpty()){
                cout<<"Stack kosong.\nPorgram bertenti"<<endl;
                break;
            }else{
                cout<<"Data sementara ditampilkan"<<endl;
                // push(s);
                display();
                max--; // tambah nomor urut input hanya jika berhasil simpan
                // max ++;
                // continue;
                // break;
            }
        }
    } 
}

void kondisi_stack(){
    cout<<"\n===KONDISI STACK==="<<endl;
    if(isEmpty()){
            cout<<"kosong"<<endl;
    }
    if(isFull()){
        cout<<"penuh"<<endl;
    }else{
        cout<<"bisa diisi (tidak penuh)"<<endl;
    }
    if(!isEmpty()){
        cout<<"ada isiya"<<endl;
        cout<<"jumlah data stack saat ini "<< top <<endl;
    }

}
int main() {
    input();
    display();
    kondisi_stack();
    return 0;
}