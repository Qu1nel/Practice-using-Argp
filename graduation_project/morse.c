/*
 Copyright (C) 2010, 2015 Ben Asselstine

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Library General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
*/
#include "morse.h"

#include <argz.h>
#include <ctype.h>
#include <error.h>
#include <stdio.h>
#include <string.h>

struct morse_letter {
    char letter;
    char *morse_string;
};

struct morse_letter morse_letters[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"},
    {0},

};

static char lookup_morse(char *dotsanddashes)
{
    struct morse_letter *rec = morse_letters;
    while (rec->letter != '\0') {
        if (strcmp(dotsanddashes, rec->morse_string) == 0) return rec->letter;
        rec++;
    }
    return '\0';
}

static char *lookup_letter(char letter)
{
    struct morse_letter *rec = morse_letters;
    while (rec->letter != '\0') {
        if (toupper(letter) == rec->letter) return rec->morse_string;
        rec++;
    }
    return NULL;
}

static int is_dots_and_dashes(char *word)
{
    if (strspn(word, ".-") == strlen(word)) return 1;
    return 0;
}

static int is_alphanumeric(char *word)
{
    char *alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    if (strspn(word, alphanumeric) == strlen(word)) return 1;
    return 0;
}

static int process_word(char *word, int capitalize)
{
    if (is_alphanumeric(word)) {
        /* convert word to morse code */
        char *letter;
        for (letter = word; *letter != '\0'; letter++) {
            char *morse = lookup_letter(*letter);
            printf("%s ", morse);
        }
    } else if (is_dots_and_dashes(word)) {
        /* convert morse code to word */
        char letter = lookup_morse(word);
        if (capitalize)
            letter = toupper(letter);
        else
            letter = tolower(letter);
        printf("%c", letter);
    } else
        return -1;
    return 0;
}

int morse_process_line(char *argz, size_t argz_len, int capitalize)
{
    const char *prev = NULL;
    char *word;
    while ((word = argz_next(argz, argz_len, prev))) {
        int retval = process_word(word, capitalize);
        if (retval == -1) {
            error(0, 0, "Error parsing `%s'.", word);
            return -1;
        } else if (is_alphanumeric(word))
            printf(" ");
        prev = word;
    }
    printf("\n");
    return 0;
}
