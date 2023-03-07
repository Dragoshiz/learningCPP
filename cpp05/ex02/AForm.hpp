#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <fstream>

class Bureaucrat;

class AForm{
	public:
		AForm();
		AForm(AForm const &);
		virtual ~AForm();
		AForm(std::string, int, int, bool, std::string);
		AForm& operator=(AForm const &);
		std::string getName(void)const;
		std::string getTarget(void)const;
		int getGrade2sign(void)const;
		int getGrade2exec(void)const;
		bool isSigned(void)const;
		void setSigned(bool);
		void beSigned(Bureaucrat &);
		int setGrade2exec(int gradeExec);
		int setGrade2sign(int gradeSign);
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		std::string	_target;
};

std::ostream& operator<<(std::ostream&, AForm const &);
#endif

