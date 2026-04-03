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

void input() {
    int s;
    int counter = 1; // Agar user tahu ini input data ke-berapa

    while (true) {
        cout << "\nInput ke-" << counter << endl;
        cout << "Masukkan panjang jalan: ";
        cin >> s;

        // selesai jika user input 999
        if (s == 999) {
            cout << "Input dihentikan (999)." << endl;
            break; 
        }

        // jika input >= 60, data di simpan
        if (s >= 60) {
            if (isFull()) {
                cout << "Stack Penuh! Tidak bisa simpan " << s << endl;
                break; // penuh = selesai
            } else {
                push(s); //tambahka data ke stack
                cout << "Data " << s << " berhasil disimpan ke Stack." << endl;
                counter++; // tambah nomor urut input hanya jika berhasil simpan
            }
        } 
        // inputan <60, keluarkan isi data dan berhentika program
        else {
            cout << "Input < 60 terdeteksi." << endl;
            pop(); // Jalankan output dulu 
            cout << "Program dihentikan karena input kurang dari 60." << endl;
            break; 
        }
    }
}

void display() {
    if (isEmpty()) {
        cout << "\nStack sekarang kosong." << endl;
    } else {
        cout << "\nIsi Stack saat ini (dari atas ke bawah):" << endl;
        for (int i = maksimal-1; i >=0; i--) { // ambil datanya dari index terakhir (Fist in Last Out)
            cout << "Data index [" << i << "] : " << panjang_jalan[i] << endl;
        }
    }
}

int main() {
    input();
    display();
    return 0;
}