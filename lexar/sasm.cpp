/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 19:16:11 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/20 05:22:02 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.hpp"
#include "lexar.hpp"

i32     mapToNumber(std::string s);
std::vector<i32>    compileToInstructions(strings s);
bool    isInteger(std::string s);

int     main(int ac, char **av)
{
    std::string     line;
    std::string     content;
    std::ifstream   myfile;
    Lexar           lexar;
    if (ac != 2)
        {
            std::cout << av[0] << " has NO arguments!!" <<std::endl;
            exit(1);
        }

        myfile.open(av[1]);
        if (!myfile.is_open())
        {
            std::cout << "Error: could not open [" << av[1] << "]" << std::endl;
            exit(1);
        }

        while (getline(myfile, line))
        {
            content += line + "\n";
            std::cout << line << std::endl;
        }
        myfile.close();
        strings lexemes = lexar.lex(content);
        std::vector<i32> instructions = compileToInstructions(lexemes);

        // write to binary file
        std::ofstream ofile;
        ofile.open("out.bin", std::ios::binary);
        for (i32 i = 0; i < instructions.size(); i++) {
            ofile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
        }
        ofile.close();
        return (0);
}

std::vector<i32>    compileToInstructions(strings s)
{
    std::vector<i32> instructions;
    for (i32 i = 0; i< s.size(); i++)
    {
        if (isInteger(s[i]))
        {
           instructions.push_back(stoi(s[i])); 
        }
        else
        {
            i32 instruction = mapToNumber(s[i]);
            if (instruction != -1)
            {
                instructions.push_back(instruction);
            }
            else
            {
                std::cout << "Error: Invalid Instruction! [" << s[i] << "]" <<std::endl;
            }
        }
    }
    instructions.push_back(0x40000000);
    return (instructions);
}

bool isInteger(std::string s) {
	for (i32 i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}
i32 mapToNumber(std::string s) {
	if (s == "+") {
		return 0x40000001;
	} else if (s == "-") {
		return 0x40000002;
	} else if (s == "*") {
		return 0x40000003;
	} else if (s == "/") {
		return 0x40000004;
	}
	return -1; // invalid instruction
}