# SHA-256
This repository contains the project submission for 4th year Software Development module, Theory of Algorithms. The following sections explain the preject specifications, the running of the application, the research involved and extras which were added.
## Project Specifcation
The aim was to write a program in the C programming language that calculates the SHA-256 checksum of an input. The algorithm is specified in the Secure
Hash Standard document supplied by the (United States) [National Institute of Standards and Technology](https://www.nist.gov/publications/secure-hash-standard). The only pre-requisite was that the program
performs the algorithm — we were free to decide what input the algorithm should be performed on. The recomendation was to allow the user to input some free text
or a filename via the command line.
## SHA256
SHA-256 is a member of the SHA-2 cryptographic hash functions designed by the NSA. SHA stands for Secure Hash Algorithm. Cryptographic hash functions are mathematical operations run on digital data; by comparing the computed "hash" (the output from execution of the algorithm) to a known and expected hash value, a person can determine the data's integrity. A one-way hash can be generated from any piece of data, but the data cannot be generated from the hash.
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

an example input and output can be seen below.
```sh
   SHA-256 $ ./sha256 README.md 
   27354abd 41e9ee5a 192ec7df 176cc51e 5199785e 3ff3c349 9ade0bd0 73031aaf
```
## Project Testing
To make sure that the program was up to standard it was tested using two different sha256 programs. One was an online sha256 converter and the second was a terminal converter called open ssl. On both occasions the tests passed. An open ssl example can be seen below which hashes the testFile.txt file
```sh
    $ openssl sha256 testFile 
      SHA256(testFile)= b4f37654698f09d8bd86b6cc3b4adc157ec2017a116607318bf9dbfd8d24f76e
```
The sample below shows the program result for the testFile.txt
```sh
   $ ./sha256 testFile 
   b4f37654 698f09d8 bd86b6cc 3b4adc15 7ec2017a 11660731 8bf9dbfd 8d24f76e
```
As you can see above both hashs are the same
## Project Extras
The extras which were added to the project are as follows 
 - Instead of creating one line functions I am using macros functions. The snippet below shows an example of a macros function
 ```sh
   //Macros Functions
   #define rotr(x,n) (((x) >> (n)) | ((x) << (32-(n))))
   #define SIG0(x) (rotr(x,7) ^ rotr(x,18) ^ ((x) >> 3 ))
   #define SIG1(x) (rotr(x,17) ^ rotr(x,19) ^ ((x) >> 10))
 ```
 - When adding the last 65bits I am converting from Little Endian to Big Endian as the Nist Standard specifies. This is being done by using a macros function. The following code snippet deminstrates how this was achieved 
```sh
   // Macros for changing from little endian to big endian
   #define Swap64(x) \
	( (((x) >> 56) & 0x00000000000000FF) | (((x) >> 40) & 0x000000000000FF00) | \
	  (((x) >> 24) & 0x0000000000FF0000) | (((x) >>  8) & 0x00000000FF000000) | \
	  (((x) <<  8) & 0x000000FF00000000) | (((x) << 24) & 0x0000FF0000000000) | \
	  (((x) << 40) & 0x00FF000000000000) | (((x) << 56) & 0xFF00000000000000) )
```
The convertion was completed before the hashing by passing nobits into the macros function before adding to the pointer
```sh
   if (BIG_ENDIAN_CHECK) {
		M->s[7] = *nobits;
	}
	else {
		M->s[7] = Swap64(*nobits);
	}
```
 - I am handling file read errors by checking whether a file has been entered. If no file has been entered the application exits. The code snippet below shows how this was implemented.
 ```sh
  FILE* msgf;
  msgf = fopen(argv[1], "r");

  // File error handling 
  if (! msgf){
    printf("Error opening file or no file specified..\n");
    exit(-1);
  }
```
## References
- Lecture Videos and Notes from Lecturer Ian McLoughlin
- https://csrc.nist.gov/projects/hash-functions (SHA256 documentation)
- https://gcc.gnu.org/onlinedocs/cpp/Macros.html (Macros Functions)
- https://www.programiz.com/c-programming/c-preprocessor-macros (Macros Functions)
- https://www.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html (Reading Files in C)
- https://betterexplained.com/articles/understanding-big-and-little-endian-byte-order/ (Little and Big Endian)
- https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian (Converting Little to big Endian)
