# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 05:19:53 by mwingrov          #+#    #+#              #
#    Updated: 2018/08/20 05:22:23 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS=-std=c++11

all: sasm 

sasm: sasm.o lexar.o
	$(CXX) $(CFLAGS) sasm.o lexar.o -o $@

lexar.o: lexar.hpp lexar.cpp
	$(CXX) $(CFLAGS) -c lexar.cpp

sasm.o: lexar.hpp sasm.cpp
	$(CXX) $(CFLAGS) -c sasm.cpp

clean:
	rm -f sasm *.o *.bin