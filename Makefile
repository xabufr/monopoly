# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/Programmation/monopoly

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/Programmation/monopoly

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thomas/Programmation/monopoly/CMakeFiles /home/thomas/Programmation/monopoly/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thomas/Programmation/monopoly/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named monopoly

# Build rule for target.
monopoly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 monopoly
.PHONY : monopoly

# fast build rule for target.
monopoly/fast:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/build
.PHONY : monopoly/fast

# target to build an object file
src/core/consolelogger.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/consolelogger.o
.PHONY : src/core/consolelogger.o

# target to preprocess a source file
src/core/consolelogger.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/consolelogger.i
.PHONY : src/core/consolelogger.i

# target to generate assembly for a file
src/core/consolelogger.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/consolelogger.s
.PHONY : src/core/consolelogger.s

# target to build an object file
src/core/conversion.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/conversion.o
.PHONY : src/core/conversion.o

# target to preprocess a source file
src/core/conversion.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/conversion.i
.PHONY : src/core/conversion.i

# target to generate assembly for a file
src/core/conversion.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/conversion.s
.PHONY : src/core/conversion.s

# target to build an object file
src/core/exception.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/exception.o
.PHONY : src/core/exception.o

# target to preprocess a source file
src/core/exception.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/exception.i
.PHONY : src/core/exception.i

# target to generate assembly for a file
src/core/exception.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/exception.s
.PHONY : src/core/exception.s

# target to build an object file
src/core/filelogger.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/filelogger.o
.PHONY : src/core/filelogger.o

# target to preprocess a source file
src/core/filelogger.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/filelogger.i
.PHONY : src/core/filelogger.i

# target to generate assembly for a file
src/core/filelogger.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/filelogger.s
.PHONY : src/core/filelogger.s

# target to build an object file
src/core/logger.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/logger.o
.PHONY : src/core/logger.o

# target to preprocess a source file
src/core/logger.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/logger.i
.PHONY : src/core/logger.i

# target to generate assembly for a file
src/core/logger.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/logger.s
.PHONY : src/core/logger.s

# target to build an object file
src/core/random.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/random.o
.PHONY : src/core/random.o

# target to preprocess a source file
src/core/random.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/random.i
.PHONY : src/core/random.i

# target to generate assembly for a file
src/core/random.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/random.s
.PHONY : src/core/random.s

# target to build an object file
src/core/singleton.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/singleton.o
.PHONY : src/core/singleton.o

# target to preprocess a source file
src/core/singleton.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/singleton.i
.PHONY : src/core/singleton.i

# target to generate assembly for a file
src/core/singleton.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/singleton.s
.PHONY : src/core/singleton.s

# target to build an object file
src/core/trigo.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/trigo.o
.PHONY : src/core/trigo.o

# target to preprocess a source file
src/core/trigo.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/trigo.i
.PHONY : src/core/trigo.i

# target to generate assembly for a file
src/core/trigo.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/core/trigo.s
.PHONY : src/core/trigo.s

# target to build an object file
src/game/carte/carte.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/carte.o
.PHONY : src/game/carte/carte.o

# target to preprocess a source file
src/game/carte/carte.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/carte.i
.PHONY : src/game/carte/carte.i

# target to generate assembly for a file
src/game/carte/carte.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/carte.s
.PHONY : src/game/carte/carte.s

# target to build an object file
src/game/carte/paquet.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/paquet.o
.PHONY : src/game/carte/paquet.o

# target to preprocess a source file
src/game/carte/paquet.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/paquet.i
.PHONY : src/game/carte/paquet.i

# target to generate assembly for a file
src/game/carte/paquet.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/carte/paquet.s
.PHONY : src/game/carte/paquet.s

# target to build an object file
src/game/case/case.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/case/case.o
.PHONY : src/game/case/case.o

# target to preprocess a source file
src/game/case/case.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/case/case.i
.PHONY : src/game/case/case.i

# target to generate assembly for a file
src/game/case/case.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/case/case.s
.PHONY : src/game/case/case.s

# target to build an object file
src/game/des.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/des.o
.PHONY : src/game/des.o

# target to preprocess a source file
src/game/des.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/des.i
.PHONY : src/game/des.i

# target to generate assembly for a file
src/game/des.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/des.s
.PHONY : src/game/des.s

# target to build an object file
src/game/joueur.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/joueur.o
.PHONY : src/game/joueur.o

# target to preprocess a source file
src/game/joueur.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/joueur.i
.PHONY : src/game/joueur.i

