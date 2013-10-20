#include "wav.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string wav::ReadCharValue(int bytes){ //funkcja czytaj�ca znaki z pliku WAV
	string RetValue="";

	for(int i=0;i<bytes;i++)
		RetValue+=file.get();

	return RetValue;
}

string wav::dec2bin(int val){
	string wyn;

	while(val>0){
		if(val%2==0)wyn+="0";
		else wyn+="1";
		val/=2;
	}

	while(wyn.size()<8)wyn+="0";
	reverse(wyn.begin(),wyn.end());

	return wyn;
}

long long wav::bin2dec(string A){
	long long d=1;
	long long wyn=0;
	for(int i=A.size()-1;i>=0;i--){
		if(A[i]=='1'){
			wyn+=d;
		}

		d*=2;
	}

	return wyn;
}

long long wav::ReadIntValue(int bytes){ //funkcja czytajaca z pliku WAV wartosci calkowite
	vector<int> BYTES;

	for(int i=0;i<bytes;i++)
		BYTES.push_back(file.get());

	string WYN;

	for(int i=BYTES.size()-1;i>=0;i--)
		WYN+=dec2bin(BYTES[i]);

	return bin2dec(WYN);
}

void wav::load(string FileName){
	file.open(FileName, std::ios::in | std::ios::out );
}

void wav::translate(){
	long long size, bits;
	ReadCharValue(4); //wczytwanie slowa "RIFF"
	ReadIntValue(4); //wczytanie rozmiaru pliku
	ReadCharValue(4); //wczytanie slowa "WAVE"
	ReadCharValue(4); //wczytanie slowa "fmt "
	bits=ReadIntValue(4); //ilosc bitow
	ReadIntValue(2); //sposob przechowywania; z kompresja czy bez (nie mam pojecia, o co z tym chodzi)
	ReadIntValue(2); //kanaly; 1->mono, 2->stereo
	ReadIntValue(4); //sample rate
	ReadIntValue(4); //avg_bytes_sec
	ReadIntValue(2); //block_align
	ReadIntValue(2); //bits_per_sample
	ReadCharValue(4); //slowo "data"
	size=ReadIntValue(4); //ile bitow dzwieku mamy

	while(!file.eof()){
		double A=ReadIntValue(bits/8);
		Trans.push_back(A);
	}
<<<<<<< HEAD
}

wav::wav(string FileName){
	load(FileName);
	translate();
}
=======
	system("pause");
}
<<<<<<< HEAD
>>>>>>> a3e9fb821e4cad84cf308543f4e22bdcb1ae6656
=======
>>>>>>> a3e9fb821e4cad84cf308543f4e22bdcb1ae6656
