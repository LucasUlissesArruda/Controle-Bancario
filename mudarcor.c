/*
Autor: Lucas Ulisses - Leonardo Henrique 
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include <windows.h> 

void mudar_cor(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}