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

struct polyclinic randevual(struct polyclinic *polic, int *gun, int *saat_x, int *flag){
	
	if(*gun== 1 && polic->pazartesi.saat[*saat_x]== false ){
		polic->pazartesi.saat[*saat_x] = 1;
		printf("Pazartesi icin randevunuz olusturulmustur.(%d. Saat)\n",*saat_x);
		*flag = 1;
	}
	else if( *gun== 2 && polic->sali.saat[*saat_x]== false ){
		polic->sali.saat[*saat_x] = 1 ;
		printf("Sali icin randevunuz olusturulmustur.(%d. Saat)\n",*saat_x);
		*flag = 1;
	}
	else if( *gun == 3 && polic->carsamba.saat[*saat_x] == false){
		polic->carsamba.saat[*saat_x] = 1;
		printf("Carsamba icin randevunuz olusturulmustur.(%d. Saat)\n",*saat_x);
		*flag = 1;
	}
	else if( *gun == 4 && polic->persembe.saat[*saat_x] == false){
		polic->persembe.saat[*saat_x] = 1;
		printf("Persembe icin randevunuz olusturulmustur.(%d. Saat)\n",*saat_x);
		*flag = 1;
	}
	else if( *gun == 5 && polic->cuma.saat[*saat_x] == false){
		polic->cuma.saat[*saat_x] = 1;
		printf("Cuma icin randevunuz olusturulmustur.(%d. Saat)\n",*saat_x);
		*flag = 1;
	}
	else
		printf("\nSecmis oldugunuz randevu saati doludur.Randevunuz olusturulamadi.!!!\n");
		
		
	return *polic;

}

void RandevuKayit(struct polyclinic *polic, int *gun, int *saat_x, int *input_x){
	int x;
	FILE *pfile;
	pfile = fopen("RandevuKayit.txt","a+");
		
    if (pfile == NULL)  { 
        printf("Cannot open file \n"); 
	}
	
	else  {
	
	if(*input_x == 1){fprintf(pfile,"Kbb Randevusu:\n");}
	else if(*input_x == 2){fprintf(pfile,"Goz Randevusu:\n");}	
	else if(*input_x == 3){fprintf(pfile,"Dahiliye Randevusu:\n");}
	else if(*input_x == 4){fprintf(pfile,"Genel Cerrahi Randevusu:\n");}
	else if(*input_x == 5){fprintf(pfile,"Noroloji Randevusu:\n");}
	
	if(*gun == 1 && polic->pazartesi.saat[*saat_x]== true ){fprintf(pfile,"Pazartesi icin randevu : %d. Saat\n",*saat_x);}
	if(*gun == 2 && polic->sali.saat[*saat_x]== true ){fprintf(pfile,"Sali icin randevu : %d. Saat\n",*saat_x);}
	if(*gun == 3 && polic->carsamba.saat[*saat_x]== true ){fprintf(pfile,"Carsamba icin randevu : %d. Saat\n",*saat_x);}
	if(*gun == 4 && polic->persembe.saat[*saat_x]== true ){fprintf(pfile,"Persembe icin randevu : %d. Saat\n",*saat_x);}
	if(*gun == 5 && polic->cuma.saat[*saat_x]== true ){fprintf(pfile,"Cuma icin randevu : %d. Saat\n",*saat_x);}
		
		fclose(pfile);
	}
	rewind(pfile);
}

