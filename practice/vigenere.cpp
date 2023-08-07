#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain_text, string key){
    int plainTextLength = plain_text.length();
    int keyLength = key.length();

    string encryptedText;

    for(int i = 0; i<plainTextLength; i++){
        char plainChar = plain_text[i];
        char keyChar = key[i%keyLength];

        if(isalpha(plainChar)){
            char base = isupper(plainChar)?'A':'a';
            char encryptedChar = (plainChar-base + keyChar-base)% 26 +base;
            encryptedText.push_back(encryptedChar);
        }else{
            encryptedText.push_back(plainChar);
        }
    }

    return encryptedText;
}

string decrypt(string encrypted_text, string key){
    string plain_text;

    int encryptedLength = encrypted_text.length();
    int keyLength = key.length();

    for(int i = 0; i < encryptedLength; i++){
        char encryptedChar = encrypted_text[i];
        char keyChar = key[i % keyLength];

        if(isalpha(encryptedChar)){
            char base = 'a';
            
            char plainChar = ((encryptedChar-base) -  (keyChar-base)+26) % 26 +base;
            plain_text.push_back(plainChar);
        }else{
            plain_text.push_back(encryptedChar);
        }
    }
    return plain_text;
}


int main(){
    string plain_text = "the cbgbz tycowh vdiqee the jocg, nmjnqv to oyss, flqn … to ifakzs g ydchihmq from khgkvaha didnyhq sst is xuh tuwoyiube. all prgh oi dyqhux are hdo fkci ez nature. … [jbmx is,] flulq can dkbs huyx m big xktu ihykzyix imjbayj the nshz ip sst, dnybwzoj dnu buiw of jkzino jbk-hqnq the qxojabys. ayh concept ut zygo niwczw with zva slogjcyt sv the abefkfoo. jbqvuzavu if dns rqqc aj nature ybkopoj dnu khuzulei, zvack vgmm ggwj have stsyhan jboel na time; jbkz mi the rosc ip zejodi would pa eodyyxo aj time. qrgj my have prkb oi jifebfk non-lregemgz rqqc, outside cb jcwk, creating k oxolybyu. now dnop tycihczzyix ymwbf sound yciocvwd zksyfsgh. very siyr fsqu jbq biblical mubyovh uv wip: xuh vxscosuv, outside cb jcwk, able du mxuudk  universe";
    string encryptedText = "qul zonuw arzbda ikbnrl qul gbjz, ufgaxo gv llzl, mena … ml pyxxgl t rapobezx cevf xozhihax kbaafan zlq pl kba gbpllpnyr. xys mena bp alxark tor aab yhpp bm gxgbkb. … [gotq vz,] meryx znu axil ubru t yvn uxan vorhmfbu pfgohrg aab ulem bm zlq, wklipwbq aab yhpp bm gxgbkb cyx-anax qul nkvcxofl. hre jhkpliq bm mfzl ubtpgp jpme gox zeltqvvg ls aab hubsrylb. goxormhor py qul exjz hc ahmrel vorhmbq aab hubsrylb, goxpr sttf tnpg otsr lqffaxa cyble ah qvtx; quhm ff aab yhpp bm gxgbkb jvniq ix lhalfql hc gpfb. jotq jl axil meru bp gvmxysr kbu-ielzbzns exjz, hrgzbar vy qvtx, zeltqvuz x hubsrylb. avp quhm arzvovwmfbu fftom pbbga fvfbjotq shffypto. ilkv zbve ypdb gox yviefphe zbuvbca hc tvw: kba ielzbzns, hrgzbar vy qvtx, xosx qb jkbnax  rapobezx";
    
    string key = "xnht";

    string encrypted =  encrypt(plain_text, key);

    string encryptedTextWithoutSpace;

    for(int i = 0; i < encryptedText.length(); i ++){
        if(isalpha(encryptedText[i])){
            encryptedTextWithoutSpace.push_back(encryptedText[i]);
        }
    }

    string decrypted = decrypt(encryptedTextWithoutSpace, key);

    // cout<<"Encrypted: " << encrypted <<endl;
    cout<<"Decrypted: " << decrypted <<endl;
}