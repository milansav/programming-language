#include <stdio.h>
#include <malloc.h>
#include "dynarr/dynarr.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "utils/debug.h"


const char* type_keyword[] = 
{"IDENTIFIER",
"KEYWORD",
"STRING_LITERAL",
"NUMBER_LITERAL",
"CHAR_LITERAL",
"OPERATOR", 
"SEMICOLON", 
"COMMA", 
"DOT", 
"OPEN_BRACKET", 
"CLOSE_BRACKET", 
"OPEN_CURLY", 
"CLOSE_CURLY"};

int main(int argc, char *argv[])
{
    debug_mode += OUTPUT_PARSER;
    debug_mode += OUTPUT_ALL;
    FILE *fp;
    fp = fopen(argv[1], "r");
    unsigned int start = ftell(fp);
    fseek(fp, 0, SEEK_END);
    unsigned int end = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    if(debug_mode & OUTPUT_ALL)
    {
    printf("Size of the file %dbytes\n", (end-start));
    }

    char* code = malloc(end-start);
    fread(code, 1, end-start, fp);
    printf("%s\n", code);

    struct dynarr *arr = lexer_lexify(code);

    if(debug_mode & OUTPUT_LEXER || debug_mode & OUTPUT_ALL)
    {
        for(unsigned int i = 0; i < arr->count; i++)
        {
            printf("Type: %s. Label: %s\n", type_keyword[arr->token_arr[i].type], arr->token_arr[i].label);
        }
    }

    parser_parse_code(arr);

    //free(code);
    return 0;
}