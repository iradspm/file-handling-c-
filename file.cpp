#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//functions declarations
void login();
void registr();
void forgot();
void Adminlogin();
void adminmenu();
void usermenu();
void changeAdminPassword();
void exitback();
void viewUserProfile();
void changerUserPassword();
void requestCar();
void mercedes();
void toyota();
void nissan();
void approveRequest();
void returnRentedCar();
void updateSystem();

//variables
bool b=true;

//ios::app--append
//ios::in--read
//ios::out--write

 

//int argc, char **argv[]
main()
{ 
        int choice;
        cout<<"*******************Welcome to car rental system**************************\n\n";
        cout<<"1.Normal User Login"<<endl;
        cout<<"2.Administrator Login"<<endl;    
        cout<<"3.logout"<<endl;
        cout<<"\nSelect your role to proceed :";
        cin>>choice;
        cout<<endl;
        cout <<"------------------------------------------\n";
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                       Adminlogin();
                        break;            
                case 3:
                        cout<<"Thanks for using this program.\n\n";
                       // return 0;
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , Try again..\n"<<endl;
                        main();
        }

}
void Adminlogin()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<" ***********Welcome to the Administrative Page****************\n\n"<<endl;
        cout<<"please enter the following details"<<endl;
        
        cout<<"Enter your Username :";
        cin>>user;
        cout<<"Enter your Password :";
        cin>>pass;
        cout <<"---------------------------------------------\n";

        ifstream input("Admin.txt",ios::in);
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
            cout<<"\nHello:\t"<<user<<"\n<Your login was successul>\n";
            adminmenu();

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                system("CLS");
                main();
        }
}
     

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"*******************Welcome to the Normal user page**********************\n\n"<<endl;
        cout<<"please enter the following details"<<endl;
        
        cout<<"Enter your Username :";
        cin>>user;
        cout<<"Enter your Password :";
        cin>>pass;
        cout <<"---------------------------------------------\n";

        ifstream input("usersDB.txt",ios::in);
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello:\t"<<  user<<"\n<Your login was successul>\n";
                usermenu();

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}
void adminmenu()
{ 
        int choice;
        cout<<"\n******************Admin MENU*******************************\n\n";
        cout<<"1.Register new user"<<endl;
        cout<<"2.Approve Users Car Rent Request"<<endl;
        cout<<"3.Update System on Returned car"<<endl;
        cout<<"4.Change Admin password"<<endl;
        cout<<"5.Exit"<<endl;
      
        cout<<"\nSelect your action to proceed :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                       registr();
                        break;
                case 2:
                      // cout<<"approve users car rent request"<<endl;
                      approveRequest();
                        break;
                case 3:
                       // cout<<"update system on returned car"<<endl;
                       updateSystem();
                        break;
                case 4:
                	//cout<<"change admin password"<<endl;
                	changeAdminPassword();
                	break;
                case 5:
                	//cout<<"change admin password"<<endl;
                	exitback();
                	break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , Try again..\n"<<endl;
                        main();
        }

}
void usermenu()
{ 
        int choice;
        cout<<"\n***************Normal User MENU***************\n\n";
        cout<<"1.View Personal Details/Profile"<<endl;
        cout<<"2.Request to rent a car"<<endl;
        cout<<"3.Return rented car"<<endl;
        cout<<"4.Change Your Password"<<endl;
        cout<<"5.Exit"<<endl;
      
        cout<<"\nSelect your action to proceed :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                    //cout<<"view personal details"<<endl;
                    viewUserProfile();
                    break;
                case 2:
                       //cout<<"Request  to rent a car"<<endl;
                       requestCar();
                       break;
                case 3:
                       // cout<<"Return rented car"<<endl;
                       returnRentedCar();
                        
                        break;
                case 4:
                	//cout<<"change your password"<<endl;
                	changerUserPassword();
                	
                	break;
                case 5:
                	exitback();
                	break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , Try again..\n"<<endl;
                        main();
        }

}

