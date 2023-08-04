#include<bits/stdc++.h>
using namespace std;

// 1. The following cipher has been created using the Caesar cipher. Write a program to decipher it.
string decryptCaesarCipher(string encryptedText, int key) {
    string decryptedText = encryptedText;
    for (char& ch : decryptedText) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base - key + 26) % 26 + base;

    }
    return decryptedText;
}

int main() {
    string encryptedText = "ftqzqjfwuxxqdmbbiuxxoaynuzqoxagpymotuzqxqmdzuzsuafmzpnxaowotmuz";

    // Try all possible keys (0 to 25) to decrypt the text
    for (int key = 1; key < 26; ++key) {
        string decryptedText = decryptCaesarCipher(encryptedText, key);
        cout << "Key = " << key << ", Decrypted text = " << decryptedText << endl;
    }

    return 0;
}

// Key = 1, Decrypted text = espypievtwwpclaahtwwnzxmtypnwzfoxlnstypwplcytyrtzelyomwznvnslty
// Key = 2, Decrypted text = droxohdusvvobkzzgsvvmywlsxomvyenwkmrsxovokbxsxqsydkxnlvymumrksx
// Key = 3, Decrypted text = cqnwngctruunajyyfruulxvkrwnluxdmvjlqrwnunjawrwprxcjwmkuxltlqjrw
// Key = 4, Decrypted text = bpmvmfbsqttmzixxeqttkwujqvmktwcluikpqvmtmizvqvoqwbivljtwkskpiqv
// Key = 5, Decrypted text = aolulearpsslyhwwdpssjvtipuljsvbkthjopulslhyupunpvahukisvjrjohpu
// Key = 6, Decrypted text = znktkdzqorrkxgvvcorriushotkiruajsginotkrkgxtotmouzgtjhruiqingot
// Key = 7, Decrypted text = ymjsjcypnqqjwfuubnqqhtrgnsjhqtzirfhmnsjqjfwsnslntyfsigqthphmfns
// Key = 8, Decrypted text = xliribxomppivettamppgsqfmrigpsyhqeglmripievrmrkmsxerhfpsgoglemr
// Key = 9, Decrypted text = wkhqhawnloohudsszloofrpelqhforxgpdfklqhohduqlqjlrwdqgeorfnfkdlq
// Key = 10, Decrypted text = vjgpgzvmknngtcrryknneqodkpgenqwfocejkpgngctpkpikqvcpfdnqemejckp
// Key = 11, Decrypted text = uifofyuljmmfsbqqxjmmdpncjofdmpvenbdijofmfbsojohjpuboecmpdldibjo
// Answer
// Key = 12, Decrypted text = thenextkillerappwillcombinecloudmachinelearningiotandblockchain
// Key = 13, Decrypted text = sgdmdwsjhkkdqzoovhkkbnlahmdbkntclzbghmdkdzqmhmfhnszmcaknbjbgzhm
// Key = 14, Decrypted text = rfclcvrigjjcpynnugjjamkzglcajmsbkyafglcjcyplglegmrylbzjmaiafygl
// Key = 15, Decrypted text = qebkbuqhfiiboxmmtfiizljyfkbzilrajxzefkbibxokfkdflqxkayilzhzexfk
// Key = 16, Decrypted text = pdajatpgehhanwllsehhykixejayhkqziwydejahawnjejcekpwjzxhkygydwej
// Key = 17, Decrypted text = oczizsofdggzmvkkrdggxjhwdizxgjpyhvxcdizgzvmidibdjoviywgjxfxcvdi
// Key = 18, Decrypted text = nbyhyrnecffylujjqcffwigvchywfioxguwbchyfyulhchacinuhxvfiwewbuch
// Key = 19, Decrypted text = maxgxqmdbeexktiipbeevhfubgxvehnwftvabgxextkgbgzbhmtgwuehvdvatbg
// Key = 20, Decrypted text = lzwfwplcaddwjshhoaddugetafwudgmvesuzafwdwsjfafyaglsfvtdgucuzsaf
// Key = 21, Decrypted text = kyvevokbzccvirggnzcctfdszevtcfludrtyzevcvriezexzfkreuscftbtyrze
// Key = 22, Decrypted text = jxudunjaybbuhqffmybbsecrydusbektcqsxydubuqhdydwyejqdtrbesasxqyd
// Key = 23, Decrypted text = iwtctmizxaatgpeelxaardbqxctradjsbprwxctatpgcxcvxdipcsqadrzrwpxc
// Key = 24, Decrypted text = hvsbslhywzzsfoddkwzzqcapwbsqzciraoqvwbszsofbwbuwchobrpzcqyqvowb
// Key = 25, Decrypted text = gurarkgxvyyrenccjvyypbzovarpybhqznpuvaryrneavatvbgnaqoybpxpunva