# target to generate assembly for a file
src/game/joueur.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/game/joueur.s
.PHONY : src/game/joueur.s

# target to build an object file
src/graphics/cameramanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/cameramanager.o
.PHONY : src/graphics/cameramanager.o

# target to preprocess a source file
src/graphics/cameramanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/cameramanager.i
.PHONY : src/graphics/cameramanager.i

# target to generate assembly for a file
src/graphics/cameramanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/cameramanager.s
.PHONY : src/graphics/cameramanager.s

# target to build an object file
src/graphics/graphicalengine.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/graphicalengine.o
.PHONY : src/graphics/graphicalengine.o

# target to preprocess a source file
src/graphics/graphicalengine.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/graphicalengine.i
.PHONY : src/graphics/graphicalengine.i

# target to generate assembly for a file
src/graphics/graphicalengine.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/graphicalengine.s
.PHONY : src/graphics/graphicalengine.s

# target to build an object file
src/graphics/gui/fontmanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/fontmanager.o
.PHONY : src/graphics/gui/fontmanager.o

# target to preprocess a source file
src/graphics/gui/fontmanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/fontmanager.i
.PHONY : src/graphics/gui/fontmanager.i

# target to generate assembly for a file
src/graphics/gui/fontmanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/fontmanager.s
.PHONY : src/graphics/gui/fontmanager.s

# target to build an object file
src/graphics/gui/guibuttonitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guibuttonitem.o
.PHONY : src/graphics/gui/guibuttonitem.o

# target to preprocess a source file
src/graphics/gui/guibuttonitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guibuttonitem.i
.PHONY : src/graphics/gui/guibuttonitem.i

# target to generate assembly for a file
src/graphics/gui/guibuttonitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guibuttonitem.s
.PHONY : src/graphics/gui/guibuttonitem.s

# target to build an object file
src/graphics/gui/guicolorselector.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicolorselector.o
.PHONY : src/graphics/gui/guicolorselector.o

# target to preprocess a source file
src/graphics/gui/guicolorselector.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicolorselector.i
.PHONY : src/graphics/gui/guicolorselector.i

# target to generate assembly for a file
src/graphics/gui/guicolorselector.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicolorselector.s
.PHONY : src/graphics/gui/guicolorselector.s

# target to build an object file
src/graphics/gui/guicontener.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicontener.o
.PHONY : src/graphics/gui/guicontener.o

# target to preprocess a source file
src/graphics/gui/guicontener.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicontener.i
.PHONY : src/graphics/gui/guicontener.i

# target to generate assembly for a file
src/graphics/gui/guicontener.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guicontener.s
.PHONY : src/graphics/gui/guicontener.s

# target to build an object file
src/graphics/gui/guielement.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guielement.o
.PHONY : src/graphics/gui/guielement.o

# target to preprocess a source file
src/graphics/gui/guielement.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guielement.i
.PHONY : src/graphics/gui/guielement.i

# target to generate assembly for a file
src/graphics/gui/guielement.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guielement.s
.PHONY : src/graphics/gui/guielement.s

# target to build an object file
src/graphics/gui/guiitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiitem.o
.PHONY : src/graphics/gui/guiitem.o

# target to preprocess a source file
src/graphics/gui/guiitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiitem.i
.PHONY : src/graphics/gui/guiitem.i

# target to generate assembly for a file
src/graphics/gui/guiitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiitem.s
.PHONY : src/graphics/gui/guiitem.s

# target to build an object file
src/graphics/gui/guimanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guimanager.o
.PHONY : src/graphics/gui/guimanager.o

# target to preprocess a source file
src/graphics/gui/guimanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guimanager.i
.PHONY : src/graphics/gui/guimanager.i

# target to generate assembly for a file
src/graphics/gui/guimanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guimanager.s
.PHONY : src/graphics/gui/guimanager.s

# target to build an object file
src/graphics/gui/guinode.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guinode.o
.PHONY : src/graphics/gui/guinode.o

# target to preprocess a source file
src/graphics/gui/guinode.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guinode.i
.PHONY : src/graphics/gui/guinode.i

# target to generate assembly for a file
src/graphics/gui/guinode.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guinode.s
.PHONY : src/graphics/gui/guinode.s

# target to build an object file
src/graphics/gui/guiprogressbaritem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiprogressbaritem.o
.PHONY : src/graphics/gui/guiprogressbaritem.o

# target to preprocess a source file
src/graphics/gui/guiprogressbaritem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiprogressbaritem.i
.PHONY : src/graphics/gui/guiprogressbaritem.i