void add_patient(struct patient *new_pat, int index){
	char str[50];
	int flag=0;

	new_pat=new_pat+index-1;
	
	new_pat->patient_num = index+202100;
	
	while( flag == 0){
		printf("Hasta adi soyadi :  ");
		scanf(" %[^\n]",str);
		if(strlen(str) >= 30){
			printf("maksimum 29 karakter olarak girilmelidir\n");
			flag=0;
		}	
		else{
			strcpy(new_pat->name, str);
			flag=1;
		}
	}
	puts(new_pat->name);
	
	printf("Hasta TCKN (son 4 hanesini giriniz ):");
	scanf("%d",&new_pat->tc);
	printf("%d",new_pat->tc);
 
	printf("\nHasta yasi : ");
	scanf("%d",&new_pat->age );
	printf("%d\n",new_pat->age);
	
	flag=0;
	while(flag==0 ){
		printf("Hastanin cinsiyeti : ");
		scanf("%s",str);
		if(strlen(str) == 5){
			strcpy(new_pat->gender, str);
			flag= 1;
		}
		else{
			flag=0;
			printf("DiKKAT !!! maksimum 5 karakter giriniz \n");
		}
			
		}
	puts(new_pat->gender);
	
	printf("Hastanin kilosu : ");
	scanf("%d",&new_pat->weigth);
	printf("%d\n",new_pat->weigth);
	
	printf("Hastanin boyu : ");
	scanf("%d",&new_pat->heigth);
	printf("%d\n",new_pat->heigth);
	
	flag = 0;
	while( flag == 0){
		printf("Hastanin kan grubu : ");
		scanf("%s",str);
		if( strlen(str) <=3 ){
			strcpy(new_pat->blood_group, str);
			flag=1;
		}
		else{
			printf("DiKKAT:!! maskimum 3 karakter giriniz \n");
		flag=0;
		}
	}
	puts(new_pat->blood_group);
	
	printf("Hastalik Gecmisini giriniz (maksimum 500 karakter) : ");
	scanf(" %[^\n]",new_pat->hasta_gecmisi);
	
	
	system("cls");
	

}

void inforefresh(int hastatc, struct patient *new_pat, int index){
	system("cls");
	int i, flag=0;
	char str[50];
	struct patient *temp;
	temp=new_pat;
 	for(i=0; i<100; i++){
		if(hastatc != new_pat->tc){
			flag=0;
			new_pat++;
		}
			
		else{
			flag=1;
			break;
		}
		
	}
	if(flag == 1 ){
	
		printf("hasta bilgileri \nHasta Adi : %s\nHasta TCKN : %d\nHasta ID Number : %d\nHasta Yasi : %d\nHasta Cinsiyeti : %s\nHasta Kilosu : %d\nHasta Boyu : %d\nHastanin Kan Grubu : %s\nHastanin ozgecmisi : %s\n\n Yeni bilgileri giriniz..\n", new_pat->name, new_pat->tc, new_pat->patient_num, new_pat->age, new_pat->gender, new_pat->weigth, new_pat->heigth, new_pat->blood_group, new_pat->hasta_gecmisi);
		
		while( flag == 0){
			printf("Hasta adi soyadi :  ");
			scanf(" %[^\n]",str);
			if(strlen(str) >= 30){
				printf("maksimum 29 karakter olarak girilmelidir\n");
				flag=0;
			}	
			else{
				strcpy(new_pat->name, str);
				flag=1;
				}
		}
		printf("Hasta TCKN :");
		scanf("%d",&new_pat->tc);
		printf("%d",new_pat->tc);
	 
		printf("\nHasta yasi : ");
		scanf("%d",&new_pat->age );
		printf("%d\n",new_pat->age);
		
 		flag=0;
		while(flag==0 ){
			printf("Hastanin cinsiyeti : ");
			scanf("%s",str);
			if(strlen(str) == 5){
				strcpy(new_pat->gender,str);
				flag= 1;
			}
			else{
				flag=0;
				printf("DiKKAT !!! maksimum 5 karakter giriniz \n");
			}
		}
		puts(new_pat->gender);
		
		printf("Hastanin kilosu : ");
		scanf("%d",&new_pat->weigth);
		printf("%d\n",new_pat->weigth);
		
		printf("Hastanin boyu : ");
		scanf("%d",&new_pat->heigth);
		printf("%d\n",new_pat->heigth);
		
		flag = 0;
		while( flag == 0){
			printf("Hastanin kan grubu : ");
			scanf("%s",str);
			if( strlen(str) <=3 ){
				strcpy(new_pat->blood_group, str);
				flag=1;
			}
			else{
				printf("DiKKAT:!! maskimum 3 karakter giriniz \n");
			flag=0;
			}
		}
		puts(new_pat->blood_group);
		
		printf("Hastalik Gecmisini giriniz (maksimum 500 karakter) : ");
		scanf(" %[^\n]",new_pat->hasta_gecmisi);
		
		printf("Guncel bilgiler...\nHasta Adi : %s\nHasta TCKN : %d\nHasta ID Number : %d\nHasta Yasi : %d\nHasta Cinsiyeti : %s\nHasta Kilosu : %d\nHasta Boyu : %d\nHastanin Kan Grubu : %s\nHastanin ozgecmisi : %s\n", new_pat->name, new_pat->tc, new_pat->patient_num, new_pat->age, new_pat->gender, new_pat->weigth, new_pat->heigth, new_pat->blood_group, new_pat->hasta_gecmisi);
		}
	
	else {
		printf("\n Dikkat!  hasta kaydi bulunamadi.!! Lutfen once hasta kaydi yapiniz. \n");
	}
	
}

