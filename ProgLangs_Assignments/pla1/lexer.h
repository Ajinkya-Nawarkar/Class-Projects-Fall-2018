//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 8-25-2015
//  author: Ajinkya Nawarkar | an839
//*****************************************************************************
 
#ifndef LEXER_H
#define LEXER_H

// Include standard IO streams
#include <stdio.h>

// The lexical analyzer global variables and functions
extern int   yylex();
extern FILE *yyin;         // input stream
extern FILE *yyout;        // output stream
extern int   yyleng;       // length of current lexeme
extern char *yytext;       // text of current lexeme

// Maximum lexeme length
#define MAX_LEXEME_LEN 100

// List of token codes

namespace token_ns
{
	enum tokens {
					TOK_IF = 1001,
					TOK_ELSE = 1002,
					TOK_FOR = 1003,
					TOK_WHILE = 1004,
					TOK_PRINT = 1005,
					TOK_RETURN = 1006,	
					TOK_CONTINUE = 1007, 
					TOK_BREAK = 1008,
					TOK_DEBUG = 1009, 
					TOK_READ = 1010, 
					TOK_LET = 1011, 
					TOK_INT = 1100, 
					TOK_FLOAT = 1101, 
					TOK_STRING = 1102,
					TOK_SEMICOLON = 2000, 
					TOK_OPENPAREN = 2001, 
					TOK_CLOSEPAREN = 2002, 
					TOK_OPENBRACKET = 2003, 
					TOK_CLOSEBRACKET = 2004, 
					TOK_OPENBRACE = 2005, 
					TOK_CLOSEBRACE = 2006, 
					TOK_COMMA = 2007, 
					TOK_PLUS = 3000, 
					TOK_MINUS = 3001, 
					TOK_MULTIPLY = 3002,
					TOK_DIVIDE = 3003, 
					TOK_ASSIGN = 3004,	 
					TOK_EQUALTO = 3005, 
					TOK_LESSTHAN = 3006, 
					TOK_GREATERTHAN = 3007, 
					TOK_NOTEQUALTO = 3008, 
					TOK_AND = 3009, 
					TOK_OR = 3010, 
					TOK_NOT = 3011, 
					TOK_LENGTH = 3012, 	
					TOK_IDENTIFIER = 4000, 
					TOK_INTLIT = 4001, 
					TOK_FLOATLIT = 4002, 
					TOK_STRINGLIT = 4003, 
					TOK_EOF = 5000, 
					TOK_EOF_SL = 5001,
					TOK_UNKNOWN = 6000,
					TOK_WHITE = 7000
				};
}

#endif

