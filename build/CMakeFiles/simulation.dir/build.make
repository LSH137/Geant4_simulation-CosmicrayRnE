# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/lsh/CosmicrayRnE/G4project/sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/lsh/CosmicrayRnE/G4project/sample/build

# Include any dependencies generated for this target.
include CMakeFiles/simulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simulation.dir/flags.make

CMakeFiles/simulation.dir/simulation.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/simulation.cc.o: ../simulation.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simulation.dir/simulation.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/simulation.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/simulation.cc

CMakeFiles/simulation.dir/simulation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/simulation.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/simulation.cc > CMakeFiles/simulation.dir/simulation.cc.i

CMakeFiles/simulation.dir/simulation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/simulation.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/simulation.cc -o CMakeFiles/simulation.dir/simulation.cc.s

CMakeFiles/simulation.dir/simulation.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/simulation.cc.o.requires

CMakeFiles/simulation.dir/simulation.cc.o.provides: CMakeFiles/simulation.dir/simulation.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/simulation.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/simulation.cc.o.provides

CMakeFiles/simulation.dir/simulation.cc.o.provides.build: CMakeFiles/simulation.dir/simulation.cc.o


CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/DetectorConstruction.cc

CMakeFiles/simulation.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/DetectorConstruction.cc > CMakeFiles/simulation.dir/src/DetectorConstruction.cc.i

CMakeFiles/simulation.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/DetectorConstruction.cc -o CMakeFiles/simulation.dir/src/DetectorConstruction.cc.s

CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.requires

CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.provides: CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.provides

CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.provides.build: CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o


CMakeFiles/simulation.dir/src/Hit.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/Hit.cc.o: ../src/Hit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simulation.dir/src/Hit.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/Hit.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/Hit.cc

CMakeFiles/simulation.dir/src/Hit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/Hit.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/Hit.cc > CMakeFiles/simulation.dir/src/Hit.cc.i

CMakeFiles/simulation.dir/src/Hit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/Hit.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/Hit.cc -o CMakeFiles/simulation.dir/src/Hit.cc.s

CMakeFiles/simulation.dir/src/Hit.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/Hit.cc.o.requires

CMakeFiles/simulation.dir/src/Hit.cc.o.provides: CMakeFiles/simulation.dir/src/Hit.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/Hit.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/Hit.cc.o.provides

CMakeFiles/simulation.dir/src/Hit.cc.o.provides.build: CMakeFiles/simulation.dir/src/Hit.cc.o


CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/PrimaryGeneratorAction.cc

CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/PrimaryGeneratorAction.cc > CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/PrimaryGeneratorAction.cc -o CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.requires

CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.provides: CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.provides

CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o


CMakeFiles/simulation.dir/src/RunAction.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/RunAction.cc.o: ../src/RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/simulation.dir/src/RunAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/RunAction.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/RunAction.cc

CMakeFiles/simulation.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/RunAction.cc > CMakeFiles/simulation.dir/src/RunAction.cc.i

CMakeFiles/simulation.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/RunAction.cc -o CMakeFiles/simulation.dir/src/RunAction.cc.s

CMakeFiles/simulation.dir/src/RunAction.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/RunAction.cc.o.requires

CMakeFiles/simulation.dir/src/RunAction.cc.o.provides: CMakeFiles/simulation.dir/src/RunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/RunAction.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/RunAction.cc.o.provides

CMakeFiles/simulation.dir/src/RunAction.cc.o.provides.build: CMakeFiles/simulation.dir/src/RunAction.cc.o


CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o: ../src/SensitiveDetector.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/SensitiveDetector.cc

CMakeFiles/simulation.dir/src/SensitiveDetector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/SensitiveDetector.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/SensitiveDetector.cc > CMakeFiles/simulation.dir/src/SensitiveDetector.cc.i

CMakeFiles/simulation.dir/src/SensitiveDetector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/SensitiveDetector.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/SensitiveDetector.cc -o CMakeFiles/simulation.dir/src/SensitiveDetector.cc.s

CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.requires

CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.provides: CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.provides

CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.provides.build: CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o


CMakeFiles/simulation.dir/src/SteppingAction.cc.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/src/SteppingAction.cc.o: ../src/SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/simulation.dir/src/SteppingAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/src/SteppingAction.cc.o -c /media/lsh/CosmicrayRnE/G4project/sample/src/SteppingAction.cc

CMakeFiles/simulation.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/src/SteppingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lsh/CosmicrayRnE/G4project/sample/src/SteppingAction.cc > CMakeFiles/simulation.dir/src/SteppingAction.cc.i

CMakeFiles/simulation.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/src/SteppingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lsh/CosmicrayRnE/G4project/sample/src/SteppingAction.cc -o CMakeFiles/simulation.dir/src/SteppingAction.cc.s

CMakeFiles/simulation.dir/src/SteppingAction.cc.o.requires:

.PHONY : CMakeFiles/simulation.dir/src/SteppingAction.cc.o.requires

CMakeFiles/simulation.dir/src/SteppingAction.cc.o.provides: CMakeFiles/simulation.dir/src/SteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/src/SteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/simulation.dir/src/SteppingAction.cc.o.provides

CMakeFiles/simulation.dir/src/SteppingAction.cc.o.provides.build: CMakeFiles/simulation.dir/src/SteppingAction.cc.o


# Object files for target simulation
simulation_OBJECTS = \
"CMakeFiles/simulation.dir/simulation.cc.o" \
"CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/simulation.dir/src/Hit.cc.o" \
"CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/simulation.dir/src/RunAction.cc.o" \
"CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o" \
"CMakeFiles/simulation.dir/src/SteppingAction.cc.o"

# External object files for target simulation
simulation_EXTERNAL_OBJECTS =

simulation: CMakeFiles/simulation.dir/simulation.cc.o
simulation: CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o
simulation: CMakeFiles/simulation.dir/src/Hit.cc.o
simulation: CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o
simulation: CMakeFiles/simulation.dir/src/RunAction.cc.o
simulation: CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o
simulation: CMakeFiles/simulation.dir/src/SteppingAction.cc.o
simulation: CMakeFiles/simulation.dir/build.make
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4Tree.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4GMocren.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4visHepRep.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4RayTracer.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4VRML.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4interfaces.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4persistency.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4error_propagation.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4readout.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4physicslists.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4parmodels.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4FR.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4vis_management.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4modeling.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4run.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4event.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4tracking.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4processes.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4analysis.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4zlib.so
simulation: /usr/lib/x86_64-linux-gnu/libexpat.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4digits_hits.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4track.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4particles.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4geometry.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4materials.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4graphics_reps.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4intercoms.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4global.so
simulation: /home/lsh/Documents/GEANT4/install/lib/libG4clhep.so
simulation: CMakeFiles/simulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable simulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simulation.dir/build: simulation

.PHONY : CMakeFiles/simulation.dir/build

CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/simulation.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/DetectorConstruction.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/Hit.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/PrimaryGeneratorAction.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/RunAction.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/SensitiveDetector.cc.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/src/SteppingAction.cc.o.requires

.PHONY : CMakeFiles/simulation.dir/requires

CMakeFiles/simulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simulation.dir/clean

CMakeFiles/simulation.dir/depend:
	cd /media/lsh/CosmicrayRnE/G4project/sample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/lsh/CosmicrayRnE/G4project/sample /media/lsh/CosmicrayRnE/G4project/sample /media/lsh/CosmicrayRnE/G4project/sample/build /media/lsh/CosmicrayRnE/G4project/sample/build /media/lsh/CosmicrayRnE/G4project/sample/build/CMakeFiles/simulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simulation.dir/depend

