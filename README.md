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

Note that current version failed to pass the last test of  `calculator`. The output is incorrect when involved in `float compare`.

The major reason is the `fcom` instruction over `float compare` is not correctly implemented.

AT&T style assembly code about fpu is in need. 
