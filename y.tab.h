
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RIGHT = 258,
     LEFT = 259,
     EQUAL = 260,
     ROT_Z_POS = 261,
     ROT_Z_NEG = 262,
     ROT_Y_POS = 263,
     ROT_Y_NEG = 264,
     ROT_X = 265,
     VAR_NAME = 266,
     SEMICOL = 267,
     ANGLE = 268,
     NUMBER = 269,
     RBRA = 270,
     LBRA = 271,
     ITER = 272,
     RENDER = 273,
     DEFINE = 274,
     AXIOM = 275,
     NAME = 276
   };
#endif
/* Tokens.  */
#define RIGHT 258
#define LEFT 259
#define EQUAL 260
#define ROT_Z_POS 261
#define ROT_Z_NEG 262
#define ROT_Y_POS 263
#define ROT_Y_NEG 264
#define ROT_X 265
#define VAR_NAME 266
#define SEMICOL 267
#define ANGLE 268
#define NUMBER 269
#define RBRA 270
#define LBRA 271
#define ITER 272
#define RENDER 273
#define DEFINE 274
#define AXIOM 275
#define NAME 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


