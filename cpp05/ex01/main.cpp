#include "Bureaucrat.hpp"

int main(){

	std::cout << "======== Correct grade ============" <<	std::endl;
	Bureaucrat bureau("Elvis", 5);
	Form	house("House form", 10, 1, false);
	bureau.signForm(house);

	std::cout << "======== Form already signed ============" <<	std::endl;
	Form car("car form", 10, 1, true);
	bureau.signForm(car);

	std::cout << "======== Bureau grade too low for form ============" <<	std::endl;
	Bureaucrat lowlvl("Kenny", 150);
	Form	field("Field form", 1, 1, false);
	lowlvl.signForm(field);
	std::cout << "======== Bureau instantiating too low/high grade ============" <<	std::endl;
	Bureaucrat toolow("Lowlife", 155);
	Bureaucrat tooHigh("HighLife", -5);
	std::cout << "======== Form instantiating too low/high grade ============" <<	std::endl;
	Form 	toolittle("", 200,200, false);
	Form 	toonotlittle("Little",-1, -2,false);
	return 0;
}
