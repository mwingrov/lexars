/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:57:49 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/20 04:12:55 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <fstream>
# include <vector>

typedef int32_t i32;

class stack
{
    ///public variables
    public:
        stack();
        void    run();
        void    loadProgram(std::vector<i32> program);
        ~stack();

    ////private variables
    private:
        i32 pc = 100;
        i32 sp = 0;
        std::vector<i32> memory;
        i32 type = 0;
        i32 data = 0;
        i32 running = 1;

        i32 getType(i32 instruction);
        i32 getData(i32 instruction);
        void    fech();
        void    decode();
        void    execute();
        void    doPrimitive();
};

#endif