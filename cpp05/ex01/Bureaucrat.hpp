#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &);
		Bureaucrat(std::string);
		Bureaucrat(std::string, int);
		~Bureaucrat();
		Bureaucrat& operator=(Bureaucrat const &);
		std::string getName(void)const;
		int		getGrade(void)const;
		void	increment(void);
		void	decrement(void);
		int		setGrade(int);
		void	signForm(Form &);
		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};
	private:
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& obj);

#endif
