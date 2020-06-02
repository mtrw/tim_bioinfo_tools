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
    
    const long int selectpos = strtol(argv[7],&ssend,10);
    
    if(s1len!=s2len){
        printf("STRINGS ARE OF UNEQUAL LENGTH\n");
        exit(1);
    }
    for(int i=0; i<s1len; i++ ){
        //printf("LOOP\n");
        if(s1[i]!='-'){
            s1pos = s1pos + inc1;
        }
        
        if (s2[i]!='-'){
            s2pos = s2pos + inc2;
        }

        //printf("i is %d\n\t",i);
        //printf("positions are %d:%d (selecting %d)\n\t",s1pos,s2pos,selectpos);
        //printf("chars are %c:%c\n\t",s1[i],s2[i]);
        //if (i!=0 && i!=(s1len-1) ){
        //    printf("nearby chars on s1/s2 are %c:%c/%c:%c\n",s1[i-1],s1[i+1],s2[i-1],s2[i+1]);
        //}
        
        if (s1pos==selectpos){
            if ((i==0 || i==(s1len-1) ) || (s1[i]!='-' && s2[i]!='-' && s1[i-1]!='-' && s2[i-1]!='-' && s1[i+1]!='-' && s2[i+1]!='-' )) {
                printf("%d\t%d\t%c\t%c\n",s1pos,s2pos,s1[i],s2[i]);
            } else {
                printf("NA\tNA\tNA\tNA\n");
            }
            exit(0);
        }
    }
    //position not in alignment
    printf("NA\tNA\tNA\tNA\n");
    exit(1);
}
