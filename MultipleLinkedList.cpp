#include <iostream>
#include <string>
using namespace std;

struct Lagu{ // struct buat kebawah
    string namaLagu;
    string namaPenyanyi;
    Lagu* nextLagu;
};

struct Playlist{ // data atas
    string namaPlaylist;
    Playlist*next;
    Lagu*headLagu;
};

Playlist* head = NULL;

void tambahPlaylist(string plylist){
    Playlist*newData = new Playlist();
    newData->namaPlaylist = plylist;
    newData->next = NULL;
    newData->headLagu = NULL;

    if (head == NULL){
        head = newData;
    }else{
        Playlist*cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newData;
    }
}

void addSong(string playlist, string nama_lagu, string nama_penynyi){
    Playlist* cur = head; // membuat node baru yang akan di taro di node playlist
    while(cur!= NULL){ // jika kita sambungkan, maka ada node yang lain
        if(cur->namaPlaylist == playlist){ // kita cek apakah di node playlist ada data namaPlaylist, lalu kita cocokan dengan inputan user, jika sama program berlanjut
            Lagu* newData = new Lagu(); // buat node newData
            newData->namaLagu = nama_lagu; // newData menyimpan data ke namaLagu dan isinya adalah variabel nama_lagu
            newData->namaPenyanyi = nama_penynyi; // newData menyimpan data ke namaPenyanyiu dan isinya adalah variabel nama_penyanyi
            newData->nextLagu = NULL; // lalu kita next kan ke bawah == NULL,karena ini headLagu

            if(cur->headLagu == NULL){ // cek apakah sudah ada headLagu
                cur->headLagu = newData; // kalo belum isi headLagu dengan newData
            }else{ // kalo udah ada headLagu sebelumnya
                Lagu* temp = cur->headLagu; // kita buat variabel tem yang berfungsi mirip seperti cur, tapi dia berada di node lagu
                while(temp->nextLagu != NULL){ // kalo kita next kan ada node yang lain (tidak NULL)
                    temp = temp->nextLagu; // maka temp kita sambungkan ke node lagu berikutnya
                }
                temp->nextLagu = newData;// isi node lagu berikutnya dengan newData
            }
            return; // kembalikan nilai
        }
        cur =  cur->next; // lalu lanjut ke node playlist berikutnya
    }
}



void delSong(string nama_playlist, string nama_lagu){
    Playlist* cur = head; // kita posisikan cur pada head
    // cur berfungsi agar dia bisa melakukan cek di suatu b node

    while(cur != NULL){ // selama nodenya tidak kosong, code berlanjut
        if(cur->namaPlaylist == nama_playlist){ // jika cur menemukan node, maka dia akan lari ke namaPlaylist, dan kemudian di bandingkan dengan nama_playlist
            // jika datanya sama, code berlanjut
            Lagu* l = cur->headLagu; // l adalah cur yang menyambung, dimana cur atau l akan menyambung ke headLagu
            Lagu* prev = NULL; // prev seperti asistennya l

            while(l != NULL){ // apabila head lagu kosong, code berlanjut
                if(l->namaLagu == nama_lagu){ // cek datanya sama atau tidak
                    if(prev == NULL){ // jika prev nemu kalo nodenyan kosong
                        cur->headLagu = l->nextLagu; // cur akan ke nexLagu lalu l akan mencari lagu
                    }else{ // jika tidak
                        prev->nextLagu = l->nextLagu; // prev dan l ke next lagu
                    }
                    delete l; // setelah ketemu data lagunya, kita delete dengan keyword
                    cout<<"Lagu telah dihapus"<<endl; // cetak ini
                    return; // code berhenti
                }
                prev = l;
                l = l->nextLagu;
            }
            
            cout<<"Lagu tidak ditemukan"<<endl; // kalo lagu gk ditemukan, cetak ini
        }
        cur = cur->next; // lalu kita next ke node playlist selanjutnya
    }
    cout<<"Playlist tidak ditemukan\n"<<endl;// cetak ini jika data kosong
}

void del_Playlist(string nama_playlist){
    Playlist* cur = head;
    Playlist* prev = NULL;
    while(cur != NULL){
        if(cur->namaPlaylist == nama_playlist){

            Lagu* l = cur->headLagu;
            while(l != NULL){
                Lagu* del = l;
                l = l->nextLagu;
                delete del;
            }

            if(prev == NULL){
                head = cur->next;
            }else{
                prev->next = cur->next; 
            }
            delete cur;
            cout<<"Playlist telah dihapus"<<endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout<<"Playlist tidak ditemukan"<<endl;
}

void tampil(){
    Playlist* cur = head;
    if(cur == NULL) {
        cout << "Database Playlist Kosong." << endl;
        return;
    }

    while(cur != NULL){
        cout<<"==============================================="<<endl;
        cout << "Nama Playlist : " << cur->namaPlaylist << endl;
        cout << "Daftar Lagu : \n";
        
        Lagu* temp = cur->headLagu;
        if(temp == NULL){
            cout << "\t(Tidak ada lagu)" << endl;
        } else {
            string penyanyiAwal = temp->namaPenyanyi;
            bool semuaSama = true; 
            Lagu* checkTemp = cur->headLagu;
            while(checkTemp != NULL){
                cout << "\t" << checkTemp->namaLagu << endl;
                if(checkTemp->namaPenyanyi != penyanyiAwal){
                    semuaSama = false; 
                }
                checkTemp = checkTemp->nextLagu;
            }
            if(semuaSama){
                cout << "\t(Oleh Penyanyi: " << penyanyiAwal << ")" << endl;
            } else {
                cout << "        (Playlist Campuran - Penyanyi berbeda)" << endl;
            }
            cout<<"==============================================="<<endl;
        }
        cout << endl; 
        cur = cur->next;
    }
}

int main(){
    tambahPlaylist("Dangdut Kece");
    addSong("Dangdut Kece","Kok koyo ngene","Gading");
    tambahPlaylist("Hindia");
    addSong("Hindia","Kita Kesana","Baskara");
    addSong("Hindia","Rumah ke rumah","Baskara");
    addSong("Hindia","Evaluasi","Baskara");
    tampil();
    delSong("Hindia","Kita Kesana");
    tampil();
    
    return 0;
}
