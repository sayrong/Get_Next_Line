# Get_Next_Line

Function that return line from file descriptor.

Prototype
fd - file descriptor
line - pointer where to save line
```
 int get_next_line(const int fd, char **line);
 ```
 
 Support multiple file descirptors.
 Implemented without lseek, just with list structure and library libft.
 
 ## Compile 
 
 Compile with your main:
 
 First compile Library
 ```
 make -C libft/
 ```
 
 Then link together with main
 ```
 clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
 clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
 clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
 ```
