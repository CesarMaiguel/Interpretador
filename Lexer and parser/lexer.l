%{
#include <stdio.h>
#include <stdlib.h>
#include "AnalizadorSintactico.h";
%}

%option noyywrap
%option yylineno

ignore " "|\t|\n|\r
caracter [A-Za-z]
digito [0-9]
boleano "true"|"false"

%%

{ignore}				{;}
"."					{return ('.');}
"{"					{return ('{');}
"}"					{return ('}');}
";"					{return (';');}
","					{return (',');}
"("					{return ('(');}
")"					{return (')');}
"["					{return ('[');}
"]"					{return (']');}
"si"					{return IF;}
"sino_si"				{return ELSEIF;}
"sino"					{return ELSE;}
"main"					{return MAIN;}
"integer"				{return ITGR;}
"decimal"				{return DOU;}
"bool"					{return T_F;}
"text"					{return TEXT;}
"para"					{return FOR;}
"mientras"				{return WHILE;}
"+"					{return SUMA;}
"-"					{return RESTA;}
"*"					{return MULTIPLICACION;}
"/"					{return DIVISION;}
"++"					{return AUMENTAR;}
"--"					{return DISMINUIR;}
":="					{return ASIGNADOR;}
">"					{return MAYOR;}
"<"					{return MENOR;}
"=="					{return IGUAL;}
">="					{return MAYORIGUAL;}
"<="					{return MENORIGUAL;}
"<>"					{return DIFERENTE;}
{digito}+				{return ENTERO;}
{digito}+"."{digito}			{return DECIMAL;}
{boleano}				{return BOLEANO;}
"\""({digito}|{caracter}|" ")*"\""	{return CADENA;}
{caracter}({caracter}|(digito))*	{return NOMBRECAMPO;}
.					{printf("Error en la linea: %d\n",yylineno);}


%%

yyerror(char *msg)
{
printf("%s\n", msg);
}

int main(void)
{
char nombreArchivo[50];
printf("Nombre del archivo: ");
scanf("%s",&nombreArchivo);
yyin = fopen(nombreArchivo, "rt");
if(yyin == NULL){
printf("\nNo se puede leer el archivo\n");
}
else{

    int successfull = yyparse();

    if(successfull==0){
        printf("Compilation successfully!\n");
        printf("-------------------------\n");
        printf("- Errors: 0\n");
        printf("- Warnings: 0\n");
    }
}

fclose(yyin);
getchar();
}
