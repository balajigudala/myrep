



char * rem_space(char *str)
{
        int i,j=0;
        for(i=0;str[i]!='\0';i++)
        {
                while(str[i]==' ')
                {
                        i++;
                        if(str[i]!=' ')
                        {
                                i--;
                                goto print;
                        }
                }
print:
                str[j]=str[i];
                j++;
        }
        str[j]='\0';
        return str;
}


