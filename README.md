# SHA-256
This repository contains the project submission for 4th year Software Development module, Theory of Algorithms. The following sections explain the preject specifications, the running of the application, the research involved and extras which were added.
## Project Specifcation
The aim was to write a program in the C programming language that calculates the SHA-256 checksum of an input. The algorithm is specified in the Secure
Hash Standard document supplied by the (United States) [National Institute of Standards and Technology](https://www.nist.gov/publications/secure-hash-standard). The only pre-requisite was that the program
performs the algorithm — we were free to decide what input the algorithm should be performed on. The recomendation was to allow the user to input some free text
or a filename via the command line.
## Running the Program
The following application running guide is guided towards systems which are running windows opperating system.
### Software Requirements
To run the sha256 program the following software may be required to installed.

To clone this repository it is recommended that Git is installed on your system. To install Git click on this [link](https://git-scm.com/) and follow the install instructions.

To run this program you will need to intall a C compiler. I recommend using the GCC compiler. To install the GCC compiler click on the following [link](https://gcc.gnu.org/install/index.html) and follow the instructions stated.

### Clone Repository
To clone the repository, open a terminal window and navigate to a directory at which you would like to clone the repository. To clone the repository enter the following command
```sh
   $ git clone https://github.com/kevind992/SHA-256.git
```
Once the repository has finished cloning move into the newly cloned repository by typing 
```sh
   $ cd SHA-256
```
The next step is to create a file which will be hashed throught the hashing program.

### Creating Test File
Navigate to the SHA-256 directory using your system explorer. Once within the directory right click in the directory and click new - Text Document. Give the file a name and add some text which you which to be hashed. Once this is complete we are nearly ready to run the program.
### Compiling and Running
To compile the program reopen your terminal which was used to clone the repository and type the following command
```sh
   $ gcc -o sha256 sha256.c
```
All going well, no message should appear which means the application was successfully compiled.
The final step is to run the program. Assuming that a test text file was created within the SHA-256 directory, you can now run the following command to run the hashing program
```sh
   $ ./sha256 testFile
```
The testFile should be whatever you named you file. 

The output after the program has run should be a series of characters

## Project Research

## Project Extras

The extras which were added to the project are as follows 

 - When adding the last 65bits I am converting from Little Endian to Big Endian as the Nist Standard specifies. This is being done by using a macros function. The following code snippet deminstrates how this was achieved 
```sh
   // Macros for changing from little endian to big endian
   #define Swap(x) (((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) | ((x<<24)&0xff000000))
```
The convertion was completed before the hashing by passing nobits into the macros function before adding to the pointer
```sh
   M->s[7] = Swap(*nobits);
```
 - I am handling file read errors
 - Instead of creating one line functions I am using macros functions
