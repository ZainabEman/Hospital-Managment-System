//
// Created by Admin on 5/8/2023.
//

#include "classes.h"
#include <iostream>
#include <fstream>
#include<conio.h>
using namespace std;

//to set a person detail
void person::set_person() {
    cin.ignore();
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Age : ";
    cin>>age;cin.ignore();
    cout<<"Enter CNIC : ";
    getline(cin,cnic);
    cout<<"Enter your Address : ";
    getline(cin,address);
}

void person::get_person() {
    cout<<"\n\n\tName : "<<name;
    cout<<"\n\n\tAge : "<<age;
    cout<<"\n\n\tPhone Number : "<<phoneNum;
    cout<<"\n\n\tCNIC : "<<cnic;
    cout<<"\n\n\tAddress : "<<address;
}

const string &person::getName() const {
    return name;
}

person::person() {
    name="Zainab Eman";
    age=19;
    phoneNum="0137-1079201";
    cnic="30719-39292-9320";
    address="Gulam abad Faisalabad";
}

int patient:: patient_count=0;

void patient::set_patient() {
    person::set_person();
    cout<<"Enter Disease of patient : ";
    getline(cin,disease);
    cout<<"Enter Registration Number : ";
    cin>>reg_no;
    cin.ignore();
    cout<<"Enter Admit Date : ";
    getline(cin,date_admit);
    cout<<"Enter Discharge date : ";
    getline(cin,date_discharge);
    system("cls");
    cout<<" Data is Entered Successfully ";

}

void patient::get_patient() {
    person::get_person();
    cout<<"\n\n\tRegistration Number : "<<reg_no;
    cout<<"\n\n\tAdmit Date : "<<date_admit;
    cout<<"\n\n\tDischarge date : "<<date_discharge;
}

void patient::bill_cal() {
    system("CLS");
    bill=5000,total=0;
    cout << "_______________________________________________________________________________";
    cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
    cout << "_______________________________________________________________________________";
    cout << "\nHospital Room Charges                      :\t  1000";
    cout << "\nHospital Care Charges                      :\t  50";
    cout << "\nHospital Maintenance Charges                :\t  50";
    cout << "\nPatient Individual  Charges                :\t " << bill;
    cout << "\n_______________________________________________________________________________";
    total = 1000 + 50 + 50 + bill;
    cout << "\nTotal Fee Charge                           :\t"  << total<<"\n";
    cout << "_______________________________________________________________________________";
}

void patient::list_of_dpt() {
    cout << "_______________________________________________________________________________";
    cout<<"\n\t\t\tAVAILABLE DEPARMENTS \n";
    cout << "_______________________________________________________________________________";
    cout<<"\n\n1._.Cardiology";
    cout<<"\n2._.Neurology";
    cout<<"\n3._.Radiology";
    cout<<"\n4._.General Surgery";
    cout<<"\n5._.Ophthalmology";
    cout<<"\n6._.Nutrition and Dietetics";
    cout<<"\n7._.Gastroenterology";
    cout<<"\n8._.2Hematology";
}

void patient::avail_doctor()
{
    ifstream inFile;
    inFile.open("avail_doc.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << "_______________________________________________________________________________";
        cout << "\n\t\t\tAVAILABLE DOCTORS \n";
        cout << "_______________________________________________________________________________\n";
        cout << inFile.rdbuf();         //Read text file data
    }
    inFile.close();
}

void patient::book_appointment() {
    ifstream inFile;
    inFile.open("avail_doc.txt");
    if (inFile.fail()) {
        cout << "Error opening file." << endl;
        return;
    } else {
        cout << "Available Doctors are : \n";
        cout << inFile.rdbuf();
        int id2;
        cout << "\nEnter doctor Id: ";
        cin >> id2;
        cout << "Your Appointment is Booked Successfully";
        return;
    }
}
void patient::patient_history() {
    ifstream inFile;
    inFile.open("Patient_history.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();//Read text file data
    }
    inFile.close();
}

void patient::prev_pat_list() {
    ifstream inFile;
    inFile.open("prev_rec_pat.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();//Read text file data
    }
    inFile.close();
}
float patient::getTotal()  {
    return 6100;
}

