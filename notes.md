###ft_printf Notes

- Part One: Gameplan, dried-up subject summary
- Part Two: Dried-up `printf()` man page, omitting irrelevant data

***

###Gameplan

Prototype: `int ft_printf(const char *fmt, ...)`

#####Proposed Step-by-step

######Step One:
Validate `const char *fmt` for proper formatting, storing flags in linked list on discovery and recording number of flags.

######Step Two:
Step through list and compare each argument against it's respective flag and store value with corresponding flag, performing any necessary conversions at the same time. If mismatch, return `-1`. Else, continue to next argument.

######Step Three:
When all assignments/conversions are complete, begin output process. Print out format string up until first flag, print saved value for each flag, skip past flag and continue printing.

######Step Four:
Clean up all memory usage and return number of characters printed, excluding terminating `NUL`.

######Structs:

- t_list
    - `void *data`
        - the data held by the node
    - `t_list *next`
        - the next node
- t_flag(?)
    - `char *flag`
        - a copy of the flag value
    - `void *actl`
        - a pointer to the represented value
    - `char *val`
        - the printable and converted value

***

###Subject Summary

######Mandatory:
- ft_printf will **not** manage the buffer
- must manage these conversions: `sSpdDioOuUxXcC`
- must manage `%%`
- must manage flags `#0-+` and space
- must manage minimum field-width
- must manage precision
- must manage flags `hh`, `h`, `l`, `ll`, `j`, and `z`

######Interesting Bonuses:
- Alter text color with special flags
- `%b` to print in binary

***

###Man Page Summary

>For those routines that write to a user-provided character string, that string and the format strings
     should not overlap, as the behavior is undefined.

######Anatomy of a Format String:
- >Normal characters, printed out without conversion or substitution.

- >An optional field, consisting of a decimal digit string followed by a $, specifying the next argument to access.  If this field is not provided, the argument following the last argument accessed will be used.  Arguments are numbered starting at 1.  If un-accessed arguments in the format string are interspersed with ones that are accessed the results will be indeterminate.

- >Zero or more of the following flags: `#0-+` and space

- >An optional decimal digit string specifying a minimum field width.  If the converted value has fewer characters than the field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been given) to fill out the field width.

- >An optional precision, in the form of a `.` followed by an optional digit string.  If the digit string is omitted, the precision is taken as zero.

- >An optional length modifier, that specifies the size of the argument.

- >A character that specifies the type of conversion to be applied.

####Flag Index:

######Standard:
*Flag*

- `#`
    - >The value should be converted to an "alternate     form".  For `c`, `d`, `i`, `n`, `p`, `s`, and `u` conversions, this option has no effect.  For o conversions, the precision of the number is increased to force the first character of the output string to a zero. For `x` and `X` conversions, a non-zero result has the string `0x` (or `0X` for `X` conversions) prepended to it.  For `a`, `A`, `e`, `E`, `f`, `F`, `g`, and `G` conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows). For `g` and `G` conversions, trailing zeros are not removed from the result as they would otherwise be.

- `0`
    - >Zero padding. For all conversion except `n`, the converted value is padded on the left with zeros rather than blanks. If a precision is given with a numeric conversion (`d`, `i`, `o`, `u`, `i`, `x`, and `X`), the `0` flag is ignored.

- `-`
    - >A negative field width flag; the converted value is to be left adjusted on the right with blanks rather than on the left with blanks or zeros. A `-` overrides a `0` if both are given.

- ` ` (space)
    - >A space: A blank should be left before a positive number produced by a signed conversion (`a`, `A`, `d`, `e`, `E`, `f`, `F`, `g`, `G`, or `i`).

- `+`
    - >A sign must always be placed before a number produced by a signed conversion, A `+` overrides  ` `  (space) if both are used.

######Length Modifiers:
Applicable to: `d`, `i`, `n`, `o`, `u`, `x`, or `X` conversion.

*Flag*
- `hh`
    - `d`, `i`
        - signed char
    - `o`, `u`, `x`, `X`
        - unsigned char
    - `n`
        - signed char *
- `h`
    - `d`, `i`
        - short
    - `o`, `u`, `x`, `X`
        - unsigned short
    - `n`
        - short *
- `l`
    - `d`, `i`
        - long
    - `o`, `u`, `x`, `X`
        - unsigned long
    - `n`
        - long *
- `ll`
    - `d`, `i`
        - long long
    - `o`, `u`, `x`, `X`
        - unsigned long long
    - `n`
        - long long *
- `j`
    - `d`, `i`
        - intmax_t
    - `o`, `u`, `x`, `X`
        - uintmax_t
    - `n`
        - intmax_t *
- `z`
    - `d`, `i`
        - indicates that the argument is of a signed type equivalent in size to a size_t
    - `o`, `u`, `x`, `X`
        - size_t
    - `n`
        - indicates that the argument is of a signed type equivalent in size to a size_t

####Conversion Index:

- `diouxX`
    - >The int (or appropriate variant) argument is converted to signed decimal (`d` and `i`), unsigned octal (`o`), unsigned decimal (`u`), or unsigned hexadecimal (`x` and `X`) notation.  The letters "abcdef" are used for `x` conversions; the letters "ABCDEF" are used for `X` conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.
- `DOU`
    - >The long int argument is converted to signed decimal, unsigned octal, or unsigned decimal, as if the format had been `ld`, `lo`, or `lu` respectively. These conversion characters are deprecated, and will eventually disappear.
- `C`
    - >Treated as `c` with the `l` modifier.
- `c`
    - >The int argument is converted to an unsigned char and the resulting character is written.
- `S`
    - >Treated as `s` with the `l` modifier.
- `s`
    - >The char * argument is expected to be a pointer to an array of character type (pointer to a
    string).  Characters from the array are written up to (but not including) a terminating `NUL`
    character; if a precision is specified, no more than the number specified are written.  If a
    precision is given, no null character need be present; if the precision is not specified, or is
    greater than the size of the array, the array must contain a terminating `NUL` character.
    \
    \
    If the `l` (ell) modifier is used, the wchar_t * argument is expected to be a pointer to an array
    of wide characters (pointer to a wide string).  For each wide character in the string, the
    (potentially multi-byte) sequence representing the wide character is written, including any
    shift sequences.  If any shift sequence is used, the shift state is also restored to the original state after the string.  Wide characters from the array are written up to (but not including) a terminating wide `NUL` character; if a precision is specified, no more than the number of bytes specified are written (including shift sequences).  Partial characters are never written. If a precision is given, no null character need be present; if the precision is not specified, or is greater than the number of bytes required to render the multibyte representation of the string, the array must contain a terminating wide `NUL` character.

- `%`
    - >A `%` is written. No argument is converted. The complete conversion specification is `%%`.

####Note:
In no case does a non-existent or small field width cause truncation of a numeric field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.
