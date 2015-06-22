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
Note that current version failed to pass the test of `record` and `calculator`.
The major reason is the operation over `float/double` is not correctly implemented.

AT&T style assembly code about fpu is in need. 
