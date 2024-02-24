/**
* @file Sayi.hpp
* @description Sayının basamaklarını bağlı liste olarak temsil eden bir Sayi sınıfı, header pointerı oluşturdum ve ilgili fonksiyonların imzasını tanımladım.
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 12.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"

class Sayi {
public:
    Basamak* basamakBasi;

    Sayi();
    void ekleBasamak(int deger);
};
#endif
