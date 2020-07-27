# makeReadmeToc
a c++ command-line script that will automatically develop a table of contents for a Github README.md or another markdown file.

## table of contents

[makeReadmeToc](#makereadmetoc)
- [table of contents](#table-of-contents)
- [Github README or markdown table of contents](#github-readme-or-markdown-table-of-contents)
- [status](#status)
- [prereqs](#prereqs)
- [installation](#installation)
	* [Linux/Mac OS (Bash shell)](#linux/mac-os-(bash-shell))
	* [Windows](#windows)
- [use](#use)
	* [compile and make output file](#compile-and-make-output-file)
	* [check for README.md or other markdown file](#check-for-readme.md-or-other-markdown-file)
	* [run program](#run-program)
	* [check for new file](#check-for-new-file)
		* [multiple arguments](#multiple-arguments)
- [contribution](#contribution)

Note: the table of contents for this README *was* in fact constructed using this software.

## Github README or markdown table of contents

Did you arrive here by searching "how do I make a table of contents in gitub?" Maybe you're curious about "how to use anchored 
headings for a table of contents in a GitHub README?"

If so, you've come to the right place! And even if not, you still might be able to use this tool!

## status

to be added

## prereqs

1. a computer 
2. a command-line C++ compiler; I use g++
3. a desire to quickly draft a table of contents for your GitHub README or other markdown file

## installation

### Linux/Mac OS (Bash shell)

```bash
cd path/to/where/you/want/repository
git clone https://github.com/djdebonis/makeReadmeToc
```

### Windows

```
as if I knew how to work a Windows OS...
```

## use

### compile and make output file

First, you will navigate to the repository that you just cloned. Then you will use the C++ compiler to create an executable output file. The first argument is the compiler's command, `g++`, the second argument is the source code file, `mdToTOC.cpp`, and the third argument is the name you want your output file to have. I used `desiredFileName.out`, but you can name it anything your heart desires (if you do not specify `-o name` your file will automatically be called `a.out` if you are using g++. After this you can move your your file to the repository you would like to use it in. In my case, I moved it to  `path/to/your/repository/`:

```bash
cd makeReadmeToc
g++ mdToTOC.cpp -o desiredFileName.out
mv desiredFileName.out path/to/your/repository/
```

### check for README.md or other markdown file

Navigate to the repository or directory that you just copied your file into using:

```bash
cd path/to/your/repository
```

then check to make sure that your README.md or other markdown file is in the repository:

```bash
ls
```
this will return a list of files in that directory. If your file is there, continue to the next step.

### run program

Next, you will type `./` into the command line, followed by the name of your output file. Then, you will enter the file you would like to create a table of contents for. In my circumstance, I entered this:

```bash
./desiredFileName.out README.md
```

### check for new file

Now, type `ls` into the command line. You should have a file in your repository called 'tableOfContents1.txt'! Simply enter:

```bash
open tableOfContents1.txt
```

and viola! Here is your table of contents. You can copy that text into the README/markdown file you created and Github will automatically create a indexed Table of Contents for you.

#### multiple arguments

When you feel confident creating one table of contents, if you desire, you also have the option to iterate through more than one file. You simply add more .md files to the end of the output file in command line, like so:

```bash
./desiredFileName.out README.md anotherPage.md aboutMe.md 
```
Each file will be returned as 'tableOfContents' + argument number + '.txt'

Note: if you already have a file in your folder named tableOfContents1.txt, rerunning the program will overwrite and/or change that file. So, compile all of your arguments at once!

## contribution

This program is very basic, and I would love your help! Some things that could definitely use work are:
1. abstracting procedural code in `main()` to functions
2. adding an argument parser so that the user can chose the name of their output.txt file
3. finding a way to concat the table of contents into the readme by line number!
4. any other ideas you have! let's make table of contents easier for everyone!
