
SRC1:=open_flags.cpp
SRC2:=open_fd.cpp

all:display_macro_bit open_fd
display_macro_bit: ${SRC1}
		g++ -o display_macro_bit ${SRC1}
open_fd: ${SRC2}
		g++ -o open_fd ${SRC2}
clean:
		rm display_macro_bit open_fd
