#include <LiquidCrystal.h>
//my botched 
LiquidCrystal lcd(13,12,8,7,4,2);

boolean dinoOnGround = true;  
 //declare a boolean to check if the dino is in the ground

int buttonPin = A4;
int buzzerPin = 3;

int buttonState = 0; 
 // a token variable to check the state of the button

int highScore = 0; 

boolean playState = false;
 //the game starts only when this becomes true
 // This is a common method used in coding games

int dist = 0;   
int distTwo = 0;
 // variables to set the distance between the trees

int score = 0;


//bitmap array for the dino character
byte dino [8]        
{ B00000,
  B00111,
  B00101,
  B10111,
  B11100,
  B11111,
  B01101,
  B01100,
};

//character for the tree
byte tree [8]      
{
  B00011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11111,
  B01110,
  B01110
};



void setup() {
  
 lcd.begin(16,2);
 lcd.createChar(7, dino);
 lcd.createChar(6,tree);
 lcd.setCursor(0,1);
 lcd.write(7);
 pinMode(buttonPin,INPUT);
 pinMode(buzzerPin,OUTPUT);

}

void loop() {
 
 lcd.clear();

// at the start, check is playState is true or false
if(!playState){  
  lcd.setCursor(0,0);                
 lcd.print("        Press A4"); 
 lcd.setCursor(0,1);
 lcd.print("        to start");
 
//When it is false, print the starting instruction

 if(digitalRead(buttonPin)==HIGH) //Read the button
 {
  playState = true; 
// when button pushed, make playState true
 }

}
  
// when playState is true, call the startGame function
 if(playState)
 {
  startGame();
 }

 delay(100); 
}         
// the loop function ends here


// when playState is true, startGame function is called

void startGame(){  

lcd.clear();

  dist = random(4,9);  
 distTwo = random(4,9);
//Generate two random distances for the gap between the trees

// this for loop is to make the trees move
  for(int i=16; i>=-(dist+distTwo); i--){ 

   lcd.setCursor(13,0);
 lcd.print(score);  // print the score

  int state = digitalRead(buttonPin);  
// Read the push button


 if(state == HIGH) 
 {
  buttonState = 1;
  tone(buzzerPin,700,100);
  
 
 }
 else if(state == LOW)
 {
   buttonState = 0;
 }

//when the button is pushed, print the dino on the upper 

 if(buttonState == 1){  
  lcd.setCursor(1,0); // row and set dinoOnGround to false
  lcd.write(7);
  lcd.setCursor(1,1);
  lcd.print(" ");
  dinoOnGround = false;
  
  
 }
 else{                          // When the button is not pushed 
  lcd.setCursor(1,1);     // print the dino on the lower row 
  lcd.write(7);               // and set dinoOnGround to true
  lcd.setCursor(1,0);
  lcd.print(" ");
  dinoOnGround = true;
 }


// This prints the trees so that it moves with the for loop
 lcd.setCursor(i,1); 
  lcd.write(6);
  lcd.setCursor(i+1,1);
  lcd.print(" ");

  lcd.setCursor(i+dist,1);
  lcd.write(6);
  lcd.setCursor(i+dist+1,1);
  lcd.print(" ");

   lcd.setCursor(i+dist+distTwo,1);
  lcd.write(6);
  lcd.setCursor(i+dist+distTwo+1,1);
  lcd.print(" ");

 //When the trees reaches the starting point
  if((i+dist+distTwo)==-1){
    i=12;                    
  } // they are taken to the end and set up randomly once more

/*  Now check if the position of the trees 
      and that of the dino coincides, but we
      only need to do this if the dino is in the ground.
    
     Use the dinoOnGround variable and check if the
     condition is satisfied. If so the game is over
*/



  if(i==1 && (dinoOnGround == true))
  { lcd.clear();
    lcd.print("        You Lost");
    // lcd.setCursor(1,0);
    // lcd.print("        Over!!!");
    delay(3000);
    if(score>highScore){
      highScore = score;
      
    }
    lcd.clear();
    lcd.setCursor(10,1);
      lcd.print("HS: ");
      lcd.print(highScore);
    playState = false;  //Set the playState as false so it goes to the 
    delay(3000);         // start screen after the game is over
    score = 0;
    break;
  }
  else if(i+dist == 1 && (dinoOnGround == true))
  { lcd.clear();
    lcd.print("        You Lost");
    if(score>highScore){
      highScore = score;
    }
    lcd.setCursor(10,1);
      lcd.print("HS: ");
      lcd.print(highScore);
    playState = false;
    delay(3000);
    score = 0;
    break;
  }
  else if(i+dist+distTwo == 1 && (dinoOnGround == true))
  { lcd.clear();
    lcd.print("        You Lost");
    if(score>highScore){
      highScore = score;
     
    } 
    lcd.setCursor(10,1);
      lcd.print("HS: ");
      lcd.print(highScore);
    playState = false;
    delay(3000);
    score = 0;
    break;
  }

score++;  
// increase the score variable for every run of the loop
  
  delay(500);
  
 }

}