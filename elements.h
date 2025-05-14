#ifndef ELEMENT_H_
#define ELEMENT_H_

#define ROWS 10
#define COLS 18
#define ELEMENT_COUNT 118

enum Category {
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

SDL_Color category_to_color(enum Category category) {
    switch (category) {
        case HIDROGEN:              return (SDL_Color) { 220, 228, 255 };
        case ALKALI_METAL:          return (SDL_Color) { 253, 233, 16  };
        case EARTH_ALKALI_METAL:    return (SDL_Color) { 250, 190, 14  };
        case TRANSITION_METAL:      return (SDL_Color) { 201, 48 , 44  };
        case OTHER_METALS:          return (SDL_Color) { 255, 0  , 255 };
        case SEMIMETAL:             return (SDL_Color) { 227, 68 , 137 };
        case NON_METAL:             return (SDL_Color) { 25 , 230, 25  };
        case HALOGEN:               return (SDL_Color) { 106, 90 , 205 };
        case NOBLE_GAS:             return (SDL_Color) { 144, 16 , 136 };
        case LANTHANIDE:            return (SDL_Color) { 173, 216, 230 };
        case ACTINIDE:              return (SDL_Color) { 148, 123, 192 };
        case UNKNOWN:               return (SDL_Color) { 100, 100, 100 };
        default:                    return (SDL_Color) { 255, 255, 255 };
    }
}

struct {
    char symbol[3];
    int x, y;
    enum Category category;
} elements[ELEMENT_COUNT] = {
    { "H" , 0 , 0, HIDROGEN },
    { "He", 17, 0, NOBLE_GAS },
    { "Li", 0 , 1, ALKALI_METAL },
    { "Be", 1 , 1, EARTH_ALKALI_METAL },
    { "B" , 12, 1, SEMIMETAL },
    { "C" , 13, 1, NON_METAL },
    { "N" , 14, 1, NON_METAL },
    { "O" , 15, 1, NON_METAL },
    { "F" , 16, 1, HALOGEN },
    { "Ne", 17, 1, NOBLE_GAS },
    { "Na", 0 , 2, ALKALI_METAL },
    { "Mg", 1 , 2, EARTH_ALKALI_METAL },
    { "Al", 12, 2, OTHER_METALS },
    { "Si", 13, 2, SEMIMETAL },
    { "P" , 14, 2, NON_METAL },
    { "S" , 15, 2, NON_METAL },
    { "Cl", 16, 2, HALOGEN },
    { "Ar", 17, 2, NOBLE_GAS  },
    { "K" , 0 , 3, ALKALI_METAL },
    { "Ca", 1 , 3, EARTH_ALKALI_METAL },
    { "Sc", 2 , 3, TRANSITION_METAL },
    { "Ti", 3 , 3, TRANSITION_METAL },
    { "V" , 4 , 3, TRANSITION_METAL },
    { "Cr", 5 , 3, TRANSITION_METAL },
    { "Mn", 6 , 3, TRANSITION_METAL },
    { "Fe", 7 , 3, TRANSITION_METAL },
    { "Co", 8 , 3, TRANSITION_METAL },
    { "Ni", 9 , 3, TRANSITION_METAL },
    { "Cu", 10, 3, TRANSITION_METAL },
    { "Zn", 11, 3, TRANSITION_METAL },
    { "Ga", 12, 3, OTHER_METALS },
    { "Ge", 13, 3, SEMIMETAL },
    { "As", 14, 3, SEMIMETAL },
    { "Se", 15, 3, NON_METAL },
    { "Br", 16, 3, HALOGEN },
    { "Kr", 17, 3, NOBLE_GAS  },
    { "Rb", 0 , 4, ALKALI_METAL },
    { "Sr", 1 , 4, EARTH_ALKALI_METAL },
    { "Y" , 2 , 4, TRANSITION_METAL },
    { "Zr", 3 , 4, TRANSITION_METAL },
    { "Nb", 4 , 4, TRANSITION_METAL },
    { "Mo", 5 , 4, TRANSITION_METAL },
    { "Tc", 6 , 4, TRANSITION_METAL },
    { "Ru", 7 , 4, TRANSITION_METAL },
    { "Rh", 8 , 4, TRANSITION_METAL },
    { "Pd", 9 , 4, TRANSITION_METAL },
    { "Ag", 10, 4, TRANSITION_METAL },
    { "Cd", 11, 4, TRANSITION_METAL },
    { "In", 12, 4, OTHER_METALS },
    { "Sn", 13, 4, OTHER_METALS },
    { "Sb", 14, 4, SEMIMETAL },
    { "Te", 15, 4, SEMIMETAL },
    { "I" , 16, 4, HALOGEN },
    { "Xe", 17, 4, NOBLE_GAS  },
    { "Cs", 0 , 5, ALKALI_METAL },
    { "Ba", 1 , 5, EARTH_ALKALI_METAL },
    { "La", 3 , 8, LANTHANIDE },
    { "Ce", 4 , 8, LANTHANIDE },
    { "Pr", 5 , 8, LANTHANIDE },
    { "Nd", 6 , 8, LANTHANIDE },
    { "Pm", 7 , 8, LANTHANIDE },
    { "Sm", 8 , 8, LANTHANIDE },
    { "Eu", 9 , 8, LANTHANIDE },
    { "Gd", 10, 8, LANTHANIDE },
    { "Tb", 11, 8, LANTHANIDE },
    { "Dy", 12, 8, LANTHANIDE },
    { "Ho", 13, 8, LANTHANIDE },
    { "Er", 14, 8, LANTHANIDE },
    { "Tm", 15, 8, LANTHANIDE },
    { "Yb", 16, 8, LANTHANIDE },
    { "Lu", 17, 8, LANTHANIDE },
    { "Hf", 3 , 5, TRANSITION_METAL },
    { "Ta", 4 , 5, TRANSITION_METAL },
    { "W" , 5 , 5, TRANSITION_METAL },
    { "Re", 6 , 5, TRANSITION_METAL },
    { "Os", 7 , 5, TRANSITION_METAL },
    { "Ir", 8 , 5, TRANSITION_METAL },
    { "Pt", 9 , 5, TRANSITION_METAL },
    { "Au", 10, 5, TRANSITION_METAL },
    { "Hg", 11, 5, TRANSITION_METAL },
    { "Tl", 12, 5, OTHER_METALS },
    { "Pb", 13, 5, OTHER_METALS },
    { "Bi", 14, 5, OTHER_METALS },
    { "Po", 15, 5, SEMIMETAL },
    { "At", 16, 5, HALOGEN },
    { "Rn", 17, 5, NOBLE_GAS },
    { "Fr", 0 , 6, ALKALI_METAL },
    { "Ra", 1 , 6, EARTH_ALKALI_METAL },
    { "Ac", 3 , 9, ACTINIDE },
    { "Th", 4 , 9, ACTINIDE },
    { "Pa", 5 , 9, ACTINIDE },
    { "U" , 6 , 9, ACTINIDE },
    { "Np", 7 , 9, ACTINIDE },
    { "Pu", 8 , 9, ACTINIDE },
    { "Am", 9 , 9, ACTINIDE },
    { "Cm", 10, 9, ACTINIDE },
    { "Bk", 11, 9, ACTINIDE },
    { "Cf", 12, 9, ACTINIDE },
    { "Es", 13, 9, ACTINIDE },
    { "Fm", 14, 9, ACTINIDE },
    { "Md", 15, 9, ACTINIDE },
    { "No", 16, 9, ACTINIDE },
    { "Lr", 17, 9, ACTINIDE },
    { "Rf", 3 , 6, TRANSITION_METAL },
    { "Db", 4 , 6, TRANSITION_METAL },
    { "Sg", 5 , 6, TRANSITION_METAL },
    { "Bh", 6 , 6, TRANSITION_METAL },
    { "Hs", 7 , 6, TRANSITION_METAL },
    { "Mt", 8 , 6, UNKNOWN },
    { "Ds", 9 , 6, UNKNOWN },
    { "Rg", 10, 6, UNKNOWN },
    { "Cn", 11, 6, TRANSITION_METAL },
    { "Nh", 12, 6, UNKNOWN },
    { "Fl", 13, 6, OTHER_METALS },
    { "Mc", 14, 6, UNKNOWN },
    { "Lv", 15, 6, UNKNOWN },
    { "Ts", 16, 6, UNKNOWN },
    { "Og", 17, 6, UNKNOWN },
};

#endif /* ELEMENT_H_ */