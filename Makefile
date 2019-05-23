schema: main.cpp
	g++ main.cpp -g -Wall -Wextra -Wpedantic data.cpp address.cpp library.cpp -o main.exe && ./main.exe