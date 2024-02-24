/**
* @file Dugum.cpp
* @description Dugum sınıfındaki ilgili fonksiyonun işlevlerini yazdım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 15.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
Dugum::Dugum(Basamak* sayi) {
    this->sayi = sayi;
    this->sonraki = nullptr;
}
