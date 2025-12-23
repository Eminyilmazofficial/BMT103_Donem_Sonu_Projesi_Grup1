#include "fonksiyonlar.h"

int main (void) {


    char girisDosya[50];
    int kisiSayisi, casusSayisi, maxKisi;

    printf("Kullanici sayisini giriniz: ");
    scanf("%d", &maxKisi);

    //malloc fonkiyonu sayesinde maxKisi * sizeof(kisi) bytelik bellekte yer acilir.

    kisi *kimlikListesi = (kisi *)malloc(maxKisi * sizeof(kisi));

    //Eger listedeki kisi sayisi bellekteki yerden daha fazla olursa bellek yetersiz hatasi verir.

    if (kimlikListesi == NULL) {
        printf("Hata: Bellek yetersiz!\n");
        return 1;
    }

    printf("Dosya adini giriniz: ");
    scanf("%s", girisDosya);

    kisiSayisi = dosyaOku(girisDosya, kimlikListesi, maxKisi);

    //dosyaOku fonksiyonu sayesinde kisi sayisi saptanir ve kisiSayisi degiskenine atanir

    printf("Dosya okundu. %d kisi hafizaya kaydedildi.\n", kisiSayisi);

    diziSirala(kimlikListesi, kisiSayisi);

// casusTespit fonksiyonu ile casus sayisi belirlenir ve casusSayisi degiskenine atanir.

    casusSayisi = casusTespiti(kimlikListesi, kisiSayisi);

    printf("\n---Sonuc Raporu---\n");
    printf("Islem tamamlandi.\n");
    printf("Toplam %d adet casus bulundu ve 'casus.txt' dosyasina yazildi.\n", casusSayisi);

    free(kimlikListesi);

    return 0;
}