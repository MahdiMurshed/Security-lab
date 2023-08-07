#include<bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/vigenere-cipher/

// Function to encrypt a plaintext using Vigenere cipher
string encryptVigenereCipher(const string& plaintext, const string& key) {
    string encryptedText;
    int keyLength = key.length();
    int plaintextLength = plaintext.length();

    for (int i = 0; i < plaintextLength; ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength]; // Repeating key characters

        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            char encryptedChar = (plainChar - base + (keyChar - base)) % 26 + base;
            encryptedText.push_back(encryptedChar);
        } else {
            encryptedText.push_back(plainChar); // Keep non-alphabetic characters as is
        }
    }

    return encryptedText;
}


string decryptVigenereCipher(string cipher_text, string key){
    string plainText;
    int cipherLength = cipher_text.length();
    int keyLength = key.length();

    for(int i = 0; i<cipherLength; i++){
        char cipher = cipher_text[i];
        char keyChar = key[i%keyLength];

        if(isalpha(cipher)){
            char base = isupper(cipher) ? 'A' : 'a';
            char plainChar = (((cipher-base) - (keyChar-base))+26)%26+base;

            plainText.push_back(plainChar);
        }else{
            plainText.push_back(cipher);
        }
    }

    return plainText;

}

int main() {
    string plaintext = "qul zonuw arzbda ikbnrl qul gbjz, ufgaxo gv llzl, mena … ml pyxxgl t rapobezx cevf xozhihax kbaafan zlq pl kba gbpllpnyr. xys mena bp alxark tor aab yhpp bm gxgbkb. … [gotq vz,] meryx znu axil ubru t yvn uxan vorhmfbu pfgohrg aab ulem bm zlq, wklipwbq aab yhpp bm gxgbkb cyx-anax qul nkvcxofl. hre jhkpliq bm mfzl ubtpgp jpme gox zeltqvvg ls aab hubsrylb. goxormhor py qul exjz hc ahmrel vorhmbq aab hubsrylb, goxpr sttf tnpg otsr lqffaxa cyble ah qvtx; quhm ff aab yhpp bm gxgbkb jvniq ix lhalfql hc gpfb. jotq jl axil meru bp gvmxysr kbu-ielzbzns exjz, hrgzbar vy qvtx, zeltqvuz x hubsrylb. avp quhm arzvovwmfbu fftom pbbga fvfbjotq shffypto. ilkv zbve ypdb gox yviefphe zbuvbca hc tvw: kba ielzbzns, hrgzbar vy qvtx, xosx qb jkbnax  rapobezx";
    string key = "xnht";

    string plained;

    for(char c: plaintext){
        if(isalpha(c)){
            plained.push_back(c);
        }
    }

    cout << "length text: " << plaintext.length() << ", "<<plained.length() << endl;

    cout << "Encrypted text: " << encryptVigenereCipher(plained, key) << endl;

    return 0;
}

// Plaintext
// the cbgbz tycowh vdiqee the jocg, nmjnqv to oyss, flqn … to ifakzs g ydchihmq from khgkvaha didnyhq sst is xuh tuwoyiube. all prgh oi dyqhux are hdo fkci ez nature. … [jbmx is,] flulq can dkbs huyx m big xktu ihykzyix imjbayj the nshz ip sst, dnybwzoj dnu buiw of jkzino jbk-hqnq the qxojabys. ayh concept ut zygo niwczw with zva slogjcyt sv the abefkfoo. jbqvuzavu if dns rqqc aj nature ybkopoj dnu khuzulei, zvack vgmm ggwj have stsyhan jboel na time; jbkz mi the rosc ip zejodi would pa eodyyxo aj time. qrgj my have prkb oi jifebfk non-lregemgz rqqc, outside cb jcwk, creating k oxolybyu. now dnop tycihczzyix ymwbf sound yciocvwd zksyfsgh. very siyr fsqu jbq biblical mubyovh uv wip: xuh vxscosuv, outside cb jcwk, able du mxuudk  universe