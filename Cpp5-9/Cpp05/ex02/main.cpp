#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(time(NULL));
    try{
        Bureaucrat sphynx("Sphynx", 70);
        RobotomyRequestForm form;

        form.beSigned(sphynx);
		sphynx.executeForm(form);
        // form.execute(sphynx);
    }
    catch(const std::exception& excep){
        std::cout << excep.what() << '\n';
    }
}