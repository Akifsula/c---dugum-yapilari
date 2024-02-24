/**
* @file Test.cpp
* @description  programı çalıştıran main fonksiyonunda dosya okuma ve menü işlemlerini burada yaptım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 18.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include "SayilarListesi.hpp"
#include <limits>
#include <windows.h>

using namespace std;

int main() {
    SayilarListesi sayilarListesi;
    ifstream dosya("Sayilar.txt");

    if (dosya.is_open()) {
        int sayi;
        while (dosya >> sayi) {
            Sayi* yeniSayi = new Sayi();
            while (sayi > 0) {
                yeniSayi->ekleBasamak(sayi % 10);
                sayi /= 10;
            }
            sayilarListesi.ekleSayi(yeniSayi);
        }
        dosya.close();

    } else {
        cerr << "Dosya acilamadi!" << endl;
    }

    while (true) {
        sayilarListesi.yazdirDugumDegerleri();
        cout << "1) Tek Basamaklari Basa Al" << endl;
        cout << "2) Basamaklari Tersle" << endl;
        cout << "3) En Buyuk Cikar" << endl;
        cout << "4) Cikis" << endl;
        int secim;
        cout << "Seciminiz: ";
        
        // Kullanıcıdan alınan değer sayısal değilse veya istenilen aralıkta değilse, uyarı ver
        while (!(cin >> secim) || secim < 1 || secim > 4) {
            cout << "Yanlis bir sayi ya da karakter girdiniz. Tekrar islem giriniz!" << endl;

            // Hatalı girişi temizle
            cin.clear();

            // buffer'ı temizle
            while (cin.get() != '\n');
            cout << "Seciminiz: ";
        }

        switch (secim) {
            case 1:
                sayilarListesi.teklerBasa();
                break;
            case 2:
                sayilarListesi.basamakTersle();
                break;
            case 3:
                sayilarListesi.enBuyukCikar();
                break;
            case 4:
                return 0;
            default:
                cout << "Yanlis bir sayi ya da karakter girdiniz. Tekrar islem giriniz!" << endl;
                break;
        }
    }

    return 0;
}