void printPatients(int hastatc,struct patient *new_pat, int index){
	system("cls");
	int i,flag=0;
	struct patient *temp;
	temp = new_pat;
	
	for(i=0; i<100; i++){
		if(hastatc != new_pat->tc){
			flag=0;
			new_pat++;
		}
			
		else{
			flag=1;
			break;
		}
		
	}
	if(flag == 1 ){
	
		printf("hasta bilgileri \nHasta Adi : %s\nHasta TCKN : %d\nHasta ID Number : %d\nHasta Yasi : %d\nHasta Cinsiyeti : %s\nHasta Kilosu : %d\nHasta Boyu : %d\nHastanin Kan Grubu : %s\nHastanin ozgecmisi : %s\n\n Yeni bilgileri giriniz..\n", new_pat->name, new_pat->tc, new_pat->patient_num, new_pat->age, new_pat->gender, new_pat->weigth, new_pat->heigth, new_pat->blood_group, new_pat->hasta_gecmisi);
	}	
	//new_pat = temp;
    
     else {
	printf("\n Dikkat!  hasta kaydi bulunamadi.!! Lutfen once hasta kaydi yapiniz. \n ");
         }
}

void printinfo(struct patient *new_pat, int index){
	int i;
	struct patient *temp;
	temp = new_pat;
	
	for(i=0; i<index-1; i++){
		new_pat++;
	}
	system("cls");
	printf("Hasta Adi : %s\nHasta TCKN : %d\nHasta ID Number : %d\nHasta Yasi : %d\nHasta Cinsiyeti : %s\nHasta Kilosu : %d\nHasta Boyu : %d\nHastanin Kan Grubu : %s\nHastanin ozgecmisi : %s\n", new_pat->name, new_pat->tc, new_pat->patient_num, new_pat->age, new_pat->gender, new_pat->weigth, new_pat->heigth, new_pat->blood_group, new_pat->hasta_gecmisi);
	new_pat = temp;
}

void delay(int number_of_seconds){ 
    float halfmilli_seconds = 500 * number_of_seconds; //alinan saniyeyi yarim saniyeyle carpan time kutuphanesi fonksiyonlarini kullanan delay fonksiyonu
  
    clock_t start_time = clock(); //baslama saatini kaydediyoruz
  
    while (clock() < start_time + halfmilli_seconds); //saat baslama saati ve hesaplattigimiz gecen s�reye kadar olan s�renin toplamyndan k�c�k oldugu s�rece seklinde while dongusu
} 

void displayArayuz(){   /*Oncelikle baslangicta buyuk bir H harfi bastirarak kullanici karsiliyoruz*/
	int i,j,k;
	
	for(i=0;i<=11;i++){
		printf("\t\t\t\t\t\t");
		delay(1);
		for(j=0;j<2;j++){
			
			printf("*");
		}
		for(k=1;k<=5;k++){
			if(i>4 && i<7){
				printf("**");
			}
			else{
				printf("  ");
			}
		}
		for(j=0;j<2;j++){
			printf("*");
			
		}
		printf("\n");
	}
	
	printf("\n\t\t\t KOCAELI HASTA/DOKTOR BILGI SISTEMINE HOSGELDINIZ\n");
	printf("\n\t\t\t\t Girisiniz yapiliyor..\n");
	
	
	delay(3);
	system("cls");
	
}

