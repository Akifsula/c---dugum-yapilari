/**
* @file Sayi.cpp
* @description Sayı sınıfındaki ilgili fonksiyonların işlevlerini yazdım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 15.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#include "Sayi.hpp"
#include "Basamak.hpp"

Sayi::Sayi() {
    this->basamakBasi = nullptr;
}


void Sayi::ekleBasamak(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);
    yeniBasamak->sonraki = this->basamakBasi;
    this->basamakBasi = yeniBasamak;
}
