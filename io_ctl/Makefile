
SRC1:=open_flags.cpp
SRC2:=open_fd.cpp

all:open_file

open_file:open_flags open_fd
open_flags: ${SRC1}
		g++ -o open_flags ${SRC1}
open_fd: ${SRC2}
		g++ -o open_fd ${SRC2}
clean:
		rm open_flags open_fd
