/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:25:36 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/10 00:17:46 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

int main()
{
    stack   vm;
    std::vector<i32> prog
    {
        3, 4, 0x40000001, 5, 0x40000002, 3, 0x40000003, 2, 0x40000004, 0x40000000
    };

    vm.loadProgram(prog);
    vm.run();
    return (0);
}