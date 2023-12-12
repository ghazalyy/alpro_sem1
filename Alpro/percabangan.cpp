#include <iostream>
using namespace std;
void percabangan_1(){
	int nilai;
	cout <<"Masukan nilai :";
	cin>>nilai;
	
	if (nilai >= 90) cout << "Nilai angka : A"<<endl;
	else if (nilai < 90) cout << "Nilai angka : B"<<endl;
	else cout << "Maaf anda tidak lulus"<<endl;
} 

void percabangan_2(){
	int nilai;
	
	cout << "Masukan nilai : "; cin>>nilai;
	
	if (nilai%2==0){
		cout<<"Nilai "<< nilai << " adalah nilai genap"<<endl;
	}else{
		cout<<"Nilai "<< nilai << " adalah nilai ganjil"<<endl;
	}
}

void percabangan_3(){
	int gol;
	
	cout << "Masukan gol : "; cin>>gol;
	
	switch (gol){
		case 1: cout<<"Gaji = 100";
		break;
		
		case 2: cout<<"Gaji = 200";
		break;
		
		case 3: cout<<"Gaji = 300";
		break;
		
		default : cout<<"Golongan sakah";
		break;
	}
} 

void percabangan_4(){
	int a,b,c,max;
	
	cout<<"Masukan 3 buah bilangan: "; cin>> a >> b >> c;
	
	if (a >b)
	if (a>c) max = a;
	else max = c;
	else if (b > c) max = b;
	else max=c;
	
	cout<<"Maksimum bilangan adalah: "<<max<<endl;
}

void percabangan_5(){
	int a,b,c,min;
	
	cout<<"Masukan 3 buah bilangan: "; cin>> a >> b >> c;
	
	if (a<b)
	if (a<c) min = a;
	else min = c;
	else if (b < c) min = b;
	else min=c;
	
	cout<<"Minimumm bilangan adalah: "<<min<<endl;
}

void percabangan_6(){
	int a,b,c;
	
	cout<<"Masukan 3 buah bilangan: "; cin>> a >> b >> c;
	
	cout<<"Nilai tertinggi adalah: ";
	if(a>=b && a>=c) cout<<a<<endl;
	if(b>=a && b>=c) cout<<b<<endl;
	if(c>=b && c>=a) cout<<c<<endl;
}

void percabangan_7(){ //pake char petik satu
	char jawab;
	cout<<"Yakin (y/t): "; cin>>jawab;
	
	if (jawab=='y' || jawab=='Y'){
		cout<<"OK, anda yakin"<<endl;
	} else{
		cout<<"Maaf, anda tidak yakin"<<endl;
	}
}

void percabangan_8(){ //pake string petik dua
	string jawab;
	cout<<"Yakin (y/t): "; cin>>jawab;
	
	if (jawab=="y" || jawab=="Y"){
		cout<<"OK, anda yakin"<<endl;
	} else{
		cout<<"Maaf, anda tidak yakin"<<endl;
	}
}

void percabangan_9(){
	char status;
	int grade;
	
	cout<<"Masukan Grade: "; cin>>grade;
	status = (grade>= 60)? 'L' : 'G';
	cout<<status<<endl;
	
}

void percabangan_10(){
	string status;
	int grade;
	
	cout<<"Masukan Grade: "; cin>>grade;
	status = (grade>= 60)? "Lulus" : "Gagal";
	cout<<status<<endl;
}

void percabangan_11(){
	int n = 26, m=32;
	int min = m < n ? m:n;
	cout<<"Bilangan terkecil adalah "<<min<<endl;
}

void percabangan_12(){
	int n = 100, m=20;
	int max = m > n ? m:n;
	cout<<"Bilangan terbesar adalah "<<max<<endl;
}

void percabangan_13(){
	string NIM, nama, grade, lastdigit;
	int uts, uas, tugas, min, avg, nima, total_nilai;
	
	cout<<"NIM: "; cin>>NIM;
	cout<<"Nama: "; cin>>nama;
	cout<<"Nilai uts: "; cin>>uts;
	cout<<"Nilai uas: "; cin>>uas;
	cout<<"Nilai tugas: "; cin>>tugas;
	
	nima = NIM[NIM.size() -1] -'0';
	if (nima%2==0){
		lastdigit="Genap";
	} else{
		lastdigit="Ganjil";
	}
	cout<<"NIM: "<<NIM<<" "<<lastdigit<<endl;
	
	cout<<"\nNama: "<<nama<<endl;
	
	if (uts<uas)
	if (uts<tugas) min = uts;
	else min = tugas;
	else if (uas < tugas) min = uas;
	else min=tugas;
	
	cout<<"Nilai Minimum adalah: "<<min<<endl;
	
	total_nilai = uts+uas+tugas;
	avg=total_nilai/3;
	cout<<"Rata-rata nilai: "<<avg<<endl;
	
	if(avg>=90){
		grade="A";
	} 
	else if(avg>=80 && avg < 90){
		grade="A-";
	}
	else if(avg>=75 && avg < 80 ){
		grade="B+";
	}
	else if(avg>=70 && avg < 75){
		grade="B";
	}
	else if(avg>=65 && avg < 70){
		grade="B-";
	}
	else if(avg>=60 && avg < 65){
		grade="C";
	}
	else if(avg>=55 && avg < 60){
		grade="D";
	} else{
		grade="E";
	}
	cout<<"Nilai: "<<grade<<endl;
	
}

int main(){
	//percabangan_1();
	//percabangan_2();
	//percabangan_3();
	//percabangan_4();
	//percabangan_5();
	//percabangan_6();
	//percabangan_7();
	//percabangan_8();
	//percabangan_9();
	//percabangan_10();
	//percabangan_11();
	//percabangan_12();
	percabangan_13();
	return 0;
}


