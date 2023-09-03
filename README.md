# Practice-using-Argp

> Command-line options are always optional to the operation of a program –
> this is why they are called options. A mandatory option is an oxymoron.

## Note 1

there is a rather wordy notice at the bottom of the help display. argp put the notice there because the help formatted
in this way they can give the impression to some people that \<some-option> doesn't take an argument. experienced users
find the word notice to be redundant and you can turn it off by adding the text “no-dup-args-note” to the
`ARGP_HELP_FMT` environment variable in your shell:

```bash
export ARGP_HELP_FMT="no-dup-args-note"
./step3 --help
Usage: step3 [OPTION...]

  -d, --dot=NUL             Show somedots on the screen
  -?, --help                Give this help list
      --usage               Give a short usage message
```

## Note 2

This is normal Argp behaviour: options are always parsed before arguments.

> If this is unacceptable you can make Argp to honour the order of your command-line options by passing ARGP_IN_ORDER
> into the bitwise flags parameter (the 4th parameter) of the argp_parse function

---

Repository with examples of using the argp.h library by the book `Step-by-Step into Argp`[^1].

[^1]: PDF: [view](https://github.com/Qu1nel/Practice-using-Argp/blob/main/docs/step-by-step-into-argp.pdf)
