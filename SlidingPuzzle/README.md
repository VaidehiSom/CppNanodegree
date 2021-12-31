# Sliding Puzzle: Puzzle to slide numbers and arrange in increasing order

This is my submission for capstone assignment in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213): Capstone. 

## Dependencies for Running Locally
* Visual Studio >= 2019
	* All OSes: [click here for installation instructions](https://visualstudio.microsoft.com/downloads/)
Or
* Visual Studio Launcher Extension (for running vcxproj or sln extension)

## Basic Build Instructions
If the solution file is not working in you visual studio code, please build the SlidingPuzzle.vcxproj file in your version of Visual Studio.
1. Clone this repo.
2. Open the SlidingPuzzle.vcxproj in Visual Studio.
3. Right click on "SlidingPuzzle" in "Solution Explorer". Select "Retarget Projects".
4. Now build the solution, of Ctrl+Shift+B.
5. SlidingPuzzle.sln file would be created, which can be directly opened.

## Using the solution file
When the .sln file is opened, click on run or debug. The GUI of the game will be displayed. Use arrow keys to interact with the game!

## READ ME Rubric Points
A README with instructions is included with the project. All the specifications have been met in above instructions.

## Project chosen
# The README also indicates the file and class structure, along with the expected behavior or output of the program.

Expected output-
	A square GIU of number puzzle will pop up. It will be controlled by keyboard arrow keys. 

## The README includes information about each rubric point addressed.
# The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.

The project demonstrates an understanding of C++ functions and control structures. The project code is clearly organized into functions.
Examples- ChildView.h, ChildView.cpp, SlidingPuzzle.h, SlidinPuzzle.cpp

The project accepts user input and processes the input.
Keybaord input is being process via-
	ChildView.cpp, line 53, function void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	-> SlidingPuzzleDocument.cpp, line 70, function void CSlidingPuzzleDocument::Slide(SlideDirection slideDirection)

The project uses Object Oriented Programming techniques.
Examples- ChildView.h, ChildView.cpp, SlidingPuzzle.h, SlidinPuzzle.cpp

Classes use appropriate access specifiers for class members.
Examples- ChildView.h, SlidingPuzzle.h, SlidingPuzzleDocument.h

Class constructors utilize member initialization lists.
Examples- ChildView.cpp, line 15

Classes follow an appropriate inheritance hierarchy.
Example- ChildVeiw.h, line 10
		 SlidingPuzzle.h, line 17

Derived class functions override virtual base class functions.
Example- SlidingPuzzle.h, line 23, 24
		 ChildView.h, line 24

The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

The project makes use of references in function declarations.
Example- MainFrm.h, line 13
		 CHileView.h, line 34