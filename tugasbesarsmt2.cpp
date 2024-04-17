#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void MenuResto(string daftarMenu[4][4][2], bool menuTampil[4][4][2], int angka) {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 2; c++) {
                if (daftarMenu[a][b][c] == to_string(angka)) {
                    daftarMenu[a][b][c] = " ";
                    menuTampil[a][b][c] = true;
                    return;
                }
            }
        }
    }
}

void noMejaOutdoor(int noMejaOutdoor[5][3], int angka){
    if (angka == 0) {
        cout << "Meja tidak tersedia" << endl;
        return;
    }
    for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 3; z++) {
            if (noMejaOutdoor[y][z] == angka) {
                noMejaOutdoor[y][z] = 0;  
            }
        }
    }
}

void noMejaIndoor(int noMejaIndoor[5][3], int angka){
    if (angka == 0) {
        cout << "Meja tidak tersedia" << endl;
        return;
    }
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 3; k++) {
            if (noMejaIndoor[j][k] == angka) {
                noMejaIndoor[j][k] = 0;   
            }
        }
    }
}

void kembalikanMeja(int noMeja[5][3], int angka){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (noMeja[i][j] == 0) {
                noMeja[i][j] = angka;
                return;
            }
        }
    }
}

class BlissfulBitesCafeResto {
public:
    string namaCustomer, nomorTelpon, HTBTCustomer, menu;
    int area, nomorMeja, jumlah, total;
    BlissfulBitesCafeResto* prev;
    BlissfulBitesCafeResto* next;

    BlissfulBitesCafeResto(string namaCustomer, string nomorTelpon, string HTBTCustomer, string menu, int area, int nomorMeja, int jumlah, int total) {
        this->namaCustomer = namaCustomer;
        this->nomorTelpon = nomorTelpon;
        this->HTBTCustomer= HTBTCustomer;
        this->nomorMeja = nomorMeja;
        this->menu = menu;
        this->area = area;
        this->jumlah = jumlah;
        this -> total = total;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
public:
    BlissfulBitesCafeResto* head;

    DoubleLinkedList() {
        head = nullptr;
    }

    void tambah_belakang(string namaCustomer, string nomorTelpon, string HTBTCustomer, string menu, int area, int nomorMeja, int jumlah, int total) {
        BlissfulBitesCafeResto* new_node = new BlissfulBitesCafeResto(namaCustomer, nomorTelpon, HTBTCustomer,  menu, area, nomorMeja, jumlah, total);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        BlissfulBitesCafeResto* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }

    void hapus(string namaCustomerHapus) {
        BlissfulBitesCafeResto* current = head;
        while (current != nullptr && current->namaCustomer != namaCustomerHapus) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Nama Customer " << namaCustomerHapus << " tidak ditemukan." << endl;
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }

    void update(string namaCustomer_lama, string namaCustomer_baru, string nomorTelpon_baru, string HTBTCustomer_baru, string menu_baru, int area_baru, int nomorMeja_baru, int jumlah_baru, int total_baru) {
        BlissfulBitesCafeResto* current = head;
        while (current != nullptr && current->namaCustomer != namaCustomer_lama) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << namaCustomer_lama << " tidak ditemukan." << endl;
            return;
        }
        current->namaCustomer = namaCustomer_baru;
        current->nomorTelpon = nomorTelpon_baru;
        current->HTBTCustomer = HTBTCustomer_baru;
        current->nomorMeja = nomorMeja_baru;
        current->jumlah = jumlah_baru;
        current->menu = menu_baru;
        current->area = area_baru;
        current->menu = total_baru;
        cout << "Reservasi atas Nama " << namaCustomer_lama << " telah berhasil diupdate menjadi data baru atas nama" << namaCustomer_baru << endl;
    }

    void tampilkan() {
        BlissfulBitesCafeResto* current = head;
        cout << "_" << endl;
        cout << "| Nama Customer\t| Nomor Telpon\t| Tanggal Reservasi\t| Menu\t| Jumlah Menu\t| Area\t| Nomor Meja\t| Total\t\t|" << endl;
        while (current != nullptr) {
            cout << "_" << endl;
            cout << "| " << left << setw(13) << current->namaCustomer << " | " << setw(13) << current->nomorTelpon << " | " << setw(21) << current->HTBTCustomer << " | " << setw(5) << current->menu << " | " << setw(13) << current->jumlah << " | " << setw(5) << current->area << " | " << setw(13) << current->nomorMeja << " | " << "Rp " << current->total <<".000" << " |" << endl;
            current = current->next;
        }
        cout << "_" << endl;
    }

