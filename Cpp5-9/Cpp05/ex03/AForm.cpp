#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(0), gradeToSign(50), gradeToExec(20){}

AForm::AForm(const AForm& obj) : name(obj.name), is_signed(obj.is_signed), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec) {}

AForm& AForm::AForm::operator=(const AForm& obj){
	if (this != &obj)
		this->is_signed = obj.is_signed;
	return (*this);
}

AForm::~AForm(){}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec): name(name), is_signed(0) , gradeToSign(gradeToSign), gradeToExec(gradeToExec){
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

std::string AForm::getName() const {
	return (name);
}

bool	AForm::getIs_signed(){
	return (is_signed);
}

int AForm::getGradeToSign() const{
	return (gradeToSign);
}

int AForm::getGradeToExec() const{
	return (gradeToExec);
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("grade too High !!");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("grade too Low !!");
}

const char* AForm::FormNotSignedException::what() const throw(){
	return ("Form not signed to be executed !!");
}

void AForm::beSigned(Bureaucrat &obj){
	if (is_signed)
		return ;
	if (obj.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	else
		is_signed = 1;
}

std::ostream& operator<<(std::ostream &os, AForm &obj){
	os << "name --> " << obj.getName() << "\nis_signed --> " << (obj.getIs_signed() ? "yes" : "no")
	<< "\ngradeToSign --> " << obj.getGradeToSign() << "\ngradeToExec --> " << obj.getGradeToExec();
	return (os);
}

void AForm::check_exe(Bureaucrat const & executor) const {
	if (!this->is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExec)
		throw AForm::GradeTooLowException();
}
