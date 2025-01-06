<h1 align="center">
  🖐️ SignWave - Where Gesture Speaks Volumes 🤖🎤
</h1>

Welcome to the **Hand Gesture Recognition System**! 🚀 This project aims to **bridge communication gaps** by recognizing sign language gestures in **real-time** using **flex sensors** and an **IMU6050** sensor embedded in gloves. The system translates gestures into **text** and converts them to **speech** for better accessibility. 🎙️💬

---

## 📌 Features  
✔️ **Real-time gesture recognition** using sensor-based gloves  
✔️ **Sign language to text** conversion 📝  
✔️ **Text-to-speech (TTS) integration** 🔊  
✔️ **Machine Learning for accurate classification** 🤖  
✔️ **Potential NLP and online learning enhancements**  
✔️ **Cloud deployment on AWS EC2 (planned)** ☁️  

---

## 🛠️ Hardware Used  

The following components are used to build the **gesture recognition glove**:  

| 🏷️ Component  | 🔧 Description |
|--------------|-------------|
| 🧤 **Glove**  | Base for mounting sensors |
| 🏗️ **Flex Sensors** | Detects finger bending |
| 🎯 **IMU6050 (Accelerometer + Gyroscope)** | Tracks hand motion and orientation |
| 🔌 **ESP32** | Microcontroller for processing signals |
| 🔊 **Smart Phone** | Converts text to speech |
| 🌐 **AWS EC2 (Future)** | Cloud-based processing |

---

## 🖥️ Software & Libraries  

📌 **Programming Languages:**  
- Python 🐍  
- C++ (for microcontroller programming)  

📌 **Libraries & Dependencies:**  
- `numpy` ➜ Data processing  
- `scikit-learn` ➜ Machine Learning model  
- `TensorFlow / PyTorch` ➜ (Future deep learning integration)  
- `speechRecognition` ➜ Text-to-Speech conversion  
- `Flask / FastAPI` ➜ HTTP-based data transfer  
- `AWS SDK` ➜ Cloud deployment  

---

## 🚀 How It Works  

1️⃣ **Sensors detect gestures:**  
   - **Flex sensors** measure finger bending angles  
   - **IMU6050** tracks hand movements  

2️⃣ **Data Processing:**  
   - Sensor data is sent to a **microcontroller**  
   - Features are extracted and sent to a **gesture classification model**  

3️⃣ **Classification:**  
   - Machine Learning model **predicts the gesture**  
   - Text output is generated  

4️⃣ **Speech Conversion:**  
   - The text is passed through a **Text-to-Speech (TTS) engine**  
   - The recognized word/sentence is **spoken aloud** 🔊  

---

## 🛠️ Installation & Setup  

1️⃣ **Clone the Repository**  
```bash
git clone https://github.com/daaanishhh002/gesture-recognition.git
cd gesture-recognition
```

2️⃣ **Install Dependencies**
```bash
pip install -r requirements.txt
```

### 🌍 Future Enhancements
✨ Deep Learning Model for improved accuracy
✨ Real-time Streaming for live sign language translation
✨ NLP-based contextual learning
✨ AWS Cloud Integration for remote accessibility

### 📜 License
This project is open-source under the MIT License. Feel free to modify and contribute! 🎉

### 📞 Contact
💡 Authors: Danish Ahmed, Syed Zeeshan, Syed Mubeen Ali, Shaik Abdul Sami
📧 Email: your-email@example.com
🐙 GitHub: daaanishhh002

<text align="center">
  🌟 If you like this project, give it a star ⭐ on GitHub!
</text>
