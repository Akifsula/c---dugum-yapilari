/**
* @file SayilarListesi.cpp
* @description SayilarListesi sınıfındaki tüm  fonksiyonların işlevlerini yazdım ve çıktıdaki düğüm değerlerinin görüntüsü için uğraştım. 
* @course Birinci Öğretim B grubu
* @assignment 1. Ödev
* @date 17.11.2023 - 22.11.2023
* @author Akif Emre Sula akif.sula@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>
using namespace std;

SayilarListesi::SayilarListesi()
{
    this->dugumBasi = nullptr;
}

SayilarListesi::~SayilarListesi() // düğüm nesnelerini ve içerdikleri basamakları temizledim
{
    
    Dugum *geciciDugum = dugumBasi;
    while (geciciDugum != nullptr)
    {
        Dugum *silDugum = geciciDugum;
        geciciDugum = geciciDugum->sonraki;

        Basamak *geciciBasamak = silDugum->sayi;
        while (geciciBasamak != nullptr)
        {
            Basamak *silBasamak = geciciBasamak;
            geciciBasamak = geciciBasamak->sonraki;
            delete silBasamak;
        }
        delete silDugum;
    }
}

void SayilarListesi::ekleSayi(Sayi *sayi) // liste basina sayi ekledim
{
    
    Basamak *ilk = sayi->basamakBasi;
    Dugum *yeniDugum = new Dugum(ilk);
    if (dugumBasi == nullptr)
    {
        dugumBasi = yeniDugum;
    }
    else
    {
        Dugum *gecici = dugumBasi;
        while (gecici->sonraki != nullptr)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
    yeniDugum = yeniDugum->sonraki;
}

void SayilarListesi::tersCevir() // okunan sayıları yazdırmak icin ters cevirdim.
{
    Dugum *onceki = nullptr;
    Dugum *suanki = this->dugumBasi;
    Dugum *sonra;

    while (suanki != nullptr)
    {
        sonra = suanki->sonraki;
        suanki->sonraki = onceki;
        onceki = suanki;
        suanki = sonra;
    }

    this->dugumBasi = onceki;
}

void SayilarListesi::yazdirDugumDegerleri() // düğümleri ve adresleri alt alta ekrana yazdırdım.
{
    Dugum *suankiDugum = this->dugumBasi;
    while (suankiDugum != nullptr)
    {
        Basamak *suankiSayi = suankiDugum->sayi;

        cout << "#############";    
        while (suankiSayi != nullptr)
        {
            cout << "   ******* ";
            suankiSayi = suankiSayi->sonraki;
        }
        cout << endl;

        cout << "#" << setw(8) << suankiDugum << setw(4)<<"   #   "; // adres
        suankiSayi = suankiDugum->sayi;
        while (suankiSayi != nullptr)
        {
            cout<< "* " << adresiUcle(suankiSayi) <<" *    ";   
            suankiSayi = suankiSayi->sonraki;
        }
        cout << endl;

        cout << "#-----------#";
        suankiSayi = suankiDugum->sayi;
        while (suankiSayi != nullptr)
        {
            cout  <<setw(6)<< "   ******* ";
            suankiSayi = suankiSayi->sonraki;
        }
        cout << endl;

        cout << "#";
        suankiSayi = suankiDugum->sayi;
        int sayac = 0;
        while (suankiSayi != nullptr)
        {   
            cout << suankiSayi->deger ;  //deger
            sayac++;

            suankiSayi = suankiSayi->sonraki;
            if(suankiSayi == nullptr){
                cout  << setw(15-sayac) << "#   " ; 

            }
        }
        suankiSayi = suankiDugum->sayi;
        while (suankiSayi != nullptr)
        {
            cout << "* " << setw(3) << suankiSayi->deger  << " *    ";
            suankiSayi = suankiSayi->sonraki;
        }
        cout<< endl;  

        cout << "#############"
             ;
        suankiSayi = suankiDugum->sayi;
        while (suankiSayi != nullptr)
        {
            cout << "   ******* ";
            suankiSayi = suankiSayi->sonraki;
        }
        cout << endl<<endl;

        suankiDugum = suankiDugum->sonraki;
    }
    cout << endl;
}
string SayilarListesi::adresiUcle(Basamak *adres) // sayının adresinin son üc basamagını string şeklinde aldım.
{
    string strAdres;
    stringstream ss;
    ss << adres;
    strAdres = ss.str().substr(ss.str().length() - 3, 3);

    return strAdres;
}
void SayilarListesi::teklerBasa() // tek sayı iceren düğümleri başa aldım.
{
    // Mevcut düğümü işaret ettirdim
    Dugum *suankiDugum = this->dugumBasi;

    
    while (suankiDugum != nullptr)
    {
        // Mevcut sayıdaki rakamları işaret ettirdim
        Basamak *suankiSayi = suankiDugum->sayi;

        // Tek ve çift rakamların listelerini oluşturturdum
        Basamak *tekRakamlarBas = nullptr;  // Tek rakamların başı
        Basamak *ciftRakamlarBas = nullptr; // Çift rakamların başı
        Basamak *tekRakamlarSon = nullptr;  // Tek rakamların sonu
        Basamak *ciftRakamlarSon = nullptr; // Çift rakamların sonu

        
        while (suankiSayi != nullptr)
        {
            Basamak *sonraki = suankiSayi->sonraki;

            // Rakamın tek olup olmadığını kontrol ettirdim
            if (suankiSayi->deger % 2 == 1)
            {
                if (tekRakamlarBas == nullptr)
                {
                    tekRakamlarBas = suankiSayi;
                    tekRakamlarSon = suankiSayi;
                }
                else
                {
                    tekRakamlarSon->sonraki = suankiSayi;
                    tekRakamlarSon = suankiSayi;
                }
            }
            else
            {
                if (ciftRakamlarBas == nullptr)
                {
                    ciftRakamlarBas = suankiSayi;
                    ciftRakamlarSon = suankiSayi;
                }
                else
                {
                    ciftRakamlarSon->sonraki = suankiSayi;
                    ciftRakamlarSon = suankiSayi;
                }
            }

            suankiSayi->sonraki = nullptr; 
            suankiSayi = sonraki;
        }

        // Tek rakamlar listesini çift rakamlar listesine bağlattırdım
        if (tekRakamlarBas != nullptr)
        {
            tekRakamlarSon->sonraki = ciftRakamlarBas;
            suankiDugum->sayi = tekRakamlarBas;
        }
        else
        {
            suankiDugum->sayi = ciftRakamlarBas;
        }
        suankiDugum = suankiDugum->sonraki;
    }
}
void SayilarListesi::basamakTersle() // basamakları tersten yazıp sayı düğümlerini ters cevirmis oldum.
{
    Dugum *suankiDugum = this->dugumBasi;

    while (suankiDugum != nullptr)
    {
        Basamak *onceki = nullptr;
        Basamak *suankiBasamak = suankiDugum->sayi;

        while (suankiBasamak != nullptr)
        {
            Basamak *sonra = suankiBasamak->sonraki;
            suankiBasamak->sonraki = onceki;
            onceki = suankiBasamak;
            suankiBasamak = sonra;
        }

        suankiDugum->sayi = onceki;

        suankiDugum = suankiDugum->sonraki;
    }
}
void SayilarListesi::enBuyukCikar() //  her cagırıldıgında en buyuk dugumu silen fonksiyonu olusturdum
{
    Dugum *suankiDugum = this->dugumBasi;
    Dugum *enBuyukDugum = nullptr;
    int enBuyukSayi = INT_MIN;  // En küçük değerle başlattım

    while (suankiDugum != nullptr)
    {
        int sayiDegeri = 0;
        Basamak *suankiBasamak = suankiDugum->sayi;
        
        while (suankiBasamak != nullptr)
        {
            sayiDegeri = sayiDegeri * 10 + suankiBasamak->deger;
            suankiBasamak = suankiBasamak->sonraki;
        }

        // En büyük sayıyı ve düğümü buldurdum
        if (sayiDegeri > enBuyukSayi)
        {
            enBuyukSayi = sayiDegeri;
            enBuyukDugum = suankiDugum;
        }

        suankiDugum = suankiDugum->sonraki;
    }

    if (enBuyukDugum != nullptr)
    {
        Dugum *gecis = this->dugumBasi;
        Dugum *onceki = nullptr;

        // En büyük düğümü listeden çıkarttım
        while (gecis != enBuyukDugum)
        {
            onceki = gecis;
            gecis = gecis->sonraki;
        }

        if (onceki != nullptr)
        {
            onceki->sonraki = enBuyukDugum->sonraki;
        }
        else
        {
            this->dugumBasi = enBuyukDugum->sonraki;
        }

        // Düğüm içindeki basamakları sildirdim
        Basamak *suankiBasamak = enBuyukDugum->sayi;
        while (suankiBasamak != nullptr)
        {
            Basamak *sil = suankiBasamak;
            suankiBasamak = suankiBasamak->sonraki;
            delete sil;
        }
        delete enBuyukDugum;
    }
}