void patient::add_patient_data() {
    ofstream ofile;
    ofile.open("prev_rec_pat.txt",ios::app);
    if(ofile.fail())
    {
        cout<<" \nFile cannot be opened!!! ";
    }
    else
    {
        ofile<<getName()<<"\t"<<getDisease()<<"\t"<<getTotal()<<" Pkr"<<endl;
        cout<<"\nData Entered Successfully\n";
    }
}
 string &patient::getDisease(){
    return disease;
}

patient::patient() {
    patient_count++;
    reg_no=123;
    date_admit="23-8-22";
    date_discharge="31-08-22";
    disease="Cardiaonic problem";
}

void patient::patient_menu() {
    int ch;
    do {
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tPATIENT MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout << "\n\t\tEnter your Choice\n";
        cout << "\t\t1_Display Patient Data.\n";
        cout << "\t\t2_Display Department List.\n";
        cout << "\t\t3_Display Available Doctor.\n";
        cout << "\t\t4_Display Previous Patients List.\n";
        cout << "\t\t5_Display Patient History.\n";
        cout << "\t\t6_To Book Appointment.\n";
        cout << "\t\t7_To Calculate Bill.\n";
        cout << "\t\t8_Go back to Main Menu.\n";
        cout << "\t\t0_To Exit.\n";
        cout << "\t\tchoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("cls");
                get_patient();
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                list_of_dpt();
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                avail_doctor();
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                prev_pat_list();
                getch();
                system("cls");
                break;
            case 5:
                system("cls");
                patient_history();
                getch();
                system("cls");
                break;
            case 6:
                system("cls");
                book_appointment();
                getch();
                system("cls");
                break;
            case 7:
                system("cls");
                bill_cal();
                getch();
                system("cls");
                break;
            case 8:
                system("cls");
                return;
            default:
                system("cls");
                system_end();
                getch();
                system("cls");
                exit(1);
        }
    }while(1);
}

void staff::set_staff() {
    person::set_person();
    cout<<"Enter Salary : ";
    cin>>salary;cin.ignore();
    cout<<"Enter Duty time  \nFrom : ";
    getline(cin,time_from);
    cout<<"To : ";
    getline(cin,time_to);
}

staff::staff() {
    salary=50000;
    time_from="9:00 AM";
    time_to="5:00 AM";
}

void staff::get_staff() {
    person::get_person();
    cout<<"\n\n\tSalary : "<<salary;
    cout<<"\n\n\tDuty Time is From : "<<time_from<<" to "<<time_to;
}

float staff::getSalary() const {
    return salary;
}

admin::admin() {}

void admin::admin_menu() {
    patient pobj;
    doctor dobj;
    nurse nobj;
    accountant accobj;
    int ch;
    do {
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tADMIN MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout << "\n\t\tEnter your Choice\n";
        cout << "\t\t1_Display Departments Lists.\n";
        cout << "\t\t2_Display Doctor's Data.\n";
        cout << "\t\t3_Add Doctor's Data.\n";
        cout << "\t\t4_Display Previous Patients List.\n";
        cout << "\t\t5_Add Patient Record.\n";
        cout << "\t\t6_display Nurse Record.\n";
        cout << "\t\t7_Add Nurse Record.\n";
        cout << "\t\t8_Display Accountant Record.\n";
        cout << "\t\t9_Add Accountant Record.\n";
        cout << "\t\t10_Go back to Main Menu.\n";
        cout << "\t\t0_To Exit.\n";
        cout << "\t\tchoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("cls");
                pobj.list_of_dpt();
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                dobj.doctor_rec();
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                cout<<"*_*_*_*_ADD DOCTOR DATA_*_*_*_*";
                dobj.add_doctor();
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                pobj.prev_pat_list();
                getch();
                system("cls");
                break;
            case 5:
                system("cls");
                pobj.add_patient_data();
                break;
            case 6:
                system("cls");
                nobj.display_nurse();
                getch();
                system("cls");
                break;
            case 7:
                system("cls");
                nobj.add_nurse();
                getch();
                system("cls");
                break;
            case 8:
                system("cls");
                accobj.display_acc();
                getch();
                system("cls");
                break;
            case 9:
                system("cls");
                accobj.add_acc();
                getch();
                system("cls");
                break;
            case 10:
                system("cls");
                return;
                break;
            default:
                system("cls");
                system_end();
                getch();
                system("cls");
                exit(1);
        }
    }while(1);
}

