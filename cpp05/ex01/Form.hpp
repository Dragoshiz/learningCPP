#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <stdexcept>

class Bureaucrat;

class Form{
	public:
		Form();
		Form(Form const &);
		~Form();
		Form(std::string, int, int, bool);
		Form& operator=(Form const &);
		std::string getName(void)const;
		int getGrade2sign(void)const;
		int getGrade2exec(void)const;
		bool isSigned(void)const;
		void beSigned(Bureaucrat &);
		int setGrade2exec(int gradeExec);
		int setGrade2sing(int gradeSign);
		class GradeTooHighException: public std::exception{
			public:
				const char* what()const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what()const throw();
		};
	private:
		const std::string _name;
		const int _grade2sign;
		const int _grade2exec;
		bool _is_signed;
};

std::ostream& operator<<(std::ostream&, Form const &);
#endif

