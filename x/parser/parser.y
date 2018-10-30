%skeleton "lalr1.cc"
%define api.namespace {x::parser}
%define api.value.type variant
%define api.token.constructor
%define parse.assert
%define parse.error verbose
%param {x::program &prog}

%code requires {
#include "program.h"
#include "lexer.h"
} // code requires

%token END 0
%token IDENTIFIER NUMCONST
%token RETURN "<[]>" WHILE "while" IF "if" ELSE "else" VAR "var" VAR16 "var16" SPRITE "spr" CONST "const"
%token LOR "||" LAND "&&" LEQ "==" LNE "!="
%token PP "++" MM "--" PTR "*" ADDR "$"
%token PL "+" MI "-" OR "|" AND "&" XOR "^" LSH "<<" RSH ">>"
%token EQ "=" PL_EQ "+=" MI_EQ "-=" OR_EQ "|=" AND_EQ "&=" XOR_EQ "^=" LSH_EQ "<<=" RSH_EQ ">>="

%nonassoc IF
%nonassoc ELSE

%right EQ PL_EQ MI_EQ OR_EQ AND_EQ XOR_EQ LSH_EQ RSH_EQ
%left LOR
%left LAND
%left LEQ LNE
%left OR
%left XOR
%left AND
%left LSH RSH
%left PL MI
%right PP MM PTR ADDR
%left '(' '[' '<'

%%
library:
	functions;

functions: functions IDENTIFIER block
|	%empty;

statement: named_block
|	block
|	label
|	hard_stat
|	var;

named_block: IDENTIFIER block;

block: '{' statements '}';

statements: statements statement
|	statement;

label: IDENTIFIER ':' hard_stat;

hard_stat: conditional
|	while
|	jump
|	call
|	return
|	assign_expr
|	nop;

conditional: IF expr statement
|	IF expr statement ELSE statement;

while: WHILE expr statement;

jump: '<' expr '>' sep;

call: '[' IDENTIFIER ']' sep;

return: RETURN sep;

nop: ';';

var: var_type IDENTIFIER sep
|	var_type IDENTIFIER EQ expr sep
|	CONST IDENTIFIER EQ expr sep;

var_type: VAR
|	VAR16
|	SPRITE;

expr: literal
|	IDENTIFIER
|	binary_expr
|	unary_expr;

literal: NUMCONST
|	'(' num_arr ')';

num_arr: num_arr ',' NUMCONST
|	NUMCONST;

binary_expr: expr LOR expr
|	expr LAND expr
|	expr LEQ expr
|	expr LNE expr
|	expr PL expr
|	expr MI expr
|	expr OR expr
|	expr AND expr
|	expr XOR expr;

unary_expr: PP expr
|	MM expr
|	PTR expr
|	ADDR expr
|	expr PP
|	expr MM;

assign_expr: IDENTIFIER EQ expr sep
|	IDENTIFIER PL_EQ expr sep
|	IDENTIFIER MI_EQ expr sep
|	IDENTIFIER OR_EQ expr sep
|	IDENTIFIER AND_EQ expr sep
|	IDENTIFIER XOR_EQ expr sep;

sep: '\n'
|	';';

