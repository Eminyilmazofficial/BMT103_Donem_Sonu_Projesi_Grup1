#include "fonksiyonlar.h"

int karsilastir(const void *a, const void *b) 

/*Bu fonksiyon sayesinde qsort'u çalıştıran fonksiyondur.
Eger ilk eleman ikinciden buyuk ise 1 i kucuk ise -1 dondurur esit ise eger 0 degerini dondurur.*/

{

    const kisi *v1 = (kisi *)a;
    const kisi *v2 = (kisi *)b;

    if (v1->kimlikNumarasi > v2->kimlikNumarasi) {
        return 1;
    }

    else if (v1->kimlikNumarasi < v2->kimlikNumarasi) {
        return -1;
    }

    else {
        return 0;
    }
}

//Giris dosyasini okuyup diziye kaydeden ve kapasite kontrolu yapan fonksiyon

int dosyaOku(char *girisDosya, kisi liste[], int maxKisi) {

    FILE *dosyaPointer = fopen(girisDosya, "r");

    if (dosyaPointer == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    int sayac = 0;

    while (fscanf(dosyaPointer, "%lld", &liste[sayac].kimlikNumarasi) != EOF)
{
        sayac++;

        if (sayac >= maxKisi) {
            long long gecici;
            if (fscanf(dosyaPointer, "%lld", &gecici) != EOF) {
                printf("kapasite yetersiz\n");
                fclose(dosyaPointer);
                exit(1);
            }
        }
    }

/* Karsidan alinan maxKisi sayisi eger dosyadaki veri sayisindan az ise program 'kapasite yetersiz' yazdirarak
programi exit fonksiyonu ile sonlandirir.*/

    fclose(dosyaPointer);
    return sayac;
}


void diziSirala(kisi liste[], int kisiSayisi) {

    qsort(liste, kisiSayisi, sizeof(kisi), karsilastir);
    
    /*qsort fonksiyonu ile veriler kucukten buyuge siralanir.
Bu sayede ayni sayi degerine sahip kisiler kolay bir sekilde saptanabilir.*/

    printf("%d kisi kucukten buyuge siralandi.\n", kisiSayisi);

}


//Casuslari tespit eden fonksiyon

int casusTespiti(kisi liste[], int kisiSayisi) {


    FILE *casusDosya = fopen("casus.txt", "w");

    if (casusDosya == NULL) {

        printf("Dosya acilamadi!\n");

        return 0;
    }

        int casusSayisi = 0;


    for (int i = 0;i < kisiSayisi-1;i++) {

/* qsort fonksiyonu sayesinde siralanmis sayilari bir sonrakine esit olup olamadigini kontrol ediyor.
casusSayisi degiskeni sayesinde de casus sayisi sayiliyor. */

        if (liste[i].kimlikNumarasi == liste[i+1].kimlikNumarasi) {

            printf("Casus tespit edildi: %lld\n", liste[i].kimlikNumarasi);
            fprintf(casusDosya,"%lld\n", liste[i].kimlikNumarasi);
            casusSayisi++;

            while (i < kisiSayisi - 1 && liste[i].kimlikNumarasi == liste[i+1].kimlikNumarasi) {
                i++;
            }

        }
    }

    fclose(casusDosya);

    return casusSayisi;
}

