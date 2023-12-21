#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    bool lulus;
    int nilaiUjian;  // Menambahkan field nilaiUjian
    int biaya;
};

struct Node {
    string nama;
    int biaya;
    Node* next;
};

Mahasiswa daftarMahasiswa[100];
int jumlahMahasiswa = 0;

Node* namaLulusHead = 0;

// Fungsi sorting (Bubble Sort)
void sortingMahasiswa() {
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
            if (daftarMahasiswa[j].nama > daftarMahasiswa[j + 1].nama) {
                // Tukar elemen jika tidak terurut
                Mahasiswa temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }
    cout << "Daftar Mahasiswa telah diurutkan berdasarkan nama\n";
}

// Implementasi stack (Array)
const int MAX_STACK = 100;
Mahasiswa stackMahasiswa[MAX_STACK];
int topStack = -1;

void pushStack(Mahasiswa m) {
    if (topStack < MAX_STACK - 1) {
        stackMahasiswa[++topStack] = m;
        cout << "Mahasiswa " << m.nama << " ditambahkan ke dalam stack\n";
    } else {
        cout << "Stack penuh, tidak bisa menambahkan mahasiswa\n";
    }
}

void popStack() {
    if (topStack >= 0) {
        cout << "Mahasiswa " << stackMahasiswa[topStack--].nama << " dihapus dari stack\n";
    } else {
        cout << "Stack kosong, tidak ada mahasiswa untuk dihapus\n";
    }
}

// Implementasi queue (Array)
const int MAX_QUEUE = 100;
Mahasiswa queueMahasiswa[MAX_QUEUE];
int frontQueue = -1;
int rearQueue = -1;

void enqueue(Mahasiswa m) {
    if (rearQueue < MAX_QUEUE - 1) {
        if (frontQueue == -1) {
            frontQueue = 0;
        }
        queueMahasiswa[++rearQueue] = m;
        cout << "Mahasiswa " << m.nama << " ditambahkan ke dalam queue\n";
    } else {
        cout << "Queue penuh, tidak bisa menambahkan mahasiswa\n";
    }
}

void dequeue() {
    if (frontQueue <= rearQueue) {
        cout << "Mahasiswa " << queueMahasiswa[frontQueue++].nama << " dihapus dari queue\n";
        if (frontQueue > rearQueue) {
            frontQueue = rearQueue = -1; // Reset queue jika sudah kosong
        }
    } else {
        cout << "Queue kosong, tidak ada mahasiswa untuk dihapus\n";
    }
}

void informasiJurusan() {
    cout << "Program studi ini mengajarkan konsep dasar pemrograman yang banyak digunakan pada dunia industri saat ini.\n";
}

void pendaftaranMahasiswaBaru() {
    string nama;
    int umur;

    cout << "Masukkan nama mahasiswa baru: ";
    cin >> nama;

    cout << "Masukkan umur mahasiswa baru: ";
    cin >> umur;

    Mahasiswa m{nama, umur, false, 0, 0};
    daftarMahasiswa[jumlahMahasiswa++] = m;
    cout << "Mahasiswa berhasil didaftarkan\n";
}

void tesUjian() {
    string namaUji;
    bool ditemukan = false;

    cout << "Masukkan nama mahasiswa yang akan melaksanakan tes ujian: ";
    cin >> namaUji;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nama == namaUji) {
            ditemukan = true;

            if (daftarMahasiswa[i].umur >= 17 && daftarMahasiswa[i].umur <= 25) {
                cout << "Masukkan nilai tes ujian untuk mahasiswa " << namaUji << ": ";
                cin >> daftarMahasiswa[i].nilaiUjian;

                if (daftarMahasiswa[i].nilaiUjian >= 60) {
                    cout << "Mahasiswa " << namaUji << " lulus ujian dengan nilai " << daftarMahasiswa[i].nilaiUjian << "\n";
                    daftarMahasiswa[i].lulus = true;

                    Node* newNode = new Node{daftarMahasiswa[i].nama, 0};
                    if (!namaLulusHead) {
                        namaLulusHead = newNode;
                    } else {
                        Node* temp = namaLulusHead;
                        while (temp->next) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                    }
                } else {
                    cout << "Mahasiswa " << namaUji << " tidak memenuhi syarat nilai untuk lulus ujian\n";
                }
            } else {
                cout << "Mahasiswa " << namaUji << " tidak memenuhi syarat umur untuk lulus ujian\n";
            }
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa tidak ditemukan\n";
    }
}