# target to generate assembly for a file
src/graphics/gui/guiprogressbaritem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiprogressbaritem.s
.PHONY : src/graphics/gui/guiprogressbaritem.s

# target to build an object file
src/graphics/gui/guirectangleitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guirectangleitem.o
.PHONY : src/graphics/gui/guirectangleitem.o

# target to preprocess a source file
src/graphics/gui/guirectangleitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guirectangleitem.i
.PHONY : src/graphics/gui/guirectangleitem.i

# target to generate assembly for a file
src/graphics/gui/guirectangleitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guirectangleitem.s
.PHONY : src/graphics/gui/guirectangleitem.s

# target to build an object file
src/graphics/gui/guislidernumberitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guislidernumberitem.o
.PHONY : src/graphics/gui/guislidernumberitem.o

# target to preprocess a source file
src/graphics/gui/guislidernumberitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guislidernumberitem.i
.PHONY : src/graphics/gui/guislidernumberitem.i

# target to generate assembly for a file
src/graphics/gui/guislidernumberitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guislidernumberitem.s
.PHONY : src/graphics/gui/guislidernumberitem.s

# target to build an object file
src/graphics/gui/guitextinputitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextinputitem.o
.PHONY : src/graphics/gui/guitextinputitem.o

# target to preprocess a source file
src/graphics/gui/guitextinputitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextinputitem.i
.PHONY : src/graphics/gui/guitextinputitem.i

# target to generate assembly for a file
src/graphics/gui/guitextinputitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextinputitem.s
.PHONY : src/graphics/gui/guitextinputitem.s

# target to build an object file
src/graphics/gui/guitextitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextitem.o
.PHONY : src/graphics/gui/guitextitem.o

# target to preprocess a source file
src/graphics/gui/guitextitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextitem.i
.PHONY : src/graphics/gui/guitextitem.i

# target to generate assembly for a file
src/graphics/gui/guitextitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guitextitem.s
.PHONY : src/graphics/gui/guitextitem.s

# target to build an object file
src/graphics/gui/guiwindowcontener.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindowcontener.o
.PHONY : src/graphics/gui/guiwindowcontener.o

# target to preprocess a source file
src/graphics/gui/guiwindowcontener.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindowcontener.i
.PHONY : src/graphics/gui/guiwindowcontener.i

# target to generate assembly for a file
src/graphics/gui/guiwindowcontener.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindowcontener.s
.PHONY : src/graphics/gui/guiwindowcontener.s

# target to build an object file
src/graphics/gui/guiwindownode.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindownode.o
.PHONY : src/graphics/gui/guiwindownode.o

# target to preprocess a source file
src/graphics/gui/guiwindownode.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindownode.i
.PHONY : src/graphics/gui/guiwindownode.i

# target to generate assembly for a file
src/graphics/gui/guiwindownode.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/gui/guiwindownode.s
.PHONY : src/graphics/gui/guiwindownode.s

# target to build an object file
src/graphics/particlemanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/particlemanager.o
.PHONY : src/graphics/particlemanager.o

# target to preprocess a source file
src/graphics/particlemanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/particlemanager.i
.PHONY : src/graphics/particlemanager.i

# target to generate assembly for a file
src/graphics/particlemanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/particlemanager.s
.PHONY : src/graphics/particlemanager.s

# target to build an object file
src/graphics/scenemanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenemanager.o
.PHONY : src/graphics/scenemanager.o

# target to preprocess a source file
src/graphics/scenemanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenemanager.i
.PHONY : src/graphics/scenemanager.i

# target to generate assembly for a file
src/graphics/scenemanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenemanager.s
.PHONY : src/graphics/scenemanager.s

# target to build an object file
src/graphics/scenenode.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenode.o
.PHONY : src/graphics/scenenode.o

# target to preprocess a source file
src/graphics/scenenode.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenode.i
.PHONY : src/graphics/scenenode.i

# target to generate assembly for a file
src/graphics/scenenode.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenode.s
.PHONY : src/graphics/scenenode.s

# target to build an object file
src/graphics/scenenodecircleshapeitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodecircleshapeitem.o
.PHONY : src/graphics/scenenodecircleshapeitem.o

# target to preprocess a source file
src/graphics/scenenodecircleshapeitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodecircleshapeitem.i
.PHONY : src/graphics/scenenodecircleshapeitem.i

# target to generate assembly for a file
src/graphics/scenenodecircleshapeitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodecircleshapeitem.s
.PHONY : src/graphics/scenenodecircleshapeitem.s

