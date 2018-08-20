/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:54:02 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/20 05:05:21 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "stack.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: " << av[0] << " <File> Invalid!" << std::endl;
        return (0);
    }

    std::ifstream   r(av[1], std::ios::binary);
    i32             i;
    std::vector<i32> prog;
    while (r.read((char *) &i, sizeof(i)))
    {
        prog.push_back(i);
    };

    stack   vm;
    vm.loadProgram(prog);
    vm.run();
    return (0);
}