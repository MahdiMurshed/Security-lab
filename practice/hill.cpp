#include<bits/stdc++.h>
using namespace std;

int col;
void  generateKeyMatrix(string key, int keyMatrix[3][3]){
    int index = 0;

    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 3; j++){
            keyMatrix[i][j] = key[index] - 'a';
            index++;
        }
    }
}

void generateMessageMatrix(string plain_text, int messageMatrix[][196]){
    int ind = 0;

    for(int i=0; i<196; i++){
        for(int j =0; j < 3; j++){
            messageMatrix[j][i] = plain_text[ind] - 'a';
            ind++; 
        }
    }
}

void encrypt(int encryptedMatrix[3][196], int plainMatrix[3][196], int keyMatrix[3][3]){
    int x, i, j;

    for(i = 0; i<3; i++){
        for(j = 0; j< 196; j++){
            encryptedMatrix[i][j] = 0;
            for(x = 0; x< 3; x++){
                encryptedMatrix[i][j] += plainMatrix[i][x] * keyMatrix[x][j];
            }
            encryptedMatrix[i][j] %= 26;
        }
    }
}


int main(){
    string plain_text = "the cbgbz tycowh vdiqee the jocg, nmjnqv to oyss, flqn … to ifakzs g ydchihmq from khgkvaha didnyhq sst is xuh tuwoyiube. all prgh oi dyqhux are hdo fkci ez nature. … [jbmx is,] flulq can dkbs huyx m big xktu ihykzyix imjbayj the nshz ip sst, dnybwzoj dnu buiw of jkzino jbk-hqnq the qxojabys. ayh concept ut zygo niwczw with zva slogjcyt sv the abefkfoo. jbqvuzavu if dns rqqc aj nature ybkopoj dnu khuzulei, zvack vgmm ggwj have stsyhan jboel na time; jbkz mi the rosc ip zejodi would pa eodyyxo aj time. qrgj my have prkb oi jifebfk non-lregemgz rqqc, outside cb jcwk, creating k oxolybyu. now dnop tycihczzyix ymwbf sound yciocvwd zksyfsgh. very siyr fsqu jbq biblical mubyovh uv wip: xuh vxscosuv, outside cb jcwk, able du mxuudk  universe";
    string encryptedText = "qul zonuw arzbda ikbnrl qul gbjz, ufgaxo gv llzl, mena … ml pyxxgl t rapobezx cevf xozhihax kbaafan zlq pl kba gbpllpnyr. xys mena bp alxark tor aab yhpp bm gxgbkb. … [gotq vz,] meryx znu axil ubru t yvn uxan vorhmfbu pfgohrg aab ulem bm zlq, wklipwbq aab yhpp bm gxgbkb cyx-anax qul nkvcxofl. hre jhkpliq bm mfzl ubtpgp jpme gox zeltqvvg ls aab hubsrylb. goxormhor py qul exjz hc ahmrel vorhmbq aab hubsrylb, goxpr sttf tnpg otsr lqffaxa cyble ah qvtx; quhm ff aab yhpp bm gxgbkb jvniq ix lhalfql hc gpfb. jotq jl axil meru bp gvmxysr kbu-ielzbzns exjz, hrgzbar vy qvtx, zeltqvuz x hubsrylb. avp quhm arzvovwmfbu fftom pbbga fvfbjotq shffypto. ilkv zbve ypdb gox yviefphe zbuvbca hc tvw: kba ielzbzns, hrgzbar vy qvtx, xosx qb jkbnax  rapobezx";
    
    string key = "abcdefghi";

    int keyMatrix[3][3];

    generateKeyMatrix(key, keyMatrix);

    // for(int i = 0; i< 3; i++){
    //     for(int j = 0; j < 3; j++){
    //        cout<< i <<", "<<j<<" :" <<keyMatrix[i][j]<<endl;
    //     }
    // }

    string encryptedTextWithoutSpace;

    for(int i = 0; i < encryptedText.length(); i ++){
        if(isalpha(encryptedText[i])){
            encryptedTextWithoutSpace.push_back(encryptedText[i]);
        }
    }

    int sizeToPad = encryptedTextWithoutSpace.size()%3;

    for(int i = 0; i< sizeToPad; i++){
        encryptedTextWithoutSpace+='a';
    }

    col = encryptedTextWithoutSpace.size()/3;
    int messageMatrix[3][196];

    generateMessageMatrix(encryptedTextWithoutSpace, messageMatrix);

    int cipherMatrix[3][196];

    encrypt(cipherMatrix, messageMatrix, keyMatrix);
    string cipherText;

    for(int i = 0; i< 196; i++){
        for(int j = 0; j<3;j++){
            cout<<cipherMatrix[j][i]<<" ";
            cipherText.push_back(cipherMatrix[j][i] + 'a');
        }
    }
  
    cout<<cipherText<<endl;


    return 0;
}