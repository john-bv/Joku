Errors

```
Err [01]: Type Mismatch when declaring "apples"
---- source.joku[3:19]
   |
 3 | apples: void = 0;
   |  |      ----   ~
   |  |         |   \_ This value has a type named "int".
   |  |         |
   |  |         \_____ Which collides with the type "void".
   |  |
   |  |                Note: This can be resolved by renaming
   |  |                    | "void" to "int".
   |  |
   |  \__ The type "void" can not be used to express the type "int".
   |
   \_ Declaration of "apples" is invalid.
```



Token Error

```
Error! Tokenization failed:
> Illegal token in identifer in [source.joku:10:3]
```


