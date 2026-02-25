/*#include <iostream>
#include <cstring>
using namespace std;
char line[1001], words[101][101];
int wordCount;
int main() 
{
    cin.getline(line, 1001);
    char* p=strtok(line, " ");
    while(p!= NULL && wordCount<101) 
    {
        strncpy(words[wordCount], p, 100);
        wordCount++;
        p=strtok(NULL, " ");
    }

    for (int i=0; i<wordCount-1; i++) 
        for (int j = i+1; j<wordCount; j++) 
        {
            int lenI=(int)strlen(words[i]);
            int lenJ=(int)strlen(words[j]);
            bool swapNeeded=false;
            if (lenJ>lenI || (lenJ==lenI && strcmp(words[j], words[i])<0)) {
                char tmp[101];
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }
        }
    for (int i=0; i<wordCount; i++)
        cout<<words[i]<<"\n";
    return 0;
}*/

#include <stdio.h>
#include <string.h>
char line[1001], words[101][101];
int wordCount;
int main(void)
{
    if (scanf("%1000[^\n]", line)!=1) return 0;
    char *p=strtok(line, " ");
    while(p!=NULL && wordCount<101)
    {
        strncpy(words[wordCount], p, 100);
        wordCount++;
        p=strtok(NULL, " ");
    }
    for (int i=0; i<wordCount-1; i++)
        for (int j=i+1; j<wordCount; j++)
        {
            int lenI=(int)strlen(words[i]);
            int lenJ=(int)strlen(words[j]);

            if (lenJ>lenI || (lenJ==lenI && strcmp(words[j], words[i])<0))
            {
                char tmp[101];
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }
        }
    for (int i=0; i<wordCount; i++)
        printf("%s\n", words[i]);
    return 0;
}