    void hapus_seluruh_data() {
        BlissfulBitesCafeResto* current = head;
        while (current != nullptr) {
            BlissfulBitesCafeResto* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
    }
};

int main() {
    DoubleLinkedList linked_list;

    string daftarMenu[4][4][2] = {
        {
            {"Chicken Wings", "Rp 35.000"},
            {"Spring Rolls", " Rp 25.000"},
            {"Caprese Salad", "Rp 40.000"},
            {"Garlic Bread", " Rp 20.000"}
        },

        {
            {"Spaghetti Bolognese", "Rp 50.000"},
            {"Beef Burger with Fries", "Rp 60.000"},
            {"Vegetarian Stir Fry", "Rp 45.000"},
            {"Seafood Paella", "Rp 75.000"}
        },

        {
            {"Chocolate Lava Cake", "Rp 40.000"},
            {"Tiramisu", "Rp 45.000"},
            {"Fruit Salad", "Rp 25.000"},
            {"Cheesecake", "Rp 50.000"}
        },

        {
            {"Fresh Juice", "Rp 20.000"},
            {"Sparkling Water", "Rp 15.000"},
            {"Espresso", "Rp 20.000"},
            {"Mineral Water", "Rp 10.000"}
        }
    };

    string titles[4] = {"\t\tMenu Appetizers", "\t      Menu Main Courses", "\t\tMenu Desserts", "\t\tMenu Beverages \t"};

    bool menuTampil[4][4][2] = {{{false}}};

    int choice;
    char ulang;
    do {
        cout << endl;
        cout << " \tSelamat Datang Di Blissful Bites Cafe Resto!        " << endl << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Kami sangat senang dapat menyambut Anda hari ini. Sebelum |" << endl;
        cout << "| Anda memulai petualangan kuliner Anda bersama kami,       |" << endl;
        cout << "| izinkan kami untuk mengucapkan terima kasih atas kunjungan|" << endl;
        cout << "| Anda. Di sini, kami selalu berkomitmen untuk memberikan   |" << endl;
        cout << "| pengalaman kuliner yang tak terlupakan, yang dipenuhi     |" << endl;
        cout << "| dengan rasa kebahagiaan dan kenikmatan.                   |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "\nBlissful Bites Cafe Resto" << endl << endl;
        cout << "1. Profil Blissful Bites Cafe Resto" << endl;
        cout << "2. Menu" << endl;
        cout << "3. Update Reservasi" << endl;
        cout << "4. Hapus Reservasi" << endl;
        cout << "5. Hapus Seluruh Data Reservasi" << endl;
        cout << "6. Tampilkan Data Reservasi" << endl;
        cout << "7. Exit" << endl << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Tambahkan logika untuk menampilkan profil cafe
                break;
            }
            case 2: {
                for (int x = 0; x < 4; x++) {
                    cout << "" << endl << endl;
                    cout << titles[x] << endl;
                    cout << "" << endl << endl;
                    int index = x * 4; // Hitung indeks awal pada halaman saat ini
                    for (int i = 0; i < 4; i++) {
                        if (!menuTampil[x][i][0] && !menuTampil[x][i][1]) {
                            cout << index + i + 1 << ". " << left << setw(32) << daftarMenu[x][i][0] << daftarMenu[x][i][1] << endl << endl;
                        }
                    }
                }

                char reservasi;
                cout << "_" << endl << endl;
                cout << "Apakah anda ingin melakukan reservasi? (y/t) : ";
                cin >> reservasi;
                if (reservasi == 'y'){
                        int Outdoor[5][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12},
                            {13, 14, 15}
                        };

                        int Indoor[5][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12},
                            {13, 14, 15}
                        };

                        string namaCustomer1, nomorTelpon1, area1, HTBTCustomer1;
                        int nomorMeja1, menu1, jumlah1;
                        int nomor_pilihan = 0;
                        const int maxPesanan = 10; // Batas maksimum jumlah pesanan
                        string pesanan[maxPesanan][2];
                        int jumlahPesanan = 0;

                        cout << "_" << endl << endl;
                        cout << "Masukan Nama Customer: ";
                        cin >> namaCustomer1;
                        cout << "Masukkan nomor telpon: ";
                        cin >> nomorTelpon1;
                        cout << "Masukkan (hari tanggal bulan tahun) reservasi: ";
                        cin >> HTBTCustomer1;
                        getline(cin, HTBTCustomer1);

                        do{
                            cout << "Pilih menu anda dengan menginputkan angka yang tertera pada tiap menu (1-16): ";
                            cin >> menu1;
                            if (menu1 >= 1 && menu1 <= 16) {
                            cout << "Masukkan jumlah menu: ";
                            cin >> jumlah1;
                            int halaman = (menu1 - 1) / 4; // Hitung halaman berdasarkan nomor menu
                            int indeksMenu = (menu1 - 1) % 4; // Hitung indeks menu pada halaman yang dipilih
                            pesanan[jumlahPesanan][0] = daftarMenu[halaman][indeksMenu][0]; // Simpan nama menu
                            pesanan[jumlahPesanan][1] = daftarMenu[halaman][indeksMenu][1]; // Simpan harga menu
                            jumlahPesanan++;
                        } else {
                            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                            continue;
                        }

                        cout << endl;
                        cout << "Apakah anda ingin melakukan pemesanan menu yang lain? (y/t) : ";
                        cin >> ulang;
                        } while (ulang != 't'&& jumlahPesanan < maxPesanan);
                        cout << "_" << endl << endl;

                        cout << "Pesanan Anda:" << endl;
                        double totalBelanja = 0.0; // Inisialisasi total belanja
                        for (int i = 0; i < jumlahPesanan; ++i) {
                            cout << pesanan[i][0] << " x" << jumlah1 << endl;
                            double harga = stod(pesanan[i][1].substr(3)); 
                            double subtotal = harga * jumlah1; 
                            cout << "Subtotal: " << "Rp " << subtotal << ".000" << endl << endl;
                            totalBelanja += subtotal;  
                        }
                        cout << "Total Belanja: " << "Rp " << totalBelanja << ".000" << endl << endl;

                        cout << "_" << endl << endl << endl;
                        cout << "SILAHKAN MEMILIH AREA DAN NOMOR MEJA" << endl << endl;
                        cout << "_" << endl << endl;
                        cout << "\t\t   Nomor Meja" << endl;
                        cout << endl;
                        cout << "_" << endl << endl;
                        cout << endl;
                        cout << "\t\t    Outdoor" << endl;
                        cout << endl;

                        for (int i = 0; i < 5; i++) {
                            for (int d = 0; d < 3; d++) {
                                cout << left << setw(23) << Outdoor[i][d];
                            }
                            cout << endl;
                        }

                        cout << "_" << endl << endl;
                        cout << endl;
                        cout << "\t\t      Indoor" << endl;
                        cout << endl;
                        for (int a = 0; a < 5; a++) {
                            for (int c = 0; c < 3; c++) {
                                cout << left << setw(23) << Indoor[a][c];
                            }
                            cout << endl;
                        }
                        
                        int pilihArea;
                        do{
                            cout << "\nPilih Area:" << endl;
                            cout << "1. Outdoor" << endl;
                            cout << "2. Indoor" << endl;
                            cout << "Masukkan pilihan: ";
                            cin >> pilihArea;
                            
                            int nomor;
                            if (pilihArea != 3) { // input nomor meja hanya jika bukan opsi selesai
                                cout << "Silahkan pilih nomor meja anda: ";
                                cin >> nomor;
                            }

                            switch (pilihArea) {
                                case 1: {
                                    if (nomor != 0) {
                                        cout << "anda memilih area OUTDOOR dengan nomor meja " << nomor << endl;
                                        cout << endl;
                                        noMejaOutdoor(Outdoor, nomor);
                                        nomor_pilihan = nomor;
                                    }
                                    break;
                                }
                                case 2: {
                                    if (nomor != 0) {
                                        cout << "anda memilih area INDOOR dengan nomor meja " << nomor << endl;
                                        cout << endl;
                                        noMejaIndoor(Indoor, nomor);
                                        nomor_pilihan = nomor;
                                    }
                                    break;
                                }
                                default: {
                                    cout << "Pilihan tidak valid. Silahkan pilih lagi." << endl;
                                    break;
                                }
                            }
                            cout << endl;
                            cout << "Apakah anda sudah yakin dengan pilihan meja anda (y/t)? ";
                            cin >> ulang;
                            cout << endl;

                            if (ulang == 't') {
                                kembalikanMeja(choice == 1 ? Outdoor : Indoor, nomor_pilihan);
                            }
                        } while (ulang != 'y');
                    linked_list.tambah_belakang(namaCustomer1, nomorTelpon1, HTBTCustomer1, pesanan[10][2], pilihArea, nomor_pilihan, jumlah1, totalBelanja);
                    } else if(reservasi == 't') {
                        cout << "Kembali ke menu awal" << endl;
                    } else {
                        cout << "Pilihan tidak tersedia" << endl;
                    }
                }
            case 3: {
                string namaCustomer_lama,  namaCustomer_baru, nomorTelpon_baru, HTBTCustomer_baru, menu_baru;
                int area_baru, nomorMeja_baru, jumlah_baru, total_baru;
                for (int x = 0; x < 4; x++) {
                    cout << "" << endl << endl;
                    cout << titles[x] << endl;
                    cout << "" << endl << endl;
                    int index = x * 4; // Hitung indeks awal pada halaman saat ini
                    for (int i = 0; i < 4; i++) {
                        if (!menuTampil[x][i][0] && !menuTampil[x][i][1]) {
                            cout << index + i + 1 << ". " << left << setw(32) << daftarMenu[x][i][0] << daftarMenu[x][i][1] << endl << endl;
                        }
                    }
                }

                char reservasi;
                cout << "_" << endl << endl;
                cout << "Apakah anda ingin melakukan reservasi? (y/t) : ";
                cin >> reservasi;
                if (reservasi == 'y'){
                        int Outdoor[5][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12},
                            {13, 14, 15}
                        };

                        int Indoor[5][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12},
                            {13, 14, 15}
                        };

                        int nomor_pilihan = 0;
                        const int maxPesanan = 10; // Batas maksimum jumlah pesanan
                        string pesanan[maxPesanan][2];
                        int jumlahmenu_baru = 0;

                        cout << "_" << endl << endl;
                        cout << "Masukkan Nama Customer yang akan di update: ";
                        cin >> namaCustomer_lama;
                        cout << "Masukan Nama Customer: ";
                        cin >> namaCustomer_baru;
                        cout << "Masukkan nomor telpon: ";
                        cin >> nomorTelpon_baru;
                        cout << "Masukkan (hari tanggal bulan tahun) reservasi: ";
                        cin >> HTBTCustomer_baru;
                        getline(cin, HTBTCustomer_baru);

                        int jumlah1;
                        int menu1;
                        char ulang;
                        do{
                            cout << "Pilih menu anda dengan menginputkan angka yang tertera pada tiap menu (1-16): ";
                            cin >> menu1;
                            if (menu1 >= 1 && menu1 <= 16) {
                            cout << "Masukkan jumlah menu: ";
                            cin >> jumlah1;
                            int halaman = (menu1 - 1) / 4; // Hitung halaman berdasarkan nomor menu
                            int indeksMenu = (menu1 - 1) % 4; // Hitung indeks menu pada halaman yang dipilih
                            menu_baru[jumlahmenu_baru][0] = daftarMenu[halaman][indeksMenu][0]; // Simpan nama menu
                            menu_baru[jumlahmenu_baru][1] = daftarMenu[halaman][indeksMenu][1]; // Simpan harga menu
                            jumlahmenu_baru++;
                        } else {
                            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                            continue;
                        }

                        cout << endl;
                        cout << "Apakah anda ingin melakukan pemesanan menu yang lain? (y/t) : ";
                        cin >> ulang;
                        } while (ulang != 't'&& jumlahmenu_baru < maxPesanan);
                        cout << "_" << endl << endl;

                        cout << "Pesanan Anda:" << endl;
                        double totalBelanja = 0.0; // Inisialisasi total belanja
                        for (int i = 0; i < jumlahmenu_baru; ++i) {
                            cout << menu_baru[i][0] << " x" << jumlah1 << endl;
                            double harga = stod(menu_baru[i][1].substr(3)); 
                            double subtotal = harga * jumlah1; 
                            cout << "Subtotal: " << "Rp " << subtotal << ".000" << endl << endl;
                            totalBelanja += subtotal;  
                        }
                        cout << "Total Belanja: " << "Rp " << totalBelanja << ".000" << endl << endl;

                        cout << "_" << endl << endl << endl;
                        cout << "SILAHKAN MEMILIH AREA DAN NOMOR MEJA" << endl << endl;
                        cout << "_" << endl << endl;
                        cout << "\t\t   Nomor Meja" << endl;
                        cout << endl;
                        cout << "_" << endl << endl;
                        cout << endl;
                        cout << "\t\t    Outdoor" << endl;
                        cout << endl;

                        for (int i = 0; i < 5; i++) {
                            for (int d = 0; d < 3; d++) {
                                cout << left << setw(23) << Outdoor[i][d];
                            }
                            cout << endl;
                        }

                        cout << "_" << endl << endl;
                        cout << endl;
                        cout << "\t\t      Indoor" << endl;
                        cout << endl;
                        for (int a = 0; a < 5; a++) {
                            for (int c = 0; c < 3; c++) {
                                cout << left << setw(23) << Indoor[a][c];
                            }
                            cout << endl;
                        }
                        
                        int pilihArea;
                        do{
                            cout << "\nPilih Area:" << endl;
                            cout << "1. Outdoor" << endl;
                            cout << "2. Indoor" << endl;
                            cout << "Masukkan pilihan: ";
                            cin >> pilihArea;
                            
                            int nomor;
                            if (pilihArea != 3) { // input nomor meja hanya jika bukan opsi selesai
                                cout << "Silahkan pilih nomor meja anda: ";
                                cin >> nomor;
                            }

                            switch (pilihArea) {
                                case 1: {
                                    if (nomor != 0) {
                                        cout << "anda memilih area OUTDOOR dengan nomor meja " << nomor << endl;
                                        cout << endl;
                                        noMejaOutdoor(Outdoor, nomor);
                                        nomor_pilihan = nomor;
                                    }
                                    break;
                                }
                                case 2: {
                                    if (nomor != 0) {
                                        cout << "anda memilih area INDOOR dengan nomor meja " << nomor << endl;
                                        cout << endl;
                                        noMejaIndoor(Indoor, nomor);
                                        nomor_pilihan = nomor;
                                    }
                                    break;
                                }
                                default: {
                                    cout << "Pilihan tidak valid. Silahkan pilih lagi." << endl;
                                    break;
                                }
                            }
                            cout << endl;
                            cout << "Apakah anda sudah yakin dengan pilihan meja anda (y/t)? ";
                            cin >> ulang;
                            cout << endl;

                            if (ulang == 't') {
                                kembalikanMeja(choice == 1 ? Outdoor : Indoor, nomor_pilihan);
                            }
                        } while (ulang != 'y');
                    linked_list.tambah_belakang(namaCustomer_lama, namaCustomer_baru, nomorTelpon_baru, HTBTCustomer_baru, menu_baru[10][2], area_baru, nomorMeja_baru, jumlah_baru, total_baru);
                    } else if(reservasi == 't') {
                        cout << "Kembali ke menu awal" << endl;
                    } else {
                        cout << "Pilihan tidak tersedia" << endl;
                    }
                cout << "Update Data" << endl;
                linked_list.update(namaCustomer_lama, namaCustomer_baru, nomorTelpon_baru, HTBTCustomer_baru, menu_baru, area_baru, nomorMeja_baru, jumlah_baru, total_baru);
                break;
            }
            case 4: {
                string namaCustomerHapus;
                cout << "Masukkan nama customer yang akan dihapus: ";
                cin >> namaCustomerHapus;
                linked_list.hapus(namaCustomerHapus);
                cout << "Data " << namaCustomerHapus << " telah dihapus." << endl;
                // Tambahkan logika untuk menghapus reservasi
                break;
            }
            case 5: {
                linked_list.hapus_seluruh_data();
                cout << "Semua data telah dihapus." << endl;
                // Tambahkan logika untuk menghapus semua data reservasi
                break;
            }
            case 6: {
                // Tampilkan data reservasi
                linked_list.tampilkan();
                cout << endl;
                break;
            }
            case 7: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        } 

    }while (choice != 7);

    return 0;
}