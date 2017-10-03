%{
#include<stdio.h>
#include "grammatic.bizon.h"

struct {
    int first_line;
    int last_line;
    int first_column;
    int last_column;
} yylloc;

int line_number = 0;
int column_number = 0;

static void updateLocation() {
    yylloc.first_line = line_number;
    yylloc.first_column = column_number;

    for (int i = 0; i < yyleng; i++) {
        if( yytext[i] == '\n' ) {
            line_number++;
            column_number = 0;
        } else {
            column_number++;
        }
    }

    yylloc.last_line = line_number;
    yylloc.last_column = column_number;

    printf("%s", yytext);
    printf(" begins in %d %d", yylloc.first_line, yylloc.first_column);
    printf(" and ends in %d %d\n", yylloc.last_line, yylloc.last_column);
}

#define YY_USER_ACTION updateLocation();
%}

%option noyywrap

DIGIT [0-9]
LETER [a-zA-Z_]
id {LETER}({DIGIT}|{LETER})*
IntegerLiteral [1-9]{DIGIT}*|0

%%
"int" return INT;
"boolean" return BOOLEAN;
"System.out.println" PRINTLN;
"class" return CLASS;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"new" return NEW;
"this" return THIS;
"return" return RETURN;
"true" return TRUE;
"false" return FALSE;
"extends" return EXTENDS;
"public" return PUBLIC;
"private" return PRIVATE;
"String" return STRING;
"main" return MAIN;
"static" return STATIC;
"void" return VOID;
"int[]" return INT_ARRAY;
"length" return LENGTH;
"&&" return AND;
"||" return OR;
"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"<" return LESS;
">" return GREATER;
"!" return NOT;
"=" return ASSIGN;
"(" return LPAREN;
")" return RPAREN;
"[" return LBRACKET;
"]" return RBRACKET;
"{" return LBRACE;
"}" return RBRACE;
"," return COMMA;
"." return DOT;
";" return SEMICOLON;
"%" return MOD; 

{id} return ID;
{IntegerLiteral} return NUMBER;

%%
