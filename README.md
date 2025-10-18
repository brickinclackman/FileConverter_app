# 🧰 FileConverter

![Qt](https://img.shields.io/badge/Qt-6.x-brightgreen?logo=qt&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
![FFmpeg](https://img.shields.io/badge/FFmpeg-Required-important?logo=ffmpeg&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-informational)

---

> 🎬 **FileConverter** est une application graphique écrite en **C++/Qt** permettant de convertir des **images**, **vidéos** et **audios** avec **qualité maximale** grâce à FFmpeg.

---

## ✨ Fonctionnalités

✅ Interface graphique moderne basée sur **Qt Widgets**  
🖼️ Conversion d’**images** : JPG ↔️ PNG ↔️ BMP ↔️ JPEG  
🎬 Conversion de **vidéos** : MP4 ↔️ MOV ↔️ AVI ↔️ WEBM ↔️ MKV  
🎵 Conversion de **fichiers audio** : MP3 ↔️ WAV ↔️ FLAC ↔️ OGG ↔️ AAC  
⚙️ Conversion **haute qualité** sans perte perceptible  
📜 Affichage en temps réel des logs FFmpeg  
🧩 Code organisé et extensible grâce à `converter.cpp`

---

## 🧱 Architecture du projet

```

FileConverter/
│
├── FileConverter.pro
├── README.md
├── main.cpp
├── mainwindow.h / mainwindow.cpp / mainwindow.ui
│
├── converter.h / converter.cpp
│
└── screens/
├── imagewindow.h / imagewindow.cpp / imagewindow.ui
├── videowindow.h / videowindow.cpp / videowindow.ui
├── audiowindow.h / audiowindow.cpp / audiowindow.ui

````

---

## ⚙️ Technologies utilisées

| Outil / Librairie | Rôle |
|--------------------|------|
| **Qt 6 / 5** | Interface graphique (QWidgets, QProcess, QFileDialog, etc.) |
| **C++17** | Langage principal |
| **FFmpeg** | Moteur de conversion multimédia |
| **QProcess** | Communication avec FFmpeg en arrière-plan |

---

## 🚀 Installation & Compilation

### 1️⃣ Prérequis
- **Qt Creator** (Qt 5.x ou Qt 6.x)
- **FFmpeg** installé et accessible depuis le terminal

### 2️⃣ Vérifier FFmpeg
```bash
ffmpeg -version
````

Si la commande n’est pas reconnue :

* **Windows :** Télécharge sur [ffmpeg.org](https://ffmpeg.org/download.html)
* **Linux / Raspberry Pi :**

  ```bash
  sudo apt install ffmpeg
  ```
* **macOS :**

  ```bash
  brew install ffmpeg
  ```

### 3️⃣ Compiler le projet

1. Ouvre `FileConverter.pro` avec **Qt Creator**
2. Clique sur ▶️ **Exécuter** (ou `Ctrl + R`)
3. Profite de ton interface Qt 🎉

---

## 🧩 Utilisation

1. Lance le logiciel
2. Choisis entre :

   * 🖼️ **IMAGE**
   * 🎬 **VIDÉO**
   * 🎵 **AUDIO**
3. Sélectionne ton fichier source
4. Choisis le format de sortie
5. Clique sur **Convertir**
6. Observe la progression et le log FFmpeg en direct ✨

---

## 🧠 Détails techniques

* Le moteur de conversion (`converter.cpp`) utilise **FFmpeg** via `QProcess`
* Chaque type de fichier applique des **paramètres qualité adaptés** :

| Type      | Paramètres FFmpeg                                      |
| --------- | ------------------------------------------------------ |
| 🖼️ Image | `-qscale:v 1` (qualité maximale)                       |
| 🎬 Vidéo  | `-c:v libx264 -preset slow -crf 18 -c:a aac -b:a 192k` |
| 🎵 Audio  | `-vn -c:a libmp3lame -q:a 2`                           |

---

## 🔧 Améliorations futures

* 🔹 Ajout d’une **barre de progression (QProgressBar)** en temps réel
* 🔹 **Conversion par lot** de plusieurs fichiers
* 🔹 Choix du **bitrate / CRF personnalisé**
* 🔹 **Thème sombre / clair** avec QPalette
* 🔹 Export automatique dans un dossier “Output”

---

## 🧑‍💻 Auteur

**👋 Brickin Clackman**
Étudiant en **Cybersécurité, Informatique, Réseaux et Électronique**
Créateur passionné de logiciels, vidéos et projets créatifs 🧱💡
📸 [Chaîne YouTube – Brickin Gaming](https://www.youtube.com/@brickingaming)

---

## 📜 Licence

Ce projet est distribué sous licence **MIT**.
Tu peux l’utiliser, le modifier et le redistribuer librement tant que tu cites l’auteur.

---

> 💬 *“Convertir simplement, efficacement, et avec style — c’est tout l’esprit de FileConverter.”*
