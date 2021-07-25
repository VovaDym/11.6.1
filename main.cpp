#include <iostream>
#include <string>

void shiftSymbol (char &symbol, int shift)
{
    char aSymbol;
    char zSymbol;
    if (symbol >= 'A' && symbol <= 'Z')
    {
        aSymbol = 'A';
        zSymbol = 'Z';
    } else if (symbol >= 'a' && symbol <= 'z')
    {
        aSymbol = 'a';
        zSymbol = 'z';
    }
    else
    {
        return;
    }

    int shiftedSymbol = symbol + shift % 26;

    if (shiftedSymbol > zSymbol)
    {
        symbol = aSymbol + shiftedSymbol % zSymbol - 1;

    }
    else if (shiftedSymbol < aSymbol)
    {
        symbol = zSymbol - aSymbol % shiftedSymbol + 1;
    }
    else {
        symbol += shift % 26;
    }
}

std::string encrypt_caesar (std::string &text, int shift)
{
    for (auto i : text)
    {
        shiftSymbol(text[i], shift);
    }
    return text;
}

std::string decrypt_caesar (std::string &text, int shift)
{
    for (auto i : text)
    {
        shiftSymbol(text[i], - shift);
    }
    return text;
}

int main()
{
    std::cout<<"<<<< Caesar's Secret correspondence >>>>\n";
    std::string text;
    int shift;
    std::cout<<"Caesar! Write! :\n";
    std::getline(std::cin,text);
    std::cout<<"Please come up with an encryption key :\n";
    std::cin>>shift;
    std::cout << "Encrypted text: " <<  encrypt_caesar(text, shift) << std::endl;
    std::cout << "Decrypted text: " <<  decrypt_caesar(text, shift) << std::endl;
}