//
//  string.c
//  Laboratory 11
//
//  Created by Даниил on 18/03/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include "string.h"

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "number.h"

char *normalize_line(const char *line, const size_t length, size_t *out_length)
{
    double numbers[256];
    
    unsigned int numbers_counter = 0;
    double max_line_number = -INT64_MAX;
    double min_line_number = INT64_MAX;
    
    int current_word_length = 0;
    for (int i = 0; i < length; i++) {
        if (line[i] != ' ' && line[i] != '\n') {
            current_word_length++;
            continue;
        }
        
        char buff[255];
        strlcpy(buff, line + (i - current_word_length), current_word_length + 1);
        if (is_numeric_string(buff)) {
            double number = atof(buff);
            
            if (number > max_line_number) {
                max_line_number = number;
            }
            
            if (number < min_line_number) {
                min_line_number = number;
            }
            
            numbers[numbers_counter++] = number;
        } else {
            return NULL;
        }
        current_word_length = 0;
    }
    
    if (numbers_counter > 0) {
        const double average = (min_line_number + max_line_number) / 2.0;
        for (int i = 0; i < numbers_counter; i++) {
            numbers[i] /= average;
        }
        
        return concat_numbers(numbers, numbers_counter, out_length);
    }
    
    return NULL;
}

bool is_numeric_string(const char *string)
{
    unsigned long length = strlen(string);
    unsigned int dots_count = 0;
    
    for (int i = 0; i < length; i++) {
        if (string[i] == '.') {
            if (++dots_count > 1)
                return false;
            
            continue;
        }
        
        if (string[i] < '0' || string[i] > '9')
            return false;
    }
    
    return true;
}
