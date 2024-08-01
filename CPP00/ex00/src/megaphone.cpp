#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string str;
	int	i;
	int j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			j = 0;
			str = argv[i];
			while (argv[i][j])
			{
				str[j] = std::toupper(argv[i][j]);
				j++;
			}
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}