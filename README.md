## Pascal Compiler

### Compile the compiler

`cd` to the `src/` directory, type 

``` bash
$ make
```

### Run the test

eg:

``` bash
src/ $ cp ../testing/record test.pas
src/ $ make test
```

### NOTE

The backend can run successfully on linux32 machines with att style assembly. 

To run it on 64-bit machines, modify the Makefile to add `-m32` option after `gcc` command as:

``` sh
$ gcc -m32 -o test.o out.s
```
