void rain(){
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
  

 unsigned int index_2[5][5]={
    {0B11111000,0B11111000,0B11111000,0B11111000,0B11111000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
 };
 
for(int times=0;times<5;times++){
  for(int j=0;j<5;j++){
    int pos;
    unsigned int value=index_2[0][j];
    
    for(int i=0;i<5;i++){
      int n=0;
      while(bitRead(value,n)==0){
        n++;
      }
      if(i!=0){
        
        for(int a=1;a<4;a++){
         if(a!=i){
           index_2[a][j]=0B00000000;
         }
        }
        
        bitWrite(index_2[i][j],n,1);  
       
      }
      bitWrite(index_2[0][j],n,0);  
      
       for(int t=0;t<20;t++){
          for(int k=0;k<5;k++){
              digitalWrite(latch_pin, LOW);
              
              shiftOut(data_pin, clock_pin,LSBFIRST, ~(index_2[k][4]));
              shiftOut(data_pin, clock_pin,LSBFIRST, ~(index_2[k][3]));
              shiftOut(data_pin, clock_pin,LSBFIRST, ~(index_2[k][2]));
              shiftOut(data_pin, clock_pin,LSBFIRST, ~(index_2[k][1]));
              shiftOut(data_pin, clock_pin,LSBFIRST, ~(index_2[k][0]));
              shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
            
              digitalWrite(latch_pin, HIGH);
              delay(1);
          }
        }
       pos=n; 
      }
       bitWrite(value,pos,0);   

    }
  }
}
