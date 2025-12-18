#include "Bureaucrat.hpp"

int main(){
	//-------------Creating bureaucrats--------------//
	Bureaucrat Sphynx("Sphynx", 15);
	Bureaucrat Bak_Sahbi("sebban", 1);
	Bureaucrat mol_taxi("tl3i", 100);
	//------------Creating Forms--------------------//
	Form certificate1("3a9d zdiyad 1", 10, 5);
	Form certificate2("3a9d zdiyad 2", 10, 5);
	Form certificate3("3a9d zdiyad 3", 10, 5);
	//------------Signing Forms--------------------//
	Sphynx.signForm(certificate1);
	Bak_Sahbi.signForm(certificate2);
	mol_taxi.signForm(certificate3);
}