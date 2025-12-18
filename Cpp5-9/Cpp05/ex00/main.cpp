#include "Bureaucrat.hpp"

int main(){
	//---------------Clean------------------//
	{
		Bureaucrat Sphynx("Sphynx", 2);
		Sphynx.increment();
		std::cout << Sphynx << std::endl;
	}
	//---------------Default---------------//
	{
		try {
			Bureaucrat Skinny;
			std::cout << Skinny << std::endl;
			Skinny.decrement();// error ajmi
		}
		catch (std::exception &excep){
			std::cerr << excep.what() << std::endl;
		}
	}
	//--------------Parametrized--------------//
	{
		try{
			Bureaucrat sebban("moul_cyber", -1);//error ajmi
		}
		catch (std::exception &execp){
			std::cerr << execp.what() << std::endl;
		}
	}
}