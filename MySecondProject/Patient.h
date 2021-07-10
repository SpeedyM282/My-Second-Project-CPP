/*
Name: Akhadbek Rizakulov
ID: 2010227
Date: 11.05.2021
*/


/********* Patient Details Class *********/


#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient{
	public:
		Patient() : first_name("No Data"), last_name("No Data"), address("No Data"), email("No Data"), phone("No Data"), gender("No Data"), problem("No Data"), prescr_doctor("No Data") {}
			
		void set_firstName (std::string first_name){ 
			
			this->first_name = first_name;
		}
		
		void set_lastName (std::string last_name){
			
			this->last_name = last_name;
		}
		
		void set_address (std::string address){
			
			this->address = address;
		}
		
		void set_email (std::string email){
			
			this->email = email;
		}
		
		void set_phone (std::string phone){
			
			this->phone = phone;
		}
		
		void set_gender (std::string gender){
			
			this->gender = gender;
		}
		
		void set_problem (std::string problem){
			
			this->problem = problem;
		}
		
		void set_prescrDoctor (std::string prescr_doctor){
			
			this->prescr_doctor = prescr_doctor;
		}
		
		void set_idNum (std::string id_num){
			
			this->id_num = id_num;
		}
		
		void set_age (int age){
			
			this->age = age;
		}
		
		std::string get_firstName () const { return first_name; }
		
		std::string get_last_name () const { return last_name; }
		
		std::string get_address () const { return address; }
		
		std::string get_email () const { return email; }
		
		std::string get_phone () const { return phone; }
		
		std::string get_gender () const { return gender; }
		
		std::string get_problem () const { return problem; }
		
		std::string get_prescr_doctor () const { return prescr_doctor; }
		
		std::string get_id_num () const { return id_num; }
		
		int get_age () const { return age; }		
		
		std::string get_username () const { return username; }
		
		std::string get_password () const { return password; }
		
		~Patient(){}
		
	private:
		
		std::string id_num, first_name, last_name, address, email, phone, gender, problem, prescr_doctor;
		
		int age;
		
		const std::string username = "spiderman"; 
		const std::string password = "IamSpiderMan";
		
};



#endif














