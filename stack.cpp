/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:05:53 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/10 00:15:22 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

//functions

stack::stack()
{
    std::cout << "Constructor Called" << std::endl;
    memory.reserve(1000000);
}

stack::~stack()
{
    std::cout << "Destructor called" << std::endl;
}

i32 stack::getType(i32 instruction)
{
    i32 type = 0xc0000000;
    type = (type & instruction) >> 30;
    return (type);
}

i32 stack::getData(i32 instruction)
{
    i32 data = 0x3fffffff;
    data = data & instruction;
    return (data);
}

void    stack::fech()
{
    pc++;
}

void    stack::decode()
{
    type = getType(memory[pc]);
    data = getData(memory[pc]);
}

void    stack::execute()
{
    if (type == 0 || type == 2)
    {
        sp++;
        memory[sp] = data;
    }
    else
    {
        doPrimitive();
    }
}

void    stack::doPrimitive()
{
    switch (data)
    {
        case 0:// halt
            std::cout << "halt" << std::endl;
            running = 0;
            break;
        case 1:// add
            std::cout << "add " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] + memory[sp];
            sp--;
            break;
        case 2:// sub
            std::cout << "sub " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] - memory[sp];
            sp--;
            break;
        case 3:// mul
            std::cout << "mul " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] * memory[sp];
            sp--;
            break;
        case 4:// div
            std::cout << "div " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] / memory[sp];
            sp--;
            break;
        case 5:// mod
            std::cout << "mod " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] % memory[sp];
            sp--;
            break;
    }
}

void    stack::run()
{
    pc -= 1;
    while (running == 1)
    {
        fech();
        decode();
        execute();
        std::cout << "tos: " << memory[sp] << std::endl;
    }
}

void    stack::loadProgram(std::vector<i32> program)
{
    for (i32 i = 0; i < program.size(); i++)
    {
        memory[pc + i] = program[i];
    }
}