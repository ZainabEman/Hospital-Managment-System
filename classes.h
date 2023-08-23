//
// Created by Admin on 5/8/2023.
//

#ifndef HOSPITAL_MANAGMENT_SYSTEM_CLASSES_H
#define HOSPITAL_MANAGMENT_SYSTEM_CLASSES_H
#include<iostream>
using namespace std;


//Base class//Parent class

class person {
    string name;
    int age;
    string phoneNum,cnic;
    string address;
public:
    person();                           //default constructor to initialize the object
    void set_person();                  //Function to initialize object by user
    void get_person();                  //Function to Print object by user
    const string &getName() const;      //Getter function to return constant string "name" to use outside the class
};


class patient:public person{
    int reg_no;
    string date_admit;
    string date_discharge,disease;
    float bill,total;
public:
    patient();                          //default constructor to initialize the object
    void set_patient();                 //Function to initialize object by user
    void get_patient();                 //Function to Print object by user
    void bill_cal();                    //Function to Calculate bill
    static void list_of_dpt();          //Function to display list of all departments
    void avail_doctor();                //Function to display list of available doctors
    void book_appointment();            //Function to book appointment
    void patient_history();             //Function to Display history of the user(patient)
    void add_patient_data();            //Function to add patient add in text file
    void prev_pat_list();               //Function to display list of Previous patients
    void patient_menu();                //Function to display menu for patient

     string &getDisease() ;             //getter function to return private data member " Disease "
     float getTotal() ;                 //getter function to return private data member " total "

    static int patient_count;           //static count// to count patients
};


class staff: public person{
    float salary;
    string time_from,time_to;
public:
    staff();                            //default constructor to initialize the object
    float getSalary() const;            //getter function to return private data member " salary "

    void set_staff();                   //Function to initialize object by user
    void get_staff();                   //Function to Print object by user
};

class doctor:public staff{
    int doc_id;
    string spec;
    float fees;
    string status;
public:
    doctor();                           //default constructor to initialize the object

    void doctor_menu();                 //Function to display doctor's menu
    void set_doctor();                  //Function to initialize object by user
    void get_doctor();                  //Function to Print object by user
    void fees_cal();                    //Function to calculate fees
    void add_doctor();                  //Function to add doctor data
    void patients_rec();                //Function to display list of all patients
    void this_patient();                //Function to display data of a specific patient
    static void add_pat_rec();          //Function to add patient data
    void doctor_rec();                  //Function to display doctors data
    const string &getStatus() const;    //getter function to return private data member " status "
};

class accountant:public staff{
    int acc_ID;
    string chargeRoom ;
public:
    accountant();                       //default constructor to initialize the object
    const string &getchargeRoom() const;//getter function to return private data member " room number "

    int getAccId() const;               //getter function to return private data member "accountant id "

    void set_accountant();              //Function to initialize object by user
    void get_accountant();              //Function to Print object by user
    void Acc_menu();                    //Function to display Accountant's menu
    void display_acc();                 //Function to display Accountant data
    void add_acc();                     //Function to add accountant data
};


class nurse:public staff{
    int nurseID;
    string chargeRoom;
public:
    nurse();                            //default constructor to initialize the object
    const string &getchargeRoom() const;//getter function to return private data member "room number "

    int getNurseId() const;             //getter function to return private data member "nurse id "

    void set_nurse();                   //Function to initialize object by user
    void get_nurse();                   //Function to Print object by user
    void nurse_menu();                  //Function to display nurse's menu
    void display_nurse();               //Function to display nurse data
    void add_nurse();                   //Function to add nurse data
};
class admin:public staff{

public:
    admin();                            //default constructor to initialize the object
    void admin_menu();                  //Function to display admin 's menu
};
void system_end();
#endif //HOSPITAL_MANAGMENT_SYSTEM_CLASSES_H
