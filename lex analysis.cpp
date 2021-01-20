#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{

    int i,ic=0,m,cc=0,oc=0,pc = 0, qc = 0,j,k,l, constants[30];
    char b[30],operators[30],identifiers[30],keyword[30],punctuation[30];

    printf("enter the string : ");
    scanf("%[^\n]s",&b);
    for(i=0; i<strlen(b); i++)
    {
        if(isspace(b[i]))
        {
            k = i;
            break;
        }
        else if(isalpha(b[i]))
        {
            keyword[ic] =b[i];
            ic++;
        }
    }
    for(i=k;i<strlen(b);i++)
    {
        if(isalpha(b[i]))
        {
            identifiers[pc] =b[i];
            pc++;
        }
        else if(isdigit(b[i]))
        {
            m=(b[i]-'0');
            i=i+1;
            while(isdigit(b[i]))
            {
                m=m*10 + (b[i]-'0');
                i++;
            }
            i=i-1;
            constants[cc]=m;
            cc++;
        }
        else
        {
            if(b[i]=='*' || b[i]=='+' || b[i]=='/' || b[i]=='-')
            {
                operators[oc]= b[i];
                oc++;
            }
            else if(b[i]==':' || b[i]==';' || b[i]==',')
            {
                punctuation[qc] = b[i];
                qc++;
            }
        }
    }

    printf("keyword: ");
    for(i=0;i<ic;i++)
        printf("%c",keyword[i]);
    printf("\nidentifiers: ");
    for(i=0; i<pc; i++)
    {
        if(i!=(pc-1))
            printf("%c, ",identifiers[i]);
        else
            printf("%c\n",identifiers[i]);
    }
    printf("constants: ");
    for(i=0; i<cc; i++)
    {
        if(i!=(cc-1))
            printf("%d, ",constants[i]);
        else
            printf("%d\n",constants[i]);
    }
    printf("operators: ");
    for(i=0; i<oc; i++)
    {
        if(i!=(oc-1))
            printf("%c, ",operators[i]);
        else
            printf("%c\n",operators[i]);
    }
    printf("punctuation: ");
    for(i=0; i<qc; i++)
    {
        if(i!=(qc-1))
            printf("%c, ",punctuation[i]);
        else
            printf("%c\n",punctuation[i]);
    }
    return 0;
}