void namaLulus() {
    if (namaLulusHead) {
        cout << "Nama Mahasiswa yang Lulus:\n";
        Node* temp = namaLulusHead;
        while (temp) {
            cout << temp->nama << endl;
            temp = temp->next;
        }
    } else {
        cout << "Belum ada mahasiswa yang lulus\n";
    }
}

void pembayaran() {
    string namaBayar;
    bool ditemukan = false;

    cout << "Masukkan nama mahasiswa yang akan melakukan pembayaran: ";
    cin >> namaBayar;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nama == namaBayar) {
            ditemukan = true;

            if (daftarMahasiswa[i].biaya > 0) {
                cout << "Mahasiswa " << namaBayar << " telah membayar sejumlah: " << daftarMahasiswa[i].biaya << endl;
            } else {
                if (daftarMahasiswa[i].nilaiUjian >= 80) {
                    daftarMahasiswa[i].biaya = 6000;
                } else if (daftarMahasiswa[i].nilaiUjian >= 60) {
                    daftarMahasiswa[i].biaya = 5500;
                } else if (daftarMahasiswa[i].nilaiUjian >= 40) {
                    daftarMahasiswa[i].biaya = 5000;
                } else {
                    cout << "Nilai tes ujian tidak valid\n";
                    return;
                }

                cout << "Biaya jurusan untuk mahasiswa " << namaBayar << " sejumlah " << daftarMahasiswa[i].biaya << endl;
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "peserta  tidak ditemukan\n";
    }
}

void tampilDaftarMahasiswa() {
    if (jumlahMahasiswa > 0) {
        cout << "Daftar peserta :\n";
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << "Nama: " << daftarMahasiswa[i].nama << ", Umur: " << daftarMahasiswa[i].umur;
            if (daftarMahasiswa[i].lulus) {
                cout << " (Lulus)";
            } else {
                cout << " (Belum lulus)";
            }
            cout << endl;
        }
    } else {
        cout << "Belum ada peserta  yang terdaftar\n";
    }
}

void hapusMahasiswa() {
    if (jumlahMahasiswa > 0) {
        string namaHapus;
        cout << "Masukkan nama peserta yang akan dihapus: ";
        cin >> namaHapus;

        bool ditemukan = false;
        for (int i = 0; i < jumlahMahasiswa; i++) {
            if (daftarMahasiswa[i].nama == namaHapus) {
                ditemukan = true;

                for (int j = i; j < jumlahMahasiswa - 1; j++) {
                    daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                }

                jumlahMahasiswa--;
                cout << "Peserta berhasil dihapus\n";
                break;
            }
        }

        if (!ditemukan) {
            cout << "Peserta tidak ditemukan\n";
        }
    } else {
        cout << "Belum ada peserta yang terdaftar\n";
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Utama\n";
        cout << "[1] Informasi Seputar Jurusan\n";
        cout << "[2] Pendaftaran Mahasiswa Baru 2024\n";
        cout << "[3] Melakukan Uji Tes\n";
        cout << "[4] Melihat Nama yang lulus\n";
        cout << "[5] Verifikasi Pembayaran\n";
        cout << "[6] Tampil Daftar Peserta\n";
        cout << "[7] Hapus Mahasiswa\n";
        cout << "[8] Sorting Mahasiswa\n";
        cout << "[9] Push ke Stack\n";
        cout << "[10] Pop dari Stack\n";
        cout << "[11] Enqueue ke Queue\n";
        cout << "[12] Dequeue dari Queue\n";
        cout << "[0] Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                informasiJurusan();
                break;
            case 2:
                pendaftaranMahasiswaBaru();
                break;
            case 3:
                tesUjian();
                break;
            case 4:
                namaLulus();
                break;
            case 5:
                pembayaran();
                break;
            case 6:
                tampilDaftarMahasiswa();
                break;
            case 7:
                hapusMahasiswa();
                break;
            case 8:
                sortingMahasiswa();
                break;
            case 9: {
                Mahasiswa m;
                cout << "Masukkan data mahasiswa untuk push ke stack:\n";
                cout << "Nama: ";
                cin >> m.nama;
                cout << "Umur: ";
                cin >> m.umur;
                pushStack(m);
                break;
            }
            case 10:
                popStack();
                break;
            case 11: {
                Mahasiswa m;
                cout << "Masukkan data mahasiswa untuk enqueue ke queue:\n";
                cout << "Nama: ";
                cin >> m.nama;
                cout << "Umur: ";
                cin >> m.umur;
                enqueue(m);
                break;
            }
            case 12:
                dequeue();
                break;
            case 0:
                cout << "Keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
