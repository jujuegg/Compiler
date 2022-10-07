/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MUL = 260,
    DIV = 261,
    LP = 262,
    RP = 263,
    LMP = 264,
    RMP = 265,
    SEMICOLON = 266,
    COLON = 267,
    DOT = 268,
    COMMA = 269,
    ASSIGN = 270,
    EQ = 271,
    GT = 272,
    LT = 273,
    LE = 274,
    GE = 275,
    NEWLINE = 276,
    ABSOLUTE = 277,
    AND = 278,
    BEGIN_ = 279,
    BREAK = 280,
    CASE = 281,
    CONST = 282,
    CONTINUE = 283,
    DO = 284,
    ELSE = 285,
    END = 286,
    FOR = 287,
    FUNCTION = 288,
    IF = 289,
    MOD = 290,
    NIL = 291,
    NOT = 292,
    OBJECT = 293,
    OF = 294,
    OR = 295,
    PROGRAM = 296,
    THEN = 297,
    TO = 298,
    WHILE = 299,
    ARRAY = 300,
    INTEGER = 301,
    DOUBLE = 302,
    WRITE = 303,
    WRITELN = 304,
    STRING = 305,
    FLOAT = 306,
    READ = 307,
    VAR = 308,
    NUMBER = 309,
    ID = 310,
    STR = 311
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define LP 262
#define RP 263
#define LMP 264
#define RMP 265
#define SEMICOLON 266
#define COLON 267
#define DOT 268
#define COMMA 269
#define ASSIGN 270
#define EQ 271
#define GT 272
#define LT 273
#define LE 274
#define GE 275
#define NEWLINE 276
#define ABSOLUTE 277
#define AND 278
#define BEGIN_ 279
#define BREAK 280
#define CASE 281
#define CONST 282
#define CONTINUE 283
#define DO 284
#define ELSE 285
#define END 286
#define FOR 287
#define FUNCTION 288
#define IF 289
#define MOD 290
#define NIL 291
#define NOT 292
#define OBJECT 293
#define OF 294
#define OR 295
#define PROGRAM 296
#define THEN 297
#define TO 298
#define WHILE 299
#define ARRAY 300
#define INTEGER 301
#define DOUBLE 302
#define WRITE 303
#define WRITELN 304
#define STRING 305
#define FLOAT 306
#define READ 307
#define VAR 308
#define NUMBER 309
#define ID 310
#define STR 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 116 "B083040019.y" /* yacc.c:1909  */

    float 	floatVal;
    int 	intVal;

#line 171 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
