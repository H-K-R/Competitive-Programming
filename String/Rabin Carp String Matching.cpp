
/// **** Rabin-Karp

#define MD 1000000009
using namespace std;

ll pm=31,powr[MX],hs[MX];

void powCalc(){
    powr[0] = 1;
    for(int i=1;i<MX;i++){
        powr[i] = (powr[i-1]*pm)%MD;
    }
}

vector<int> ans;

void rabin_karp(char txt[],char ptt[]){
    int P = strlen(ptt),T=strlen(txt),i,crr;

    memset(hs,0,sizeof hs);

    for(i=0; i<T; i++){
        hs[i+1] = (hs[i]+(txt[i]-'a'+1)*powr[i])%MD;
    }
    ll hss = 0;
    for(i=0; i<P; i++){
        hss = (hss+(ptt[i]-'a'+1)*powr[i])%MD;
    }

    for(i=0;i+P-1<T;i++){
        crr = (hs[i+P] - hs[i] + MD)%MD;

        if(crr == hss*powr[i]%MD){
            ans.push_back(i+1);
        }
    }
}


