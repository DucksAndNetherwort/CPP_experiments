# 1Drender

*What is a `class`? What is an `object`? What is an instance?*
 
An object is a thing that might represent something in the real world. e.g. a `Pet`. 
A class is scaffolding or a template, that describes the required data for the object, and it's behaviours. Behaviours are usually verbs. an instance is the scaffolding or template filled out. 

The class needs to be made first, with all the variables and *methods* declared, and everything has to have it's accessibility (from outside, or subclasses) defined. A class usually doesn't have any memory allocated to the methods or variables.

Once the class has been made, an object can be created from it(using `ClassName ObjectName;`), and then the methods can be called with `ObjectName.FunctionName();`,
and the variables can be accessed with `ObjectName.VariableName = aNumber;`.

Here is the code for an example class and instance. The class represents a line that will be drawn on a text display. It implements a method to draw a line of '#' between two given points. The code creates an instance and uses it to draw a line.
