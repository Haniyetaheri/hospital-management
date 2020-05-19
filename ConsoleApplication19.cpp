// Hospital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "conio.h"

using namespace std;
 
int count_B=0;
int count_D=0;


class  person
{
public:
	person(){}
	person(string name,string family,string address,string phone,int age){
	
	   this->name=name;
	   this->family=family;
	   this->address=address;
	   this->phone=phone;
	   this->age=age;
	}

	void setname(string name){ this->name=name; }
	void setfamily(string family){ this->family=family; }
	void setaddress(string address){ this->address=address; }
	void setphone(string phone){ this->phone=phone; }
	void setage(int age){ this->age=age; }

	string getname()const{ return name; }
	string getfamily()const{ return family; }
	string getaddress()const{ return address; }
	string getphone()const{ return phone; }
	int getage()const{ return age; }

	void report(){

		cout<<name<<setw(6)<<" "<<family<<setw(8)<<" "<<address<<setw(8)<<" "<<phone<<setw(8)<<" "<<age<<setw(3)<<" ";

	}


protected:

	string name,family,address,phone;
	int age;



};
class bimar :public person{

private:
	string B_code,D_code,D_name,typebimari;

	

public:
	bimar(){}
	bimar(string name,string family,string address,string phone,int age,string B_code,string D_code,string D_name,string typebimari):person( name, family, address, phone, age){
	
	   this->D_code=D_code;
	   this->B_code=B_code;
	   this->D_name=D_name;
	   this->typebimari=typebimari;
	
	}

	void setB_code(string B_code){ this->B_code=B_code; }
	void setD_code(string D_code){ this->D_code=D_code; }
	void setD_name(string D_name){ this->D_name=D_name; }
	void settypebimari(string typebimari){ this->typebimari=typebimari; }
	
	string getB_code()const{ return B_code; }
	string getD_code()const{ return D_code; }
	string getD_name()const{ return D_name; }
	string gettypebimari()const{ return typebimari; }
	 


	void report(){

		cout<<name<<setw(6)<<" "<<family<<setw(10)<<" "<<address<<setw(8)<<" "<<phone<<setw(8)<<" "<<age<<setw(3)<<" "<<D_code<<setw(3)<<" "<<D_name<<setw(6)<<" "<<B_code<<setw(3)<<" "<<typebimari<<setw(5)<<endl;

	}
};
class docter :public person{

private:
	string Do_code,typespecial;

public:
	docter(){}
	docter(string name,string family,string address,string phone,int age,string Do_code,string typespecial):person( name, family, address, phone, age){
	
	   this->Do_code=Do_code;
	   this->typespecial=typespecial;
	
	}

	void setDo_code(string Do_code){ this->Do_code=Do_code; }
	void settypespecial(string typespecial){ this->typespecial=typespecial; }
	
	string gettypespecial()const{ return typespecial; }
	string getDo_code()const{ return Do_code; }
	
	void report(){

		cout<<name<<setw(6)<<" "<<family<<setw(8)<<" "<<address<<setw(8)<<" "<<phone<<setw(8)<<" "<<age<<setw(3)<<" "<<Do_code<<setw(3)<<" "<<typespecial<<setw(5)<<endl;

	}



};

//bimaran...............................

vector<bimar>list_B,list_B2;
fstream outputfile_B;

