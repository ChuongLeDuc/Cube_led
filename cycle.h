
void cycle(){
  unsigned int column_value[5]={0B00000000,0B00000000,0B00000000,0B00000000,0B00000000};
  for(int column=1;column<=3;column++){
    for(int pos=column+2;pos<=8-column;pos++){
      bitWrite(column_value[column-1],pos,1);
     
      digitalWrite(latch_pin, LOW);
      
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
      shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
      digitalWrite(latch_pin, HIGH);
      delay(50);
    }

   
      for(int i=column-1;i<=5-column;i++){
        bitWrite(column_value[i],8-column,1);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }

      for(int pos=8-column;pos>=2+column;pos--){
     
        bitWrite(column_value[5-column],pos,1);
        digitalWrite(latch_pin, LOW);
      
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
      shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
      shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
      digitalWrite(latch_pin, HIGH);
      delay(50);
    }
    
   for(int i=5-column;i>=column-1;i--){
        bitWrite(column_value[i],2+column,1);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }
}

for(int column=3;column>=1;column--){
 
   for(int i=2+column;i<=8-column;i++){
        bitWrite(column_value[5-column],i,0);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }

       for(int i=5-column;i>=column-1;i--){
        bitWrite(column_value[i],8-column,0);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }
  

       for(int i=8-column;i>=2+column;i--){
        bitWrite(column_value[column-1],i,0);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }
      
      for(int i=column-1;i<=5-column;i++){
        bitWrite(column_value[i],column+1,0);
        digitalWrite(latch_pin, LOW);
    
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(column_value[0]));
        shiftOut(data_pin, clock_pin,LSBFIRST, 0B11111000);
    
        digitalWrite(latch_pin, HIGH);
        delay(50);
      }

      
}

}
