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
void enQueue(string data[3], int antrian, bool isEmergency){
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
    // vitur emergency
    else if(isEmergency == true){ // jika isEmergency bernilai true
        newData->next = front; // newData berada di node ke berapa pun, akan langsung mrnjadi front
        front = newData; // front sekarang menjadi newData
        cout<<newData->nama<<" pasien emergency, harus ditangani dulu"<<endl; // cetak  ini
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
            temp = temp->next; // maka temp yang tadinya di front, berapa di node selanjutnya
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
    cout<<"===========Antrian Knilik Mandiraja============="<<endl;
    cout<<"No antrian : "<<temp->noAntrian<<"\n\tNama : "<<temp->nama<<"\n\tAlamat : "<<temp->alamat<<"\n\tTanggal reservasi : "<<temp->tanggal<<endl;
    cout<<"=== Nomor antrian "<<temp->noAntrian<<" Masuk keruangan dokter==="<<endl;
    // abis itu frontnya kita pindah ke node berikutnya
    front = front->next;
    if(front == NULL){ //kalo frontnya after pindah tenyata NULL
        rear = NULL; // maka kita sinkronkan rear-nya
    }
    // temp menyimpan front lama, jadi kita langsung hapus aja
    delete temp;
}
// function ini berfungsi untuk menghabus semua data dan node yang telah dibuat
void clear(){
    // jika front tidak sama dengan null
    while(front != NULL){
        AntrianKlinik*temp = front; // buat variabel bayangan temp, dengan nilai awal berapa di front
        front = front->next; // frontnya kita geser terus ke node selanjutnya
        delete temp; // temp tadi kan sebagai front, maka front-nya akan kita hapus
        // lalu karena tadi frontny udah pindah ke Node selanjutnya, maka kita hapus lagi front (sebagai Node selanjutnya)
    }
    rear = NULL; // karena nanti front akan null, maka kita perlu samakan rear-nya juga
    cout<<"Seluruh antrian berhasil di hapus"<<endl; // cetak ini
}
// function Display berfungsi untuk menapilkan semua data yang ada di semua Node
void Display(){
    // cek dulu apakah kosong
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front; // yaa kita buat lagi si temp, kek agak bosen denger-nya, next kita pakai cur aja la
    cout<<"\n-----Data Antrian Klinik-----"<<endl; // cetak ini
    cout<<"Jumlah antrian saat ini : "<<count()<<"\n"<<endl; // cetak ini
    while(temp!=NULL){ // kalo temp-nya gk null
        // cetak data di Node
        cout<<"No antrian : "<<temp->noAntrian<<"\n\tNama : "<<temp->nama<<"\n\tAlamat : "<<temp->alamat<<"\n\tTanggal reservasi : "<<temp->tanggal<<endl;
        temp = temp->next; // tadikan temp = front, nah sekarang temp = Node salnjutnya
    }
    cout<<"-----------------------------"<<endl;// cetak ini
}
// function ini berfungsi agar resepsionis bisa mencari data pasien dengan nomor antrian
void searchQueueBYNumber(int cari_antrian){ // dengan paramaeter cari_antrian
    // yaa kita cek lagi apakah kita belum inputkan data
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front; // temp lagi
    // di sini saya ingin mengetahui pasien tadi itu tinggal menunggu berapa antrian lagi
    int posisi = 0; // ini buat deklarasi awal ya
    while(temp!=NULL){ // yaa aku gk perlu jelasin lagi
        if(cari_antrian == temp->noAntrian){ // nah kalo no antrian yang dicari oleh reseprionis tadi
            // sama dengan data yang sudah di input tadi, code berjalan
            cout<<"Data atas nama "<<cari_antrian<<" ditemukan"<<endl;//cetak ini
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl; // ini juga, untuk menampilkan nama dan antrian keberapa
            return; // berhenti
        }
        temp=temp->next; // yaa kita next-kan si temp, more!
        posisi++;// posisinya kita +1
    }
    cout<<"Data atas nama "<<cari_antrian<<" tidak ditemukan"<<endl; // kalo gk nemu, cetak ini
}
// ini fungsinya mirip si ama yang tadi, tapi ini cari berdasarkan nama pasien
void searchQueueBYName(string cari_nama){ // yaa bisa dilihat kalo parameternya cari_nama dengan tipe data string
    // sama kek tadi
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front; // ini jg sama
    int posisi = 0; // ini juga
    while(temp!=NULL){ // ini juga sama
        if(cari_nama == temp->nama){ // nah ini bedanya
            // disini saat resepsionis masukkan nama pasien, lalu sama program nemu nama yang sama, code berjalan
            cout<<"Data atas nama "<<cari_nama<<" ditemukan"<<endl; // cetak ini
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl;// cetak nama, dan dia diantrian ke berapa
            return; // berhenti
        }
        temp=temp->next; // temp lagi, malas ah
        posisi++; // posisi +=1
    }
    cout<<"Data atas nama "<<cari_nama<<" tidak ditemukan"<<endl;// kalo kondisi if gk memenuhi, cetak ini
}
// jadi dalam beberapa kasus resepsionis bisa aja salah melakukan input data, atau pasienny yang salah ngomong
// untuk itu, fitur ini coba aku kembangkan, yakni vitur mengubah data, dengan mencari nomor antrian
void changeDataBYQueue(int cari_antrian){ // parameter nomor antrian
    // kalo kosong
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return; // jika kosong program akan berhenti
    }
    AntrianKlinik*temp = front; // temp and temp and temp
    
    int posisi = 0; // ni juga sama kek tadi, agar reseprionis dan pasien tau kurang berapa antrian lagi
    while(temp!=NULL){ // jika temp gk null
        if(cari_antrian == temp->noAntrian){ // kita cek, apakah noAntrian yang di masukkan benar, kalo benar lanjut 
            cout<<"Data dengan nomor antrian "<<cari_antrian<<" ditemukan"<<endl; // cetak ini
            // melakukan input data yang baru
            cout<<"Input data baru"<<endl;
            string namaBaru,alamatBaru,tanggalBaru;
            cout<<"Nama pasien : ";getline(cin>>ws,namaBaru);
            cout<<"Alamat pasien (kabupaten) : ";getline(cin>>ws,alamatBaru);
            cout<<"Tanggal reservasi (dd/mm/yyyy) : ";getline(cin>>ws,tanggalBaru);
            //simpan ganti data lama, dengan data baru
            temp->nama = namaBaru;
            temp->alamat = alamatBaru;
            temp->tanggal = tanggalBaru;
            cout<<"\tNama : "<<temp->nama<<"\n\tBerada di urutan : "<<posisi<<endl; // cetak ini
            return; // kembalikan
        }
        temp=temp->next; // bosen ama temp
        posisi++;// posisi +=1
    }
    cout<<"Data atas nama "<<cari_antrian<<" tidak ditemukan"<<endl; // cetak ini
}
void Summary(){
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
        return;
    }
    AntrianKlinik*temp = front;
    int jumlah = 0;
    while(temp !=NULL){
        temp = temp->next;
        jumlah++;
    }
    cout<<"=======Ringkasan Data======="<<endl;
    cout<<"Jumlah Antrian     : "<<jumlah<<endl;
    cout<<"Pasien selanjutnya : "<<front->nama<<endl;
    cout<<"Pasien terakhir    : "<<rear->nama<<endl;
    cout<<"============================"<<endl;
}

