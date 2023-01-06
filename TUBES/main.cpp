#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    listTask LT;
    adrTask T;
    adrProject P; adrProject S;
    Task t;
    Project r;
    string tes;
    string status1 = "ToDo"; string status2 = "OnProgress"; string status3 = "Done";
    string namaProject;
    int pilihan;

    createListTask(LT);
    T = createElemenTask(status1);
    insertTask(LT,T);

    T = createElemenTask(status2);
    insertTask(LT,T);

    T = createElemenTask(status3);
    insertTask(LT,T);

    pilihan = selectMenu();
    while (pilihan != 0) {
        if (pilihan == 1) {
            cout << endl << "======= Task =======" << endl;
            showTask(LT);
            cout << endl;
            selectMenu2(pilihan);
        }else if (pilihan == 2){
            cout << "=== Masukkan Data Project yang Ingin Ditambahkan ===" << endl;
            cout << "Nama Project\t : ";
            cin >> r.namaProject;
            cout << "Tanggal Deadline : ";
            cin >> r.tanggal.day;
            cin >> r.tanggal.month;
            cin >> r.tanggal.year;
            cout << endl;
            cout << "=== Masukkan Task ===" << endl;
            cout << "Task (ToDo/OnProgress/Done): ";
            cin >> tes;
            cout << endl;
            P = createElemenProject(r);
            insertProjectSort(LT, tes, T, P);
            selectMenu2(pilihan);
        }else if(pilihan == 3){
            cout << "================== Project Manager ==================" << endl << endl;
            showAll(LT, T);
            cout << "=====================================================" << endl;
            selectMenu2(pilihan);
        }else if (pilihan == 4) {
            cout << "=== Masukkan Data Project yang Ingin Dihapus ===" << endl;
            cout << "Task (ToDo/OnProgress/Done)\t: ";
            cin >> tes;
            cout << "Nama Project\t\t\t: ";
            cin >> namaProject;
            cout << endl;
            deleteByParent(LT, P, namaProject, tes);
            selectMenu2(pilihan);
        }else if (pilihan == 5) {
            cout << "=== Masukkan Data Project yang Ingin Dicari ==="<< endl;
            cout << "Task (ToDo/OnProgress/Done)\t: ";
            cin >> tes;
            cout << "Nama Project\t\t\t: ";
            cin >> namaProject;
            S = searchByParent(LT, T, P, namaProject, tes);
            if (S != nil) {
                cout << infoP(S).namaProject << " - " << infoP(S).tanggal.day << "/" << infoP(S).tanggal.month << "/" << infoP(S).tanggal.year << endl;
            }else{
                cout << endl << "Project Tidak Ditemukan!" << endl << endl;
            }
            selectMenu2(pilihan);
        }else if (pilihan == 6) {
            cout << "=== Menampilkan Banyaknya Project yang Ada Pada Task ===" << endl;
            cout << "Task (ToDo/OnProgress/Done)\t: ";
            cin >> tes;
            cout << "Total Project\t\t\t: " << countChild(LT, T, P, tes) << endl;
            selectMenu2(pilihan);
        }
    }
    cout << "Anda telah keluar dari program." << endl;
}
