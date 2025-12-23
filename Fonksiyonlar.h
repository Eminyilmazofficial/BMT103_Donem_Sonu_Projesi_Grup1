//Dosyanin birden fazla kez calismasini engeller.
#ifndef FONKSIYONLAR_H
#define FONKSIYONLAR_H

//kutuphaneler

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef sayesinde degisken turunu daha kisa halde yazilmasina olanak saglar. 

typedef struct {
    long long int kimlikNumarasi;
}
kisi;

//Fonksiyonlar

int dosyaOku(char *girisDosya, kisi liste[], int maxKisi);

void diziSirala(kisi liste[], int kisiSayisi);

int casusTespiti(kisi liste[], int kisiSayisi);

#endif
