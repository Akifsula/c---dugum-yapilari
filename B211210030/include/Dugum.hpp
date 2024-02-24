/**
* @file Dugum.hpp
* @description  Bağlı listeyi temsil eden Dugum sınıfını ve ilgili fonksiyonların imzasını tanımladım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 12.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>

#include "Sayi.hpp"

class Dugum {
public:
    Basamak* sayi;
    Dugum* sonraki;

    Dugum(Basamak* sayi);
    Dugum* adresiGetir();
};
#endif