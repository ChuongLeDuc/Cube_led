void square_front_back(){
  for(int k=0;k<5;k++){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B10000000)>>k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B10000000)>>k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B10000000)>>k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B10000000)>>k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B10000000)>>k));
    shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);
  }

  for(int k=0;k<5;k++){
    digitalWrite(latch_pin, LOW);
    
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B00001000)<<k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B00001000)<<k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B00001000)<<k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B00001000)<<k));
    shiftOut(data_pin, clock_pin,LSBFIRST, ~((0B00001000)<<k));
    shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);

    digitalWrite(latch_pin, HIGH);
    delay(square_time);
  }
}
