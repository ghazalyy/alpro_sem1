#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int pilihan;
	
do{
	cout<<"1. Menu koordinat"<<endl;
	cout<<"2. Menu mengkalikan deret bil prima"<<endl;
	cout<<"3. Menu nilai max 4 bilangan"<<endl;
	cout<<"4. Menu suhu"<<endl;
	cout<<"5. Menu nilai diskriminan"<<endl;
	cout<<"6. Menu menghitung nilai sisi miring segitiga siku-siku"<<endl;
	cout<<"7. Menu menjumlahkan deret bil prima"<<endl;
	cout<<"8. Menghitung nilai faktorial"<<endl;
	cout<<"9. Exit"<<endl;
	cout<<"Silahkan pilih menu(1/2/3/4/5/6/7/8/9): "; cin>>pilihan;
	
	if(pilihan==1){
		double x1, y1, x2, y2, jarak;
    	double skala = 1.0; 
    	cout<<"Menu no 1"<<endl;
    
    	cout << "Masukkan koordinat x1: ";cin >> x1;
    	cout << "Masukkan koordinat y1: ";cin >> y1;
    
    	cout << "Masukkan koordinat x2: ";cin >> x2;
    	cout << "Masukkan koordinat y2: ";cin >> y2;
    
    	jarak = skala * sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    
    	cout << "Jarak antara kedua kota adalah " << jarak << " satuan." << endl;
	}
	
	else if(pilihan==2){
		int nilai, a, b;
		double sum = 1;
		cout<<"Menu bilangan prima"<<endl;
		cout<<"Masukan nilai n: ";cin>>nilai;
		
		for(a=1;a<nilai;a++){
			int bil=0;
			for(b=1;b<=a;b++){
				if(a%b==0){
					bil++;
				}
			}
			if (bil==2)
			sum *= a;
			cout<<a<<" ";
		}
		cout<<endl;
		cout<<"Hasil perkalian: "<<sum<<endl;
	}
	
	else if(pilihan==3){
		int b1, b2, b3, b4, max;
		cout<<"Menu nomor 3"<<endl;
		cout<<"Masukan Bilangan 1: ";cin>>b1;
		cout<<"Masukan Bilangan 2: ";cin>>b2;
		cout<<"Masukan Bilangan 3: ";cin>>b3;
		cout<<"Masukan Bilangan 4: ";cin>>b4;
		
		if(b1>b2 && b1>b3 && b1>b4) max = b1;
		else if(b2>b1 && b2>b3 && b2>b4) max = b2;
		else if(b3>b1 && b3>b2 && b3>b4) max = b3;
		else max = b4;
		
		cout<<"Nilai max bilangan diatas adalah: "<<max<<endl;
	}
	
	else if(pilihan==4){
		int suhu;
		cout<<"Menu pilihan 4"<<endl;
		cout<<"Masukan suhu: ";cin>>suhu;
		
		if (suhu<15){
			cout<<"Dingin"<<endl;
		}
		else if(suhu>=15 && suhu<25){
			cout<<"sejuk"<<endl;
		}
		else if(suhu>=25 && suhu<30){
			cout<<"Hangat"<<endl;
		}
		else if(suhu>=30 && suhu<35){
			cout<<"Panas"<<endl;
		}
		else if(suhu>=35 && suhu<40){
			cout<<"Sangat Panas"<<endl;
		}
		else if(suhu>40){
			cout<<"Tidak Terdefinisi"<<endl;
		}
		else{
			cout<<"Masukan yang benar"<<endl;
		}
	}
	
	else if(pilihan==5){
		double A, B, C, D;
		cout<<"Masukan Nilai A: ";cin>>A;
		cout<<"Masukan Nilai B: ";cin>>B;
		cout<<"Masukan Nilai C: ";cin>>C;
		
		D = pow(B,2) - 4 * A * C;
		
		cout<<"Nilai Diskriminan: "<<D<<endl;
		
	}
	
	else if(pilihan==6){
		double A, B, sisimiring;
		cout<<"Masukan panjang sisi A: ";cin>>A;
		cout<<"Masukan panjang sisi B: ";cin>>B;
		
		sisimiring = sqrt(pow(A,2)+pow(B,2));
		
		cout<<"Sisi Miring segitiga siku siku: "<<sisimiring<<endl;
	}
	
	else if(pilihan==7){
		int nilai, a, b;
		double sum = 1;
		cout<<"Menu bilangan prima"<<endl;
		cout<<"Masukan nilai n: ";cin>>nilai;
		
		for(a=1;a<nilai;a++){
			int bil=0;
			for(b=1;b<=a;b++){
				if(a%b==0){
					bil++;
				}
			}
			if (bil==2)
			sum += a;
			cout<<a<<" ";
		}
		cout<<endl;
		cout<<"Hasil penjumlahan: "<<sum<<endl;
	}
	
	else if(pilihan==8){
		double angka, hasil,i;
		cout<<"Menu faktorial"<<endl;
		cout<<"Masukan nilai n: ";cin>>angka;

  		hasil = 1;
  		for(i=1;i<=angka;i++) {
    		hasil = hasil * i;
  		}
  		cout << angka << "! = " << hasil<<endl;
	}
	
	else if(pilihan==9){
		exit(0);
	}
	
	else{
		cout<<"pilihan anda salah"<<endl;
	}
	
}
while(pilihan >= 1);
}
