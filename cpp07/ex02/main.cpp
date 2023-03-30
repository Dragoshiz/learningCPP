#include "Array.hpp"

int	main()
{
	{
		std::cout << "Making a class of type char\n\n";
		Array<char> arr;
		try{
			std::cout << "Nothing in the char array\n" << arr[0] << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}

		usleep(90000);
		std::cout << "Trying to acces index out of bounds" << std::endl;
		try{
			std::cout << arr[1] << std::endl ;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		usleep(100000);
		std::cout << "Making a class of type char with elements inside and copying it to the old one\n\n";
		Array<char> arr2(10);
		arr = arr2;
		std::cout << "Trying again the same index as before\n";
		try{
			std::cout << "Nothing is displayed as it has a int 0" << arr[1];
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		usleep(10000);
		std::cout << "Displaying the elements from the second array\n";
		for (int i=0; i < arr2.size(); i++)
			std::cout << "Element number: " << i << arr2[i] << "\n";
		std::cout << std::endl;
	}
	{
		std::cout << "Making a class of type int\n\n";
		Array<int> arr;
		try{
			std::cout << "Nothing in the int array\n" << arr[0] << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		usleep(90000);
		std::cout << "Trying to acces index out of bounds" << std::endl;
		try{
			std::cout << arr[1] << std::endl ;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		usleep(100000);
		std::cout << "Making a class of type int with elements inside and copying it to the old one\n\n";
		Array<int> arr2(10);
		arr = arr2;
		std::cout << "Trying again the same index as before\n";
		try{
			std::cout << arr[1] << std::endl ;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		usleep(10000);
		std::cout << "Displaying the elements from the second array\n";
		for (int i=0; i < arr2.size(); i++)
			std::cout << "Element number: " << i << " " << arr2[i] << "\n";
		std::cout << std::endl;
	}
}