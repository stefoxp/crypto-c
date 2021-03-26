/**************************************************************/
/* 
    Scopo:      programma per la crittografia del testo 
                contenuto in un file di testo
    Argomenti:  nomi del file di input e del file di output
*/
/**************************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include "crittografia.h"

int main()
{
    int chiave_critto,      /* input: chiave da utilizzare per la crittografia */
        esito;               /* output: esito delle funzioni */
    
    /* inizializzazione */
    chiave_critto = 60;
    esito = 0;
    
    /* acquisisce la chiave da tastiera e la verifica */
    while((chiave_critto < 1) || (chiave_critto > 51))
    {
        printf("Inserire un intero (compreso fra 1 e 51): ");
        scanf("%d", 
                &chiave_critto);
    }
    
    /* chiama la funzione che si occupa della codifica */
    esito = codifica(chiave_critto);
    
    if (esito > 0)
        printf("\nProblemi con la funzione di codifica!\n");
    
    /* chiama la funzione che si occupa della decodifica */
    esito = decodifica(chiave_critto);
    
    if (esito > 0)
        printf("\nProblemi con la funzione di decodifica!\n");

    
    /* restituisce un codice di esito */
    return(0);
}
