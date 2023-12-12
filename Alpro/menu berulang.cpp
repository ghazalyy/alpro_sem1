#include<iostream>
using namespace std;

int main(){
	int pilihan;
	cout<<"1. Menu menampilkan deret bilangan prima"<<endl;
	cout<<"2. Menu menampilkan faktorial"<<endl;
	cout<<"3. Menu menampilkan luas persegi panjang"<<endl;
	cout<<"4. Menu menampilkan luas segitiga"<<endl;
	cout<<"5. Nested looping bintang kecil ke besar"<<endl;
	cout<<"6. Nested looping bintang besar ke kecil"<<endl;
	cout<<"7. Mengecek bilangan prima"<<endl;
	cout<<"8. EXIT"<<endl;
	
do{
	cout<<"Silahkan pilih menu: "; cin>>pilihan;
	
	if(pilihan==1){
		int nilai;
		cout<<"Menu bilangan prima"<<endl;
		cout<<"Masukan nilai n: ";cin>>nilai;
		
	for(int a=1;a<nilai;a++){
		int bil=0;
		for(int b=1;b<=a;b++){
			if(a%b==0){
				bil++;
			}
		}
		if (bil==2)
		cout<<a<<" ";
	}
	cout<<endl;
	}
	
	else if(pilihan==2){
		double angka, hasil,i;
		cout<<"Menu faktorial"<<endl;
		cout<<"Masukan nilai n: ";cin>>angka;

  		hasil = 1;
  		for(i=1;i<=angka;i++) {
    		hasil = hasil * i;
  		}
  		cout << angka << "! = " << hasil<<endl;
	}
	
	else if(pilihan==3){
		int l, p, luas; 
		cout<<"Menu luas persegi panjang"<<endl;
		cout<<"Masukan nilai panjang: ";cin>>p;
		cout<<"Masukan nilai lebas: ";cin>>l;
		luas=p*l;
		cout << "luas persegi panjang = "<<luas<<endl;
	}
	
	else if(pilihan==4){
		float a, t, luas;
		cout<<"Menu luas segitiga"<<endl;
		cout << "Masukan alas segitiga: ";cin >> a;
  		cout << "Masukan tinggi segitiga: ";cin >> t;
  		cout << endl;
 
  		luas = 0.5 * a * t;
 
  		cout << "Luas segitiga = "<< luas << endl;
	}
	
	else if(pilihan==5){
		int jumlah;
		cout<<"Menu Nested looping bintang kecil ke besar"<<endl;
  		printf("Input tinggi segitiga: ");
  		scanf("%i",&jumlah);
  		printf("\n");
 
  		for (int i = 1; i <= jumlah; i++) {
    		for (int j = 1; j <= i; j++) {
      			printf("* ");
    		}
    		printf("\n");
  		}
  		cout<<endl;
	}
	
	else if(pilihan==6){
		int  i, j, n;
		cout<<"Menu Nested looping bintang besar ke kecil"<<endl;
      	cout << "input tinggi segitiga:  ";cin >> n;
      	for (i = n; i >= 1; i--)
      	{
            for (j = 1; j <= i; j++)
            {
                  cout << "* ";
            }
            
            cout << "\n";
      	}
	}
	
	else if(pilihan==7){
		int n,i;
  		bool angka_prima = true;
  		cout<<"Menu Mengecek bilangan prima"<<endl;
  		cout << "Input satu angka bulat: ";cin >> n;
 
  if (n == 0 || n == 1) {
    angka_prima = false;
  }
  else {
    for (i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        angka_prima = false;
        break;
      }
    }
  }
 
  cout << endl;
  if (angka_prima)
    cout << n << " adalah angka prima"<<endl;
  else
    cout << n << " bukan angka prima"<<endl;
    cout<<endl;
	}
	
	else if(pilihan==8){
		exit(0);
	}
	
	else{
		cout<<"pilihan anda salah"<<endl;
	}
	
}
while(pilihan >= 1);
}