void write_B()
{
  string B_code,D_code,D_name,typebimari;
  string name,family,address,phone;
  int age;

  cout<<" \n   enter name of bimar  : ";
  cin>>name;
  cout<<"\n    enter family of bimar  : ";
  cin>>family;
  cout<<"  \n  enter address of bimar  : ";
  cin>>address;
  cout<<" \n   enter phone of bimar  : ";
  cin>>phone;
  cout<<" \n   enter age of bimar  : ";
  cin>>age;
  cout<<" \n   enter code of bimar  : ";
  cin>>B_code;
  cout<<"\n    enter code of doctor  : ";
  cin>>D_code;
  cout<<"\n    enter name of doctor  : ";
  cin>>D_name;
  cout<<" \n   enter type of bimari  : ";
  cin>>typebimari;
  
  list_B.push_back(bimar(name,family,address,phone,age,B_code,D_code,D_name,typebimari));
  outputfile_B.open("bimaran.csv",ios::app);
  outputfile_B<<name + "," +  family + "," + address + "," + phone + "," + to_string(age) + "," + B_code + "," + D_code + "," + D_name + "," + typebimari<<endl;
  count_B++;









}
void displayall_B()
{
	
    cout<<"\n\n\n                       All bamara                          \n\n";
	cout<<"------------------------------------------------------------------\n";
	cout<<"\nname  family   address   phone  age   B_code   D_code   D_name   typebimari\n";
	for (int i = 0; i<list_B.size() ; i++)
	{
		list_B[i].report();
	}
	cout<<"\nnumber of bimaran : "<<count_B<<"\n";
}
void displayone_B(string Code)
{
	system("cls");
    cout<<"\n\n\n            bamara                                      \n\n";
	cout<<"-------------------------------------------------------------\n ";
	cout<<"\nname  family   address    phone  age   B_code   D_code   D_name  typebimari\n";
	for (int i = 0; i<list_B.size() ; i++)
	{
		if (list_B[i].getB_code()==Code)
		{
               list_B[i].report();
		}
		
	}

}
void modifile_B(string Code)
{
	string D_code,D_name,typebimari;
	int a;
	for (int i = 0; i<list_B.size(); i++)
	{
		if (list_B[i].getB_code()==Code)
		{
               cout<<"    select menue      \n  ";
			   cout<<"    1: D_code         \n  ";
			   cout<<"    2: D_name         \n  ";
			   cout<<"    3: typebimari     \n  ";
			   cin>>a;
			   switch (a)
			   {
			   case 1: cout<<"\n    enter code of doctor  : "; cin>>D_code; list_B[i].setD_code(D_code);break;
               case 2: cout<<"\n    enter name of doctor  : "; cin>>D_name; list_B[i].setD_name(D_name);break;
			   case 3: cout<<"\n   enter type of bimari  : "; cin>>typebimari; list_B[i].settypebimari(typebimari); break;
			   default:
				   break;
			   }

		}
		
	}







}
void deleteall_B()
{ 
	list_B.clear();
}
void deleteone_B(string Code)
{
	
	for (int i = 0; i<list_B.size(); i++)
	{
		if (list_B[i].getB_code()!=Code)
		{
			list_B2.push_back(list_B[i]);
		}
		
	}
	list_B=list_B2;
	vector<bimar>().swap(list_B2);

}

//doctor................................

vector<docter>list_D,list_D2;
fstream outputfile_D;

void write_D()
{
  string Do_code,typespecial;
  string name,family,address,phone;
  int age;

  cout<<" \n  enter name of Doctor  : ";
  cin>>name;
  cout<<"\n   enter family of Doctor  : ";
  cin>>family;
  cout<<"\n   enter address of Doctor  : ";
  cin>>address;
  cout<<"\n   enter phone of Doctor  : ";
  cin>>phone;
  cout<<"\n   enter age of Doctor  : ";
  cin>>age;
  cout<<"\n   enter code of Doctor  : ";
  cin>>Do_code;
  cout<<"\n   enter typespecial  : ";
  cin>>typespecial;
  
  list_D.push_back(docter(name,family,address,phone,age,Do_code,typespecial));
  outputfile_D.open("Docters.csv",ios::app);
  outputfile_D<<name + "," +  family + "," + address + "," + phone + "," + to_string(age) + "," + Do_code + "," + typespecial<<endl;
  count_D++;

}
void displayall_D()
{
	system("cls");
    cout<<"\n\n\n           All doctor            \n\n";
	cout<<"---------------------------------------------------\n" ;
	cout<<"\nname   family   address   phone   age   Docter_code   typespecial\n";
	for (int i = 0; i<list_D.size(); i++)
	{
		list_D[i].report();
	}
	cout<<"\n number of doctors : "<<count_D;
}
void displayone_D(string Code)
{
	system("cls");
    cout<<"\n\n\n           doctor           \n\n";
	cout<<"-------------------------------------------------\n";
	cout<<"\nname   family  address    phone   age    Docter_code   typespecial\n";
	for (int i = 0; i <list_D.size(); i++)
	{
		if (list_D[i].getDo_code()==Code)
		{
               list_D[i].report();
		}
		
	}

}
void modifile_D(string Code)
{
	string Do_code,typespecial;
	int a;
	for (int i = 0; i <list_D.size(); i++)
	{
		if (list_D[i].getDo_code()==Code)
		{
               cout<<"    select menue D     \n  ";
			   cout<<"    1: Do_code         \n  ";
			   cout<<"    2: typespecial     \n  ";
			   cin>>a;
			   switch (a)
			   {
			   case 1: cout<<"\n    enter code of doctor  : "; cin>>Do_code; list_D[i].setDo_code(Do_code);break;
			   case 2: cout<<" \n   enter type of bimari  : "; cin>>typespecial; list_D[i].settypespecial(typespecial); break;
			   default:
				   break;
			   }

		}
		
	}

}
void deleteall_D()
{ 
	list_D.clear();
}
void deleteone_D(string Code)
{
	
	for (int i = 0; i <list_D.size(); i++)
	{
		if (list_D[i].getDo_code()!=Code)
		{
			list_D2.push_back(list_D[i]);
		}
		
	}
	list_D=list_D2;
	vector<docter>().swap(list_D2);

}
void show()
{
   string code;
   cout<<"\n   enter code of doctor   \n";
   cin>>code;
   cout<<"          bimar                     typebimari     \n";  
	for (int i = 0; i < count_B; i++)
	{
		if (list_B[i].getD_code()==code)
		{
			cout<<list_B[i].getname()<<"   "<<list_B[i].getfamily()<<"   "<<list_B[i].gettypebimari()<<endl;

		}
	}

}

