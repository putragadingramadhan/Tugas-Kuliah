// Putra Gading Ramadhan
#include <iostream> /*c++ adalah bahasa pemrograman yang sangat minimalis. 
Secara defult dia bahkan tidak tahu cara ngeprint tulisan ke layar.
fungsinya baris ini membantu memberitahu compiler untuk mengambil file bernama input-output stream
isinya berupa file logika tentang cout (untuk print) dan cin (untuk input)
using namespace std; */

#include <string>// tipe data string bukan bawaan asli c++, makanya perlu kita panggil dulu

// penggunaan struct, untuk membuat tipe data baru
struct Mahasiswa {
    std :: string nama;
    int umur;
    float ipk;
};
// OOP
class Mobil {
    public :
    std :: string nama_mobil;
    int tahun_produksi;
    std :: string warna;
};

void nama(std :: string nama, int umur){
    std :: cout << "Hallo "<< nama << ", Selamat masuk umur " << umur <<std :: endl;
}
int luas_pesergiPNjng (int tinggi, int lebar){
    int luas = tinggi*lebar;
    return luas;
}

int main (){
    //variabel hanya dapat menyinpan 1 nilai, contoh
    // int x = 30,40;//akan error
    int x = 40;

    short _predikat = 376;
    std :: cout << _predikat << std :: endl;

    /*
    ======
    Tipe data bilangan bulat
    ======*/
    int jumlah_mahasiswa = 900;
    short nilai = 89;
    long data_followers = 1000000;
    long long data_penduduk = 2000000000;
    
    /*
    ======
    Tipe data bilangan pecahan
    ======*/
    float tinggi_badan = 89.90;
    double Diskon = 10.99999;
    long double p = 3.1433333233333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333L;
    /*
    ======
    Tipe data teks
    ======*/
    char predikat_nilai = 'A';
    std :: string status = "Lulus";

    if(nilai > 85 && predikat_nilai == 'A'){
        std :: cout << status << std :: endl;
    }else{
        std :: cout << "Anda belum lulus" << std:: endl;
    }

    bool udah_nikah = true;
    bool belum_nikah = false;
    bool dan = udah_nikah && belum_nikah;
    // std :: cout << dan << std :: endl;
    if (dan == 0){
        std :: cout << "False" << std :: endl;
    }

    //cetak
    std :: cout << "\n==Print struct=="<< std :: endl;
    Mahasiswa mhs1;
    mhs1.nama = "Andi";
    mhs1.umur = 18;
    mhs1.ipk = 3.90;
    std :: cout << "Nama : "<<mhs1.nama<< std::endl;
    std :: cout << "Umur : "<<mhs1.umur<< std::endl;
    std :: cout << "IPK : "<<mhs1.ipk<< std::endl;

    std :: cout << "\n==Print struct mhs 2=="<< std :: endl;
    Mahasiswa mhs2;
    mhs2.nama = "Birin";
    mhs2.umur = 20;
    mhs2.ipk = 4.00;
    std :: cout << "Nama : "<<mhs2.nama<< std::endl;
    std :: cout << "Umur : "<<mhs2.umur<< std::endl;
    std :: cout << "IPK : "<<mhs2.ipk<< std::endl;
    
    std :: cout << "\n==Print class=="<< std :: endl;
    Mobil m1;
    m1.nama_mobil = "Avanza";
    m1.tahun_produksi= 2006;
    m1.warna = "Kuning";
    std :: cout << "Nama Mobil : "<<m1.nama_mobil<< std::endl;
    std :: cout << "Tahun Produksi : "<<m1.tahun_produksi<< std::endl;
    std :: cout << "Warna : "<<m1.warna<< std::endl;

    // pamggil function
    nama("Putra Gading Ramadhan", 19);
    int tinggi,lebar;
    std :: cout << "Masukkan tinggi pesergi panjang : "<< std :: endl;
    std :: cin >>  tinggi;
    std :: cout << "Masukkan lebar pesergi panjang : "<< std :: endl;
    std :: cin >> lebar;
    std :: cout << luas_pesergiPNjng(tinggi,lebar)<< "m2"<< std :: endl;


    /*Jadi, aku mau coba membuat program sederhana tentang membeli buku
    Algoritmanya
    1. user ditampilkan daftar buku dan harga
    2. user pilih buku dan harga berdasarkan nomor
    3. user akan memilih membeli berapa buku
    4. jika harga buku >120.000, maka dapat diskon 10%
    5. user ditampilkan bill nya
    6. selesai*/
    std :: string  buku [3]={"Psychology of money", "Rich Dad Poor Dad", "Start With Why"}; //nama buku
    int harga_buku [] ={50000,70000,30000}; // harga
    std :: cout << "==Welcome to Gragading Store==" << std :: endl;
    std :: cout << "==" << std :: endl;
    int pilihan, qty;
    int len = sizeof(harga_buku)/sizeof(harga_buku[0]); //untuk mengecek stok buku berdasarkan index

    //tampilkan daftar buku dengan harga
    for(int i =0; i<len;i++){
        std :: cout << i+1 <<". " << buku[i] << " Harga Rp" << harga_buku[i] << std :: endl; 
    }

    // pilih buku dan harga berdasarkan nomor
    std :: cout << "Pilih buku (berdasakan nomor) : " << std :: endl; 
    std :: cin >> pilihan;

    // jika user tidak memilih nomor yang sudah tertera
    if(pilihan < 1 || pilihan > len){
        std :: cout << "Pilihan tidak valid" << std :: endl; 
        return 0;
    }

    std :: cout << "Jumlah yang di beli : " << std :: endl;
    std :: cin >> qty;

    int index_pilihan = pilihan -1; // -1 untuk menghitung berdasarkan index
    std :: string namaTerpilih = buku[index_pilihan];
    int harga_satuan = harga_buku[index_pilihan];
    int total_harga = harga_satuan * qty;
    int total_bayar_DGNDiskon;

    int diskon;
    if (total_harga > 120000){ // untuk diskon
        int dikurang = (total_harga * 10)/100;
        diskon = dikurang;
        total_bayar_DGNDiskon = total_harga - dikurang;
    }
    // tampilkan ke user
    std :: cout << "\n--- Detail Pembelian ---" << std :: endl;
    std :: cout << "Buku            : " << namaTerpilih << std :: endl;
    std :: cout << "Harga Satuan    : " << harga_satuan << std :: endl;
    std :: cout << "Jumlah          : " << qty << std :: endl;
    std :: cout << "Total biaya     : " << total_harga << std :: endl;
    std :: cout << "Diskon 10%      : " << diskon << std :: endl;
    std :: cout << "Total Pembayaran: " << total_bayar_DGNDiskon << std :: endl;
    std :: cout << "\n-------------------------" << std :: endl;
    // selesai








    return 0;
}