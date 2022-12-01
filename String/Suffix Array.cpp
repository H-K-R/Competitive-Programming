/**
    Name : Suffix array
    Description : it gives all suffixes in sorted form on an array
    the array contains starting position of suffixes in sorted order
    Longest common prefix array contains long match with the previous suffix in sorted form
    Complexity : O(n^2Logn)
    Ex :

    0 banana                          5 a
    1 anana     Sort the Suffixes     3 ana
    2 nana      ---------------->     1 anana
    3 ana        alphabetically       0 banana
    4 na                              4 na
    5 a                               2 nana
    So the suffix array for "banana" is {5, 3, 1, 0, 4, 2}

    Uses :

        * number of uniqe substring of a string : n(n+1)/2 − ∑ lcp[i] (summation of all lcp is duplicate string as lcp means longest match with the prev string)
        * longest common substring by sliding window   (add special character and joint all strings then calculate lcp and by sliding window we can determine the longest substring)
        * longest repeated substring : maximum value of lcp is longest repeated substring, number of the maximum number is the longest repeated substring is the longest repeated substring
        * Finding a substring in a string : by binary search on the lcp array
*/

#define MX 10005

int sfa[10009],pos[10009],tmp[10009],lcp[10009],gap=1,ln;
char ss[10009];
bool scmp(int a,int b)
{
    if(pos[a]!=pos[b])return pos[a]<pos[b];
    a+=gap;
    b+=gap;
    return (a<ln&&b<ln)?pos[a]<pos[b]:a>b;

}
void buildsa()
{
    int i,j;
    ln=strlen(ss);
    for(i=0;i<=ln;i++){
        sfa[i]=i;
        pos[i]=ss[i];
    }
    for(gap=1;;gap*=2){
        sort(sfa,sfa+ln,scmp);
        for(i=0;i<ln;i++){
            tmp[i+1]=tmp[i]+scmp(sfa[i],sfa[i+1]);
        }
        for(i=0;i<ln;i++)pos[sfa[i]]=tmp[i];
        if(tmp[i]==ln-1)break;
    }
}
void buildlcp()
{
    int i,j,k;
    for(i=0,k=0;i<ln;i++){
        if(pos[i]==ln-1)continue;
        for(j=sfa[pos[i]+1];ss[i+k]==ss[j+k];)k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
    lcp[ln-1] = 0;
}
