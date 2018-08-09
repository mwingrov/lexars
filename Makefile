# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 21:32:57 by mwingrov          #+#    #+#              #
#    Updated: 2018/08/09 21:47:10 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -std=c++11

all: stack

stack: stack.o main.o
	$(CXX) $(CFLAGS) stack.o main.o -o stack

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

stack.o: stack.hpp stack.cpp
	$(CXX) $(CFLAGS) -c stack.cpp

clean:
	rm -f *.o stack