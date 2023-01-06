#include "tubes.h"

void createListTask(listTask &LT) {
    firstT(LT) = nil;
}

adrTask createElemenTask(Task t) {
    adrTask T = new elmtTask;
    infoT(T) = t;
    child(T) = nil;
    nextT(T) = nil;

    return T;
}

void insertTask(listTask &LT, adrTask T) {
    if (firstT(LT) == nil) {
        firstT(LT) = T;
    }else{
        adrTask ptr = firstT(LT);
        while (nextT(ptr) != nil) {
            ptr = nextT(ptr);
        }
        nextT(ptr) = T;
    }
}

void showTask(listTask LT) {
    if (firstT(LT) == nil) {
        cout << "Task Tidak Ditemukan!" << endl;
    }else{
        adrTask T = firstT(LT);
        while (T != nil) {
            cout << infoT(T) << " ";
            T = nextT(T);
        }
    }
    cout << endl;
}

adrTask searchTask(listTask LT, string status){
    adrTask T = firstT(LT);
    if(firstT(LT) == nil){
        cout<<"Task Tidak Ditemukan!"<<endl;
    }else{
        while(T != nil){
            if(infoT(T) == status){
                return T;
            }
            T = nextT(T);
        }
    }
    return nil;
}

adrProject createElemenProject(Project r) {
    adrProject P = new elmtProject;
    infoP(P).namaProject = r.namaProject;
    infoP(P).tanggal.day = r.tanggal.day;
    infoP(P).tanggal.month = r.tanggal.month;
    infoP(P).tanggal.year = r.tanggal.year;
    nextP(P) = nil;

    return P;
}

void insertFirstP(listTask &LT, string status, adrTask T, adrProject P) {
    T = searchTask(LT, status);
    if (child(T) == nil) {
        child(T) = P;
    }else{
        nextP(P) = child(T);
        child(T) = P;
    }
}

void insertLastP(listTask &LT, string status, adrTask T, adrProject P) {
    T = searchTask(LT, status);
    if (child(T) == nil) {
        child(T) = P;
    }else{
        adrProject ptr = child(T);
        while (nextP(ptr) != nil && (infoP(nextP(ptr)).tanggal.year < infoP(P).tanggal.year || infoP(nextP(ptr)).tanggal.month < infoP(P).tanggal.month || infoP(nextP(ptr)).tanggal.day <= infoP(P).tanggal.day)){
            ptr = nextP(ptr);
        }
        nextP(ptr) = P;
    }
}

void insertProjectSort(listTask &LT, string status, adrTask T, adrProject P) {
    T = searchTask(LT, status);
    if (T != nil) {
        if (child(T) == nil) {
            child(T) = P;
        }else{
            if (infoP(child(T)).tanggal.year > infoP(P).tanggal.year) {
                insertFirstP(LT, status, T, P);
            }else if(infoP(child(T)).tanggal.year == infoP(P).tanggal.year){
                if(infoP(child(T)).tanggal.month > infoP(P).tanggal.month) {
                    insertFirstP(LT, status, T, P);
                }else if (infoP(child(T)).tanggal.month == infoP(P).tanggal.month) {
                    if(infoP(child(T)).tanggal.day > infoP(P).tanggal.day) {
                        insertFirstP(LT, status, T, P);
                    }else{
                        insertLastP(LT, status, T, P);
                    }
                }else{
                    insertLastP(LT, status, T, P);
                }
            }else{
                insertLastP(LT, status, T, P);
            }
        }
    }else{
        cout << "Task tidak ditemukan!" << endl;
    }
}

void deleteByParent(listTask &LT, adrProject &P, string namaProject, string status){
    adrTask T = searchTask(LT, status);
    adrProject Q = child(T);
    if(T != nil){
        while(Q != nil && infoP(Q).namaProject != namaProject){
            Q = nextP(Q);
        }
        if (Q == nil) {
            cout << "Project Tidak Ditemukan!" << endl;
        }else if (nextP(Q) == nil) {
            P = Q;
            child(T) = nil;
        }else{
            adrProject last = child(T);
            while (nextP(nextP(last)) != nil) {
                last = nextP(last);
            }

            if(Q == child(T)){
                P = Q;
                child(T) = nextP(Q);
                nextP(Q) = nil;
            }else if (Q == nextP(last)) {
                P = nextP(last);
                nextP(last) = nil;
            }else{
                adrProject prec = child(T);
                while (infoP(nextP(prec)).namaProject != infoP(Q).namaProject) {
                    prec = nextP(prec);
                }
                P = Q;
                nextP(prec) = nextP(P);
                nextP(P) = nil;
            }
        }
    }
}

adrProject searchByParent(listTask LT, adrTask T, adrProject P, string namaProject, string status){
    T = searchTask(LT, status);
    if(T != nil){
        P = child(T);
        while(P != nil && infoP(P).namaProject != namaProject){
            P = nextP(P);
        }
        if(P != nil){
            return P;
        }
    }else{
        return nil;
    }
}

int countChild(listTask LT, adrTask T, adrProject P, string status) {
    T = searchTask(LT, status);
    int total = 0;
    if (T != nil) {
        P = child(T);
        while (P != nil) {
            total++;
            P = nextP(P);
        }
    }else{
        cout << "Project tidak ditemukan" << endl;
    }
    return total;
}

void showAll(listTask LT, adrTask T) {
    if (firstT(LT) == nil) {
        cout << "Task Tidak Ditemukan!" << endl;
    }else{
        T = firstT(LT);
        while (T != nil) {
            cout << infoT(T) << endl;
            adrProject P = child(T);
            while (P != nil) {
                cout << infoP(P).namaProject << " - " << infoP(P).tanggal.day << "/" << infoP(P).tanggal.month << "/" << infoP(P).tanggal.year <<endl;
                P = nextP(P);
            }
            cout << endl;
            T = nextT(T);
        }
    }
}

int selectMenu() {
    cout << "====================== M E N U ======================" << endl;
    cout << "1. Menampilkan Task" << endl;
    cout << "2. Menambah Project ke Task" << endl;
    cout << "3. Menampilkan Seluruh Task dan Project" << endl;
    cout << "4. Menghapus Project" << endl;
    cout << "5. Mencari Project dari Task" << endl;
    cout << "6. Menampilkan Banyaknya Project yang Ada Pada Task" << endl;
    cout << "0. Exit" <<  endl << endl;

    int input = 0;
    cout << "Masukkan menu: ";
    cin >> input;
    return input;
}

void selectMenu2(int &pilihan) {
    cout << "Kembali ke menu utama? (Y/N) : ";
    char input;
    cin >> input;
    if (input == 'Y' || input == 'y') {
        pilihan = selectMenu();
    }else if (input == 'N' || input == 'n') {
        pilihan = 0;
    }
    cout << endl;
}
