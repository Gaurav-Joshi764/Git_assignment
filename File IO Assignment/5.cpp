#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

struct student
{
 char name[20];
 float roll;
 char course[10];
 float cgpa;
};

fstream file;
student obj;

void add()
{
 cout<<"Enter Name: ";
 cin>>obj.name;
 cout<<"Enter Roll Number: ";
 cin>>obj.roll;
 cout<<"Enter Course: ";
 cin>>obj.course;
 cout<<"Enter CGPA: ";
 cin>>obj.cgpa;

 file.open("database.txt",ios::app) ;
 file.write((char*)&obj,sizeof(obj));
 file.close();
}

void show_all()
{
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  cout<<"Name: "<<obj.name<<endl;
  cout<<"Roll Number: "<<obj.roll<<endl;
  cout<<"Course: "<<obj.course<<endl;
  cout<<"CGPA: "<<obj.cgpa<<endl<<endl;

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

void search()
{
 float user;
 cout<<"Enter Roll Number: ";
 cin>>user;
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (obj.roll==user)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Roll Number: "<<obj.roll<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"CGPA: "<<obj.cgpa<<endl<<endl;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

/*void edit()
{

 char user[15];
 cout<<"Enter registration Number: ";
 cin>>user;

 file.open("database.txt",ios::in|ios::out);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (strcmp(obj.reg,user)==0)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Registration Number: "<<obj.reg<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"CGPA: "<<obj.cgpa<<endl<<endl;

   cout<<"\nEnter New course: ";
   cin>>obj.course;

   file.seekp(file.tellg()-sizeof(obj));
   file.write((char*)&obj,sizeof(obj));
   cout<<"\n\nFile Updated";
   break;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}*/


int main()
{

 int option;

 while(1)
 {
  cout<<"Enter 1 to Enter Record\n";
  cout<<"Enter 2 to Show All Record\n";
  cout<<"Enter 3 to Search Record\n";
  cout<<"Enter 4 to Exit\n";
  cout<<"\n\nEnter Option: ";
  cin>>option;

  switch (option)
  {
   case 1:
    add();
    cout<<"\n\nRecord Entered\n";
    getch();
    break;
   case 2:
    show_all();
    break;
   case 3:
    search();
    break;
   case 4:
    exit(0);
  }
 }

 return 0;
}
