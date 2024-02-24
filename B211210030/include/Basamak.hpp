/**
* @file Basamak.hpp
* @description Basamak sınıfındaki kurucu fonksiyonun imzasını tanımladım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 12.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#ifndef BASAMAK_HPP
#define BASAMAK_HPP
#include <iostream>


class Basamak {
public:
    int deger;
    Basamak* sonraki;

    Basamak(int deger);
};

 
 #endif