void registr()
{

        string reguser,regpass,ru,rp,ra;
        unsigned int amount;
        //system("cls");
        cout<<"User information"<<endl;
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        cout<<"\nEnter flat Fee Amount :";
        cin>>amount;

        ofstream reg("usersDB.txt",ios::app);
        if(amount<10500)
        {
        	cout<<"Flat fee amount should be more than 10500"<<endl;
        	//system("CLS");
        	cout<<"---------------------------------------"<<endl;
        	registr();
		}
		else
		{
			//check if username exists
			ifstream check("usersDB.txt",ios::in);
			while(check>>ru>>ra>>ra)
			{
				if(reguser==ru)
				{
					cout<<"Username already taken, choose another username!"<<endl;
					cout<<"------------------------------------------"<<endl;
					adminmenu();
					//break;
				}
				else
				{
						reg<<"\n"<<reguser<< ' '<<regpass<< ' '<<amount<<endl;
      					system("cls");
       					cout<<"\nRegistration Sucessful\n";
       					adminmenu();
				}
			}
	
		}
       
        

}
void changeAdminPassword()
{
	 int count;
        string user,u,p;
        system("cls");
        cout<<" ***********Change admin password****************\n\n"<<endl;
        cout<<"please verify the following details"<<endl;
        
        cout<<"Enter admin Username :";
        cin>>user;
        cout <<"---------------------------------------------\n";

        ifstream getAdmin("Admin.txt",ios::in);
        while(getAdmin>>u>>p)
        {
                if(u==user)

                {
                        count=1;
                        system("cls");
                }
        }
        getAdmin.close();
        if(count==1)
        {
        	string newPassword;
            cout<<"Username is:"<<user<<"\nPassword is:"<<p<<"\n";
            cout<<"Enter below details to update your password"<<endl;
            cout<<"New password:\t";
            cin>>newPassword;
            p=newPassword;
            
            //ofstream update("Admin.txt",ios::out);
            ofstream update("Admin.txt",ios::out);
      		update<<user<< ' '<<p<<endl;
      		cout<<"\nUpdate successful"<<endl;
      		adminmenu();
            

             //adminmenu();

        }
        else
        {
                cout<<"\nUSERNAME ERROR\nPlease check your username\n";
                //system("CLS");
                changeAdminPassword();
        }
	
}
void exitback()
{
	system("CLS");
	main();
}
void viewUserProfile()
{
	string username, password, amount, u;
	int count;
	cout <<"---------------------------------------------"<<endl;
	cout <<"To view your profile, enter your username:\t";
	cin >>username;
	cout<<"**********My Profile*************"<<endl;
	
	//read from textfile
	ifstream userdetail("usersDB.txt",ios::in);
	while(userdetail>>u>>password>>amount)
	{
		if(username==u)
		{
			count=1;
		}
	}
	userdetail.close();
	if(count==1)
	{
		cout<<"  username   | password  |  Balance   "<<endl;
		cout<<"**********************************************"<<endl;
		cout<<"      "<<username<<"    "<<password<< "     "<<amount<< " "<<endl;
		usermenu();
		
	}
	else
	{
		cout<<"Wrong username!, try again"<<endl;
		usermenu();
	}	
	
}
void changerUserPassword()
{
	cout<<"**********Change Password************"<<endl;
	string username, password, amount, u, npassword;
	int count;
	cout<<"To verify its you, Enter your username:\t";
	cin>>username;
	
	ifstream getUser("usersDB.txt",ios::in);
	while(getUser>>u>>password>>amount)
	{
		if(username==u)
		{
			count=1;
		}
	}
	if(count==1)
	{
		cout<<"\nEnter new password:\t";
		cin>>npassword;
		password=npassword;
		//update details
		ofstream updatep("usersDB.txt",ios::out);
		updatep<<username<< ' ' <<password<< ' ' <<amount<<endl;
		cout<<"\nUpdate successful"<<endl;
		usermenu();
	}
	else
	{
		cout<<"User doesn't exist!"<<endl;
		usermenu();
	}
	
}

