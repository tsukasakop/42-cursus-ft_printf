/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:55:12 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/10 21:59:21 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Function to convert a single hexadecimal digit to an integer
int hex_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}

// Function to evaluate escape sequences in a string
char* evaluate_escape_sequences(const char* input) {
    size_t len = strlen(input);
    char* output = malloc(len + 1);  // Allocate enough memory for the output string
    if (!output) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    const char* src = input;
    char* dest = output;

    while (*src) {
        if (*src == '\\' && *(src + 1)) {
            src++;  // Skip the backslash
            if (*src == 'x' && isxdigit(*(src + 1))) {
                // Handle hexadecimal escape sequences
                int value = 0;
                src++;
                for (int i = 0; i < 2 && isxdigit(*src); i++, src++) {
                    value = value * 16 + hex_to_int(*src);
                }
                src--;  // Move back one character since we advanced one too far
                *dest++ = (char)value;
            } else if (*src >= '0' && *src <= '7') {
                // Handle octal escape sequences
                int value = 0;
                for (int i = 0; i < 3 && *src >= '0' && *src <= '7'; i++, src++) {
                    value = value * 8 + (*src - '0');
                }
                src--;  // Move back one character since we advanced one too far
                *dest++ = (char)value;
            } else {
                // Handle other escape sequences
                switch (*src) {
                    case 'n':
                        *dest++ = '\n';
                        break;
                    case 't':
                        *dest++ = '\t';
                        break;
                    case 'r':
                        *dest++ = '\r';
                        break;
                    case '\\':
                        *dest++ = '\\';
                        break;
                    case '"':
                        *dest++ = '"';
                        break;
                    default:
                        *dest++ = '\\';
                        *dest++ = *src;
                        break;
                }
            }
        } else {
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';  // Null-terminate the output string

    return output;
}

