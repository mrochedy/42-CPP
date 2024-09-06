/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:40:22 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 18:11:05 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replaceAllOccurences(std::string str, std::string s1, std::string s2)
{
	std::string replaced_str;
	std::string::size_type pos = 0;
	std::string::size_type s1_len = s1.length();

	while (true) {
		std::string::size_type next_occurence = str.find(s1, pos);
		if (next_occurence == std::string::npos) {
			replaced_str.append(str, pos, std::string::npos);
			break;
		}

		replaced_str.append(str, pos, next_occurence - pos);
		replaced_str.append(s2);
		pos = next_occurence + s1_len;
	}

	return replaced_str;
}

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::ifstream file1(argv[1]);
	if (!file1.is_open()) {
		std::cerr << "File " << argv[1] << " cannot be opened" << std::endl;
		return 1;
	}

	std::string file2_name;
	file2_name = std::string(argv[1]) + ".replace";
	std::ofstream file2(file2_name.c_str());
	if (!file2.is_open()) {
		std::cerr << "File copy cannot be created" << std::endl;
		file1.close();
		return 1;
	}

	std::string line;
	while (std::getline(file1, line))
		file2 << replaceAllOccurences(line, argv[2], argv[3]) << std::endl;

	file1.close();
	file2.close();
}
