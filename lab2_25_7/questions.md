# LAB 2

1. Byte Extraction Program.

2. Check the Endianess of a machine.

3. WAP to display the memory arrangement on your computer. (memory arrangement & content of the value).

---

## Explanation of `1.c`

- `unsigned char` : It can hold an 8-bit (1-byte) non-negative integer. (0-255)
- `unsigned int` : It can hold an 32-bit (4-byte) non-negatvive integer.

- `a = (value&0xff)` :

```
00010001 00100010 00110011 01000100  (value)
& 00000000 00000000 00000000 11111111  (0xff)
-------------------------------------
00000000 00000000 00000000 01000100  (Result)
```


- `(value >> 8) & 0xff` :

```
00000000 00010001 00100010 00110011  (shifted value)
& 00000000 00000000 00000000 11111111  (0xff)
-------------------------------------
00000000 00000000 00000000 00110011  (Result)
```

## Explanation of `2.c`

- `char *c = (char*) &x`
    - `&x` : returns a pointer to the memory address of `x` of type `unsigned int*`.

    - `(char*)` : 
        - type casting to `char*` type.
        - dereferencing a `(char*)` means that , it reads only one byte from the memory location it points to.

    - looking at the contents of memory one byte at a time, starting from the lowest memory address of `x`.  

- **Little-Endian**
    - LSB is stored at the lowest memory address.

- **Big-Endian**
    - MSB is stored at the lowest memory address.