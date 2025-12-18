#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj){
	if (this != &obj)
		*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj){
	if (this != &obj)
		this->grade = grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string	Bureaucrat::getName(){
	return (name);
}

int Bureaucrat::getGrade(){
	return (grade);
}

void Bureaucrat::increment(){
	if (grade - 1 < 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrement(){
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too High !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too Low !!");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat &obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void	Bureaucrat::signForm(Form &form){
	try{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &excep){
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << excep.what() << std::endl;
	}
}