all: derleme baglama calistirma
derleme: 
	g++ -c -I "./include" ./src/Basamak.cpp -o ./lib/Basamak.o  
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o  
	g++ -c -I "./include" ./src/Sayi.cpp -o ./lib/Sayi.o  
	g++ -c -I "./include" ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o  
	g++ -c -I "./include" ./src/Test.cpp -o ./lib/Test.o 

baglama:
	g++ ./lib/Basamak.o ./lib/Dugum.o ./lib/Sayi.o ./lib/SayilarListesi.o ./lib/Test.o -o ./bin/Test

calistirma:
	./bin/Test   
