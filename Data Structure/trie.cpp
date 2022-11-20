
///      *** Trie[(number of words)*(maximum lenght)]


/**
    Name : Trie with array
    This trie is for All Uppercase & Lowercase letters
*/

int mp(char ch){
    if(ch<95) return (int) (ch - 'A');
    return (int) (ch - 'a' + 26);
}

struct node{
    bool end;
    int next[55];
    int cnt; /// here cnt is counting how many element ends at this point
    void set(){
        cnt = 0;
        end = false;
        for(int i=0;i<=53;i++){
            next[i] = 0;
        }
    }
}ara[MX];

int ptr;

void insert(char *st){
    int i,in,x=0,y;
    for(i=0;st[i];i++){
        if(st[i]==' ') continue;
        in = mp(st[i]);
        /// If the chain is not exists
        /// allocating memory by ptr++ that means new array element
        if(!ara[x].next[in]){
            ///putting next arrays position at recent array's linked part
            ara[x].next[in] = ptr++;
            ara[ptr-1].set();
        }
        x = ara[x].next[in];
    }
    ///marking last element as last
    ara[x].end=1;
    ara[x].cnt++;
}


int search(char *st){
    int i,in,x=0,cn=0;
    for(i=0;st[i];i++){
        if(st[i]==' ')continue;
        cn++;
        in = mp(st[i]);
        ///if query element not exists then returning false
        if(!ara[x].next[in]) return 0;
        x = ara[x].next[in];
    }
    if(!cn) return 1;
    /// returning how many elements like "st"
    return ara[x].cnt;
}