//cars
void requestCar()
{
	cout<<"*************Available cars***************"<<endl;
	cout<<" Car     | Number of Cars"<<endl;
	//fetch cars from carsDB.txt
	string carType,count;
	int counter;
	ifstream cars("carsDB.txt",ios::in);
	while(cars>>carType>>count)
	{
		cout<<carType<<' '<<' ' <<count<<endl;
	}
		
		//car menu options
		int option;
		cout<<"**************Request Car**************"<<endl;
		cout<<"1. Mercedes"<<endl;
		cout<<"2. Toyota"<<endl;
		cout<<"3. Nissan"<<endl;
		
		cout<<"Enter your choice:\t";
		cin>>option;
		switch(option)
		{
			case 1:
				mercedes();
				break;
			case 2:
				toyota();
				break;
			case 3:
				nissan();
				break;
			default:
				cout<<"Wrong choice of car!, try again."<<endl;
				requestCar();
			
		}
	usermenu();
	
}
void mercedes()
{
	string username,password,u,carType;
	unsigned int balance,number,count,new_number;
	cout<<"Enter your username:\t";
	cin>>username;
	
	//check username
	ifstream user("usersDB.txt",ios::in);
	while(user>>u>>password>>balance)
	{
		if(username==u)
		{
			count=1;
		}
	}
	if(count==1)
	{
		//check balance
		if(balance <5000)
		{
			cout<<username<<"\tYour balance in below 5000, please top up!"<<endl;
			usermenu();
		}
		else
		{
			//check number of cars
			ifstream cars("carsDB.txt",ios::in);
			if(cars>>carType>>number)
			{
				if(number==0)
				{
				cout<<"Choose another car, mercedes are not available!"<<endl;
				requestCar();
				}
				
				else
				{
				//send request
				ofstream sendRequest("requests.txt",ios::out);
				sendRequest<<username<<' '<<"Mercedes"<<' '<<"NotApproved"<<' '<<"NotReturned"<<endl;
				cout<<"Request sent, wait for approval!"<<endl;
				 //update cars count
  				ofstream updateCars("carsDB.txt",ios::app);
				new_number=number-1;
				//updateCars<<"Mercedes"<< ' '<<new_number<<endl;
				//updateCars<<'Mercedes'<<new_number<<endl;

				}
			
		}
		
		}
	}
	else
	{
		cout<<"Your records don't match"<<endl;
		usermenu();
	}
	
}

void toyota()
{
	string username,password,u,carType;
	unsigned int balance,number,count,new_number;
	cout<<"Enter your username:\t";
	cin>>username;
	
	//check username
	ifstream user("usersDB.txt",ios::in);
	while(user>>u>>password>>balance)
	{
		if(username==u)
		{
			count=1;
		}
	}
	if(count==1)
	{
		//check balance
		if(balance <5000)
		{
			cout<<username<<"\tYour balance in below 5000, please top up!"<<endl;
			usermenu();
		}
		else
		{
			//check number of cars
			ifstream cars("carsDB.txt",ios::in);
			if(cars>>carType>>number)
			{
				if(number==0)
				{
				cout<<"Choose another car, mercedes are not available!"<<endl;
				requestCar();
				}
				
				else
				{
				//send request
				ofstream sendRequest("requests.txt",ios::out);
				sendRequest<<username<<' '<<"Toyota"<<' '<<"NotApproved"<<' '<<"NotReturned"<<endl;
				cout<<"Request sent, wait for approval!"<<endl;
				 //update cars count
  				ofstream updateCars("carsDB.txt",ios::app);
				new_number=number-1;
				//updateCars<<"Mercedes"<< ' '<<new_number<<endl;
				//updateCars<<'Mercedes'<<new_number<<endl;

				}
			
		}
		
		}
	}
	else
	{
		cout<<"Your records don't match"<<endl;
		usermenu();
	}
	
}
void nissan()
{
	string username,password,u,carType;
	unsigned int balance,number,count,new_number;
	cout<<"Enter your username:\t";
	cin>>username;
	
	//check username
	ifstream user("usersDB.txt",ios::in);
	while(user>>u>>password>>balance)
	{
		if(username==u)
		{
			count=1;
		}
	}
	if(count==1)
	{
		//check balance
		if(balance <5000)
		{
			cout<<username<<"\tYour balance in below 5000, please top up!"<<endl;
			usermenu();
		}
		else
		{
			//check number of cars
			ifstream cars("carsDB.txt",ios::in);
			if(cars>>carType>>number)
			{
				if(number==0)
				{
				cout<<"Choose another car, mercedes are not available!"<<endl;
				requestCar();
				}
				
				else
				{
				//send request
				ofstream sendRequest("requests.txt",ios::out);
				sendRequest<<username<<' '<<"Nissan"<<' '<<"NotApproved"<<' '<<"NotReturned"<<endl;
				cout<<"Request sent, wait for approval!"<<endl;
				 //update cars count
  				ofstream updateCars("carsDB.txt",ios::app);
				new_number=number-1;
				//updateCars<<"Mercedes"<< ' '<<new_number<<endl;
				//updateCars<<'Mercedes'<<new_number<<endl;

				}
			
		}
		
		}
	}
	else
	{
		cout<<"Your records don't match"<<endl;
		usermenu();
	}
	
}
void approveRequest()
{
	cout<<"***************User Requests*************"<<endl;
	string username, request,u,carType,returnStatus;
	
	ifstream requests("requests.txt",ios::in);
	while(requests>>u>>carType>>request>>returnStatus)
	{
		cout<<"Username|Car requested| status"<<endl;
		cout<<u<<' '<<carType<<' '<<request<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Enter username of user to approve:\t";
		cin>>username;
		if(username==u)
		{
			//update
			if(request=="NotApproved")
			{
			ofstream up("requests.txt",ios::out);
			up<<username<<' '<<carType<<' '<<"Approved"<<endl;
			cout<<"Request approved!"<<endl;
			adminmenu();
			}
			else
			{
				cout<<"Already approved!"<<endl;
				adminmenu();
			}
		}
	}
	adminmenu();
}

