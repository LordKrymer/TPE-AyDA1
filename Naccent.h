#ifndef NACCENT_H_INCLUDED
#define NACCENT_H_INCLUDED




char removeAccent(char &letter){
    if (letter == '�'){letter = 'a';}
    if (letter == '�'){letter = 'A';}
    if (letter == '�'){letter = 'e';}
    if (letter == '�'){letter = 'E';}
    if (letter == '�'){letter = 'i';}
    if (letter == '�'){letter = 'I';}
    if (letter == '�'){letter = 'o';}
    if (letter == '�'){letter = 'O';}
    if (letter == '�'){letter = 'u';}
    if (letter == '�'){letter = 'U';}
    return letter;
}
#endif // NACCENT_H_INCLUDED
