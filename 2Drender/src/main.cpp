#include <Arduino.h>
#include <SoftwareSerial.h>


//these variables indicate the dimentions of the display
const int width = 16;
const int height = 16;

class TwoDRender
{
  public:
    
private:
//this char array contians the output of the renderer, and it is 2-dimentional (like the renderer output)
  char output[width][height];
  
  //temps
  int tmp1;
  int tmp2;
  char lineSwap1[17];
  char lineSwap2[17];
public:
  void draw(int vertex1x, int vertex1y, int vertex2x, int vertex2y)
  {
    //this is the main render code lol
  }

//the function that allows text to be printed
  int txtdraw(int x, int y, char text[17]) {
//error checking, if the input text does not fit on the display, it will return -1, to show that it does not fit
    if(x >= width || x < 0 || y >= height || y < 0) {
      return -1;
    }
//this actually puts the text in the output variable
    for (int i = 0; (i + x) < width && text[i] != 0; i++)
    {
      output[i + x][y] = text[i];
    }
    
    return 0;
  }

  void render() {
//this outputs the contents of the output variable to the display
    for (int y = 0; y < width; y++)
    {
      for (int x = 0; x < height; x++)
      {
        Serial.print(output[x][y]);
      }
      Serial.println();
      
    }
    
  }

  void reset() {
//the reset function, simply here to set the entire output to underscores when called
    for (int x = 0; x < width; x++)
    {
      for (int y = 0; y < height; y++)
      {
        output[x][y] = '_';
      }
      
    }
    
    
  };

  ~TwoDRender() {};
};

TwoDRender render;

void setup() {
  Serial.begin(9600);
  render.reset();
  render.render();
  Serial.println();
  render.txtdraw(3, 0, "Test");
  render.txtdraw(12, 4, "truncate"); //this doesn't actually fit on the display
  render.render();
}

void loop() {
  // put your main code here, to run repeatedly:
}