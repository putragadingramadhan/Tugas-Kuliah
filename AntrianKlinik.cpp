/*
Sebuah rumah sakit/klinik menggunakan layanan pemdaftaran online via whatsApps
Pelanggan/pasien akan mengirim data nama,alamat,tanggal. Setelah user mengirim data tersebut, pihak klinik langsung mengirimkan nomr antria secara otomatis
jumlah nomor antrian dibatasi hanya 100 antrian, dengan resepsionis melakukan input data dihari yang sama.
Masalah : 
    1. Pelanggan datang secara acak (tidak sesuai urutan)
    2. Pasien melakukan reservasi secara acak juga
Solusi : 
    Membuat program yang memungkinkan melakukan sorting berdasarkan no antrian

Disini saya coba mengimplementasikan Queue dengan Linked List (single) dengan vitur tambahan sorted pada enQueue
*/
#include <iostream>
#include <string>
using namespace std;
struct AntrianKlinik{
    string nama, alamat, tanggal; // tanggal disini untuk mengetahui kapan pasie chat wa
    int noAntrian;
    AntrianKlinik*next;
};

AntrianKlinik *rear = NULL, *front = NULL;

bool isEmpty(){
    return front == NULL; // karena front itu seperti head, maka logikanya kita cuman perlu front == NULL
    // jika front gk null, akan menghasilkan output 0, jika benar  null maka akan 1
}
int count(){
    int jumlah = 0 ; // deklarasikan dulu sebagai 0
    AntrianKlinik*temp = front; // bikin variabel bayangan temp, dengan nilai awal sebagai front/head
    while(temp!= NULL){ // jika temp isinya gk NULL
        jumlah ++; // jumlah ditambah 1
        temp = temp->next; // temp ke Node berikutnya
    }
    return jumlah; // kembalikan nilai jumlah
}
void enQueue(string data[3], int antrian){
    // jika reservasi pasien lebih dari 100, maka antrian penuh
    if(count()>100){ 
        cout<<"Antrian penuh"<<endl;
        return;
    }
    AntrianKlinik*newData = new AntrianKlinik();// buat node baru
    newData->nama = data[0];//index 0 untuk nama
    newData->alamat = data[1];//index 1 untuk alamat
    newData->tanggal = data[2];//index 2 untuk tanggal
    newData->noAntrian = antrian;//untuk nomor antrian

    AntrianKlinik*temp = front; // buat temp sebagai variable bayangan dengan nilai awal berada di front/head
    // apabila belum ada head, maka newData pertama sebagai head/front dan rear berada diposisi tersbut bersamaan dengan front
    if(isEmpty()){
        front = rear = newData;
    }
    // disini saya coba langsung melakukan sorting, yakni mengurutkan data berdasarkan nomor antrian pasien
    // di else if ini, kita sudah punya data front/head, lalu saya ingin membandingkan dengan semua data setelah head/front
    // jika setelah dibandingkan dengan front no antrian lebih kecil, maka Node tersebut yang akan jadi front
    // why?? agar mudah aja si kalo kita udah punya node awal yang urut, tinggal kita sorting data di belakangnya
    else if(antrian<front->noAntrian){ // jika antrian lama kurang dari antian baru
        newData->next = front; 
        front =newData;// newData akan menjadi front/head
    }else{
        // baru urutkan  data setelahnya
        while(temp->next != NULL && temp->next->noAntrian<antrian){ //jika temp ke next Node masih ada data Node
            // dan temp ke Node berikutnya, jika no antrian lama lebih kecil dari nomor antrian di node berikutnya
            temp = temp->next; // maka
        }
        // baru kita masukkan datanya
        newData->next = temp->next;
        temp->next = newData;
        if(newData->next == NULL){
            rear = newData;
        }
    }
    cout<<"Nomor antrian : "<<antrian<<" berhasil ditambah"<<endl; // jida data sudah masuk dan sudah diurutkan,cetak line ini
}
// deQueue berfungsi untuk melakukan proses antrian pertama
void deQueue(){
    // cek dulu apakah datanya ada
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front; // buat variabel bayangan temp
    // cetak ini
    cout<<"===Antrian Knilik Mandiraja==="<<endl;
    cout<<"No antrian : "<<temp->noAntrian<<"\n\tNama : "<<temp->nama<<"\n\tAlamat : "<<temp->alamat<<"\n\tTanggal reservasi : "<<temp->tanggal<<endl;
    cout<<"===No AAntrian"<<temp->noAntrian<<" Masuk keruangan dokter==="<<endl;
    // abis itu frontnya kita pindah ke node berikutnya
    front = front->next;
    if(front == NULL){ //kalo frontnya after pindah tenyata NULL
        rear = NULL; // maka kita sinkronkan rear-nya
    }
    // temp menyimpan front lama, jadi kita langsung hapus aja
    delete temp;
}
void clear(){
    while(front != NULL){
        AntrianKlinik*temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    cout<<"Seluruh antrian berhasil di hapus"<<endl;
}
void Display(){
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front;
    cout<<"\n-----Data Antrian Klinik-----"<<endl;
    cout<<"Jumlah antrian saat ini : "<<count()<<"\n"<<endl;
    while(temp!=NULL){
        cout<<"No antrian : "<<temp->noAntrian<<"\n\tNama : "<<temp->nama<<"\n\tAlamat : "<<temp->alamat<<"\n\tTanggal reservasi : "<<temp->tanggal<<endl;
        temp = temp->next;
    }
    cout<<"-----------------------------"<<endl;
}
void searchQueueBYNumber(int cari_antrian){
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front;
    int posisi = 1;
    while(temp!=NULL){
        if(cari_antrian == temp->noAntrian){
            cout<<"Data atas nama "<<cari_antrian<<" ditemukan"<<endl;
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl;
            return;
        }
        temp=temp->next;
        posisi++;
    }
    cout<<"Data atas nama "<<cari_antrian<<" tidak ditemukan"<<endl;
    
}
void searchQueueBYName(string cari_nama){
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front;
    int posisi = 1;
    while(temp!=NULL){
        if(cari_nama == temp->nama){
            cout<<"Data atas nama "<<cari_nama<<" ditemukan"<<endl;
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl;
            return;
        }
        temp=temp->next;
        posisi++;
    }
    cout<<"Data atas nama "<<cari_nama<<" tidak ditemukan"<<endl;   
}
void changeDataBYQueue(int cari_antrian){
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front;
    
    int posisi = 1;
    while(temp!=NULL){
        if(cari_antrian == temp->noAntrian){
            cout<<"Data dengan nomor antrian "<<cari_antrian<<" ditemukan"<<endl;
            
            cout<<"Input data baru"<<endl;
            string namaBaru,alamatBaru,tanggalBaru;
            cout<<"Nama pasien : ";getline(cin>>ws,namaBaru);
            cout<<"Alamat pasien (kabupaten) : ";getline(cin>>ws,alamatBaru);
            cout<<"Tanggal reservasi (dd/mm/yyyy) : ";getline(cin>>ws,tanggalBaru);
            
            temp->nama = namaBaru;
            temp->alamat = alamatBaru;
            temp->tanggal = tanggalBaru;
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl;
            return;
        }
        temp=temp->next;
        posisi++;
    }
    cout<<"Data atas nama "<<cari_antrian<<" tidak ditemukan"<<endl;
}
int main(){
    // saya membuat fitur sandi sederhana sebagai pengaman
    string sandi = "KlinikWiddiyaPWT";
    string n;
    cout<<"Masukkan sandi : ";getline(cin>>ws,n);
    // jika sandi yang diinput oleh user benar, program berlanjut
    if(n == sandi){
        cout<<"Sandi benar"<<endl;
        while(true){
            cout<<"\n===Pilihan Menu==="<<endl;
            cout<<"1. Input data"<<endl;
            cout<<"2. Pasien ke ruangan dokter"<<endl;
            cout<<"3. Hapus semua data"<<endl;
            cout<<"4. Lihat semua data antrian"<<endl;
            cout<<"5. Cari data"<<endl;
            cout<<"6. keluar"<<endl;
            cout<<"=================="<<endl;

            string pilihan;
            cout<<"Silahkan pilih menu (1-6) : ";
            cin>>pilihan;
            if(pilihan == "1"){
                string nama,alamat,tanggal;
                cout<<"Nama pasien : ";getline(cin>>ws,nama);
                cout<<"Alamat pasien (kabupaten) : ";getline(cin>>ws,alamat);
                cout<<"Tanggal reservasi (dd/mm/yyyy) : ";getline(cin>>ws,tanggal);

                int antrian;
                cout<<"No Antrian : ";
                cin>>antrian;

                string data[3] = {nama,alamat,tanggal};
                enQueue(data,antrian);

            }else if(pilihan == "2"){
                deQueue();
                // Display();
            }else if(pilihan == "3"){
                clear();
            }else if(pilihan == "4"){
                Display();
            }else if(pilihan == "5"){
                string cari;
                cout<<"Cari berdasarkan (nama/noAntrian) : ";getline(cin>>ws,cari);
                if(cari == "nama"){
                    string n;
                    cout<<"Nama pasien : ";getline(cin>>ws,n);
                    searchQueueBYName(n);
                }else if(cari == "noAntrian" ){
                    int antrian;
                    cout<<"No Antrian : ";
                    cin>>antrian;
                    searchQueueBYNumber(antrian);
                }
            }else if(pilihan == "6"){
                cout<<"Anda keluar dari program"<<endl;
                break;
            }
            else{
                cout<<"Pilihan tidak ada!!"<<endl;
                break;
            }
        }
    // jika sandi salah, cetak Sandi salah
    }else{
        cout<<"Sandi salah"<<endl;
    }
    return 0;
}