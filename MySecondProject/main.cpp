/*
Name: Akhadbek Rizakulov
ID: 2010227
Date: 11.05.2021
*/


/********** Main File **********/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Patient.h"
#include "Menu_Heading.h"


int main(){
	
	Patient patient1;
	
	std::fstream new_file;
	
	std::string username = patient1.get_username();
	std::string password = patient1.get_password();
	
	std::string username1 = "";
	std::string password1 = "";
	
	std::string key, id_num, first_name, last_name, address, email, phone, gender, problem, prescr_doctor;
	int command, age;
	
/*************** For Loop To For Log-In Menu ****************/
	
	for(;;){
		
		login_menu();
		
		std::cout << "\tUsername: ";
		std::cin >> username1;
		std::cout << "\n\tPassword: ";
		std::cin >> password1;
		
/*********** Condition To check wether the inputted username and password are correct ************/		
		
		if (username1 != username && password1 != password){
			
			wrong_input();
			
			std::cout << "\n\n  Enter any key to go to log-in menu: ";
			std::cin >> key; std::cout << "\n\n";
		}
		else{
			
/********* If username and password are correct ***********/			
			
			for(;;){				
				
				main_menu();
/********* Main menu items ********/				
				std::cout << "  1. Add Patient\n\n";
				std::cout << "  2. Show Patients Details\n\n";
				std::cout << "  3. Delete Patient\n\n";
				std::cout << "  0. Exit\n\n\n";
				std::cout << "  Enter command (0-4): ";
				std::cin >> command;
				
				switch (command){
					
					case 1:{
						
						patient_set_menu();
/********** Creating .txt file for collecting data (File handling)**********/						
						new_file.open("Patient.txt", std::ios::in);
						
						std::cout << "\n  First Name: "; std::cin >> first_name;
						new_file >> first_name;
						
						std::cout << "\n  Last Name: "; std::cin >> last_name;
						new_file >> last_name;
						
						std::cout << "\n  Gender [F/M]: "; std::cin >> gender;
						new_file >> gender;
						
						std::cout << "\n  Age: "; std::cin >> age; std::cin.ignore();
						new_file >> age;
						
						std::cout << "\n  Address: "; std::getline(std::cin, address);
						new_file >> address;
						
						std::cout << "\n  Contact no: "; std::cin >> phone;
						new_file >> phone;
						
						std::cout << "\n  Email: "; std::cin >> email; std::cin.ignore();
						new_file >> email;
						
						std::cout << "\n  Problem: "; std::getline(std::cin, problem);
						new_file >> problem;
						
						std::cout << "\n  ID Number: "; std::cin >> id_num; std::cin.ignore();
						new_file >> id_num;
						
						std::cout << "\n  Prescribed Doctor: "; std::getline(std::cin, prescr_doctor);
						new_file >> prescr_doctor;
						
						any_key(key);	
/*************** Setting data to patient class member data **************/							
						patient1.set_firstName(first_name);
						patient1.set_lastName(last_name);
						patient1.set_idNum(id_num);
						patient1.set_gender(gender);
						patient1.set_age(age);
						patient1.set_address(address);
						patient1.set_phone(phone);
						patient1.set_email(email);
						patient1.set_problem(problem);
						patient1.set_prescrDoctor(prescr_doctor);
						
						new_file.close();
						break;
					}
					
					case 2:{
						
						if(first_name != ""){
							
						patient_details_menu();
/************* Opening .txt file to output the data in it *************/						
						new_file.open("Patient.txt", std::ios::out);
						
						std::cout << "\n  First Name: " << patient1.get_firstName() << "\n\n";
						new_file << "First Name: " << first_name << "\n";
						
						std::cout << "  Last Name: " << patient1.get_last_name() << "\n\n";
						new_file << "Last Name: " << last_name << "\n";
						
						std::cout << "  ID Number: " << patient1.get_id_num() << "\n\n";
						new_file << "ID Number: " << id_num << "\n";
						
						std::cout << "  Gender [F/M]: " << patient1.get_gender() << "\n\n";
						new_file << "Gender: " << gender << "\n";
						
						std::cout << "  Age: " << patient1.get_age() << "\n\n";
						new_file << "Age: " << age << "\n";
						
						std::cout << "  Address: " << patient1.get_address() << "\n\n";
						new_file << "Address: " << address << "\n";
						
						std::cout << "  Contact no: " << patient1.get_phone() << "\n\n";
						new_file << "Contact no: " << phone << "\n";
						
						std::cout << "  Email: " << patient1.get_email() << "\n\n";
						new_file << "Email: " << email << "\n";
						
						std::cout << "  Problem: " << patient1.get_problem() << "\n\n";
						new_file << "Problem: " << problem << "\n";
						
						std::cout << "  Prescribed Doctor: " << patient1.get_prescr_doctor() << "\n\n";
						new_file << "Prescribed Doctor: " << prescr_doctor << "\n";
						
						new_file.close();
						
						any_key(key);
				
						}else{
							std::cout << "\n\n" << std::setfill('-') << std::setw(56);
							std::cout << "\n\n\t  No Data Found\n\n";
							std::cout << std::setfill('-') << std::setw(40) << "\n\n";
							
							any_key(key);
						}
						break;
					}
					
					case 3:{
						
						std::string line, id;
						
						char choice;
						
						delete_details_menu();
/************** Delete Patinet Details Menu Items **************/						
						std::cout << "\n  Enter ID of patient: ";
						std::cin >> id;
						
						std::cout << "\n  Do you really want to delete patient? (Y/N): ";
						std::cin >> choice;
						
						if(choice == 'Y'){
							std::ifstream myfile;
							std::ofstream outfile;
							
							myfile.open("Patient.txt");
							outfile.open("Patient.txt");
							
							while (!myfile.eof()) {
								myfile >> line;	
								if(line == id_num){
									if(line == ";")
									std::cout << myfile.eof() << "\n";
									break;
								}
							}
							
							std::cout << "\n  The patient with ID " << id << " has been deleted if it exsisted" << "\n";
							
							any_key(key);
							
							myfile.close();
							outfile.close();
							
						}
						else if (choice == 'N'){
							
							any_key(key);
							
						}
						else{
							
							std::cout << "\nWrong input!\n";
						}
						
						break;
					}
					
					case 0:{
						
						std::cout << "\n\n" << std::setfill('-') << std::setw(52);
						std::cout << "\n\n\t\tGoodbye!\n\n";
						std::cout << std::setfill('-') << std::setw(40) << "\n\n";
						exit(0);
						break;
					}
					
					default:{
						
						wrong_input();
						
						any_key(key);
						
						break;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}













