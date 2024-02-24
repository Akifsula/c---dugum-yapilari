/**
* @file SayilarListesi.hpp
* @description SayilarListesi sınıfındaki mainde cağırcağım tüm  fonksiyonların imzasını tanımladım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 17.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include <string>
#include <sstream>
#include "Dugum.hpp"
using namespace std;
class SayilarListesi
{
public:
    Dugum *dugumBasi;

    SayilarListesi();
    ~SayilarListesi();

    void ekleSayi(Sayi *sayi);
    void tersCevir();
    void yazdirDugumDegerleri();
    void teklerBasa();
    void basamakTersle();
    void enBuyukCikar();
private:
    string adresiUcle(Basamak *adres);
};

#endif