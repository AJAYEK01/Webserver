# 🌐 NodeMCU ESP8266 Simple Web Server

This project demonstrates how to set up a basic web server using the NodeMCU ESP8266 Wi-Fi module. When connected to Wi-Fi, it hosts a web page displaying a simple message like **"Hello from NodeMCU!"**, accessible from any browser on the same local network.

## 📋 Description
A beginner-friendly example to learn about embedded web development and IoT using NodeMCU and Arduino IDE. Perfect for students and hobbyists starting with ESP8266.

## ✅ Features
- Connects to Wi-Fi network
- Hosts a web server on port 80
- Displays a simple HTML message
- Lightweight and fast setup

## 🛠 Requirements
- NodeMCU (ESP8266) board
- Arduino IDE
- USB cable for programming
- Wi-Fi network credentials

## 🚀 Setup Instructions

1. **Install ESP8266 Board Support:**
   - In Arduino IDE, go to `File > Preferences`.
   - Add this URL to *Additional Board URLs*:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```

2. **Install Board:**
   - Open `Tools > Board > Boards Manager`.
   - Search and install "esp8266".

3. **Upload Code:**
   - Replace `YOUR_SSID` and `YOUR_PASSWORD` in the code.
   - Select board: `NodeMCU 1.0 (ESP-12E Module)`
   - Upload the sketch via USB.

4. **View Output:**
   - Open Serial Monitor (115200 baud).
   - Copy the IP address displayed.
   - Open it in your browser to view the page.

## 🌍 Example Output

> Hello from NodeMCU!

## 📄 License

This project is licensed under the [MIT License](LICENSE).