void displayHazirlayanlar(){   //Odevi hazirlayanlaryn isimlerini bastirarak programymyzy sonlandyryyoruz
	int i;
	char hazirlayanlar[5][30]={"Irem", "Can"};
	printf("\n");
	printf("\n");
	printf("Created By");
	printf("\n");
	for(i=0;i<5;i++){
		delay(1);
		printf("%s\n",hazirlayanlar[i]);
	}
}

int accessControl(){
	char c;
	int password;
	printf("Hastane Gorevlisi olarak giris yapmak icin 'Y' \nHasta girisi yapmak icin 'R' \nCikis yapmak icin 'Q' tuslayiniz\n");
	scanf("%c",&c);//Kullanicidan aldigimiz input ile  kullaniciyi istedigi bolume yonlendiriyoruz

	
	if(c == 'Y' || c == 'y'){
		printf("\nHosgeldiniz devam etmek icin size verilen anahtari giriniz=>");
		scanf("%d",&password);//Kullanicinin yetkili olup olmadigini saglamak amacyyla
		printf("\n");
		int sayac=3;
		while(password!=Key && sayac>0){
			
			printf("Yanlis anahtar girildi lutfen yeniden deneyin \n");
			scanf("%d",&password);//anahtar dogru girilene kadar kullanicinin anahtari tekrar girmesi istenir
		}
		if(password==Key){
			system("cls");
			printf("\nPersonel girisine hosgeldiniz \n\n");
			return 1;
		}
	}
	else if(c == 'R' || c =='r'){
		system("cls");
		printf("\nHasta girisine hosgeldiniz\n");
		return 2;
	}
	else if(c == 'q' || c == 'Q')//Alinan karakterin q olmasy halinde sistemden cikis yapilir
		return 88;
}

void covidtest(struct covid *covid){
	int flag=0;
	printf("lutfen adinizi soyadinizi giriniz:");
	scanf(" %[^\n]",covid->name);
	printf("\nLutfen asagidaki sorulara evet ya da hayir olarak cevap verin\n");
	flag = 0;
	while( flag == 0){
		printf("Atesiniz veya ates oykunuz var mi?\n");
		scanf("%s",covid->ates);
		if(strcmp(covid->ates,"evet")==0 || strcmp(covid->ates,"hayir")==0){
			flag=1;
			break;
		}
		else{
			printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
			flag=0;
		}
	}
	flag = 0;
	while( flag == 0){
		printf("Oksurugunuz var mi?\n");
		scanf("%s",covid->oksuruk);
		if(strcmp(covid->oksuruk,"evet")==0 || strcmp(covid->oksuruk,"hayir")==0){
			flag=1;
			break;
		}
		else{
			printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
			flag=0;
		}
	}
	flag = 0;
	while( flag == 0){
		printf("Nefes darligi, bogaz agrisi bas agrisi, kas agrilari,tat ve koku alma kaybi veya ishal var mi?\n");
		scanf("%s",covid->agri);
		if(strcmp(covid->agri,"evet")==0 || strcmp(covid->agri,"hayir")==0){
			flag=1;
			break;
		}
		else{
			printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
			flag=0;
		}
	}
	if(strcmp(covid->ates,"evet")==0 || strcmp(covid->oksuruk,"evet")==0 || strcmp(covid->agri,"evet")==0){
		printf("Koronavirus riskiniz vardir,lutfen maske takip bir saglik kurulusuna basvurun\n\n");}
	else  {
		flag = 0;
		while( flag == 0){
			printf("Son 14 gun icerisinde yurt disinda bulundunuz mu?\n");
			scanf("%s",covid->yurtdisi);
			if(strcmp(covid->yurtdisi,"evet")==0 || strcmp(covid->yurtdisi,"hayir")==0){
				flag=1;
				break;
			}
			else{
				printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
				flag=0;
			}
		}	
		flag = 0;
		while( flag == 0){
			printf("Son 14 gun icerisinde ev halkindan birisi yurt disindan geldi mi?\n");
			scanf("%s",covid->yurtdisiev);
			if(strcmp(covid->yurtdisiev,"evet")==0 || strcmp(covid->yurtdisiev,"hayir")==0){
				flag=1;
				break;
			}
			else{
				printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
				flag=0;
			}
		}
		flag = 0;
		while( flag == 0){
			printf("Son 14 gun icerisinde yakinlarinizdan herhangi birisi solunum yolu hastaligi nedeni ile hastaneye yatti mi?\n");
			scanf("%s",covid->solunum);
			if(strcmp(covid->solunum,"evet")==0 || strcmp(covid->solunum,"hayir")==0){
				flag=1;
				break;
			}
			else{
				printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
				flag=0;
			}
		}
		flag = 0;
		while( flag == 0){
			printf("Son 14 gun icerisinde yakinlarinizdan COVID-19 hastaligi tanisi olan birisi oldu mu?\n");
			scanf("%s",covid->yakinlar);
			if(strcmp(covid->yakinlar,"evet")==0 || strcmp(covid->yakinlar,"hayir")==0){
				flag=1;
				break;
			}
			else{
				printf("eksik yada hatali tuslama yaptiniz.lutfen tekrar deneyin.\n");
				flag=0;
			}
		}
		if(strcmp(covid->yurtdisi,"evet")==0 || strcmp(covid->yurtdisiev,"evet")==0 || strcmp(covid->solunum,"evet")==0 ||strcmp(covid->yakinlar,"evet")==0){
			printf("Koronavirus riskiniz vardir,lutfen maske takip bir saglik kurulusuna basvurun\n\n");
		}
		else{
			printf("COVID-19 acisindan dusuk risklisiniz lutfen sikayetiniz yonunde degerlendirilmek uzere ilgili bolume basvurun.\n\n");
			}
	}
}

