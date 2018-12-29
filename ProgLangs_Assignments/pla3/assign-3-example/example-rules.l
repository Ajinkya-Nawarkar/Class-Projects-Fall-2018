/******************************************************************* 
purpose: CSE 4713 / 6713 Assignment 3 example recursive descent parser
created: 10-26-2014
 author: J. Edward Swan II
 *******************************************************************/
%option noyywrap
%{
#include "lexer.h"

int yyLine = 1;
%}

DIGIT	[0-9]

%%
 
 /* Keywords */ 

let       	{ return TOK_LET; }
read	  	{ return TOK_READ; }
print	  	{ return TOK_PRINT; }
if		  	{ return TOK_IF; }
while     	{ return TOK_WHILE; }

 /* Punctuation */

;         	{ return TOK_SEMICOLON; }
\(        	{ return TOK_OPENPAREN; }
\)        	{ return TOK_CLOSEPAREN; }
\{        	{ return TOK_OPENBRACE; }
\}        	{ return TOK_CLOSEBRACE; }

 /* Operators */

\+        	{ return TOK_PLUS; }
-         	{ return TOK_MINUS; }
\*        	{ return TOK_MULTIPLY; }
\/        	{ return TOK_DIVIDE; }
:=        	{ return TOK_ASSIGN; }
== 		  	{ return TOK_EQUALTO; }
"<"		  	{ return TOK_LESSTHAN; }
">"			{ return TOK_GREATERTHAN; }
and			{ return TOK_AND; }
or			{ return TOK_OR; }
not			{ return TOK_NOT; }
else 		{ return TOK_ELSE; }

 /* Abstractions */

[A-Za-z][0-9A-Za-z_]*  	{ return TOK_IDENTIFIER; }
{DIGIT}+               	{ return TOK_FLOATLIT; }
{DIGIT}+"."{DIGIT}*		{ return TOK_FLOATLIT; }
\"[^\"]*\"				{ return TOK_STRINGLIT; }

 /* Eat any whitespace */

[ \t\r]+               /* nop */

 /* Eat newline characters, AND increment line counter */

[\n]      	{ yyLine++; }

 /* Found an unknown character */

.         	{ return TOK_UNKNOWN; }

 /* Recognize end of file */
 
\"[^\"]* 	{ return TOK_EOF_SL; }
<<EOF>>   	{ return TOK_EOF; }


