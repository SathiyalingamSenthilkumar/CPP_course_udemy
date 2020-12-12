CPPFLAGS=-Wall -Werror -std=c++14

#Sources and include files
SOURCES= Movie.cpp Movies.cpp main.cpp
INCLUDES = -I./  # Should specify the directory of the header files

# Creating object file variable
OBJS = $(SOURCES:.cpp=.o)

PROGRAM=movies

$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp 
	g++ -c $(CPPFLAGS) $(INCLUDES)  $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~
