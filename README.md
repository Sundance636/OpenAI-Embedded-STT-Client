# OpenAI-Embedded-TTS-Client
An application that uses the OpenAI API and websockets to send data to an ESP8266 microcontroller and display that data on a screen.

## Getting Started

### Prerequisites
 + Visual Studio Code
 + Your own OpenAI API KEY
 + PlatformIO (Visual Studio Code Extension)
 + Python (latest version)
 + 
     Following Python Packages:
   
    + python-openai
    + python-websockets
    + python-sounddevice
    + python-scipy

### Installing

Using pip or your preferred package manager install the listed packages and tools.

**Arch Linux**

```
sudo pacman -S python-openai && sudo pacman -S python-websockets && sudo pacman -S python-sounddevice && sudo pacman -S python-scipy
```

Once the prerequisite packages are installed, clone the repository and open it in Visual Studio Code, assuming the PlatformIO extenstion is installed, it will read the 'platformio.ini' file to initialize the workspace

## Usage

Before runniing anything, we must do a few more things.

**Adding Evironment Variables for API-KEY**

In order to Keep your API Key hidden ad leaving it out of the python script, we must add it as an evironment variable to your system

When doing this you can either permenantly add the `API-KEY` variable to your USER environment variables, or only temporarily for the current terminal session.

1. Temporarily
   
    With a terminal open change directory to the 'Python_Scripts' folder, from then run:
   ```
   export API_KEY="REPLACE-WITH-YOUR-API-KEY"
   ```
  This will then temorarily add `API_KEY` as an environment variable for as long as this current terminal session lasts.
       
2. Permenantly (Recomended)
   
   With a terminal open run:
   ```
   sudo echo "export API_KEY=\"PLACE-YOUR-API-KEY-HERE\"" >> ~/.bashrc
   ```
   This will append the new environment variable to the end of your .bashrc file and ensure that `API_KEY` is automatically added to the list of environment variables everytime a new terminal session is started


**Include SSID and password**

In order for the ESP8266 MCU to connect a network, we must provide those credentials directly in the `main.cpp` file. So, in your Visual Studio Code, open main.cpp and go to line 97 which will have WiFi.begin("SSID","PASSWORD");, just replace `SSID` and `PASSWORD` with the respective SSID and PASSWORD of your network and when the code is compiled and uploaded to the MCU it will connect to the given network.




