#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#define infoP(p) (p)->infoP
#define infoT(p) (p)->infoT
#define nextP(p) (p)->nextP
#define child(p) (p)->child
#define nextT(p) (p)->nextT
#define firstT(p) p.firstT
#define nil NULL

#include <iostream>
using namespace std;

typedef string Task;
typedef struct project Project;
typedef struct elmtTask *adrTask;
typedef struct elmtProject *adrProject;

struct date {
    int day, month, year;
};

struct project {
    string namaProject, status;
    date tanggal;
};

struct elmtTask {
    Task infoT;
    adrTask nextT;
    adrProject child;
};

struct elmtProject {
    Project infoP;
    adrProject nextP;
};

struct listTask {
    adrTask firstT;
};

void createListTask(listTask &LT);
adrTask createElemenTask(string t);
void insertTask(listTask &LT, adrTask T);
void showTask(listTask LT);
adrTask searchTask(listTask LT, string status);

adrProject createElemenProject(Project r);
void insertFirstP(listTask &LT, string status, adrTask T, adrProject P);
void insertLastP(listTask &LT, string status, adrTask T, adrProject P);
void insertProjectSort(listTask &LT, string status, adrTask T, adrProject P);
void deleteFirstP(listTask &LT,adrTask T, adrProject &P);
void deleteLastP(listTask &LT, adrTask T, adrProject &P);
void deleteAfterP(listTask &LT, adrTask T, adrProject &P, adrProject prec);
void deleteByParent(listTask &LT, adrProject &P, string namaProject, string status);

void showAll(listTask LT, adrTask T);
adrProject searchByParent(listTask LT, adrTask T, adrProject P, string namaProject, string status);
int countChild(listTask LT, adrTask T, adrProject P, string status);

int selectMenu();
void selectMenu2(int &pilihan);

#endif // TUBES_H_INCLUDED
