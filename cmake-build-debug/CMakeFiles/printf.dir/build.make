# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mort/printffff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mort/printffff/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/printf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/printf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/printf.dir/flags.make

CMakeFiles/printf.dir/ft_printf.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/ft_printf.c.o: ../ft_printf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/printf.dir/ft_printf.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/ft_printf.c.o   -c /Users/mort/printffff/ft_printf.c

CMakeFiles/printf.dir/ft_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/ft_printf.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/ft_printf.c > CMakeFiles/printf.dir/ft_printf.c.i

CMakeFiles/printf.dir/ft_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/ft_printf.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/ft_printf.c -o CMakeFiles/printf.dir/ft_printf.c.s

CMakeFiles/printf.dir/parser.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/printf.dir/parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/parser.c.o   -c /Users/mort/printffff/parser.c

CMakeFiles/printf.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/parser.c > CMakeFiles/printf.dir/parser.c.i

CMakeFiles/printf.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/parser.c -o CMakeFiles/printf.dir/parser.c.s

CMakeFiles/printf.dir/print_di.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_di.c.o: ../print_di.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/printf.dir/print_di.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_di.c.o   -c /Users/mort/printffff/print_di.c

CMakeFiles/printf.dir/print_di.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_di.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_di.c > CMakeFiles/printf.dir/print_di.c.i

CMakeFiles/printf.dir/print_di.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_di.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_di.c -o CMakeFiles/printf.dir/print_di.c.s

CMakeFiles/printf.dir/help.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/help.c.o: ../help.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/printf.dir/help.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/help.c.o   -c /Users/mort/printffff/help.c

CMakeFiles/printf.dir/help.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/help.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/help.c > CMakeFiles/printf.dir/help.c.i

CMakeFiles/printf.dir/help.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/help.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/help.c -o CMakeFiles/printf.dir/help.c.s

CMakeFiles/printf.dir/itoa_base.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/itoa_base.c.o: ../itoa_base.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/printf.dir/itoa_base.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/itoa_base.c.o   -c /Users/mort/printffff/itoa_base.c

CMakeFiles/printf.dir/itoa_base.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/itoa_base.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/itoa_base.c > CMakeFiles/printf.dir/itoa_base.c.i

CMakeFiles/printf.dir/itoa_base.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/itoa_base.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/itoa_base.c -o CMakeFiles/printf.dir/itoa_base.c.s

CMakeFiles/printf.dir/print_bxou.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_bxou.c.o: ../print_bxou.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/printf.dir/print_bxou.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_bxou.c.o   -c /Users/mort/printffff/print_bxou.c

CMakeFiles/printf.dir/print_bxou.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_bxou.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_bxou.c > CMakeFiles/printf.dir/print_bxou.c.i

CMakeFiles/printf.dir/print_bxou.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_bxou.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_bxou.c -o CMakeFiles/printf.dir/print_bxou.c.s

CMakeFiles/printf.dir/print_aefg.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_aefg.c.o: ../print_aefg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/printf.dir/print_aefg.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_aefg.c.o   -c /Users/mort/printffff/print_aefg.c

CMakeFiles/printf.dir/print_aefg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_aefg.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_aefg.c > CMakeFiles/printf.dir/print_aefg.c.i

CMakeFiles/printf.dir/print_aefg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_aefg.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_aefg.c -o CMakeFiles/printf.dir/print_aefg.c.s

CMakeFiles/printf.dir/print_ae.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_ae.c.o: ../print_ae.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/printf.dir/print_ae.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_ae.c.o   -c /Users/mort/printffff/print_ae.c

CMakeFiles/printf.dir/print_ae.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_ae.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_ae.c > CMakeFiles/printf.dir/print_ae.c.i

CMakeFiles/printf.dir/print_ae.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_ae.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_ae.c -o CMakeFiles/printf.dir/print_ae.c.s

CMakeFiles/printf.dir/print_f.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_f.c.o: ../print_f.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/printf.dir/print_f.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_f.c.o   -c /Users/mort/printffff/print_f.c

CMakeFiles/printf.dir/print_f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_f.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_f.c > CMakeFiles/printf.dir/print_f.c.i

CMakeFiles/printf.dir/print_f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_f.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_f.c -o CMakeFiles/printf.dir/print_f.c.s

CMakeFiles/printf.dir/print_g.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_g.c.o: ../print_g.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/printf.dir/print_g.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_g.c.o   -c /Users/mort/printffff/print_g.c

CMakeFiles/printf.dir/print_g.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_g.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_g.c > CMakeFiles/printf.dir/print_g.c.i

CMakeFiles/printf.dir/print_g.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_g.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_g.c -o CMakeFiles/printf.dir/print_g.c.s

CMakeFiles/printf.dir/parser_spec.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/parser_spec.c.o: ../parser_spec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/printf.dir/parser_spec.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/parser_spec.c.o   -c /Users/mort/printffff/parser_spec.c

CMakeFiles/printf.dir/parser_spec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/parser_spec.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/parser_spec.c > CMakeFiles/printf.dir/parser_spec.c.i

CMakeFiles/printf.dir/parser_spec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/parser_spec.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/parser_spec.c -o CMakeFiles/printf.dir/parser_spec.c.s

CMakeFiles/printf.dir/help_float.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/help_float.c.o: ../help_float.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/printf.dir/help_float.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/help_float.c.o   -c /Users/mort/printffff/help_float.c

