char tagOk[] ="27001914002A";
char tag1[] = "270023F5BF4E";
char tag2[] = "270023D9A17C";
char tag3[] = "270023FE5AA0";
int LED = 8;
int invalid = 9;
char inputTag[16]; 
int pos=0;
int compare;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

void setup()
{
  Serial.begin(9600);
   
  }

void loop()
{ 
  if (Serial.available()){ 

  int count = 0; 
      while(Serial.available() && count < 12) { 
         inputTag[count] = Serial.read(); 
         count++; 
         delay(10); 
         } 
      Serial.print(inputTag); // this command prints the rf id number
      Serial.print("\n");
       compare = 1; 
      compare = (strncmp(tagOk, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0)
      { 
        
         Serial.println( "   AYYASAMY  "); 
         digitalWrite(LED,HIGH);
      
        delay(1000);

          } 
  compare = 1; 
      compare = (strncmp(tag1, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0)
      { 
        
         Serial.println( "   VENKAT "); 
         digitalWrite(LED,HIGH);
      
        delay(1000);

          } 
           compare = 1; 
      compare = (strncmp(tag2, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0)
      { 
        
         Serial.println( "   NAGA  "); 
         digitalWrite(LED,HIGH);
      
        delay(1000);

          }

      compare = 1; 
      compare = (strncmp(tag3, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0)
      { 
        
         Serial.println( "   BOOBAL  "); 
         digitalWrite(LED,HIGH);
      
        delay(1000);

          }
          
          if (compare == 1)
          {
            digitalWrite(invalid,HIGH);
          }
          digitalWrite(LED,LOW);
        }
        

}



