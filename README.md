## All problems were created within a UNIX environment.

### PROBLEM 1:
I replaced the Shape classes draw with the red X from a previous lab and added one more object to the shapes array to show this.

compiled as:

	g++ main.cpp src/shape.cpp src/rectangle.cpp src/circle.cpp src/multcirc.cpp -lGL -lGLU -lglut

### PROBLEM 2:
I decided to use 'ncurses' for displaying this problem as 'ncurses' is extremely easy to use for such a small project. I don't think that my code adheres to the Object-Oreiented coding very well unfortunately. I did not use 'friend' as I could not recognize when I should use it. My use of pointers is pretty rough.

compiled as:

	g++ main.cpp src/world.cpp src/organism.cpp src/ant.cpp src/doodlebug.cpp -lncurses

### PROBLEM 3:
This program has a prompt that allows you to skip all of the intro bloat text. Just type anything other than 'y'. It's funny though =P

compiled as:

	g++ main.cpp src/prisoner.cpp src/linkedlist.cpp

### PROBLEM 4:
compiled as:

 	g++ main.cpp src/checkedarray.cpp

### PROBLEM 5:
compiled as:

 	g++ main.cpp src/movierating.cpp
 
### FORGE
I created a bash script for setting up and compiling multi folder C or C++ projects and rather than typing the full compilation command you would just need to use a command similar to make. If you decide not to use Forge then I have provided the compilation commands below each project.

	https://github.com/psykoshi-uaa/forge

-> copy past from forge.sh to a new file

-> run

 	sudo chmod +x [FILE_DESTINATION]
-> run

	sudo ln [FILE_DESTINATION]

 I have my link in /bin/forge so that I just have to type forge -xyz to use it.
