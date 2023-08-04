#include<bits/stdc++.h>
using namespace std;

// Function to convert text to numerical values (a=1, b=2, c=3, and so on)
vector<long long> textToNumerical(const string& text) {
    vector<long long> numericalValues;
    for (char c : text) {
        numericalValues.push_back(c - 'a' + 1);
    }
    return numericalValues;
}

// Function to convert numerical values back to text
string numericalToText(const vector<long long>& numericalValues) {
    string text;
    for (long long num : numericalValues) {
        text.push_back('a' + num - 1);
    }
    return text;
}

// Function for modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1;

    long long result = modPow(base, exp / 2, mod);
    result = (result * result) % mod;

    if (exp % 2 == 1)
        result = (result * base) % mod;

    return result;
}

// Function to encrypt using RSA
vector<long long> rsaEncrypt(const vector<long long>& plaintext, long long e, long long n) {
    vector<long long> ciphertext;
    for (long long num : plaintext) {
        long long encryptedNum = modPow(num, e, n);
        ciphertext.push_back(encryptedNum);
    }
    return ciphertext;
}

// Function to decrypt using RSA (using private keys)
vector<long long> rsaDecrypt(const vector<long long>& ciphertext, long long d, long long n) {
    vector<long long> decryptedText;
    for (long long encryptedNum : ciphertext) {
        long long decryptedNum = modPow(encryptedNum, d, n);
        decryptedText.push_back(decryptedNum);
    }
    return decryptedText;
}

int main() {
    long long n = 670726081;
    long long e = 12345713;
    string plainText = "thegranddesignbreaksthenewsbittertosomethattocreateauniversefromabsolutenothinggodisnotnecessaryallthatisneededarethelawsofnaturethatistherecanhavebeenabigbangcreationwithoutthehelpofgodprovidedthelawsofnaturepredatetheuniverseourconceptoftimebeginswiththecreationoftheuniversethereforeifthelawsofnaturecreatedtheuniversetheselawsmusthaveexistedpriortotimethatisthelawsofnaturewouldbeoutsideoftimewhatwehavethenistotallynonphysicallawsoutsideoftimecreatingauniversenowthatdescriptionmightsoundsomewhatfamiliarverymuchlikethebiblicalconceptofgodnotphysicaloutsideoftimeabletocreateuniverse";

    // Step 1: Convert plain text to numerical values
    vector<long long> numericalValues = textToNumerical(plainText);

    // Step 2: Apply RSA encryption
    vector<long long> encryptedValues = rsaEncrypt(numericalValues, e, n);

    // Output the cipher text (encrypted values)
    cout << "Cipher Text: ";
    for (long long num : encryptedValues) {
        cout << num << " ";
    }
    cout << endl;

    // Step 3: Apply RSA decryption (to verify correctness)

    long long d = 430547005; // Replace '...' with the private exponent (d)
    vector<long long> decryptedValues = rsaDecrypt(encryptedValues, d, n);
    string decryptedText = numericalToText(decryptedValues);

    // Output the decrypted text
    cout << "Decrypted Text: " << decryptedText << endl;


    return 0;
}
