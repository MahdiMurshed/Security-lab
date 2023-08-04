#include<bits/stdc++.h>
using namespace std;

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