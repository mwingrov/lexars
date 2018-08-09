/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexar.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 01:18:05 by mwingrov          #+#    #+#             */
/*   Updated: 2018/08/10 01:46:28 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexar.hpp"

strings Lexar::lex(std::string str)
{
    strings strlst;
    char    lexeme[256];
    int     i = 0;
    int     j = 0;
    State   state = START;
    int     done = 0;
    int     len = str.length();
    int     balance = 0;

    while (i < len)
    {
        switch(state)
        {
            case START:
                if (my_isSpace(str[i]))
                {
                    state = SKIP;
                }
                else if (isGroupe(str[i]))
                {
                    if (str[i] == '"')
                    {
                        lexeme[j] = str[i];
                        i++;
                        j++;
                    }
                    state = READBLOK;
                }
                else if (str[i] == '/' && str[i + 1] == '/')
                {
                    i += 2;
                    state = COMMENT;
                }
                else
                {
                    state = READCHAR;
                }
                break;
            case READCHAR:
                if (my_isSpace(str[i]))
                {
                    state = DUMP;
                }
                else if (str[i] == '\\')
                {
                    i += 2;
                }
                else if (isGroupe(str[i]))
                {
                    if (str[i] == '"')
                    {
                        lexeme[j] = str[i];
                        j++;
                        i++;
                    }
                    state = READBLOK;
                }
                else if (isSpecial(str[i]))
                {
                    if (j == 0)
                    {
                        lexeme[j] = str[i];
                        j++;
                        i++;
                    }
                    state = DUMP;
                }
                else if (str[i] == '/' && str[i + 1] == '/')
                {
                    i += 2;
                    state = COMMENT;
                }
                else
                {
                    lexeme[j] = str[i];
                    j++;
                    i++;
                }
                break;
            case READBLOK:
                if (str[i] == beg_char && str[i] != '"')
                {
                    balance++;
                    lexeme[j] = str[i];
                    j++;
                    i++;
                }
                else if (str[i] == end_char)
                {
                    balance--;
                    lexeme[j] = str[i];
                    j++;
                    i++;
                    if (balance <= 0)
                    {
                        state = DUMP;
                    }
                }
                else if (end_char == '"' && str[i] == '\\')
                    {
                        //fix to record the chars
                        i += 2;
                    }
                    else
                    {
                        lexeme[j] = str[i];
                        j++;
                        i++;
                    }
                break;
            case SKIP:
                if (my_isSpace(str[i]))
                {
                    i++;
                }
                else
                {
                    state = READCHAR;
                }
                break;
            case DUMP:
                if (j < 0)
                {
                    lexeme[j] = '\0';
                    strlst.push_back(lexeme);
                    j = 0;
                }
                state = START;
                break;
            case COMMENT:
                if (str[i] != '\n')
                {
                    i++;
                }
                else
                {
                    state = READCHAR;
                }
                break;
            case END:
                i = len;
                break;
        }
    }
    if (j > 0)
    {
        lexeme[j] = '\0';
        strlst.push_back(lexeme);
    }
    return (strlst);
}