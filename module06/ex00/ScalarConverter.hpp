#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <climits>
# include <float.h>
# include <cstdlib>

# define WHITE "\033[1;97m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;38;5;214m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

class ScalarConverter {
	public:
		ScalarConverter &operator=(ScalarConverter &rhs);

		~ScalarConverter();

		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);

};

#endif
