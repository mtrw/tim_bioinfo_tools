#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char * argv[] ){
    char * ssend;
    const long int inc1 = strtol(argv[2],&ssend,10);
    const long int inc2 = strtol(argv[5],&ssend,10);
    
    const long int s1start = strtol(argv[1],&ssend,10) - inc1;
    const long int s2start = strtol(argv[4],&ssend,10) - inc2;
    
    
    //printf("incs: %d %d\n",inc1,inc2);
    
    char * s1 = argv[3];
    char * s2 = argv[6];
    
    long int s1pos = s1start;
    long int s2pos = s2start;
    
    long int s1len = strlen(s1);
    long int s2len = strlen(s2);
    
    if(s1len!=s2len){
        printf("STRINGS ARE OF UNEQUAL LENGTH");
        exit(1);
    }
    int gapflag;
    for(int i=0; i<s1len; i++ ){
        gapflag = 0;
        
        if(s1[i]!='-'){
            //printf("Increment 1\t");
            s1pos = s1pos + inc1;
        } else {
            gapflag = 1;
        }
        
        if (s2[i]!='-'){
            //printf("Increment 2\t");
            s2pos = s2pos + inc2;
        }  else {
            gapflag = 1;
        }
        //printf("i is %d ____ \t",i);
        //printf("chars are %c:%c _____ \t",s1[i],s2[i]);
        //printf("positions are %d:%d _____ \t",s1pos,s2pos);
        
        if ((s1[i]!=s2[i]) && (gapflag==0) && ((i==0 || i==(s1len-1) ) || (s1[i-1]!='-' && s2[i-1]!='-' && s1[i+1]!='-' && s2[i+1]!='-' ))){

            printf("%d\t%d\t%c\t%c\n",s1pos,s2pos,s1[i],s2[i]);
        }
        //printf("\n");
    }
    exit(0);
}