# target to build an object file
src/graphics/scenenodeitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeitem.o
.PHONY : src/graphics/scenenodeitem.o

# target to preprocess a source file
src/graphics/scenenodeitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeitem.i
.PHONY : src/graphics/scenenodeitem.i

# target to generate assembly for a file
src/graphics/scenenodeitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeitem.s
.PHONY : src/graphics/scenenodeitem.s

# target to build an object file
src/graphics/scenenodeshapeitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeshapeitem.o
.PHONY : src/graphics/scenenodeshapeitem.o

# target to preprocess a source file
src/graphics/scenenodeshapeitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeshapeitem.i
.PHONY : src/graphics/scenenodeshapeitem.i

# target to generate assembly for a file
src/graphics/scenenodeshapeitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodeshapeitem.s
.PHONY : src/graphics/scenenodeshapeitem.s

# target to build an object file
src/graphics/scenenodespriteitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodespriteitem.o
.PHONY : src/graphics/scenenodespriteitem.o

# target to preprocess a source file
src/graphics/scenenodespriteitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodespriteitem.i
.PHONY : src/graphics/scenenodespriteitem.i

# target to generate assembly for a file
src/graphics/scenenodespriteitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodespriteitem.s
.PHONY : src/graphics/scenenodespriteitem.s

# target to build an object file
src/graphics/scenenodetextureitem.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodetextureitem.o
.PHONY : src/graphics/scenenodetextureitem.o

# target to preprocess a source file
src/graphics/scenenodetextureitem.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodetextureitem.i
.PHONY : src/graphics/scenenodetextureitem.i

# target to generate assembly for a file
src/graphics/scenenodetextureitem.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/scenenodetextureitem.s
.PHONY : src/graphics/scenenodetextureitem.s

# target to build an object file
src/graphics/texturemanager.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/texturemanager.o
.PHONY : src/graphics/texturemanager.o

# target to preprocess a source file
src/graphics/texturemanager.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/texturemanager.i
.PHONY : src/graphics/texturemanager.i

# target to generate assembly for a file
src/graphics/texturemanager.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/graphics/texturemanager.s
.PHONY : src/graphics/texturemanager.s

# target to build an object file
src/main.o:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/main.o
.PHONY : src/main.o

# target to preprocess a source file
src/main.i:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/main.i
.PHONY : src/main.i

# target to generate assembly for a file
src/main.s:
	$(MAKE) -f CMakeFiles/monopoly.dir/build.make CMakeFiles/monopoly.dir/src/main.s
