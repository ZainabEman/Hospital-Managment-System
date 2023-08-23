#include <iostream>
#include<cstring>
#include <conio.h>
#include "classes.h"
using namespace std;
int main()
{
    cout<<"____________________________________________________________________________________\n";
    cout<<"*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n";
    cout << "         HH     HH   MM      MM   SSSSSSS    \n";
    cout << "         HH     HH   MMMM  MMMM  SS          \n";
    cout << "         HHHHHHHHH   MM  MM  MM    SSSSSSS    \n";
    cout << "         HH     HH   MM      MM         SS    \n";
    cout << "         HH     HH   MM      MM   SSSSSSS    \n";
    cout<<"*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
    cout<<"____________________________________________________________________________________\n\n"
          "";
    getch();
    admin a;                    //objects of all classes
    doctor d;
    patient p;
    accountant acc;
    nurse n;
    int ch;                     //int variable to take choice from user
    char pass[15];              //char array to take in password
    do{
        system("CLS");
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tMAIN MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout<<"\t\t\n";
        cout<<"\t\t1.___.Admin.\n";
        cout<<"\t\t2.___.patient.\n";
        cout<<"\t\t3.___.Doctor.\n";
        cout<<"\t\t4.___.Accountant.\n";
        cout<<"\t\t5.___.Nurse.\n";
        cout<<"\t\t6.___.Exit. \n";
        cout<<"\t\tChoice :  \n";
        cin>>ch;
        switch(ch){
            case 1:
            login1:
                cout<<"Enter ADMIN password: ";

                cin>>pass;          //enter password

                if(strcmp(pass,"admin")==0)      //strcmp function to authenticate password
                {
                    system("cls");
                   a.admin_menu();               //call of admin 's menu
                }
                else
                {
                    cout<<"WRONG PASSWORD!!!\n";
                    goto login1;
                }
                break;
            case 2:
            login2:
                cout<<"Enter Patient password: ";

                cin>>pass;

                if(strcmp(pass,"patient")==0)       //strcmp function to authenticate password
                {
                    system("cls");
                    p.patient_menu();               //call of patient 's menu
                }
                else
                {
                    cout<<"WRONG PASSWORD!!!\n";
                    goto login2;
                }
                break;
            case 3:

            login3:
                cout<<"Enter Doctor password: ";

                cin>>pass;

                if(strcmp(pass,"doctor")==0)        //strcmp function to authenticate password
                {
                    system("cls");
                    d.doctor_menu();               //call of doctor 's menu
                }
                else
                {
                    cout<<"WRONG PASSWORD!!!\n";
                    goto login3;
                }
                break;
            case 4:
            login4:
                cout<<"Enter Accountant password: ";

                cin>>pass;
                if(strcmp(pass,"accountant")==0)        //strcmp function to authenticate password
                {
                    system("cls");
                    acc.Acc_menu();                     //call of accountant 's menu
                }
                else
                {
                    cout<<"WRONG PASSWORD!!!\n";
                    goto login4;
                }
                break;
            case 5:
            login5:
                cout<<"Enter Nurse password: ";

                cin>>pass;
                if(strcmp(pass,"nurse")==0)         //strcmp function to authenticate password
                {
                    system("cls");
                    n.nurse_menu();                 //call of nurse's menu
                }
                else
                {
                    cout<<"WRONG PASSWORD!!!\n";
                    goto login5;
                }
                break;
        }
    }while(ch!=6);
    system("cls");
    system_end();
    getch();
    system("cls");
    return 0;
}