void doctor::set_doctor() {
    set_staff();
    cout<<"Enter Doctor ID : ";
    cin>>doc_id;
    cin.ignore();
    cout<<"Enter Specialization of Doctor : ";
    getline(cin,spec);
    cout<<"Enter Fees of Doctor : ";
    cin>>fees;
    cout<<"Enter Status of Doctor : ";
    cin>>status;
    system("cls");
    cout<<" Data is Entered Successfully ";
}

void doctor::get_doctor() {
    get_staff();
    cout<<"Doctor ID : "<<doc_id<<endl;
    cout<<"Specialization : "<<spec<<endl;
    cout<<"Fees : "<<fees<<endl;
    cout<<"Status : "<<status<<endl;
}

void doctor::patients_rec() {
    ifstream inFile;
    inFile.open("prev_rec_pat.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << "\n_______________________________________________________________________________";
        cout << "\n\t\t\tPREVIOUS PATIENTs HISTORY \n";
        cout << "_______________________________________________________________________________\n";
        cout << inFile.rdbuf();
    }
    inFile.close();
}

void doctor::this_patient() {
    ifstream inFile;
    inFile.open("Patient_history.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();
    }
    inFile.close();
}

void doctor::doctor_rec() {
    ifstream inFile;
    inFile.open("Doctors.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();
    }
    inFile.close();
}

void doctor::fees_cal() {
    float temp;
    temp=fees* patient::patient_count;
    cout<<"\nFees per patient: "<<fees<<endl;
    cout<<"Total patient Checked today : "<<patient::patient_count<<endl;
    cout<<"-----------------------------------------------\n";
    cout<<"Total Fees of a Day is : "<<temp<<" Pkr\n";
}

void doctor::
add_pat_rec() {
    ofstream ofile;
    ofile.open("prev_rec_pat.txt",ios::app);
    if(ofile.fail())
    {
        cout<<" \nFile cannot be opened!!! ";
    }
    else
    {
        patient pat;
        pat.set_patient();
        ofile<<pat.getName()<<"\t"<<pat.getDisease()<<"\t"<<pat.getTotal()<<" Pkr"<<endl;
        cout<<"\nData Entered Successfully\n";
    }
}

void doctor::doctor_menu() {
    int ch;
    do {
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tDOCTOR MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout << "\n\t\tEnter your Choice\n";
        cout << "\t\t1_Display Doctor's Data.\n";
        cout << "\t\t2_Calculate Fees.\n";
        cout << "\t\t3_Display Previous Patients List.\n";
        cout << "\t\t4_Display Patient History.\n";
        cout << "\t\t5_Add Patient Record.\n";
        cout << "\t\t6_Go back to Main Menu.\n";
        cout << "\t\t0_To Exit.\n";
        cout << "\t\tchoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("cls");
                doctor_rec();
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                fees_cal();
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                patients_rec();
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                this_patient();
                getch();
                system("cls");
                break;
            case 5:
                system("cls");
                cout<<"\n*_*_*_*_*ADD PATIENT DATA_*_*_*_*_*\n";
                add_pat_rec();
                getch();
                system("cls");
                break;
            case 6:
                system("cls");
                return;
                break;
            default:
                system("cls");
                system_end();
                getch();
                system("cls");
                exit(1);
        }
    }while(1);
}

void doctor::add_doctor() {
    ofstream ofile;
    ofile.open("doc.txt",ios::app);
    if(ofile.fail())
    {
        cout<<" \nFile cannot be opened!!! ";
    }
    else
    {
        doctor obj;
        obj.set_doctor();
        ofile<<"\n"<<obj.doc_id<<"\t"<<obj.getName()<<"\t"<<obj.getStatus()<<"\t"<<obj.getSalary();
        system("cls");
        cout<<"\nData Entered Successfully\n";
    }
}

const string &doctor::getStatus() const {
    return status;
}

doctor::doctor() {
    doc_id=123;
    spec="Neuron surgeon";
    fees=100000;
    status="Visiting";
}

accountant::accountant() {
   acc_ID=123;
   chargeRoom="Room#01";
}
void accountant::set_accountant() {
    set_staff();
    cout<<"Enter Accountant ID : ";
    cin>>acc_ID;
    cin.ignore();
    cout<<"Enter Charge Room No : ";
    getline(cin,chargeRoom);
    system("cls");
    cout<<" Data is Entered Successfully ";
}
void accountant::get_accountant() {
    get_staff();
    cout<<"\n\n\tNurse ID : "<<acc_ID;
    cout<<"\n\n\tIn-Charge 5"
          <<chargeRoom<<endl;
}

