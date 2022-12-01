///    **** Knuth–Morris–Pratt(KMP) [n+k]

#define MX 1000005
///Largest possible suffix-prefix upto this index
int lps[MX];

/// prefix size is (j+1) as key i 0 based index

void lps_calc(char key[]){
    int i = 1,j = 0;
    while(key[i]){
        //cout<<"ff\n";
        if(key[i]==key[j]){
            lps[i] = ++j;
            i++;
        }
        else{
            if(j) j = lps[j-1];
            else lps[i++] = 0;
        }
    }
}
/**
*   @return -1 if no match found else return staring position of match
*/
int match(char txt[],char key[],int key_ln){
    int i=0,j=0,cn=0;
    while(txt[i]){
        if(txt[i]==key[j]){
            i++;
            j++;
            if(j==key_ln){
                return i - key_ln; //satring pos
                ///How many match
                //cn++;
                //j=lps[j-1];
            }
        }
        else{
            if(j) j = lps[j-1];
            else i++;
            /// j = 0 and pos are not equal then skipping this position
        }
    }
    return cn;
}

char txt[MX],key[MX];
