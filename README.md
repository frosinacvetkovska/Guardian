# Guardian
**Guardian** is a robot assistant for people with special needs that aims to make their daily life easier with a series of functionalities such as:
- Real-time image display using a mobile phone
- Control of the robot's movement using the Bluetooth module
- Measuring a certain distance using the distance sensor
- Use of own application which can be upgraded according to the needs of the user

## Usage
This robot aims to help a larger group of people with special needs:
- People with spinal cord injuries, arthritis who may have certain difficulties in their movement and this robot can provide them with safe movement in the environment
- People with cognitive impairments such as Alzheimer's disease or dementia who may have difficulty remembering directions or places and the robot provides them with navigation and reminders that would help them in their daily lives.
- Elderly people who have physical and cognitive challenges and thereby help them with their mobility, connecting with their family members for help or caregivers with a camera that will transmit the speech.
- Individuals with impaired vision where the robot will be their personal assistant when moving in the environment itself. He will send feedback about the environment and help them avoid the obstacles that are in front of them.

## Mobile application
In order to implement this solution, I also created an application using MIT App Inventor. The purpose for which I made it was due to the fact that there are almost no mobile applications that display an image and allow the movement of the robot itself. It consists of very simple functionality and these are:
- Bluetooth and phone connection button
- Picture box
- Button to turn off the Bluetooth connection
- Buttons to move the robot
**If you want to replicate the project you can download the .apk file for the application from the repository! Keep in mind that the movement controls have to be changed based on the requirements you will put. In order to do that you have to upload the .apk file in MIT App Inventor and change it manually.**

 Youtube video from the robot: https://youtu.be/F2Ez6jdFKGU

## Arduino parts required
- Mecanum wheels: 4
- Arduino Uno: 1
- Motor driver shield: 1
- DC motors: 4
- HC-06 Bluetooth module: 1
- Ultrasonic sensor: 1
- Jumper wires: 10 (Depends if you need more)
- Battery holder: 1
- USB cable: 1
- M3*10mm Screw: 20
- M3 Nuts: 12
- M3*16mm (Copper Pillar): 4
- M1.6*12mm Screw: 4
- M1.6*12mm Nut: 4
- Plastic Shim: 4
- M2*12mm: 2
- M2 Nut: 2
- M3*30mm screw: 8
- Aluminium Block: 4
- Standoffs: 4
- Screwdriver: 1
- Tie-wraps: 3
- Chassis plates: 2 (1 large and 1 small)
- Motor brackets: 4
- 3.7V 18650 lithium batteries: 2

![image](https://github.com/user-attachments/assets/054a8e57-a7c0-49c8-b112-a6a1163c3cbf) ![image](https://github.com/user-attachments/assets/c786a920-6e00-419d-906d-e7ba34c72845)


## Plans for future improvement of the robot
The robot has the main functionalities, but it can be improved in several aspects:
- Adding a camera with the aim of minimizing the appearance and enabling an easier way to record the territory around us, processing the recordings and adding greater functionality with the help of machine learning (detection of people, detection of what kind of object it is, etc.)
- Creation of one application with all the necessary functionalities instead of the current two which are used for navigation and getting a view from the phone in real time. This will reduce the time of assembling the robot when it is necessary to use it, but also with our development of the application it will have an interactive UI that can be easily used by people of different ages.
- Adding a sound sensor in order to receive a notification about a certain object/person near it.
- Adding light sensors in order for the robot to work at night or in places where it is dark and we need light for it to move.
- Adding a GPS sensor in order to know the exact location of the robot. The same location can be displayed on the app using map integration.
- Implementation of a function for avoiding obstacles and notifying the user with the help of proximity sensors


