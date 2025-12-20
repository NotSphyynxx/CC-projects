#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm("RobotomyRequestForm", 72, 45) {
	if (this != &obj)
		this->target = obj.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	check_exe(executor);
	std::cout << "DRRRRRRRRRR Some drilling noises......\n";
	if (std::rand() % 2 == 0)
		std::cout << target << "  has been robotomized\n";
	else
		std::cout << "The robotomy failed :(\n";
}