.PHONY : src/main.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... monopoly"
	@echo "... rebuild_cache"
	@echo "... src/core/consolelogger.o"
	@echo "... src/core/consolelogger.i"
	@echo "... src/core/consolelogger.s"
	@echo "... src/core/conversion.o"
	@echo "... src/core/conversion.i"
	@echo "... src/core/conversion.s"
	@echo "... src/core/exception.o"
	@echo "... src/core/exception.i"
	@echo "... src/core/exception.s"
	@echo "... src/core/filelogger.o"
	@echo "... src/core/filelogger.i"
	@echo "... src/core/filelogger.s"
	@echo "... src/core/logger.o"
	@echo "... src/core/logger.i"
	@echo "... src/core/logger.s"
	@echo "... src/core/random.o"
	@echo "... src/core/random.i"
	@echo "... src/core/random.s"
	@echo "... src/core/singleton.o"
	@echo "... src/core/singleton.i"
	@echo "... src/core/singleton.s"
	@echo "... src/core/trigo.o"
	@echo "... src/core/trigo.i"
	@echo "... src/core/trigo.s"
	@echo "... src/game/carte/carte.o"
	@echo "... src/game/carte/carte.i"
	@echo "... src/game/carte/carte.s"
	@echo "... src/game/carte/paquet.o"
	@echo "... src/game/carte/paquet.i"
	@echo "... src/game/carte/paquet.s"
	@echo "... src/game/case/case.o"
	@echo "... src/game/case/case.i"
	@echo "... src/game/case/case.s"
	@echo "... src/game/des.o"
	@echo "... src/game/des.i"
	@echo "... src/game/des.s"
	@echo "... src/game/joueur.o"
	@echo "... src/game/joueur.i"
	@echo "... src/game/joueur.s"
	@echo "... src/graphics/cameramanager.o"
	@echo "... src/graphics/cameramanager.i"
	@echo "... src/graphics/cameramanager.s"
	@echo "... src/graphics/graphicalengine.o"
	@echo "... src/graphics/graphicalengine.i"
	@echo "... src/graphics/graphicalengine.s"
	@echo "... src/graphics/gui/fontmanager.o"
	@echo "... src/graphics/gui/fontmanager.i"
	@echo "... src/graphics/gui/fontmanager.s"
	@echo "... src/graphics/gui/guibuttonitem.o"
	@echo "... src/graphics/gui/guibuttonitem.i"
	@echo "... src/graphics/gui/guibuttonitem.s"
	@echo "... src/graphics/gui/guicolorselector.o"
	@echo "... src/graphics/gui/guicolorselector.i"
	@echo "... src/graphics/gui/guicolorselector.s"
	@echo "... src/graphics/gui/guicontener.o"
	@echo "... src/graphics/gui/guicontener.i"
	@echo "... src/graphics/gui/guicontener.s"
	@echo "... src/graphics/gui/guielement.o"
	@echo "... src/graphics/gui/guielement.i"
	@echo "... src/graphics/gui/guielement.s"
	@echo "... src/graphics/gui/guiitem.o"
	@echo "... src/graphics/gui/guiitem.i"
	@echo "... src/graphics/gui/guiitem.s"
	@echo "... src/graphics/gui/guimanager.o"
	@echo "... src/graphics/gui/guimanager.i"
	@echo "... src/graphics/gui/guimanager.s"
	@echo "... src/graphics/gui/guinode.o"
	@echo "... src/graphics/gui/guinode.i"
	@echo "... src/graphics/gui/guinode.s"
	@echo "... src/graphics/gui/guiprogressbaritem.o"
	@echo "... src/graphics/gui/guiprogressbaritem.i"
	@echo "... src/graphics/gui/guiprogressbaritem.s"
	@echo "... src/graphics/gui/guirectangleitem.o"
	@echo "... src/graphics/gui/guirectangleitem.i"
	@echo "... src/graphics/gui/guirectangleitem.s"
	@echo "... src/graphics/gui/guislidernumberitem.o"
	@echo "... src/graphics/gui/guislidernumberitem.i"
	@echo "... src/graphics/gui/guislidernumberitem.s"
	@echo "... src/graphics/gui/guitextinputitem.o"
	@echo "... src/graphics/gui/guitextinputitem.i"
	@echo "... src/graphics/gui/guitextinputitem.s"
	@echo "... src/graphics/gui/guitextitem.o"
	@echo "... src/graphics/gui/guitextitem.i"
	@echo "... src/graphics/gui/guitextitem.s"
	@echo "... src/graphics/gui/guiwindowcontener.o"
	@echo "... src/graphics/gui/guiwindowcontener.i"
	@echo "... src/graphics/gui/guiwindowcontener.s"
	@echo "... src/graphics/gui/guiwindownode.o"
	@echo "... src/graphics/gui/guiwindownode.i"
	@echo "... src/graphics/gui/guiwindownode.s"
	@echo "... src/graphics/particlemanager.o"
	@echo "... src/graphics/particlemanager.i"
	@echo "... src/graphics/particlemanager.s"
	@echo "... src/graphics/scenemanager.o"
	@echo "... src/graphics/scenemanager.i"
	@echo "... src/graphics/scenemanager.s"
	@echo "... src/graphics/scenenode.o"
	@echo "... src/graphics/scenenode.i"
	@echo "... src/graphics/scenenode.s"
	@echo "... src/graphics/scenenodecircleshapeitem.o"
	@echo "... src/graphics/scenenodecircleshapeitem.i"
	@echo "... src/graphics/scenenodecircleshapeitem.s"
	@echo "... src/graphics/scenenodeitem.o"
	@echo "... src/graphics/scenenodeitem.i"
	@echo "... src/graphics/scenenodeitem.s"
	@echo "... src/graphics/scenenodeshapeitem.o"
	@echo "... src/graphics/scenenodeshapeitem.i"
	@echo "... src/graphics/scenenodeshapeitem.s"
	@echo "... src/graphics/scenenodespriteitem.o"
	@echo "... src/graphics/scenenodespriteitem.i"
	@echo "... src/graphics/scenenodespriteitem.s"
	@echo "... src/graphics/scenenodetextureitem.o"
	@echo "... src/graphics/scenenodetextureitem.i"
	@echo "... src/graphics/scenenodetextureitem.s"
	@echo "... src/graphics/texturemanager.o"
	@echo "... src/graphics/texturemanager.i"
	@echo "... src/graphics/texturemanager.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

