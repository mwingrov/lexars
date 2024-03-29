# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 05:08:10 by mwingrov          #+#    #+#              #
#    Updated: 2018/08/20 05:08:12 by mwingrov         ###   ########.fr        #
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