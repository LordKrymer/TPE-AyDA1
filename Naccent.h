#ifndef NACCENT_H_INCLUDED
#define NACCENT_H_INCLUDED




char removeAccent(char &letter){
    if (letter == 'á'){letter = 'a';}
    if (letter == 'Á'){letter = 'A';}
    if (letter == 'é'){letter = 'e';}
    if (letter == 'É'){letter = 'E';}
    if (letter == 'í'){letter = 'i';}
    if (letter == 'Í'){letter = 'I';}
    if (letter == 'ó'){letter = 'o';}
    if (letter == 'Ó'){letter = 'O';}
    if (letter == 'ú'){letter = 'u';}
    if (letter == 'Ú'){letter = 'U';}
    return letter;
}
#endif // NACCENT_H_INCLUDED
