#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat Sphynx("Sphynx", 136);
    Intern Stagaire;
    AForm* form = NULL;
    try{
        form = Stagaire.makeForm("Shrubbery creation", "Sphynx");
        if (!form)
            return 1;
        form->beSigned(Sphynx);
        Sphynx.executeForm(*form);
    }
    catch(std::exception& excep){
        std::cout << excep.what() << "\n";
    }
    if (form)
        delete form;
}