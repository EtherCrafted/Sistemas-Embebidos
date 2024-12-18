

// visualizar grupo 0 
void Out_G0(uint8_t dato){
  _LATB2 = (dato & 0x01) >> 0; //bit 0x01 de  dato
  _LATB3  = (dato & 0x02) >> 1; //bit 0x02 de  dato
  _LATB4  = (dato & 0x04) >> 2; //bit 0x04 de  dato
  _LATB5  = (dato & 0x08) >> 3; //bit 0x08 de  dato
  _LATB9  = (dato & 0x10) >> 4; //bit 0x10 de  dato
  _LATD6  = (dato & 0x20) >> 5; //bit 0x20 de  dato
  _LATD7  = (dato & 0x40) >> 6; //bit 0x40 de  dato
  _LATD12  = (dato & 0x80) >> 7; //bit 0x80 de  dato
}
// visualizar grupo 1 
void Out_G1(uint8_t dato){
  _LATD13 = (dato & 0x01) >> 0; //bit 0x01 de  dato
  _LATA14 = (dato & 0x02) >> 1; //bit 0x02 de  dato
  _LATA15 = (dato & 0x04) >> 2; //bit 0x04 de  dato
  _LATD10 = (dato & 0x08) >> 3; //bit 0x08 de  dato
  _LATC4  = (dato & 0x10) >> 4; //bit 0x10 de  dato
  _LATD0  = (dato & 0x20) >> 5; //bit 0x20 de  dato
  _LATB14 = (dato & 0x40) >> 6; //bit 0x40 de  dato
  _LATG13 = (dato & 0x80) >> 7; //bit 0x80 de  dato
}
// visualizar grupo 2
void Out_G2(uint8_t dato){
  _LATG14 = (dato & 0x01) >> 0; //bit 0x01 de  dato
  _LATG6  = (dato & 0x02) >> 1; //bit 0x02 de  dato
  _LATG7  = (dato & 0x04) >> 2; //bit 0x04 de  dato
  _LATG8  = (dato & 0x08) >> 3; //bit 0x08 de  dato
  _LATD9  = (dato & 0x10) >> 4; //bit 0x10 de  dato
  _LATF2  = (dato & 0x20) >> 5; //bit 0x20 de  dato
  _LATF4  = (dato & 0x40) >> 6; //bit 0x40 de  dato
  _LATF5  = (dato & 0x80) >> 7; //bit 0x80 de  dato
}
// visualizar grupo 3
void Out_G3(uint8_t dato){
  _LATF8 = (rotd & 0x01) >> 0; //bit 0x01 de  rotd
  _LATF13 = (rotd & 0x02) >> 1; //bit 0x02 de  rotd
  _LATA0 = (rotd & 0x04) >> 2; //bit 0x04 de  rotd
  _LATA1 = (rotd & 0x08) >> 3; //bit 0x08 de  rotd
  _LATE8  = (rotd & 0x10) >> 4; //bit 0x10 de  rotd
  _LATE9  = (rotd & 0x20) >> 5; //bit 0x20 de  rotd
  _LATD8 = (rotd & 0x40) >> 6; //bit 0x40 de  rotd
  _LATD11 = (rotd & 0x80) >> 7; //bit 0x80 de  rotd
}
// visualizar grupo 4
void Out_G4(uint8_t dato){
  _LATG0 = (dato & 0x01) >> 0; //bit 0x01 de  dato
  _LATG1  = (dato & 0x02) >> 1; //bit 0x02 de  dato
  _LATF1  = (dato & 0x04) >> 2; //bit 0x04 de  dato
  _LATF0  = (dato & 0x08) >> 3; //bit 0x08 de  dato
  _LATD3  = (dato & 0x10) >> 4; //bit 0x10 de  dato
  _LATD1  = (dato & 0x20) >> 5; //bit 0x20 de  dato
  _LATA2  = (dato & 0x40) >> 6; //bit 0x40 de  dato
  _LATA3  = (dato & 0x80) >> 7; //bit 0x80 de  dato
  }