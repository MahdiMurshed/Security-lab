#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
using namespace std;

vector<ll> textToNumercial(string text){
    vector<ll> numericValues;

    for(char c: text){
        numericValues.push_back(c-'a'+1);
    }

    return numericValues;
}

string numericToText(vector<ll> numValues){
    string text;

    for(ll num:numValues){
        text.push_back(num+'a'-1);
    }

    return text;
}

ll modPower(ll base, ll exp, ll mod){
    if(exp == 0){
        return 1;
    }
    ll result = modPower(base, exp / 2, mod);
    result = (result * result) % mod;

    if(exp % 2 ==1){
        result = (result*base) % mod;
    }

    return result;
}

vector<ll> rsaEncrypt(vector<ll> plainText, ll e, ll n){
    vll encryptedText;

    for(ll c: plainText){
        ll encryptedNum = modPower(c, e, n);
        encryptedText.push_back(encryptedNum);
    }

    return encryptedText;
}

vll rsaDecrypt(vll encryptedText, ll d, ll n){
    vll plainText;

    for(ll c: encryptedText){
        ll plain = modPower(c, d, n);
        plainText.push_back(plain);
    }

    return plainText;
}

int main(){
    ll n = 670726081;
    ll e = 12345713;
    ll d = 430547005; 
    string plainText = "thegranddesignbreaksthenewsbittertosomethattocreateauniversefromabsolutenothinggodisnotnecessaryallthatisneededarethelawsofnaturethatistherecanhavebeenabigbangcreationwithoutthehelpofgodprovidedthelawsofnaturepredatetheuniverseourconceptoftimebeginswiththecreationoftheuniversethereforeifthelawsofnaturecreatedtheuniversetheselawsmusthaveexistedpriortotimethatisthelawsofnaturewouldbeoutsideoftimewhatwehavethenistotallynonphysicallawsoutsideoftimecreatingauniversenowthatdescriptionmightsoundsomewhatfamiliarverymuchlikethebiblicalconceptofgodnotphysicaloutsideoftimeabletocreateuniverse";

    vll numerics = textToNumercial(plainText);

    vll encryptedNumerics = rsaEncrypt(numerics, e, n);

    vll decryptedNumerics = rsaDecrypt(encryptedNumerics, d, n);

    string decryptedText = numericToText(decryptedNumerics);

    cout<<"Decrypted: "<<decryptedText<<endl;

    //     cout << "Cipher Text: ";
    // for (long long num : encryptedNumerics) {
    //     cout << num << " ";
    // }
    // cout << endl;




    return 0;
}