void check_up1(int hasta){
	if(hasta<20){
		printf("20 yasindan kucuk oldugunuz icin size uygun olan paket ve icerigi:\n");
		printf("PAKET 1:\n");
		printf("1-Doktor muayenesi\n2-Vitamin ve mineral testleri\n3-Idrar tahlili\n");
		printf("\nDAHA DETAYLI BILGI ALMAK ICIN DOKTORUNUZA BASVURUN.\n");
	}
	if(hasta>=20 && hasta<=65){
		printf("Yetiskin grubunda oldugunuz icin size uygun olan paket ve icerigi:\n");
		printf("PAKET 2:\n");
		printf("1-Doktor muayenesi\n2-Vitamin ve mineral testleri\n3-Idrar tahlili\n");
		printf("4-Efor testi\n5-EKG\n6-ROntgen");
		printf("\nDAHA DETAYLI BILGI ALMAK ICIN DOKTORUNUZA BASVURUN.\n");
	}
	if(hasta>65 && hasta<=120){
		printf("Yasli grubunda oldugunuz icin size uygun olan paket ve icerigi:\n");
		printf("PAKET 3:\n");
		printf("1-Doktor muayenesi\n2-Vitamin ve mineral testleri\n3-Idrar tahlili\n");
		printf("4-Efor testi\n5-EKG\n6-Rontgen");
		printf("7-Karaciger ve bÃ¶brek fonksiyon testleri\n8-Kan lipid ve kolesterol testleri\n9-Ultrasonografi\n");
		printf("\nDAHA DETAYLI BILGI ALMAK ICIN DOKTORUNUZA BASVURUN.\n");
	}
}

