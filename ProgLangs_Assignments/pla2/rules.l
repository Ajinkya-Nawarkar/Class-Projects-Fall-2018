/*****************************************************************************
// CSE 4713 / 6713 Assignment 2 example flex file
*****************************************************************************/
%option noyywrap
%{
#include "lexer.h"
%}

DIGIT	[0-9]
ID	[a-zA-Z][a-zA-Z0-9_]*


%%

[ \t\n\r]+ ;
if						{ return TOK_IF; 			}
else 					{ return TOK_ELSE;			}
for						{ return TOK_FOR; 			}
while					{ return TOK_WHILE; 		}
print					{ return TOK_PRINT; 		}
return					{ return TOK_RETURN; 		}
continue				{ return TOK_CONTINUE; 		}
break					{ return TOK_BREAK; 		}
debug 					{ return TOK_DEBUG; 		}
read					{ return TOK_READ; 			}	 
let 					{ return TOK_LET; 			}
int						{ return TOK_INT;			}
float 					{ return TOK_FLOAT;			}    
string					{ return TOK_STRING; 		}  
";"						{ return TOK_SEMICOLON; 	} 
"("						{ return TOK_OPENPAREN; 	}
")"						{ return TOK_CLOSEPAREN; 	}
"["						{ return TOK_OPENBRACKET; 	}
"]"						{ return TOK_CLOSEBRACKET; 	}
"{"						{ return TOK_OPENBRACE; 	}
"}"						{ return TOK_CLOSEBRACE; 	} 
","						{ return TOK_COMMA; 		}  
"+"						{ return TOK_PLUS; 			}	  
"-"						{ return TOK_MINUS; 		} 
"*"						{ return TOK_MULTIPLY; 		}
"/"						{ return TOK_DIVIDE; 		} 
":="					{ return TOK_ASSIGN; 		} 
"=="					{ return TOK_EQUALTO; 		}
"<>"					{ return TOK_NOTEQUALTO; 	}
"<" 					{ return TOK_LESSTHAN; 		}   
">"						{ return TOK_GREATERTHAN;	}   
and						{ return TOK_AND;      		}
or						{ return TOK_OR;      		}
not						{ return TOK_NOT;    		}
length					{ return TOK_LENGTH ; 		}
{ID}					{ return TOK_IDENTIFIER;  	}
{DIGIT}+				{ return TOK_INTLIT;   		}
{DIGIT}+"."{DIGIT}*		{ return TOK_FLOATLIT; 		}
\"[^\"]*				{ return TOK_UT_SL;			}
\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"			{ return TOK_STRINGLIT;   	}

<<EOF>> 				{ return TOK_EOF; 			}
. 						{ return TOK_UNKNOWN;		}

%%