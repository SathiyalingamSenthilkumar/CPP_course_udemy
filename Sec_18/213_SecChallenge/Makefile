CPPFLAGS=-Wall -Werror -std=c++14

#Sources and include files
SOURCES= Account.cpp Savings_Account.cpp Account_Util.cpp \
	Checking_Account.cpp Trust_Account.cpp I_Printable.cpp \
	IllegalBalanceException.cpp  InsufficentFundsException.cpp \
	main.cpp
INCLUDES = -I./  # Should specify the directory of the header files

# Creating object file variable
OBJS = $(SOURCES:.cpp=.o)

PROGRAM= Acc

$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp 
	g++ -c $(CPPFLAGS) $(INCLUDES)  $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~
