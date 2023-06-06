/*Company maintains employee information as employee 
ID, name, designation, and salary. Allow user to add delete information of particular employee. 
If employee does not exist an appropriate message is displayed. If it is, then system displays 
the employee details. Use index sequential file to maintain the data*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
class employee 
{
    public:
    int id;
    int sallary;
    char name[50];
    char designation[50] ;
};
class employeedata 
{
    public:
  string filename="employedata.dat";
  employeedata()
  {
    fstream f;
    f.open(filename,ios::out);
    f.close();
  }
    void addEmployee();
    void searchEmployee();
    void displayemployee();
    void deletemployee();
    
};
void employeedata::deletemployee()
{
  employee e;
  int count=0,n;
  ifstream f(filename,ios::in|ios::binary);
  cout<<"enter employee id"<<endl;
  cin>>n;
  ofstream l("temp.dat",ios::out|ios::binary);

  while(f.read((char*)&e,sizeof(e)))
  {  
    if(e.id!=n)
    {
      l.write((char*)&e,sizeof(e));   
    }
  }
  f.close();
  l.close();
  remove("employedata.dat");//built in function syntex remove(filename)
  rename("temp.dat","employedata.dat");//built in rename filename rename(oldfilename,newfilename)
}
void employeedata::searchEmployee()
 {
   employee e;
  int count=0,n;
  ifstream f(filename,ios::in|ios::binary);
  cout<<"enter employee id"<<endl;
  cin>>n;

  while(f.read((char*)&e,sizeof(e)))
  {
    if(e.id==n)
    {
      count=1;
      break;
    }
  }
  f.close();
  if(count==1)
  {
    cout<<"records  found as fillow data"<<endl;
    cout<<"employee id:"<<e.id<<" \n " ;
    cout<<"employee name:"<<e.name<<" \n";
    cout<<"employee designation:"<<e.designation<<" \n ";
    cout<<"employee sallary:"<<e.sallary<<" \n";
  }
 }
void employeedata::addEmployee()
{    
   static int i=0;
    int e;
    employee s;
    static int data[10];
    cout<<"enter id of employee"<<endl;
    cin>>e;
    int n=0;
    for(int i=0;i<10;i++)
    {
      if(data[i]==e)
      {
        n=1;
         cout<<"index file unique index  only";
        exit(0);
      }
    }
    data[i++]=e;
    if(!n)
    {
      s.id=e;
      cout<<"enter name of employee:"<<endl;
      cin.get();
      cin.getline(s.name,50);
      cout<<"enter employee designation:"<<endl;
      //cin.get();
      cin.getline(s.designation,50);
      cout<<"enter sallary of employee"<<endl;
      cin>>s.sallary;
      ofstream f(filename,ios::out|ios::app|ios::binary);
      f.write((char*)&s, sizeof(s));
      if(f.fail())
      {
        cout<<"fail to add records"<<endl;
      }
      else 
      {
        cout<<"records added succesfully"<<endl;
      }
      f.close();
    }
}
void employeedata:: displayemployee()
{
  employee e;
  int count=0;
  ifstream f(filename,ios::in|ios::binary);
  cout<<count<<") ";
    cout<<"ID"<<" | " ;
    cout<<"NAME"<<" | ";
    cout<<"DESIGNATION"<<" | ";
    cout<<"SALLARY"<<" | ";

  while(f.read((char*)&e,sizeof(e)))
  {
    count++;
    cout<<"\n"<<count<<") ";
    cout<<e.id<<" | " ;
    cout<<e.name<<" | ";
    cout<<e.designation<<" | ";
    cout<<e.sallary<<" | \n";
  }
  if(count==0)
  {
    cout<<"records not found"<<endl;
  }
 f.close();
}

int main()
{
  employeedata e;
  int c;
  do
  {cout<<"1.add records\n2.search records\n3.display records\n4.delete records\n5.exit"<<endl;
   cout<<"enter your choice"<<endl;
   cin>>c;
   switch(c)
   {
    case 1:e.addEmployee(); break;
    case 2:cout<<"\nsearch records->:\n"<<endl;
           e.searchEmployee();break;
    case 3: e.displayemployee();break;
    case 4:
           e.deletemployee();
           cout<<"\nrecords deleted succesfully"<<endl;
           break;
    case 5:exit(0);
           break;
    default:cout<<"enter valid choice:"<<endl;
           break;
   }
  }while(c<=5);  
}