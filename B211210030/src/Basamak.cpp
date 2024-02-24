/**
* @file Basamak.cpp
* @description Basamak sınıfındaki kurucu fonksiyonun işlevini yazdım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 15.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#include "Basamak.hpp"

Basamak::Basamak(int deger) {
    this->deger = deger;
    this->sonraki = nullptr;
}
