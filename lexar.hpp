/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexar.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 01:09:31 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/10 01:27:34 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXAR_HPP
# define LEXAR_HPP

# include <iostream>
# include <vector>
# include <string>

typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte
{
    START,
    READCHAR,
    READBLOK,
    SKIP,
    DUMP,
    COMMENT,
    END
};

class Lexar
{
    public:
        strings lex(std::string str);
    private:
        bool    my_isSpace(char c);
        bool    isSpecial(char c);
        bool    isGroupe(char c);
        char    beg_char, end_char;
};

#endif