#include <Arduino.h>
#include<SoftwareSerial.h>

  class OneDRender {

    public:
      
     // Constructors
     OneDRender() {
        reset();
     };

     

     void reset() {
       strcpy(output, "________________");
     }

     // Destructor
     ~OneDRender() {};
      
      void draw(int vertex1, int vertex2) {
        int temp;
        if (vertex1 > vertex2) {
          temp = vertex2;
          vertex2 = vertex1;
          vertex1 = temp;
        }
        
        for (int i = vertex1; i <= vertex2; i++)
        {
          output[i] = '#';
        }
        
      };

      void render() {
        Serial.println(output);
      }

    private:
      char output[17];
  }; //class end
  
  OneDRender render;

void setup() {
  Serial.begin(115200);
  Serial.println();

  delay(1000);
  render.draw(8,8);
  render.render();
  render.draw(7,9);
  render.render();
  render.draw(6,10);
  render.render();
  render.draw(5,11);
  render.render();
  render.draw(4,12);
  render.render();
  render.draw(3,13);
  render.render();
  render.draw(2,14);
  render.render();
  render.draw(1,15);
  render.render();
  render.draw(0,16);
  render.render();
  for (int i = 0; i < 12; i++)
  {
    render.reset();
    render.draw(i, i+4);
    render.render();
    delay(200);
  }
  render.draw(0, 5);
  render.draw(11, 16);
  render.render();
  render.reset();
  render.render();
  delay(5000);

};

 void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 12; i++)
  {
    render.reset();
    render.draw(i, i+4);
    render.render();
    delay(200);
  }
};