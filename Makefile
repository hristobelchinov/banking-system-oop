CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = bank_app

SOURCES = main.cpp \
          src/Account.cpp \
          src/Bank.cpp \
          src/CheckingAccount.cpp \
          src/Client.cpp \
          src/SavingsAccount.cpp \
          src/Transaction.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)