#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
	private:
	const std::string	name;
	bool				is_signed;
	const int		gradeToSign;
	const int		gradeToExec;

	protected:
	void check_exe(Bureaucrat const & executor) const;

	public:
	AForm();
	AForm(const AForm& obj);
	AForm& operator=(const AForm& obj);
	virtual ~AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExec);

	std::string	getName() const;
	bool		getIs_signed();
	int			getGradeToSign() const;
	int			getGradeToExec() const;

	void			beSigned(Bureaucrat &obj);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception{
		public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception{
		public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, AForm &obj);

#endif