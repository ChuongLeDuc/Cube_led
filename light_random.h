void light_random(){
  unsigned int index[5][5]={
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
  };

  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      int random_num=random(3,8);
      bitWrite(index[i][j],random_num,1);
    }
  }

   for(int t=0;t<12;t++){
      for(int k=0;k<5;k++){
        
        
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    }
   }
   
}
