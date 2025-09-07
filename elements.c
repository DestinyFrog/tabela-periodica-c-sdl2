#include <stdio.h>
#include <string.h>

#define ROWS 10
#define COLS 18
#define ELEMENT_COUNT 118

enum Category
{
    HIDROGEN,
    ALKALI_METAL,
    EARTH_ALKALI_METAL,
    TRANSITION_METAL,
    OTHER_METALS,
    SEMIMETAL,
    NON_METAL,
    HALOGEN,
    NOBLE_GAS,
    UNKNOWN,
    LANTHANIDE,
    ACTINIDE
};

struct
{
    int layers[7];
    char symbol[3];
    int x, y;
    float atomic_mass;
    char name[20];
    enum Category category;
} elements[ELEMENT_COUNT] = {
    {{1, 0, 0, 0, 0, 0, 0}, "H", 0, 0, 1.00794, "hidrogênio", HIDROGEN},
    {{2, 0, 0, 0, 0, 0, 0}, "He", 17, 0, 4.002602, "hélio", NOBLE_GAS},
    {{2, 1, 0, 0, 0, 0, 0}, "Li", 0, 1, 6.941, "lítio", ALKALI_METAL},
    {{2, 2, 0, 0, 0, 0, 0}, "Be", 1, 1, 9.012182, "berílio", EARTH_ALKALI_METAL},
    {{2, 3, 0, 0, 0, 0, 0}, "B", 12, 1, 10.811, "boro", SEMIMETAL},
    {{2, 4, 0, 0, 0, 0, 0}, "C", 13, 1, 12.0107, "carbono", NON_METAL},
    {{2, 5, 0, 0, 0, 0, 0}, "N", 14, 1, 14.0067, "nitrogênio", NON_METAL},
    {{2, 6, 0, 0, 0, 0, 0}, "O", 15, 1, 15.9994, "oxigênio", NON_METAL},
    {{2, 7, 0, 0, 0, 0, 0}, "F", 16, 1, 18.998404, "flúor", HALOGEN},
    {{2, 8, 0, 0, 0, 0, 0}, "Ne", 17, 1, 20.1797, "neônio", NOBLE_GAS},
    {{2, 8, 1, 0, 0, 0, 0}, "Na", 0, 2, 22.98977, "sódio", ALKALI_METAL},
    {{2, 8, 2, 0, 0, 0, 0}, "Mg", 1, 2, 24.305, "magnésio", EARTH_ALKALI_METAL},
    {{2, 8, 3, 0, 0, 0, 0}, "Al", 12, 2, 26.981539, "alumínio", OTHER_METALS},
    {{2, 8, 4, 0, 0, 0, 0}, "Si", 13, 2, 28.0855, "silício", SEMIMETAL},
    {{2, 8, 5, 0, 0, 0, 0}, "P", 14, 2, 30.97376, "fósforo", NON_METAL},
    {{2, 8, 6, 0, 0, 0, 0}, "S", 15, 2, 32.065, "enxofre", NON_METAL},
    {{2, 8, 7, 0, 0, 0, 0}, "Cl", 16, 2, 35.453, "cloro", HALOGEN},
    {{2, 8, 8, 0, 0, 0, 0}, "Ar", 17, 2, 39.948, "argônio", NOBLE_GAS},
    {{2, 8, 8, 1, 0, 0, 0}, "K", 0, 3, 39.0983, "potássio", ALKALI_METAL},
    {{2, 8, 8, 2, 0, 0, 0}, "Ca", 1, 3, 40.078, "cálcio", EARTH_ALKALI_METAL},
    {{2, 8, 9, 2, 0, 0, 0}, "Sc", 2, 3, 44.95591, "escândio", TRANSITION_METAL},
    {{2, 8, 10, 2, 0, 0, 0}, "Ti", 3, 3, 47.867, "titânio", TRANSITION_METAL},
    {{2, 8, 11, 2, 0, 0, 0}, "V", 4, 3, 50.9415, "vanádio", TRANSITION_METAL},
    {{2, 8, 13, 1, 0, 0, 0}, "Cr", 5, 3, 51.9961, "cromo", TRANSITION_METAL},
    {{2, 8, 13, 2, 0, 0, 0}, "Mn", 6, 3, 54.93805, "manganês", TRANSITION_METAL},
    {{2, 8, 14, 2, 0, 0, 0}, "Fe", 7, 3, 55.845, "ferro", TRANSITION_METAL},
    {{2, 8, 15, 2, 0, 0, 0}, "Co", 8, 3, 58.9332, "cobalto", TRANSITION_METAL},
    {{2, 8, 16, 2, 0, 0, 0}, "Ni", 9, 3, 58.6934, "níquel", TRANSITION_METAL},
    {{2, 8, 18, 1, 0, 0, 0}, "Cu", 10, 3, 63.546, "cobre", TRANSITION_METAL},
    {{2, 8, 18, 2, 0, 0, 0}, "Zn", 11, 3, 65.409, "zinco", TRANSITION_METAL},
    {{2, 8, 18, 3, 0, 0, 0}, "Ga", 12, 3, 69.723, "gálio", OTHER_METALS},
    {{2, 8, 18, 4, 0, 0, 0}, "Ge", 13, 3, 72.64, "germânio", SEMIMETAL},
    {{2, 8, 18, 5, 0, 0, 0}, "As", 14, 3, 74.9216, "arsênio", SEMIMETAL},
    {{2, 8, 18, 6, 0, 0, 0}, "Se", 15, 3, 78.96, "selênio", NON_METAL},
    {{2, 8, 18, 7, 0, 0, 0}, "Br", 16, 3, 79.904, "bromo", HALOGEN},
    {{2, 8, 18, 8, 0, 0, 0}, "Kr", 17, 3, 83.798, "criptônio", NOBLE_GAS},
    {{2, 8, 18, 8, 1, 0, 0}, "Rb", 0, 4, 85.4678, "rubídio", ALKALI_METAL},
    {{2, 8, 18, 8, 2, 0, 0}, "Sr", 1, 4, 87.62, "estrôncio", EARTH_ALKALI_METAL},
    {{2, 8, 18, 9, 2, 0, 0}, "Y", 2, 4, 88.90585, "ítrio", TRANSITION_METAL},
    {{2, 8, 18, 10, 2, 0, 0}, "Zr", 3, 4, 91.224, "zircônio", TRANSITION_METAL},
    {{2, 8, 18, 12, 1, 0, 0}, "Nb", 4, 4, 92.90638, "nióbio", TRANSITION_METAL},
    {{2, 8, 18, 13, 1, 0, 0}, "Mo", 5, 4, 95.94, "molibdênio", TRANSITION_METAL},
    {{2, 8, 18, 13, 2, 0, 0}, "Tc", 6, 4, 97.9072, "tecnécio", TRANSITION_METAL},
    {{2, 8, 18, 15, 1, 0, 0}, "Ru", 7, 4, 101.07, "rutênio", TRANSITION_METAL},
    {{2, 8, 18, 16, 1, 0, 0}, "Rh", 8, 4, 102.9055, "ródio", TRANSITION_METAL},
    {{2, 8, 18, 18, 0, 0, 0}, "Pd", 9, 4, 106.42, "paládio", TRANSITION_METAL},
    {{2, 8, 18, 18, 1, 0, 0}, "Ag", 10, 4, 107.8682, "prata", TRANSITION_METAL},
    {{2, 8, 18, 18, 2, 0, 0}, "Cd", 11, 4, 112.411, "cádmio", TRANSITION_METAL},
    {{2, 8, 18, 18, 3, 0, 0}, "In", 12, 4, 114.818, "índio", OTHER_METALS},
    {{2, 8, 18, 18, 4, 0, 0}, "Sn", 13, 4, 118.71, "estanho", OTHER_METALS},
    {{2, 8, 18, 18, 5, 0, 0}, "Sb", 14, 4, 121.76, "antimônio", SEMIMETAL},
    {{2, 8, 18, 18, 6, 0, 0}, "Te", 15, 4, 127.6, "telúrio", SEMIMETAL},
    {{2, 8, 18, 18, 7, 0, 0}, "I", 16, 4, 126.90447, "iodo", HALOGEN},
    {{2, 8, 18, 18, 8, 0, 0}, "Xe", 17, 4, 131.293, "xenônio", NOBLE_GAS},
    {{2, 8, 18, 18, 8, 1, 0}, "Cs", 0, 5, 132.90546, "césio", ALKALI_METAL},
    {{2, 8, 18, 18, 8, 2, 0}, "Ba", 1, 5, 137.327, "bário", EARTH_ALKALI_METAL},
    {{2, 8, 18, 18, 9, 2, 0}, "La", 3, 8, 138.9055, "lantânio", LANTHANIDE},
    {{2, 8, 18, 19, 9, 2, 0}, "Ce", 4, 8, 140.116, "cério", LANTHANIDE},
    {{2, 8, 18, 21, 8, 2, 0}, "Pr", 5, 8, 140.90765, "praseodímio", LANTHANIDE},
    {{2, 8, 18, 22, 8, 2, 0}, "Nd", 6, 8, 144.24, "neodímio", LANTHANIDE},
    {{2, 8, 18, 23, 8, 2, 0}, "Pm", 7, 8, 144.9127, "promécio", LANTHANIDE},
    {{2, 8, 18, 24, 8, 2, 0}, "Sm", 8, 8, 150.36, "samário", LANTHANIDE},
    {{2, 8, 18, 25, 8, 2, 0}, "Eu", 9, 8, 151.964, "európio", LANTHANIDE},
    {{2, 8, 18, 25, 9, 2, 0}, "Gd", 10, 8, 157.25, "gadolínio", LANTHANIDE},
    {{2, 8, 18, 27, 8, 2, 0}, "Tb", 11, 8, 158.92534, "térbio", LANTHANIDE},
    {{2, 8, 18, 28, 8, 2, 0}, "Dy", 12, 8, 162.5, "disprósio", LANTHANIDE},
    {{2, 8, 18, 29, 8, 2, 0}, "Ho", 13, 8, 164.93031, "hólmio", LANTHANIDE},
    {{2, 8, 18, 30, 8, 2, 0}, "Er", 14, 8, 167.259, "érbio", LANTHANIDE},
    {{2, 8, 18, 31, 8, 2, 0}, "Tm", 15, 8, 168.9342, "túlio", LANTHANIDE},
    {{2, 8, 18, 32, 8, 2, 0}, "Yb", 16, 8, 173.04, "itérbio", LANTHANIDE},
    {{2, 8, 18, 32, 9, 2, 0}, "Lu", 17, 8, 174.967, "lutécio", LANTHANIDE},
    {{2, 8, 18, 32, 10, 2, 0}, "Hf", 3, 5, 178.49, "háfnio", TRANSITION_METAL},
    {{2, 8, 18, 32, 11, 2, 0}, "Ta", 4, 5, 180.9479, "tântalo", TRANSITION_METAL},
    {{2, 8, 18, 32, 12, 2, 0}, "W", 5, 5, 183.84, "tungstênio", TRANSITION_METAL},
    {{2, 8, 18, 32, 13, 2, 0}, "Re", 6, 5, 186.207, "rênio", TRANSITION_METAL},
    {{2, 8, 18, 32, 14, 2, 0}, "Os", 7, 5, 190.23, "ósmio", TRANSITION_METAL},
    {{2, 8, 18, 32, 15, 2, 0}, "Ir", 8, 5, 192.217, "irídio", TRANSITION_METAL},
    {{2, 8, 18, 32, 17, 1, 0}, "Pt", 9, 5, 195.078, "platina", TRANSITION_METAL},
    {{2, 8, 18, 32, 18, 1, 0}, "Au", 10, 5, 196.96655, "ouro", TRANSITION_METAL},
    {{2, 8, 18, 32, 18, 2, 0}, "Hg", 11, 5, 200.59, "mercúrio", TRANSITION_METAL},
    {{2, 8, 18, 32, 18, 3, 0}, "Tl", 12, 5, 204.3833, "tálio", OTHER_METALS},
    {{2, 8, 18, 32, 18, 4, 0}, "Pb", 13, 5, 207.2, "chumbo", OTHER_METALS},
    {{2, 8, 18, 32, 18, 5, 0}, "Bi", 14, 5, 208.98038, "bismuto", OTHER_METALS},
    {{2, 8, 18, 32, 18, 6, 0}, "Po", 15, 5, 208.9824, "polônio", SEMIMETAL},
    {{2, 8, 18, 32, 18, 7, 0}, "At", 16, 5, 209.9871, "astatínio", HALOGEN},
    {{2, 8, 18, 32, 18, 8, 0}, "Rn", 17, 5, 222.0176, "radônio", NOBLE_GAS},
    {{2, 8, 18, 32, 18, 8, 1}, "Fr", 0, 6, 223.0197, "frâncio", ALKALI_METAL},
    {{2, 8, 18, 32, 18, 8, 2}, "Ra", 1, 6, 226.0254, "rádio", EARTH_ALKALI_METAL},
    {{2, 8, 18, 32, 18, 9, 2}, "Ac", 3, 9, 227.0277, "actínio", ACTINIDE},
    {{2, 8, 18, 32, 18, 10, 2}, "Th", 4, 9, 232.0381, "tório", ACTINIDE},
    {{2, 8, 18, 32, 20, 9, 2}, "Pa", 5, 9, 231.03587, "protactínio", ACTINIDE},
    {{2, 8, 18, 32, 21, 9, 2}, "U", 6, 9, 238.02892, "urânio", ACTINIDE},
    {{2, 8, 18, 32, 22, 9, 2}, "Np", 7, 9, 237.0482, "netúnio", ACTINIDE},
    {{2, 8, 18, 32, 24, 8, 2}, "Pu", 8, 9, 244.0642, "plutônio", ACTINIDE},
    {{2, 8, 18, 32, 25, 8, 2}, "Am", 9, 9, 243.0614, "amerício", ACTINIDE},
    {{2, 8, 18, 32, 25, 9, 2}, "Cm", 10, 9, 247.0704, "cúrio", ACTINIDE},
    {{2, 8, 18, 32, 27, 8, 2}, "Bk", 11, 9, 247.0703, "berquélio", ACTINIDE},
    {{2, 8, 18, 32, 28, 8, 2}, "Cf", 12, 9, 251.0796, "califórnio", ACTINIDE},
    {{2, 8, 18, 32, 29, 8, 2}, "Es", 13, 9, 252.083, "einstéinio", ACTINIDE},
    {{2, 8, 18, 32, 30, 8, 2}, "Fm", 14, 9, 257.0951, "férmio", ACTINIDE},
    {{2, 8, 18, 32, 31, 8, 2}, "Md", 15, 9, 258.0984, "mendelévio", ACTINIDE},
    {{2, 8, 18, 32, 32, 8, 2}, "No", 16, 9, 259.101, "nobélio", ACTINIDE},
    {{2, 8, 18, 32, 32, 8, 3}, "Lr", 17, 9, 262.1097, "laurêncio", ACTINIDE},
    {{2, 8, 18, 32, 32, 10, 2}, "Rf", 3, 6, 261.1088, "rutherfórdio", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 11, 2}, "Db", 4, 6, 262.1141, "dúbnio", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 12, 2}, "Sg", 5, 6, 266.1219, "seabórgio", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 13, 2}, "Bh", 6, 6, 264.12, "bóhrio", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 14, 2}, "Hs", 7, 6, 277, "hássio", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 15, 2}, "Mt", 8, 6, 268.1388, "meitnério", UNKNOWN},
    {{2, 8, 18, 32, 32, 16, 2}, "Ds", 9, 6, 281, "darmstadtio", UNKNOWN},
    {{2, 8, 18, 32, 32, 17, 2}, "Rg", 10, 6, 272.1535, "roentgénio", UNKNOWN},
    {{2, 8, 18, 32, 32, 18, 2}, "Cn", 11, 6, 285, "copernício", TRANSITION_METAL},
    {{2, 8, 18, 32, 32, 18, 3}, "Nh", 12, 6, 286, "nihônio", UNKNOWN},
    {{2, 8, 18, 32, 32, 18, 4}, "Fl", 13, 6, 289, "fleróvio", OTHER_METALS},
    {{2, 8, 18, 32, 32, 18, 5}, "Mc", 14, 6, 289, "moscóvio", UNKNOWN},
    {{2, 8, 18, 32, 32, 18, 6}, "Lv", 15, 6, 289, "livermório", UNKNOWN},
    {{2, 8, 18, 32, 32, 18, 7}, "Ts", 16, 6, 294, "tenesso", UNKNOWN},
    {{2, 8, 18, 32, 32, 18, 8}, "Og", 17, 6, 294, "oganessônio", UNKNOWN},
};

struct ele {
    int layers[7];
    int atomic_number;
    char symbol[3];
    char name[20];
    float atomic_mass;
    enum Category category;
    int x, y;
};

int main() {
    FILE *f = fopen("data.bin", "wb");
    struct ele els[118];

    for (int i = 0; i < ELEMENT_COUNT; i++) {
        struct ele el;
        for (int j = 0; j < 7; j++)
            el.layers[j] = elements[i].layers[j];
        el.atomic_number = i + 1;
        el.atomic_mass = elements[i].atomic_mass;
        strcpy(el.name, elements[i].name);
        strcpy(el.symbol, elements[i].symbol);
        el.category = elements[i].category;
        el.x = elements[i].x;
        el.y = elements[i].y;
        els[i] = el;
    }

    fwrite(els, sizeof(struct ele), ELEMENT_COUNT, f);

    fclose(f);

    return 0;
}