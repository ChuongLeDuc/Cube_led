void square_up_down(){
 
  for(int k=0;k<5;k++){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);
  }

  for(int k=4;k>=0;k--){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~(0B11111000));
    shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);
  }
  
}
