#include <iostream>

using namespace std;
void Looping(){
    for(int a=0 ; a<10;a++){
        cout << "Index ke - " << a << " Kelas B" << endl;
    }
    
}

void Looping_2(){
    for(int x= 100; x>=0; x--){
        cout << "Index ke- " << x << " Kelas B" << endl;
    }
}

void Looping_3(){
    for (int a=0; a<10; a++){
        if(a>5){
            cout <<"Data yang lebih dari 5 = " << a << " " << endl;
        }
    }
}
void Looping_4(){
    int a=10;
    while (a>0){
        cout << "Data ke: " << a << endl;
        a--;
    }
}
void Looping_5(){
    int a=0;
    do {
        cout << "Data ke : " << a << endl;
        a++;
    }
    while(a<10);
}
void Looping_6(){
    int a=5;
    int jumlah = 0;
    do{
        jumlah = jumlah +a;
        cout << a << endl;
        a++;
    }
    while(a<10);
    cout << "Jumlah sampai 10 = " << jumlah << endl;
}
void bil_prima(){

    for(int a=1;a<20;a++){
	int bil=0;
	for(int b=1;b<=a;b++){
		if(a%b==0){
			bil++;
		}
	}
	if (bil==2)
	cout<<a<<" ";
	}
}

int main()
{
    //Looping();
    //Looping_2();
    //Looping_3();
    //Looping_4();
    //Looping_5();
    //Looping_6();
    bil_prima();
    return 0;
}
