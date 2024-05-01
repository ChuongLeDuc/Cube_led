void square_left_right(){
  int column[5]={0B11111000,0,0,0,0};

  for(int k=0;k<5;k++){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[4]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[3]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[2]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[1]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[0]));
    shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);

    if(k!=4){
      int extra=column[k];
      column[k]=0;
      column[k+1]=extra;
    }
  }

  for(int k=4;k>=0;k--){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[4]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[3]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[2]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[1]));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(column[0]));
    shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);

    if(k!=0){
      int extra=column[k];
      column[k]=0;
      column[k-1]=extra;
    }
  }
}
