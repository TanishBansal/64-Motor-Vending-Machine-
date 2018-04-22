
int IA0 = 9;
int IA1 = 3;
int IA2 = 4;
int IE3 = 5;
int IE4 = 6;
int IE5 = 7;
int enable = 8;
int feedback = 2;
int count = 0;
int val=0;



void setup()
{                
 
  
  Serial.begin(9600);
  pinMode(IA0, OUTPUT); 
  pinMode(IA1, OUTPUT); 
  pinMode(IA2, OUTPUT); 
  pinMode(IE3, OUTPUT); 
  pinMode(IE4, OUTPUT); 
  pinMode(IE5, OUTPUT); 
  pinMode(enable,OUTPUT);
  pinMode(feedback,INPUT);
 digitalWrite(enable,HIGH);



  // digitalWrite(enable,LOW);
   digitalWrite(IA0,LOW);
    digitalWrite(IA1,LOW);
    digitalWrite(IA2,LOW);
    digitalWrite(IE3,LOW);
    digitalWrite(IE4,LOW);
    digitalWrite(IE5,LOW);
    
}



void loop()
{

  
  /*while(Serial.available()>0)
  {
      val*=10;
      val+= (Serial.read()-'0');
    }
   parseMessage(val);
   val='\0';
Serial.print(val);
Serial.print('\n');
}*/
 for (int i=0; i <= 63; i++)
 {
  for (int j=0; j <= 3; j++)
  {
      delay(1000);
              parseMessage(i);
  }
  delay(100);
  digitalWrite(enable,HIGH);
   } 
}
void parseMessage(int i)
{ 
int  X_val =i;
 digitalWrite(enable,LOW);
 int H_q1,H_q2,H_q3,H_q4,H_S0,H_S1,H_S2,H_S3,H_S4,H_S5;
    H_S0 = X_val % 2;
    H_q1 = X_val/2;
    H_S1 = H_q1%2 ;
    H_q2 = H_q1/2 ;
    H_S2 = H_q2%2;
    H_q3 = H_q2/2;
    H_S3 = H_q3%2;
    H_q4 = H_q3/2;
    H_S4 = H_q4%2;
    H_S5 = H_q4/2;
    



  
    digitalWrite(IA0,H_S0);
    digitalWrite(IA1,H_S1);
    digitalWrite(IA2,H_S2);
    digitalWrite(IE3,H_S3);
    digitalWrite(IE4,H_S4);
    digitalWrite(IE5,H_S5);
    count++;
  
}












  