void returnRentedCar()
{
	string user,carType,status,returnStatus,u;
	unsigned int count;
	cout<<"Type your username:\t";
	cin>>u;
	//check requests
	ifstream requ("requests.txt",ios::in);
	while(requ>>user>>carType>>status>>returnStatus)
	{
		if(u==user)
		{
			cout<<"*********my requests*********"<<endl;
			cout<<user<<" "<<carType<<" "<<status<<" "<<returnStatus<<endl;
			count=1;
			break;
		}
		
	}
	requ.close();
	if(count==1)
	{
		//check status  if approved
		if(status=="Approved")
		{
			//return car
			ofstream retu("requests.txt",ios::app);
			retu<<user<<' '<<carType<<' '<<status<<' '<<"Returned"<<endl;
			cout<<"Car returned sucessfully"<<endl;
			cout<<"*********End*********"<<endl;
			usermenu();
		}
		else
		{
			cout<<"Request not yet approved, no car to return"<<endl;
			//return b;
		    usermenu();
		}
	}
	
}

void updateSystem()
{
	//check request status whether returned
	//if returned, update the system car count
	string user,carType,status, returnStatus,username;
	unsigned int count;
	
	cout<<"Enter username of user who borrowed car:\t";
	cin>>username;
	ifstream requ("requests.txt",ios::in);
	while(requ>>user>>carType>>status>>returnStatus)
	{
		if(username==user && status=="Approved" && returnStatus=="Returned")
		{
			cout<<"*********Car Status of user*********"<<endl;
			cout<<"User:"<<user<<"\tcar-type:"<<carType<<"\tApproval:"<<status<< "\tReturn status: "<<returnStatus<<endl;
			count=1;
			//break;
		}
	}
	requ.close();
	if(count==1)
	{
		//update system
		ifstream cardb("carsDB.txt",ios::in);
		ofstream cardu("carsDB.txt",ios::app);
		string carType;
		unsigned int count,num;
		if(cardb>>carType>>num)
		{
			//cout<<carType<<" "<<num<<endl;
			if(carType=="Mercedes")
			{
				cardu<<"\t"<<carType<<' '<<num+1<<endl;
				cout<<"system updated successfully"<<endl;
				usermenu();
			}
			else if(carType=="Toyota")
			{
				cardu<<"\t"<<carType<<' '<<num+1<<endl;
				cout<<"system updated successfully"<<endl;
				usermenu();
			}
			else
			{
				cardu<<"\t"<<carType<<' '<<num+1<<endl;
				cout<<"system updated successfully"<<endl;
				usermenu();
			}
		}
		

	}
	
}
