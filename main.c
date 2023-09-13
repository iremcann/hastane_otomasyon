#include <stdio.h>
#include <stdlib.h>

#include "hosp_library.h"

int number = 202100;//hasta numarasý sabiti

int main(){
	int	flag=0; // randevu fonksiyonunu cagirmadan once dogru girdi alabilme testi icin kullanildi
	int control=111, input=111; // fonksiyonlarý kullanmadan girdi alabilmek icin kullanýldý
	int hasta1;
	int *gun_x, *saat_a, *i;
	int x=111,a=111; // case 4'te randevu fonksiyonunda gun saati almak icin kullanildi
	int index;
	struct polyclinic kbb;
	kbb.randevu_ucreti=120;
	
	struct polyclinic goz;
	goz.randevu_ucreti=200;
	
	struct polyclinic dahiliye;
	dahiliye.randevu_ucreti=250;
	
	struct polyclinic genel_cerrahi;
	genel_cerrahi.randevu_ucreti=220;
	
	struct polyclinic noroloji;
	noroloji.randevu_ucreti=180;
	

	struct doctor doctorList[20];
	struct patient patients[100];
	
	struct covid test;	
	
	displayArayuz();
	
	printf("Hastanemizde Gorev Alan Doktorlarimiz\n");
	strcpy(doctorList[0].name, "Eylul Soner");
	strcpy(doctorList[0].university, "Arel University");
	strcpy(doctorList[0].departmant,"KBB");
	
	strcpy(doctorList[1].name, "Ela Altindag");
	strcpy(doctorList[1].university, "Hacettepe University");
	strcpy(doctorList[1].departmant,"KBB");
	
	strcpy(doctorList[2].name, "Zenan Birtan");
	strcpy(doctorList[2].university, "Osmangazi University");
	strcpy(doctorList[2].departmant,"Goz");
	
	strcpy(doctorList[3].name, "Zeynep Ozturk");
	strcpy(doctorList[3].university, "Osmangazi University");
	strcpy(doctorList[3].departmant,"Goz");
	
	strcpy(doctorList[4].name, "Julide Aydin");
	strcpy(doctorList[4].university, "Istanbul University");
	strcpy(doctorList[4].departmant,"Dahiliye");
	
	strcpy(doctorList[5].name, "Arslan Ibooglu");
	strcpy(doctorList[5].university, "Arizona State University");
	strcpy(doctorList[5].departmant,"Dahiliye");
	
	strcpy(doctorList[6].name, "Suat Birtan");
	strcpy(doctorList[6].university, "Afyonkarahisar University");
	strcpy(doctorList[6].departmant,"Genel Cerrahi");
	
	strcpy(doctorList[7].name, "Haldun Goksun");
	strcpy(doctorList[7].university, "Michigan University");
	strcpy(doctorList[7].departmant,"Genel Cerrahi");
	
	strcpy(doctorList[8].name, "Levent Atahanli");
	strcpy(doctorList[8].university, "Yale University");
	strcpy(doctorList[8].departmant,"Noroloji");
	
	strcpy(doctorList[9].name, "Kader Denizhan");
	strcpy(doctorList[9].university, "Ege University");
	strcpy(doctorList[9].departmant,"Noroloji");
	
	displayDoctors(doctorList);
	delay(6);
	while(control != 88){
		system("cls");//system clsleri ekrani temizlememizi sagliyor bu da bize temiz bir ekran veriyor
		control = accessControl();
		input = control;
		if(control==1){//Yetkili girisi ifi hasta eklemek hasta bilgisi acmak icin
			while(input != 99){
			printf("\n1-)Hasta kaydi icin 0'i tuslayiniz.\n2-)Hasta bilgilerine ulasmak icin 1'i tuslayiniz.\n3-)Hasta bilgi yenileme icin 2'i tuslayiniz \n4-)Yedek alma icin 3'u tuslayiniz\n5-)Randevu ucreti degistirmek icin 4'u tuslayiniz\n6-)Ust menuye donmek icin 99'u tuslayiniz : ");
			scanf("%d",&input);
				switch(input){
					case 0:
						system("cls");
						number++;
						index = number-202100;
						//printf("index : %d",index);
						add_patient(patients,index);
						printinfo(patients, index);
						break;
						
					case 1:
						system("cls");
						printf("Ulasmak istediginiz hastanin tc numarasinin son 4 hanesini giriniz : ");
						scanf("%d",&input);
						index = number-202100;
						printPatients(input, patients, index);
						break;
						
					case 2:
						system("cls");
						printf("Ulasmak istediginiz hastanin tc numarasinin son 4 hanesini giriniz : ");
						scanf("%d",&input);
						printf("\nGirmis oldugunz TCKN : %d",input);
						index = number-202100;
						inforefresh(input, patients,index);
						break;
						
					case 3:
						system("cls");
						index = number-202100;
					    yedekKayitAlma(patients,index);
					    printf("Yedek alma tamamlandi..!!\n");
					    break;
					    
					case 4:
						system("cls");
						printf("Randevu ucret degisim sayfasina hos geldiniz\n\nKbb ucret belirleme icin 1\nGoz ucret belirleme icin 2\nDahiliye ucret belirleme icin 3\nGenel cerrahi ucret belirleme icin 4\nNoroloji ucret belirleme icin 5 tuslainiz \n");
						scanf("%d",&input);
						if(input == 1)
							ucret_refresh(&kbb);
						else if( input == 2 )
							ucret_refresh(&goz);
						else if( input == 3)
							ucret_refresh(&dahiliye);
						else if( input == 4 )
							ucret_refresh(&genel_cerrahi);
						else if( input == 5 ){
							ucret_refresh(&noroloji);
						}
						break;
					
					case 99:
						system("cls");
						printf("\n    Ust Menuye Donuluyor...\n");
						delay(2);
						break;	
						
					default:
						system("cls");
						printf("hatali giris yaptiniz!! \nlutfen tekrar deneyiniz");
						break;
				}
			}
		}//hasta girisi ifi
		else if(control==2){
			while(input != 99){
				printf("Devam etmek icin \n\n");
				printf("1-Covid risk testi icin 1\n2-Randevu ucretlerini ogrenmek icin 2\n3-Check-up hakkinda bilgi almak icin 3\n4-Randevu almak icin 4\n5-Ust menuye donmek icin 99\n");
				scanf("%d",&input);
				switch(input){
					case 1:
						system("cls");
						covidtest(&test);
						covid_dosya(&test);
						break;
						
					case 2:
						system("cls");
						randevu_ucret(kbb,goz,dahiliye,genel_cerrahi,noroloji);
						break;
						
					case 3:
						system("cls");
						printf("Size uygun paketi goruntulemek icin yasinizi giriniz : ");
		    			scanf("%d",&hasta1 );
		    			check_up1(hasta1);
						break;
				
					case 4:
						system("cls");
						flag=0;
						while(flag==0){
							printf("1-Kbb icin 1\n2-Goz hastaliklari icin 2\n3-Dahiliye icin 3\n4-Genel Cerrahi icin 4\n5-Noroloji icin 5 giriniz\n");
							scanf("%d",&input);
							if(input == 1 || input == 2 || input == 3 || input == 4 || input == 5){
								flag=1;
							}
							else{
								system("cls");
								printf("Dikkat..!! Hatali sayi tusladiniz lutfen ( 1-5 ) arasýnda rakam giriniz\n\n");
							}
						}
						flag = 0;
						while( flag == 0){
							printf("Lutfen asagida verilen gunlerden birini seciniz :\n");
							printf("1-Pazartesi icin 1\n2-Sali icin 2\n3-Carsamba icin 3\n4-Persembe icin 4\n5-Cuma icin 5\n");
							scanf("%d",&x);
							if( x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
								flag=1;
							else{
								system("cls");
								printf("Dikkat..!! Hatali sayi tusladiniz lutfen ( 1-5 ) arasýnda rakam giriniz\n\n");
							}
						}
						
						flag = 0;
						while(flag == 0){
							printf("Lutfen asagida verilen saatlerden birini seciniz :\n");
							printf("08.30 icin 1\n10.00 icin 2 \n11.30 icin 3\n13.45 icin 4\n15.00 icin 5 tuslayiniz\n");
							scanf("%d", &a);
							if( a == 1 || a == 2 || a == 3 || a == 4 || a == 5){
								flag = 1;
							}
							else{
								system("cls");
								printf("Dikkat..!! Hatali sayi tusladiniz lutfen ( 1-5 ) arasýnda rakam giriniz\n\n");
							}
						}
						gun_x = &x;
						saat_a = &a;
						i = &input;
						flag=0;
						if(input==1){
							randevual(&kbb,gun_x,saat_a,&flag);
							if( flag == 1 )
								RandevuKayit(&kbb,gun_x,saat_a,i);
						}
						
						else if(input==2){
							randevual(&goz,gun_x,saat_a,&flag);
							if( flag == 1 )
								RandevuKayit(&goz,gun_x,saat_a,i);
						}
						else if(input == 3){
							randevual(&dahiliye,gun_x,saat_a,&flag);
							if( flag == 1 )
								RandevuKayit(&dahiliye,gun_x,saat_a,i);	
						}
						else if(input == 4){
							randevual(&genel_cerrahi,gun_x,saat_a,&flag);
							if( flag == 1 )
								RandevuKayit(&genel_cerrahi,gun_x,saat_a,i);
						}
						else if(input == 5){
							randevual(&noroloji,gun_x,saat_a,&flag);
							if( flag == 1 )
								RandevuKayit(&noroloji,gun_x,saat_a,i);
						}
						break;
									
					case 99:
						system("cls");
						printf("\n    Ust Menuye Donuluyor...\n");
						delay(2);
						break;
							
					default:
						system("cls");
						printf("hatali giris yaptiniz!! \nlutfen tekrar deneyiniz.\n");
						break;
				}
			}
		}
	}
	
	displayHazirlayanlar();
	return 0;
}
