#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	private:
	const std::string	name;
	bool				is_signed;
	const int		gradeToSign;
	const int		gradeToExec;

	public:
	Form();
	Form(const Form& obj);
	Form& operator=(const Form& obj);
	~Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExec);

	std::string	getName() const;
	bool		getIs_signed();
	int			getGradeToSign() const;
	int			getGradeToExec() const;

	void	beSigned(Bureaucrat &obj);

	class GradeTooHighException : public std::exception{
		public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, Form &obj);

#endif