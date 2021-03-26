/**************************************************************/
/* 
    Scopo:      funzioni per la crittografia del testo 
                contenuto in un file
    Argomenti:  nomi del file di input e del file di output
*/
/**************************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include <ctype.h>

/* costante */
#define MAX_CARATTERI 51

/* variabile globale */
char tabella_a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


/********************************/
/* dichiarazione delle funzioni */
/********************************/
int codifica(int);
int decodifica(int);


/****************************************************************/
/* definizione della funzione codifica

   Scopo:   acquisisce da tastiera il nome di un file da leggere 
            e poi scrive sul file chiamato codificato.txt 
            il contenuto del primo file codificato
*/
/***************************************************************/
int codifica(int chiave)
{
    /* dichiarazione delle variabili locali */
    FILE *filein_p,     /* lavoro: puntatore al file di input */
        *fileout_p;     /* lavoro: puntatore al file di output */
    char filein[50];   /* input: nome del file di input*/
    int c,              /* input: carattere alfanumerico */
        indice,         /* lavoro: indice per l'accesso ad array */
        esito,         /* output: valore da restituire all'esterno */
        indice_chiave;  /* lavoro: indice modificato con la chiave */
    
    
    /* inizializzazione */
    esito = 0;
    c = 0;
   
    /* recupera il nome del file di input */
    printf("Nome del file da crittografare = ");
    scanf("%s",
            filein);
    
    /* apre il file di input in modalit� di lettura: se non esiste informa l'utente */
    if ((filein_p = fopen(filein,
                          "r")) != NULL)
    {
        /* apre il file di output in modalit� di scrittura: se non esiste lo crea */
        if ((fileout_p = fopen("codificato.txt",
                               "w")) != NULL)
        {
            /* verifica che il file di input non sia vuoto */
            if (!feof(filein_p))
                /* scorre il file di input fino alla fine */
                while ((c = fgetc(filein_p)) != EOF)
                {
                    /* se si tratta di un carattere alfabetico */
                    if (isalpha(c))
                    {
                        /* ricerca la codifica corrispondente */
                        for(indice = 0;
                            tabella_a[indice] != 0;
                            indice++)
                        {
                            if(tabella_a[indice] == c)
                            {
                                /* modifica l'indice sulla base della chiave */
                                indice_chiave = indice + chiave;
                                
                                if(indice_chiave <= MAX_CARATTERI)
                                    /* memorizza la codifica trovata nel file di output */
                                    fputc(tabella_a[indice_chiave], 
                                          fileout_p);
                                else
                                    /* memorizza la codifica trovata nel file di output */
                                    fputc(tabella_a[indice_chiave - MAX_CARATTERI], 
                                          fileout_p);
                            }
                        }
                    }
                    else
                        /* memorizza il carattere letto dal file di input nel file di output */
                        fputc(c, 
                              fileout_p);
                        
                }
            
            /* verifica l'eventuale presenza di errori in scrittura sul file di output */
            if (ferror(fileout_p))
                /* restituisce un codice di errore */
                esito = 1;
            
            /* chiude il file di output */
            fclose(fileout_p);
        }
         else
            /* il file di output non pu� essere aperto: restituisce un codice di errore */
            esito = 2;

        /* verifica l'eventuale presenza di errori in lettura sul file di input */
        if (ferror(filein_p))
            /* restituisce un codice di errore */
            esito = 3;

        /* chiude il file di input */
        fclose(filein_p);
    }
    else
        /* il file di input non esiste: restituisce un codice di errore */
        esito = 4;

    /* restituisce un intero significativo */
    return(esito);
}

/****************************************************************/
/* definizione della funzione decodifica

   Scopo:   acquisisce da tastiera il nome di un file da leggere 
            e poi scrive sul file chiamato decodificato.txt 
            il contenuto del primo file dopo averlo decodificato
*/
/***************************************************************/
int decodifica(int chiave)
{
    /* dichiarazione delle variabili locali */
    FILE *filein_p,     /* lavoro: puntatore al file di input */
        *fileout_p;     /* lavoro: puntatore al file di output */
    char filein[50];    /* input: nome del file di input*/
    int c,              /* input: carattere alfanumerico */
        indice,         /* lavoro: indice per l'accesso ad array */
        esito,         /* output: valore da restituire all'esterno */
        indice_chiave;  /* lavoro: indice modificato con la chiave */
    
    
    /* inizializzazione */
    esito = 0;
    c = 0;
   
    /* recupera il nome del file di input */
    printf("Nome del file da decrittografare = ");
    scanf("%s",
            filein);
    
    /* apre il file di input in modalit� di lettura: se non esiste informa l'utente */
    if ((filein_p = fopen(filein,
                          "r")) != NULL)
    {
        /* apre il file di output in modalit� di scrittura: se non esiste lo crea */
        if ((fileout_p = fopen("decodificato.txt",
                               "w")) != NULL)
        {
            /* verifica che il file di input non sia vuoto */
            if (!feof(filein_p))
                /* scorre il file di input fino alla fine */
                while ((c = fgetc(filein_p)) != EOF)
                {
                    /* se si tratta di un carattere alfabetico */
                    if (isalpha(c))
                    {
                        /* ricerca la decodifica corrispondente */
                        for(indice = 0;
                            tabella_a[indice] != 0;
                            indice++)
                        {
                            if(tabella_a[indice] == c)
                            {
                                /* modifica l'indice sulla base della chiave */
                                indice_chiave = indice - chiave;
                                
                                if(indice_chiave >= 0)
                                    /* memorizza la codifica trovata nel file di output */
                                    fputc(tabella_a[indice_chiave], 
                                          fileout_p);
                                else
                                    /* memorizza la codifica trovata nel file di output */
                                    fputc(tabella_a[MAX_CARATTERI + indice_chiave], 
                                          fileout_p);
                            }
                        }
                    }
                    else
                        /* memorizza il carattere letto dal file di input nel file di output */
                        fputc(c, 
                              fileout_p);
                        
                }
                
            /* verifica l'eventuale presenza di errori in scrittura sul file di output */
            if (ferror(fileout_p))
                /* restituisce un codice di errore */
                esito = 1;
            
            /* chiude il file di output */
            fclose(fileout_p);
        }
         else
        {
            /* il file di output non pu� essere aperto: restituisce un codice di errore */
            esito = 2;
        }
        /* verifica l'eventuale presenza di errori in lettura sul file di input */
        if (ferror(filein_p))
            /* restituisce un codice di errore */
            esito = 3;

        /* chiude il file di input */
        fclose(filein_p);
    }
    else
    {
        /* il file di input non esiste: restituisce un codice di errore */
        esito = 4;
    }
    /* restituisce un intero significativo */
    return(esito);
}
