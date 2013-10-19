#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

fstream file; //tutaj przechowujemy WAV

string ReadCharValue(int bytes){ //funkcja czytaj¹ca znaki z pliku WAV
	string RetValue="";

	for(int i=0;i<bytes;i++)
		RetValue+=file.get();

	return RetValue;
}

string dec2bin(int val){
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

long long bin2dec(string A){
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

long long ReadIntValue(int bytes){ //funkcja czytajaca z pliku WAV wartosci calkowite
	vector<int> BYTES;

	for(int i=0;i<bytes;i++)
		BYTES.push_back(file.get());

	string WYN;

	for(int i=BYTES.size()-1;i>=0;i--)
		WYN+=dec2bin(BYTES[i]);

	return bin2dec(WYN);
}


int main(){
	file.open("test2.wav", std::ios::in | std::ios::out );

	long long size,bits;

	cout<<ReadCharValue(4)<<endl; //wczytwanie slowa "RIFF"
	cout<<ReadIntValue(4)<<endl; //wczytanie rozmiaru pliku
	cout<<ReadCharValue(4)<<endl; //wczytanie slowa "WAVE"
	cout<<ReadCharValue(4)<<endl; //wczytanie slowa "fmt "
	bits=ReadIntValue(4); //ilosc bitow
	cout<<ReadIntValue(2)<<endl; //sposob przechowywania; z kompresja czy bez (nie mam pojecia, o co z tym chodzi)
	cout<<ReadIntValue(2)<<endl; //kanaly; 1->mono, 2->stereo
	cout<<ReadIntValue(4)<<endl; //sample rate
	cout<<ReadIntValue(4)<<endl; //avg_bytes_sec
	cout<<ReadIntValue(2)<<endl; //block_align
	cout<<ReadIntValue(2)<<endl; //bits_per_sample
	cout<<ReadCharValue(4)<<endl; //slowo "data"
	size=ReadIntValue(4); //ile bitow dzwieku mamy

	for(int i=0;i<size/bits;i++){
		cout<<ReadIntValue(bits/8)<<endl;
		getchar();
	}
	system("pause");
}
