<h1 align="center">
  🖐️ SignWave - Where Gestures Speak Volumes 🤖🎤
</h1>

Welcome to the Hand Gesture Recognition System!  

This project aims to bridge communication gaps by recognizing sign language gestures in real time using flex sensors and an IMU6050 sensor embedded in gloves. The system translates gestures into text and converts them to speech for better accessibility.  

---

## 📌 Features
- Real-time gesture recognition using sensor-based gloves  
- Sign language to text conversion  
- Text-to-speech (TTS) integration  
- Machine Learning for accurate classification  
- Potential NLP and online learning enhancements  
- Cloud deployment on AWS EC2 (planned)  

---

## 🛠️ Hardware Used
The following components are used to build the gesture recognition glove:

| Component | Description |
|-----------|-------------|
| Glove | Base for mounting sensors |
| Flex Sensors | Detect finger bending |
| IMU6050 (Accelerometer + Gyroscope) | Tracks hand motion and orientation |
| ESP32 | Microcontroller for processing signals |
| Smart Phone | Converts text to speech |
| AWS EC2 | Cloud-based processing |

---

## 💻 Software & Libraries
**Programming Languages:**
- Python  
- C
- Java
- Javascript  

**Libraries & Dependencies:**
- numpy ➜ Data processing  
- scikit-learn ➜ Machine Learning model  
- TensorFlow / PyTorch ➜ (Future deep learning integration)  
- speechRecognition ➜ Text-to-Speech conversion  
- Flask ➜ Websocket-based data transfer  
- AWS SDK ➜ Cloud deployment  

---

## 🚀 How It Works
1. **Sensors detect gestures**  
   - Flex sensors measure finger bending angles  
   - IMU6050 tracks hand movements  

2. **Data Processing**  
   - Sensor data is sent to a microcontroller  
   - Features are extracted and sent to a gesture classification model  

3. **Classification**  
   - Machine Learning model predicts the gesture  
   - Text output is generated  

4. **Speech Conversion**  
   - The text is passed through a Text-to-Speech (TTS) engine  
   - The recognized word or sentence is spoken aloud

---

## 🌍 Future Enhancements
- Deep Learning Model for improved accuracy  
- Real-time Streaming for live sign language translation  
- NLP-based contextual learning  
- AWS Cloud Integration for remote accessibility  

---

## 📞 Contact
**Authors:** Danish Ahmed, Syed Zeeshan, Syed Mubeen Ali, Shaik Abdul Sami  
**Email:** ahmed.daanish002@gmail.com  
**GitHub:** [daaanishhh002](https://github.com/daaanishhh002)  

---

<p align="center">
  If you like this project, give it a star ⭐ on GitHub!
</p>

---
