complex_c_files := src/ComplexMathLib/c
complex_asm_files := src/ComplexMathLib/asm
main_c_files := src/main
main_asm_files := src/main
header_files := header
bin_files := bin/execute
obj_files := bin/obj
gcc_execute := gcc -m64 -g3 -Wall -I $(header_files) -o
gcc_obj := gcc -m64 -g3 -I $(header_files) -c

all: general_object move_obj_files linker execute

general_object: object_complex_asm_files object_complex_c_files obect_main_c_files

object_complex_c_files:
	@$(gcc_obj) $(complex_c_files)/*.c

object_complex_asm_files:
	@$(gcc_obj) $(complex_asm_files)/*.s

obect_main_c_files:
	@$(gcc_obj) $(main_c_files)/*.c

move_obj_files:
	@move *.o $(obj_files)/
	@cls

linker:
	@$(gcc_execute) $(bin_files)/main.exe $(obj_files)/*.o

execute:
	@$(bin_files)/main.exe