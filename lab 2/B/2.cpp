#include<bits/stdc++.h>
using namespace std;
// Steps
// 1. **Collect Cipher Text**: Obtain the encrypted text that you want to decrypt.
// 2. **Calculate Letter Frequencies**: Count the occurrence of each letter in the encrypted text. Create a frequency table that shows how many times each letter appears.
// 3. **Compare with Expected Frequencies**: Compare the letter frequencies in the encrypted text with the expected frequencies of letters in the language. For example, in English, the letter 'E' is the most frequently used letter, followed by 'T', 'A', 'O', etc. You can find tables of expected letter frequencies for different languages online.
// 4. **Identify High-Frequency Letters**: Identify the letters with the highest frequencies in the encrypted text. These letters are likely to correspond to the most common letters in the language.
// 5. **Guess Potential Mappings**: Based on the identified high-frequency letters, make educated guesses about their potential mappings. For example, if 'X' is the most frequent letter in the encrypted text and 'E' is the most frequent letter in the English language, you might assume that 'X' corresponds to 'E'.
// 6. **Look for Patterns**: Look for patterns in the encrypted text. Common two-letter words like 'is', 'an', 'it', 'in', etc., are great starting points. Also, look for common suffixes, prefixes, or other patterns that might help you identify more letters.

// Function to calculate letter frequencies in the given text
unordered_map<char, int> calculateLetterFrequencies(const string& text) {
    int sz = text.size();
     cout << "Size: " << sz << endl;
    unordered_map<char, int> frequencies;
    for (char ch : text) {
        if (isalpha(ch)) {
            ++frequencies[ch];
        }
    }
    return frequencies;
}

int main() {
    string encryptedText = "tqmrajq ya gowopxyoap, fxog vcasqffac ycqmxtpql, tka kxg fqxyqg kqcfqms op x topiqg xcjrkxoc op scapy as ykq socq. jl pxjq of vcasqffac ycqmxtpql. lae jxl pay kxwq fqqp jq zqsacq. o sopg ykxy gqfrqpgopi yaa asyqp opya ykq kefymq xpg zefymq as ykq jxop frkaam rma gf jl oppqc qlq. pazagl fxog xplykopi ya ykof qbycxacgopxcl vcapaeprqjqpy. vcasqffac ycqmxtpql gqmorxyqml cqxccxpiqg kqc fkxtm xpg rapyopeqg, fa lae kxwq rkafqp ya fyegl gowopxyoap, ykq jafy gossoremy as xmm jxiorxm xcyf. o jefy";;

    // Calculate letter frequencies in the encrypted text
    unordered_map<char, int> encryptedFrequencies = calculateLetterFrequencies(encryptedText);

    // Sort letters by frequency in descending order
    vector<pair<char, int>> sortedFrequencies(encryptedFrequencies.begin(), encryptedFrequencies.end());
    sort(sortedFrequencies.begin(), sortedFrequencies.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    for (const auto& pair : sortedFrequencies) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}

// Output
// Key: q, Value: 47 -> e
// Key: a, Value: 37 -> 
// Key: p, Value: 35
// Key: y, Value: 33
// Key: x, Value: 31
// Key: o, Value: 29
// Key: f, Value: 25
// Key: c, Value: 25
// Key: g, Value: 20
// Key: k, Value: 18
// Key: m, Value: 16
// Key: s, Value: 14
// Key: l, Value: 14
// Key: j, Value: 12
// Key: r, Value: 11
// Key: e, Value: 9
// Key: t, Value: 7
// Key: i, Value: 5
// Key: v, Value: 4
// Key: w, Value: 4
// Key: z, Value: 3
// Key: b, Value: 1


// Mapping: 
        // char_substitution('x', 'A');
        // char_substitution('o', 'I');
        // char_substitution('q', 'E');
        // char_substitution('p', 'N');

        // char_substitution('g', 'D');
        // char_substitution('j', 'M');
        // char_substitution('y', 'T');
        // char_substitution('a', 'O');

        // char_substitution('f', 'S');
        // char_substitution('k', 'H');
        // char_substitution('l', 'Y');
        // char_substitution('e', 'U');

        // char_substitution('w', 'V');
        // char_substitution('z', 'B');
        // char_substitution('r', 'C');
        // char_substitution('s', 'F');

        // char_substitution('c', 'R');
        // char_substitution('m', 'L');
        // char_substitution('t', 'W');
        // char_substitution('v', 'P');

        // char_substitution('i', 'G');
        // char_substitution('b', 'X');