//----------------menue-----------------

void D_menue(){

	int a;
	char Ch;
	string Code;
	do
	{	
	system("cls");

	cout<<"\n-------------------------Doctors Menue----------------------\n";
	cout<<"      1 : enter a new  Doctor                                  \n";
	cout<<"      2 : displayall  Doctors                                  \n";
	cout<<"      3 : displayone  Doctor                                   \n";
	cout<<"      4 : modifile  Doctor                                     \n";
	cout<<"      5 : deleteall  Doctors                                   \n";
	cout<<"      6 : deleteone  Doctor                                    \n";
	cout<<"      7 : show the sicks of Doctor                             \n";
	cout<<"      8 : go to sicks  Menue                                   \n";
	cin>>a;
	 switch (a){			   
	 case 1: 
		 do{			 
                 write_D(); 
				 system("cls");
				 cout<<"\n do you want to insert new doctor ? Y|N";
				 cin>>Ch;

			 } while (Ch=='Y'||Ch=='y');
		 break;
     case 2: displayall_D(); 
		 _getch();
		 break;
	 case 3: cout<<" \n   enter code of doctor  : "; cin>>Code; displayone_D(Code); _getch();
		 break;
     case 4: cout<<" \n   enter code of doctor  : "; cin>>Code; modifile_D(Code); 
		 break;
     case 5: deleteall_D(); 
		 break;
	 case 6: cout<<" \n   enter code of doctor  : "; cin>>Code; deleteone_D(Code); 
		 break;
     case 7: show(); _getch();
		 break; 
     case 8: 
		 break;  
			   default:
				   break;
			   }

	 system("cls");
	 cout<<"\n do you want to countinu ? Y|N";
	 cin>>Ch;

   } while (Ch=='Y'||Ch=='y');


}
void B_menue(){
	char Ch;
	int a;
	string Code;
	do
	{

	
	system("cls");

	cout<<"\n-------------------------sicks Menue------------------------\n";
	cout<<"      1 : enter a new  sick                                    \n";
	cout<<"      2 : displayall  sicks                                    \n";
	cout<<"      3 : displayone  sick                                     \n";
	cout<<"      4 : modifile  sick                                       \n";
	cout<<"      5 : deleteall  sicks                                     \n";
	cout<<"      6 : deleteone  sick                                      \n";
	cout<<"      7 : go to doctor menu                                    \n";
	cin>>a;

	 switch (a)
			   {
			   case 1:
				   do{
				           write_B();
						   system("cls");
				           cout<<"\n do you want to insert new Sick ? Y|N";
				           cin>>Ch;
				  } while (Ch=='Y'||Ch=='y');
				 break;
               case 2: displayall_B();_getch(); break;
			   case 3: cout<<" \n   enter code of sick  : "; cin>>Code; displayone_B(Code);_getch(); break;
               case 4: cout<<" \n   enter code of sick  : "; cin>>Code; modifile_B(Code); break;
               case 5: deleteall_B(); break;
			   case 6: cout<<" \n   enter code of sick  : "; cin>>Code; deleteone_B(Code); break;
               case 7: D_menue(); break;  
			   default:
				   break;
			   }
	 system("cls");
	 cout<<"\n do you want countinu ? Y|N";
	 cin>>Ch;

    }  while (Ch=='Y'||Ch=='y');
}
void F_menue(){
	int a;
	system("cls");
    cout<<"\n\n\n                                 first Menu                     \n\n";
	cout<<" ---------------------------------------------------------------------\n";
	cout<<"       1 : Doctor_menue      \n";
	cout<<"       2 : Sicks_menue       \n";
	cin>>a;
	 switch (a)
			   {
				   case 1: D_menue(); break;
                   case 2: B_menue(); break;
	           }

}

int _tmain(int argc, _TCHAR* argv[])
{
	F_menue();


	_getch();
	return 0;
}

