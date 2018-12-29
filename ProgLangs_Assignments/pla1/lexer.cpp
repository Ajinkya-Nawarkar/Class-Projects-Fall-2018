//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 8-25-2015
//  author: YOUR NAME HERE
//*****************************************************************************
#include "lexer.h"
#include <ctype.h>
#include <assert.h>
#include <string>
#include <ctype.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace token_ns;
//*****************************************************************************
// Do the lexical parsing
char lexeme[MAX_LEXEME_LEN];  // Character buffer for lexeme

vector<string> keywords= {"if", "else", "for", "while", "print", "return",
			"continue", "break", "debug", "read", "let", "int", "float",
			"string", "and", "or", "not", "length" };

vector<char> operators = {'+', '-', '*', '/', '>', ',', '(',
		')', '{', '}', '[', ']', ';' };

void add_char(char c){	lexeme[yyleng++] = c;	}

char read_next_char(){	return fgetc( yyin );	}

bool isPeriod(char c){	return c == '.';	}

bool isFloat(char *lexeme)
{
	string lexeme_str = lexeme;
	for (auto i = 0; i < lexeme_str.length(); i++)
	{
		if (lexeme_str[i] == '.')
			return true;
	}
	return false;
}

bool isKeyword(char *lexeme)
{
	string lexeme_str = lexeme;
	bool presence = false;
	if (find(keywords.begin(), keywords.end(), lexeme_str) != keywords.end())
		presence = true;
	return presence;
}

bool isOperator(char c)
{
	vector<char>::iterator it;
	bool presence = false;
	if (find(operators.begin(), operators.end(), c) != operators.end())
		presence = true;
	return presence;
}

tokens get_keyword_token(char *lexeme)
{
	string lexeme_str = lexeme;
	tokens token;

	if (lexeme_str == "if")
		token = TOK_IF;

	else if (lexeme_str == "else")
		token = TOK_ELSE;

	else if (lexeme_str == "for")
		token = TOK_FOR;

	else if (lexeme_str == "while")
		token = TOK_WHILE;

	else if (lexeme_str == "print")
		token = TOK_PRINT;

	else if (lexeme_str == "return")
		token = TOK_RETURN;

	else if (lexeme_str == "continue")
		token = TOK_CONTINUE;

	else if (lexeme_str == "break")
		token = TOK_BREAK;

	else if (lexeme_str == "debug")
		token = TOK_DEBUG;

	else if (lexeme_str == "read")
		token = TOK_READ;

	else if (lexeme_str == "let")
		token = TOK_LET;

	else if (lexeme_str == "int")
		token = TOK_INT;

	else if (lexeme_str == "float")
		token = TOK_FLOAT;

	else if (lexeme_str == "string")
		token = TOK_STRING;

	else if (lexeme_str == "and")
		token = TOK_AND;

	else if (lexeme_str == "or")
		token = TOK_OR;

	else if (lexeme_str == "not")
		token = TOK_NOT;

	else if (lexeme_str == "length")
		token = TOK_LENGTH;

	return token;
}

tokens get_operator_token(char *lexeme)
{
	string lexeme_str = lexeme;
	tokens token;

	if (lexeme_str == ";")
		token = TOK_SEMICOLON;

	else if (lexeme_str == "(")
		token = TOK_OPENPAREN;

	else if (lexeme_str == ")")
		token = TOK_CLOSEPAREN;

	else if (lexeme_str == "[")
		token = TOK_OPENBRACKET;

	else if (lexeme_str == "]")
		token = TOK_CLOSEBRACKET;

	else if (lexeme_str == "{")
		token = TOK_OPENBRACE;

	else if (lexeme_str == "}")
		token = TOK_CLOSEBRACE;

	else if (lexeme_str == ",")
		token = TOK_COMMA;

	else if (lexeme_str == "+")
		token = TOK_PLUS;

	else if (lexeme_str == "-")
		token = TOK_MINUS;

	else if (lexeme_str == "*")
		token = TOK_MULTIPLY;

	else if (lexeme_str == "/")
		token = TOK_DIVIDE;

	else if (lexeme_str == ">")
		token = TOK_GREATERTHAN;

	return token;
}

