# makeReadmeToc
a c++ command-line script that will automatically develop a table of contents for a Github README.md or another markdown file.

## Github README or markdown table of contents

Did you arrive here by searching "how do I make a table of contents in gitub?" Maybe you're curious about "how to use anchored 
headings for a table of contents in a GitHub README?"

If so, you've come to the right place! And even if not, you still might be able to use this tool!

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

### make output file

First, you will navigate to the repository that you just cloned. Then you will use the C++ compiler to create an executable output file. The first argument is the compiler's command, `g++`, the second argument is the source code file, `mdToTOC.cpp`, and the third argument is the filepath where you want your output file to go (mine is `path/to/your/repository/`) and the name you want your output file to have. I used `desiredFileName.out`, but you can name it anything your heart desires.

```bash
cd makeReadmeToc
g++ mdToTOC.cpp path/to/your/repository/desiredFileName.out
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
