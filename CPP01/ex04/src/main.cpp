#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	
	if (argc != 4) {
		std::cerr << "Error : wrong arguments." << std::endl 
		<< "Try with : ./file_replace <filename> <string_to_replace> <substitution_string>" << std::endl;
		return (1);
	}

	std::string infile_name = argv[1];
	//le constructeur de std::ifstream prend un nom de fichier en tant qu'argument de type const char* et non std::string.
	//Si on a un std::string contenant le nom du fichier, on utilise la méthode c_str() pour le convertir en const char*.
	std::ifstream infile(infile_name.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error : failed to open file.";
		return (1);
	}

	std::string outfile_name = "file.replace";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error : failed to open file.";
		return (1);
	}

	std::string string_to_replace = argv[2];
	std::string substitution_string = argv[3];
	std::string line;
	std::string new_line;
	std::size_t pos;
	std::size_t begin;
	while (std::getline(infile, line)) {
		pos = 0;
		begin = 0;
		new_line = "";
		if ((pos = line.find(string_to_replace, pos)) != std::string::npos) {
			while ((pos = line.find(string_to_replace, pos)) != std::string::npos) {
				new_line.append(line, begin, pos - begin);
				new_line.append(substitution_string);
				pos += string_to_replace.length();
				begin = pos;
			}
			new_line.append(line, begin, line.length() - begin);
			outfile << new_line << std::endl;
		}
		else
			outfile << line << std::endl;
	}

	infile.close();
	outfile.close();
	return (0);
}