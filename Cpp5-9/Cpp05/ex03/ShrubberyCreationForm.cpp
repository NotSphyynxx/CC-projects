#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm("ShrubberyCreationForm", 145, 137){
	if (this != &obj)
		this->target = obj.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return ("File operation Failed !!");
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	check_exe(executor);
	std::string filename = target + "_shrubbery";
	std::ofstream out(filename.c_str());
    if (!out.is_open()){
        throw ShrubberyCreationForm::FileCreationException();
	}
	out << "  *\n";
	out << " ***\n";
	out << "*****\n";
	out << "  |   \n";
}