// program utama
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
            cout<<"6. Ubah data"<<endl;
            cout<<"7. keluar"<<endl;
            cout<<"=================="<<endl;

            string pilihan;
            cout<<"Silahkan pilih menu (1-7) : ";
            cin>>pilihan;
            if(pilihan == "1"){
                string nama,alamat,tanggal;
                cout<<"Nama pasien : ";getline(cin>>ws,nama);
                cout<<"Alamat pasien (kabupaten) : ";getline(cin>>ws,alamat);
                cout<<"Tanggal reservasi (dd/mm/yyyy) : ";getline(cin>>ws,tanggal);

                int antrian;
                cout<<"No Antrian : ";
                cin>>antrian;

                char status;
                cout<<"Pasien gawat darurat?(y/n) : ";cin>>status;

                string data[3] = {nama,alamat,tanggal};
                bool s;
                if(status == 'y' || status == 'Y'){
                    s = true;
                    enQueue(data,antrian,s);
                }else{
                    s = false;
                    enQueue(data,antrian,s);
                }

            }else if(pilihan == "2"){
                deQueue();
                // Display();
            }else if(pilihan == "3"){
                clear();
            }else if(pilihan == "4"){
                Display();
                Summary();
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
                cout<<"Silahkan ubah data pasien yang sudah di masukkan sebelumnya"<<endl;
                int antri;
                cout<<"Nomor antrian : ";cin>>antri;
                changeDataBYQueue(antri);
            }else if(pilihan == "7"){
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