int yylex()
{
  static char c = -1;         // Have we read the first character yet?
  int char_type;              // Hold the character type
  bool iter_flag = true;
  tokens ret_token;

  // Prepare the buffer to hold the lexeme
  for( int i = 0; i < MAX_LEXEME_LEN; i++ )
    lexeme[i] = '\0';
  yytext = lexeme;
  yyleng = 0;

  // If the very first character has not yet been read, read it
  if( c < 0 )
    c = fgetc( yyin );
 
  // Test for end of file
  if( feof(yyin) ) {
    // Ready for next time
    c = -1; 
    // Done!
    return( TOK_EOF );
  }

//  printf("%d", c);

  // Check for alphanums
  if (isalpha(c))
  {
	  add_char(c);
	  c = read_next_char();

	  // Add all alphabets
	  while (isalpha(c))
	  {
		  add_char(c);
		  c = read_next_char();
	  }
	  // Add all numbers
	  while (isdigit(c) || c == '_')
	  {
	  		  add_char(c);
	  		  c = read_next_char();
	  }
	  iter_flag = false;
	  lexeme[yyleng] = '\0';

	  // Check for all the keywords and
	  if (isKeyword(lexeme))
		  ret_token = get_keyword_token(lexeme);
	  else
		  ret_token = TOK_IDENTIFIER;

  }

  // Check for integers and floats
  else if (isdigit(c))
  {
	  add_char(c);
	  c = read_next_char();

	  while (isdigit(c) || isPeriod(c))
	  {
	  	  add_char(c);
	  	  c = read_next_char();
	  }
	  iter_flag = false;
	  lexeme[yyleng] = '\0';

	  if (isFloat(lexeme))
		  ret_token = TOK_FLOATLIT;
	  else
		  ret_token = TOK_INTLIT;
  }

  // Check for all punctuation
  else if (ispunct(c))
  {
	  // Check all other operators
	  if (isOperator(c))
	  {
		  add_char(c);
		  lexeme[yyleng] = '\0';
		  ret_token = get_operator_token(lexeme);
	  }

	  // Check for assign or equal to operators
	  else if (c == '=')
	  {
		  add_char(c);
		  c = read_next_char();
		  if (c == '=')
		  {
			  add_char(c);
			  lexeme[yyleng] = '\0';
			  ret_token = TOK_EQUALTO;
		  }
	  }

	  else if (c == ':')
	  {
		  add_char(c);
		  c = read_next_char();
		  if (c == '=')
		  {
			  add_char(c);
			  lexeme[yyleng] = '\0';
			  ret_token = TOK_ASSIGN;
		  }
	  }

	  // Check for LESSTHAN or NOTEQUALTO operators
	  else if (c == '<')
	  {
		  add_char(c);
		  c = read_next_char();
		  if (c == '>')
		  {
			  add_char(c);
			  lexeme[yyleng] = '\0';
			  ret_token = TOK_NOTEQUALTO;
		  }
		  else {
			  lexeme[yyleng] = '\0';
			  ret_token = TOK_LESSTHAN;
			  iter_flag = false;
		  }
	  }

	  // Check for the strings
	  else if (c == '\"')
	  {
		  add_char(c);
		  c = read_next_char();
		  while((c != '\"')){
			  if( feof(yyin) )
			  {
				c = -1;
				return TOK_EOF_SL;
			  }
			  add_char(c);
			  c = read_next_char();
		  }
		  if (c == '\"')
			  add_char(c);
		  else
		  {
			  lexeme[yyleng] = '\0';
			  ret_token = TOK_UNKNOWN;
		  }

		  lexeme[yyleng] = '\0';
		  ret_token = TOK_STRINGLIT;
	  }

	  // We don't yet know how to recognize any lexemes
	  else
	  {
	  	  add_char(c);
	  	  lexeme[yyleng] = '\0';
	  	  ret_token = TOK_UNKNOWN ;
	    }
  }

  // Check for the space
  else if (isspace(c) || c == '\n'){	  ret_token = TOK_WHITE;  }

  // We don't yet know how to recognize any lexemes
  else
  {
	  add_char(c);
	  lexeme[yyleng] = '\0';
	  ret_token = TOK_UNKNOWN ;
  }

  if (iter_flag)
	  c = read_next_char();

  return ret_token;
}
