#include<iostream>
#include<cmath>
#define PI 3.14159 // Na ovoj nacin se definira konstantata PI
using namespace std;

class Krug{
	float r;
	public:
		Krug()
		{
			cout<<"Vnesete go radiusot na krugot"<<endl;
			cin>>r;
		}
		
		friend float Plostina(Krug k); // Prototip na Prijatelska funkcija Plostina na klasata Krug
		friend class Cilindar; // Prijatelska klasa Cilindar na klasata Krug
		//i dvete se prototipuvaat vo prvicnata klasa
};

float Plostina(Krug k)
{
	return pow(k.r,2)*PI; //Funkcija za presmetuvanje na plostina na krug ... do r moze da se pristapi, iako e private i toa preku objekt
	//od prvicnata klasa zatoa sto klasite se prijatelski
}

class Cilindar{
	float h;
	public:
		Cilindar(){
			cout<<"Vnesete ja visinata na cilindarot"<<endl;
			cin>>h;
		}
		
		float Volumen(Krug k)
		{
			return Plostina(k)*h; //Volumen na cilindar se presmetuva kako proizvod od povrsina na osnovata i visinata
		}
		
		float VratiRadius(Krug k){
			return k.r;
		}
		
		float VratiVisina()
		{
			return h;
		}
};

//ZABELESKA: Site funkcii od klasata Cilindar koi za da vratat nekoja vrednost, imaat potreba od nekoj clen od klasata krug,
//MORA vo delot na argumenti da go imaat imeto na klasata i objekt na klasata ... na pr.//
/*
float VratiRadius(Krug k){
			return k.r; 
			
		}
			bidejki r se naogja vo klasata Krug, mora vo delot na argumenti (vo malite zagradi)
			da stoi imeto na Klasata "Krug" i objekt od klasata "k" ... iako f-jata VratiRadius () ne e naznacena kako prijatelska vo Krug,
			bidejki se naogja vo prijatelska klasa i ima potreba od pristap do prvicnata klasa ... mora vo delot na argumenti
			da stoi imeto na klasata i objekt od klasata (Krug k).
			So drugi zborovi se definira isto kako i prijatelskata funkcija, samo sto se povikuva preku objekt od klasa.ime_funkcija
			


		

*/

int main()
{
	Krug k;
	Cilindar c;
	
	cout<<"Plostinata na krugot iznesuva "<<Plostina(k)<<endl; //Funkcijata prijatel se povikuva samo so nejzinoto ime, a ne preku objekt
	//kako argument prima objekt od klasata Krug, zatoa sto f-jata e prijatel na istata klasa
	
	cout<<"Volumenot na cilindarot so radius na osnovata "<<c.VratiRadius(k)<<" i visina "
	//Funkcijata sto se naogja vo klasata prijatel se povikuva na sledniot nacin: objekt od klasata prijatel, tocka, ime na funkcija i kako argument e objekt od prijatelskata klasa
	<<c.VratiVisina()<<" iznesuva "<<c.Volumen(k)<<endl;
	
	return 0;
	
}
