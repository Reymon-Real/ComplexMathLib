c_files := src/c
asm_files := src/asm
bin_files := bin/execute
obj_files := bin/obj
gcc_execute := gcc -m64 -g3 -Wall -o
gcc_obj := gcc -m64 -g3 -c

all: object_asm_files object_c_files move_obj_files linker execute

object_c_files:
	@$(gcc_obj) $(c_files)/*.c

object_asm_files:
	@$(gcc_obj) $(asm_files)/*.s

move_obj_files:
	@move *.o $(obj_files)/
	@cls

linker:
	@$(gcc_execute) $(bin_files)/main.exe $(obj_files)/*.o

execute:
	@$(bin_files)/main.exe