CMakeFiles/printf.dir/help_float.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/help_float.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/help_float.c > CMakeFiles/printf.dir/help_float.c.i

CMakeFiles/printf.dir/help_float.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/help_float.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/help_float.c -o CMakeFiles/printf.dir/help_float.c.s

CMakeFiles/printf.dir/print_c.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_c.c.o: ../print_c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/printf.dir/print_c.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_c.c.o   -c /Users/mort/printffff/print_c.c

CMakeFiles/printf.dir/print_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_c.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_c.c > CMakeFiles/printf.dir/print_c.c.i

CMakeFiles/printf.dir/print_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_c.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_c.c -o CMakeFiles/printf.dir/print_c.c.s

CMakeFiles/printf.dir/print_s.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_s.c.o: ../print_s.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/printf.dir/print_s.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_s.c.o   -c /Users/mort/printffff/print_s.c

CMakeFiles/printf.dir/print_s.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_s.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_s.c > CMakeFiles/printf.dir/print_s.c.i

CMakeFiles/printf.dir/print_s.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_s.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_s.c -o CMakeFiles/printf.dir/print_s.c.s

CMakeFiles/printf.dir/print_ws.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/print_ws.c.o: ../print_ws.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/printf.dir/print_ws.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/print_ws.c.o   -c /Users/mort/printffff/print_ws.c

CMakeFiles/printf.dir/print_ws.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/print_ws.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/print_ws.c > CMakeFiles/printf.dir/print_ws.c.i

CMakeFiles/printf.dir/print_ws.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/print_ws.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/print_ws.c -o CMakeFiles/printf.dir/print_ws.c.s

CMakeFiles/printf.dir/ws_help.c.o: CMakeFiles/printf.dir/flags.make
CMakeFiles/printf.dir/ws_help.c.o: ../ws_help.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/printf.dir/ws_help.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf.dir/ws_help.c.o   -c /Users/mort/printffff/ws_help.c

CMakeFiles/printf.dir/ws_help.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf.dir/ws_help.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mort/printffff/ws_help.c > CMakeFiles/printf.dir/ws_help.c.i

CMakeFiles/printf.dir/ws_help.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf.dir/ws_help.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mort/printffff/ws_help.c -o CMakeFiles/printf.dir/ws_help.c.s

# Object files for target printf
printf_OBJECTS = \
"CMakeFiles/printf.dir/ft_printf.c.o" \
"CMakeFiles/printf.dir/parser.c.o" \
"CMakeFiles/printf.dir/print_di.c.o" \
"CMakeFiles/printf.dir/help.c.o" \
"CMakeFiles/printf.dir/itoa_base.c.o" \
"CMakeFiles/printf.dir/print_bxou.c.o" \
"CMakeFiles/printf.dir/print_aefg.c.o" \
"CMakeFiles/printf.dir/print_ae.c.o" \
"CMakeFiles/printf.dir/print_f.c.o" \
"CMakeFiles/printf.dir/print_g.c.o" \
"CMakeFiles/printf.dir/parser_spec.c.o" \
"CMakeFiles/printf.dir/help_float.c.o" \
"CMakeFiles/printf.dir/print_c.c.o" \
"CMakeFiles/printf.dir/print_s.c.o" \
"CMakeFiles/printf.dir/print_ws.c.o" \
"CMakeFiles/printf.dir/ws_help.c.o"

# External object files for target printf
printf_EXTERNAL_OBJECTS =

libprintf.a: CMakeFiles/printf.dir/ft_printf.c.o
libprintf.a: CMakeFiles/printf.dir/parser.c.o
libprintf.a: CMakeFiles/printf.dir/print_di.c.o
libprintf.a: CMakeFiles/printf.dir/help.c.o
libprintf.a: CMakeFiles/printf.dir/itoa_base.c.o
libprintf.a: CMakeFiles/printf.dir/print_bxou.c.o
libprintf.a: CMakeFiles/printf.dir/print_aefg.c.o
libprintf.a: CMakeFiles/printf.dir/print_ae.c.o
libprintf.a: CMakeFiles/printf.dir/print_f.c.o
libprintf.a: CMakeFiles/printf.dir/print_g.c.o
libprintf.a: CMakeFiles/printf.dir/parser_spec.c.o
libprintf.a: CMakeFiles/printf.dir/help_float.c.o
libprintf.a: CMakeFiles/printf.dir/print_c.c.o
libprintf.a: CMakeFiles/printf.dir/print_s.c.o
libprintf.a: CMakeFiles/printf.dir/print_ws.c.o
libprintf.a: CMakeFiles/printf.dir/ws_help.c.o
libprintf.a: CMakeFiles/printf.dir/build.make
libprintf.a: CMakeFiles/printf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mort/printffff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking C static library libprintf.a"
	$(CMAKE_COMMAND) -P CMakeFiles/printf.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/printf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/printf.dir/build: libprintf.a

.PHONY : CMakeFiles/printf.dir/build

CMakeFiles/printf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/printf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/printf.dir/clean

CMakeFiles/printf.dir/depend:
	cd /Users/mort/printffff/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mort/printffff /Users/mort/printffff /Users/mort/printffff/cmake-build-debug /Users/mort/printffff/cmake-build-debug /Users/mort/printffff/cmake-build-debug/CMakeFiles/printf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/printf.dir/depend