void accountant::display_acc() {
    ifstream inFile;
    inFile.open("Accountant.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();
    }
    inFile.close();
}

void accountant::add_acc() {
    ofstream ofile;
    ofile.open("Accountant.txt",ios::app);
    if(ofile.fail())
    {
        cout<<" \nFile cannot be opened!!! ";
    }
    else
    {
        accountant a;
        a.set_accountant();
        ofile<<a.getAccId()<<"\t"<<a.getName()<<"\t"<<a.getchargeRoom()<<"\t"<<a.getSalary()<<endl;
        cout<<"\nData Entered Successfully\n";
    }
}

const string &accountant::getchargeRoom() const {
    return chargeRoom;
}

int accountant::getAccId() const {
    return acc_ID;
}
void accountant::Acc_menu() {
    int ch;
    do {
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tACCOUNTANT MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout << "\n\t\tEnter your Choice\n";
        cout << "\t\t1_Display Accountant's Data.\n";
        cout << "\t\t2_Display This Accountant Data.\n";
        cout << "\t\t3_Add Accountant Record.\n";
        cout << "\t\t4_Go back to Main Menu.\n";
        cout << "\t\t0_To Exit.\n";
        cout << "\t\tchoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("cls");
                display_acc();
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                cout<<"Accountant data : \n";
                get_accountant();
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                cout<<"*_*_*_*_*_ADD ACCOUNTANT DATA_*_*_*_*_*\n";
                add_acc();
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                return;
            default:
                system("cls");
                system_end();
                getch();
                system("cls");
                exit(1);
        }
    }while(1);
}

nurse::nurse() {
    nurseID=123;
    chargeRoom="Room#01";
}

const string &nurse::getchargeRoom() const {
    return chargeRoom;
}
void nurse::set_nurse() {
    set_staff();
    cout<<"Enter Nurse ID : ";
    cin>>nurseID;cin.ignore();
    cout<<"Enter Charge Room No : ";
    getline(cin,chargeRoom);
    system("cls");
    cout<<" Data is Entered Successfully ";
}

void nurse::display_nurse() {
    ifstream inFile;
    inFile.open("Nurse.txt");
    if (inFile.fail())
    {
        cout << "Error opening file." << endl;
        return;
    }
    else {
        cout << inFile.rdbuf();
    }
    inFile.close();
}

void nurse::add_nurse() {
    ofstream ofile;
    ofile.open("Nurse.txt",ios::app);
    if(ofile.fail())
    {
        cout<<" \nFile cannot be opened!!! ";
    }
    else
    {
        nurse a;
        a.set_nurse();
        ofile<<a.getNurseId()<<"\t"<<a.getName()<<"\t"<<a.getchargeRoom()<<"\t"<<a.getSalary()<<endl;
        cout<<"\nData Entered Successfully\n";
    }
}

int nurse::getNurseId() const {
    return nurseID;
}
void nurse::get_nurse() {
    get_staff();
    cout<<"\n\n\tNurse ID : "<<nurseID;
    cout<<"\n\n\tIn-Charge "<<chargeRoom;
}
void nurse::nurse_menu() {
    int ch;
    do {
        cout << "_______________________________________________________________________________\n";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "\t\t\t\tNURSE MENU\n ";
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
        cout << "_______________________________________________________________________________";
        cout << "\n\t\tEnter your Choice\n";
        cout << "\t\t1_Display Nurse's Data.\n";
        cout << "\t\t2_Display This Nurse Data.\n";
        cout << "\t\t3_Add Nurse Record.\n";
        cout << "\t\t4_Go back to Main Menu.\n";
        cout << "\t\t0_To Exit.\n";
        cout << "\t\tchoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("cls");
                display_nurse();
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                get_nurse();
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                cout<<"\n*_*_*_*_ENTER NURSE DATA _*_*_*_*\n";
                add_nurse();
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                return;
            default:
                system("cls");
                system_end();
                getch();
                system("cls");
                exit(1);
        }
    }while(1);
}

void system_end() {
    cout<<"*_*_*_*_*SYSTEM CREATED BY_*_*_*_*_*_\n";
    cout<<"\tZAINAB EMAN 22F-3738\n";
    cout<<"\tIMAMA KAINAT 22F-3661\n";
    cout<<"\tNOOR FATIMA 22F-3634\n";
    cout<<"*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_";
}
