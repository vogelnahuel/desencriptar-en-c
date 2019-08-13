
#include "funciones.h"




/** ----------------------------- x --- o --- x ----------------------------- */

/// funciones a resolver obligatoriamente:
void leerPonerEnListaSacarReemplazarYGrabar(FILE *fpEnt, FILE *fpSal,
        FILE *fpMal, tListaD *lista)
{
    char linea[200];
    int valor=0;
    while( fgets(linea,200,fpEnt) )
    {
        valor=empiezaConFechaYHora(linea);
        if(valor!=1)
            fprintf(fpMal,"%s",linea);
        else
            insertarEnOrden(lista,(tInfo*)linea,compXFechaYHora_2);
    }
    char linea2[200];
    while( sacarPrimero(lista,(tInfo*)linea2) )
    {
        reemplazarAbreviaciones(linea2);
        fprintf(fpSal,"%s",linea2);
    }


}

int insertarEnOrden(tListaD *p, const tInfo *d,
                    int (*comp)(const tInfo *d1, const tInfo *d2))
{
    tNodoD *pant,*psig;
    int cmp;
    if(*p!=NULL)
    {
        while( (cmp=(strcmp((*p)->info.linea,d->linea)))>0 &&(*p)->ant!=NULL)
            p=&(*p)->ant;
        while( (cmp=(strcmp((*p)->info.linea,d->linea)))<0 &&(*p)->sig!=NULL)
            p=&(*p)->sig;
        if(cmp>0)
        {
            pant=(*p)->ant;
            psig=*p;

        }
        else
        {
            pant=*p;
            psig=(*p)->sig;

        }
    }
    else
    {
        pant=psig=NULL;
    }
    tNodoD *aux=(tNodoD*)malloc(sizeof(tNodoD));
    if(aux==NULL)
        return SIN_MEM;
    aux->info=*d;
    aux->ant=pant;
    aux->sig=psig;
    if(pant!=NULL)
        pant->sig=aux;
    if(psig!=NULL)
        psig->ant=aux;
    *p=aux;
    return TODO_BIEN;

}

int empiezaConFechaYHora(const char *s)
{
    int i;
    for(i=0; i<23; i++)
    {
        if( (*s>='0' && *s<='9' ) || *s=='/' || *s==':' || *s==' '|| *s==',')
        {
            s++;
        }
        else
        {
            return 0;
        }

    }

    return 1;
}

void reemplazarAbreviaciones(char *s)
{
    char *aux=s;
    int i=0;
    int aciertos=0;
    char *donde_reemplazar=s;
    char caso;
    char casoD[9]="Document",casos[11]="successful",casop[45]="I: / MigraOnDemant / FAC-2003-ABR-MesEntero",casoA[11]="Attempting",casoQ[50]="queryring for application group",casoq[50]="queryring database with SQL string ",casor[50]="retrieved and stored in file";
    while(*aux!='\0')
    {
        if(*aux=='D'||*aux=='s'||*aux=='p'||*aux=='A'||*aux=='Q'||*aux=='q'||*aux=='r'||aciertos==1)
        {
            aciertos++;
          if(aciertos==2&&*aux!='*')
            aciertos=0;
            if(aciertos==2)
            {
                switch(caso)
                {
                case 'D':
                    while(casoD[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casoD[i];
                    donde_reemplazar++;
                    i++;
                    }break;
                case 's':
                    while(casos[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casos[i];
                                        donde_reemplazar++;
                    i++;
                    }
                    break; 
                case 'p':
                    while(casop[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casop[i];
                                        donde_reemplazar++;

                    i++;
                    }
                break;
                case 'A':
                    while(casoA[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casoA[i];
                    donde_reemplazar++;

                    i++;
                    }
                break ; 
                 case 'Q':
                     while(casoQ[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casoQ[i];
                    donde_reemplazar++;

                    i++;
                    }
                break ; 
                 case 'q':
                     while(casoq[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casoq[i];
                                        donde_reemplazar++;
                    i++;
                    }
                break ; 
                 case 'r':
                     while(casor[i]!='\0'&&*donde_reemplazar!='\0')
                    {*donde_reemplazar=casor[i];
                    donde_reemplazar++;
                    i++;
                    }
                break ;               

                }

            }
            caso=*aux;
            donde_reemplazar=aux;
            i=0;
        }
        else
        {
            aciertos=0;
            caso=' ';
        }

        aux++;
    }


}



/** funciones adicionales a resolver
    NO IMPLICAN APROBACIÖN, SÓLO MEJORAR LA CALIFICACIÓN*/
int sacarPrimero(tListaD *p, tInfo *d)
{
    if(*p!=NULL)
       {
        tNodoD *aux,*act=*p;
        while( (act)->ant!=NULL)
        act=act->ant;
        aux=act;
        act=aux->sig;
        *d=aux->info;
        free(aux);
        if(act!=NULL)
        act->ant=NULL;
        *p=act;
        return 1;
       }
       return 0;
}

int compXFechaYHora(const tInfo *d1, const tInfo *d2)
{

}
int MIstrcmp(const char *s1,  const char*s2)
{
    
}

/**funciones de string.h y ctype.h utilizadas (escribirlas con el sufijo  _MIO,
    p.ej.:  strlen_MIO, con prototipos consistentes con los de biblioteca)
*/


void crearListaD(tListaD *p)
{
    *p = NULL;
}


