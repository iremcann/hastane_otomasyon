#ifndef my_array_library
#define my_array_library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define Key 2021

struct day{
	bool saat[10];
};

struct polyclinic{
	struct day pazartesi,sali,carsamba,persembe,cuma;
	int randevu_ucreti;	
};

struct doctor{
	char name[30];
	char university[50];
	char departmant[50];
	int age;
};

struct patient{
	char name[30];
	int tc;
	int patient_num;
	int age;
	char gender[6];
	int weigth;
	int heigth;
	char blood_group[4];
	char hasta_gecmisi[501];
	
};

/*
struct test{
	char kan_testi[101];
	char mr[101];
	char kultur_testi[101];
	char alerji_testi[101];
	char gebelik_testi[101];	
};
*/

struct covid{
	char name[20];
	char ates[5];
	char oksuruk[5];
	char agri[5];
	char yurtdisi[5];
	char yurtdisiev[5];
	char solunum[5];
	char yakinlar[5];
};


void add_patient(struct patient *new_pat, int index);

void inforefresh(int hastatc, struct patient *new_pat, int index);

void printinfo(struct patient *new_pat, int index);

void printPatients(int hastatc,struct patient *new_pat, int index);

struct polyclinic randevual(struct polyclinic *polic, int *gun, int *saat_x, int *flag);

void randevu_ucret(struct polyclinic kbb,struct polyclinic goz,struct polyclinic dahiliye,struct polyclinic genel_cerrahi,struct polyclinic noroloji);

void RandevuKayit(struct polyclinic *polic, int *gun, int *saat_x, int *input_x);

void ucret_refresh(struct polyclinic *new_pol);

void covidtest(struct covid *covid);

void covid_dosya(struct covid *covid);

void check_up1 (int hasta);

void yedekKayitAlma(struct patient *hastalar,int index);

void displayHazirlayanlar();

void delay(int number_of_seconds);

void displayArayuz();

int accessControl();

void displayDoctors(struct doctor doctorList[]);


#endif
