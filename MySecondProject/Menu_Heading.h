/*
Name: Akhadbek Rizakulov
ID: 2010227
Date: 11.05.2021
*/


/************* Menus Headings *************/


#include <iostream>
#include <iomanip>

#ifndef MENU_HEADING_H
#define MENU_HEADING_H

void login_menu(){

	std::cout << std::setfill('#') << std::setw(40) << "\n" << "\t\tLog-In Menu\n" << std::setfill('#') << std::setw(41) << "\n\n";	
}

void main_menu(){

	std::cout << "\n\n" << std::setfill('#') << std::setw(40) << "\n" << "\t\tMain Menu\n" << std::setfill('#') << std::setw(41) << "\n\n";	
}

void patient_set_menu(){
	
	std::cout << "\n\n" << std::setfill('#') << std::setw(40) << "\n" << "\tSet Patient Details\n" << std::setfill('#') << std::setw(41) << "\n\n";
}

void patient_details_menu(){
	
	std::cout << "\n\n" << std::setfill('#') << std::setw(40) << "\n" << "\tPatient Details\n" << std::setfill('#') << std::setw(41) << "\n\n";
}


void change_patinet_details_menu(){
	
	std::cout << "\n\n" << std::setfill('#') << std::setw(40) << "\n" << "\tChange Patient Details\n" << std::setfill('#') << std::setw(41) << "\n\n";
}

void delete_details_menu(){
	
	std::cout << "\n\n" << std::setfill('#') << std::setw(40) << "\n" << "\tDelete Patient Details\n" << std::setfill('#') << std::setw(41) << "\n\n";
}

void wrong_input(){
	
	std::cout << "\n\n" << std::setfill('-') << std::setw(56);
	std::cout << "\n\n\t  Wrong Input!\n\n";
	std::cout << std::setfill('-') << std::setw(40) << "\n\n";
}

void any_key(std::string key){
	
	std::cout << "\n\n  Enter any key to go to main menu: ";
	std::cin >> key;
}

#endif



