void randevu_ucret(struct polyclinic kbb,struct polyclinic goz,struct polyclinic dahiliye,struct polyclinic genel_cerrahi,struct polyclinic noroloji){
	int poliklinik;
	printf("1-Kbb icin 1\n2-Goz hastaliklari icin 2\n3-Dahiliye icin 3\n4-Genel Cerrahi icin 4\n5-Noroloji icin 5 giriniz\n");
	printf("Muayene Olmak Istediginiz Poliklinigin numarasini Giriniz:  ");
	scanf("%d",&poliklinik);
	
	switch(poliklinik){
		case 1:
			printf("Kbb poliklinligi randevu ucretiniz %d tl dir\n",kbb.randevu_ucreti);
			break;
		case 2:
			printf("Goz hastaliklari poliklinligi randevu ucretiniz %d tl dir.\n",goz.randevu_ucreti);
			break;
		case 3:
			printf("dahiliye poliklinligi randevu ucretiniz %d tl dir.\n",dahiliye.randevu_ucreti);
			break;
		case 4:
			printf("Genel Cerrahi poliklinligi randevu ucretiniz %d tl dir.\n",genel_cerrahi.randevu_ucreti);
			break;
		case 5:
			printf("Noroloji poliklinligi randevu ucretiniz %d tl dir.\n",noroloji.randevu_ucreti);
			break;
		default:
			printf("Yanlis ya da eksik tuslama yaptiniz.\n\n");
	}
}

void ucret_refresh(struct polyclinic *new_pol){
	system("cls");
	int input;
	printf("Belirlemek istediginiz ucreti giriniz\n");
	scanf("%d",&input);
	new_pol->randevu_ucreti=input;
}

void yedekKayitAlma(struct patient *hastalar,int index){
	FILE *hastaneKayitlari=fopen("hastaneKayitlari.txt","w+");
	if(hastaneKayitlari==NULL){
		fprintf(stderr,"Yedek kayit alinirken bir hata meydana geldi.");
		exit(1);
	}
    else { 
    	    int i;
    	    for(i=0; i<index; i++){
    	    fprintf(hastaneKayitlari,"------------------------YENI HASTA--------------------------------------------------\n");
			fprintf(hastaneKayitlari,"Hasta ismi : %s\n",hastalar->name);
			fprintf(hastaneKayitlari,"Hasta Tc : %d\n",hastalar->tc);
			fprintf(hastaneKayitlari,"Hasta yasi : %d\n",hastalar->age);
			fprintf(hastaneKayitlari,"Hasta cinsiyeti : %s\n",hastalar->gender);
			fprintf(hastaneKayitlari,"Hasta boyu : %d\n",hastalar->heigth);
			fprintf(hastaneKayitlari,"Hasta kilosu : %d\n",hastalar->weigth);
			fprintf(hastaneKayitlari,"Hastalik gecmisi : %s\n",hastalar->hasta_gecmisi);
			fprintf(hastaneKayitlari,"Hasta kan grubu : %s\n",hastalar->blood_group);
			hastalar++;
			}
			
	fprintf(hastaneKayitlari,"\n------------------------------\ntoplam hasta sayisi %d",index);
	fclose(hastaneKayitlari);
	}
}

void displayDoctors(struct doctor doctorList[]){//Hastanede bulunan doktorlari departmanlari ile beraber ekrana bastirmamizi saglar
	int i,j;
	for(i=0;i<10;i++){
		printf("%s\t\t%s\n",doctorList[i].name,doctorList[i].departmant);
		//printf("%s\n",doctorList[i].departmant);
	
	}
}

void covid_dosya(struct covid *covid){
	FILE *pfile;
	pfile = fopen("testdosyas�.txt","a");
		
    if (pfile == NULL)  { 
        printf("Cannot open file \n"); 
	}
	fprintf(pfile," %s\t",covid->name);
	
	if(strcmp(covid->ates,"evet")==0 || strcmp(covid->oksuruk,"evet")==0 || strcmp(covid->agri,"evet")==0){
		fprintf(pfile,"Koronavirus riski:y�ksek\n");}
	else  {
		
		if(strcmp(covid->yurtdisi,"evet")==0 || strcmp(covid->yurtdisiev,"evet")==0 || strcmp(covid->solunum,"evet")==0 ||strcmp(covid->yakinlar,"evet")==0){
			fprintf(pfile,"Koronavirus riski:y�ksek\n");}
	
		else{
			fprintf(pfile,"Koronavirus riski:d���k\n");}
	}
	fclose(pfile);	
}
