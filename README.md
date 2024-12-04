All problems were created within a UNIX environment.



I created a bash script for setting up and compiling multi folder
C or C++ projects, and rather than compiling you would just need
to use a command similar to make.

	https://github.com/psykoshi-uaa/forge

After copying and pasting the script I recommend creating a symbolic link (I set mine to /bin/forge)



PROBLEM 1:
	I replaced the Shape classes draw with the red X from a previous
	lab and added one more object to the shapes array to show this.

	compiled as:

		g++ main.cpp src/shape.cpp src/rectangle.cpp src/circle.cpp src/multcirc.cpp -lGL -lGLU -lglut



PROBLEM 2:
	I decided to use 'ncurses' for displaying this problem as 'ncurses'
	is extremely easy to use for such a small project. I don't think
	that my code adheres to the Object-Oreiented coding very well
	unfortunately. I did not use 'friend' as I could not recognize
	when I should use it. My use of pointers is pretty rough.

	compiled as:

		g++ main.cpp src/world.cpp src/organism.cpp src/ant.cpp src/doodlebug.cpp -lncurses



PROBLEM 3:
