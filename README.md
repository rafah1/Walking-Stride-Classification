

# Walking-Stride-Classification

![image](https://user-images.githubusercontent.com/35944732/127803688-8f8f8a70-39e3-42e8-bb28-114fca5cb284.png)


Is intuitive to all of us that having a correct gait is very important.
A small problem in the feet, might change the way a person walks. Even subtle changes in the stride, can cause a chain reaction of adjustments of posture, and walking mechanics. These changes can put stress on the leg muscles, and body joints. Long walks and running, with a faulty stride, increase the risk of developing complications which may lead to more serious problems. That is why gait analysis is very important.
 
Gait analysis is the assessment of the way a person walks. Usually it is done, using video analysis, by a highly skilled specialist who does the interpretation. Beside the observation analysis, the commonly used tool is pressure plate analysis. Which provides an idea of how the weight is distributed on the feet soles.

While the analysis of the stride is a dynamic problem. Current method of diagnosis is not based on movement, it is mainly observational by an expert, and mostly based on weight distribution on a sensing surface.
 
Using the ST SensorTile fixed to the shoe, we propose that you can detect whether or not your stride is pronating or supinating. The main set of the sensors that we will use for this project are the gyro, the accelerometer, and the compass.


Final Report in Google Docs:

https://docs.google.com/document/d/17RcKpGCK8gkb1wyRmNkTXA7NZOqp3j9zShf3wMb5xG8/edit?usp=sharing


Project Presentation in Google Docs:

https://docs.google.com/presentation/d/1J446wwsRWfFNJ151eCp1U2G-3nKs7uOY9QrBzNaMDK0/edit?usp=sharing


Demo Video in Youtube:


https://youtu.be/eZLqpIjwU2s



*Installing and using the software:*

In order to use the inference model, in windows or Android, the .bin file has to be flashed into the SensorTile in the address 0x08000000, and the Json file copied over, to windows or Android App, to show text instead of number classifications. This can also be done configuring manually the classes in the app.

The project files backup is included, in the repository, inside the code directory. The backup files have to be placed on the project folder of the machine where the SensiML Data application is installed. Also a DCLI file is included with the export of the project, and can be imported back to SensiML, and used with the included dataset on the data directory.

