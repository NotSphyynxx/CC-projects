#include "Form.hpp"

Form::Form() : name("Default"), is_signed(0), gradeToSign(50), gradeToExec(20){}

Form::Form(const Form& obj) : name(obj.name), is_signed(obj.is_signed), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec) {}

Form& Form::Form::operator=(const Form& obj){
	if (this != &obj)
		this->is_signed = obj.is_signed;
	return (*this);
}

Form::~Form(){}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec): name(name), is_signed(0) , gradeToSign(gradeToSign), gradeToExec(gradeToExec){
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
}

std::string Form::getName() const {
	return (name);
}

bool	Form::getIs_signed(){
	return (is_signed);
}

int Form::getGradeToSign() const{
	return (gradeToSign);
}

int Form::getGradeToExec() const{
	return (gradeToExec);
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("grade too High !!");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("grade too Low !!");
}

void Form::beSigned(Bureaucrat &obj){
	if (is_signed)
		return ;
	if (obj.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	else
		is_signed = 1;
}

std::ostream& operator<<(std::ostream &os, Form &obj){
	os << "name --> " << obj.getName() << "\nis_signed --> " << (obj.getIs_signed() ? "yes" : "no")
	<< "\ngradeToSign --> " << obj.getGradeToSign() << "\ngradeToExec --> " << obj.getGradeToExec();
	return (os);
}