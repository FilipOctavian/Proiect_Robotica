# Proiect Arduino: Barieră Automată pentru Mașinuțe

## Descriere

Acest proiect constă în realizarea unei bariere automate pentru mașinuțe, bazată pe senzori de mișcare. Scopul principal al acestui proiect este să detecteze mișcarea vehiculelor jucărie și să controleze automat o barieră, utilizând un sistem Arduino. Aceasta este o aplicație practică ce implică utilizarea senzorilor, a motoarelor și a iluminării, oferind o introducere utilă în electronica și programarea cu Arduino.

## Funcționalitate

- **Detectarea mișcării:** Doi senzori de mișcare vor detecta prezența mașinuțelor.
- **Controlul barierei:** Un electromotor va ridica sau coborî bariera în funcție de semnalele primite de la senzori.
- **Semnalizare luminoasă:** LED-urile roșu și verde vor indica starea barierei:
  - LED roșu: Bariera este coborâtă.
  - LED verde: Bariera este ridicată.

## Componente utilizate

- **2 senzori de mișcare** – pentru detectarea prezenței mașinuțelor.
- **1 LED roșu și 1 LED verde** – pentru semnalizare vizuală.
- **Electromotor** – pentru acționarea barierei.
- **Breadboard și fire de legătură** – pentru conexiunile electrice.
- **Arduino** – pentru logica și controlul proiectului.

## Pin folositi si metode de conectare a componentelor

### **1. Senzor cu ultrasunete HC-SR04**

#### **Conexiuni:**
- **VCC (alimentare)** → Conectat la **5V** pe Arduino (fir roșu). Acest pin furnizează tensiunea necesară senzorului.
- **GND (împământare)** → Conectat la **GND** pe Arduino (fir negru).
- **TRIG (triggerează semnalul ultrasonic)** → Conectat la pinul **9** de pe Arduino (fir galben). Acesta trimite un semnal către senzor pentru a iniția măsurătoarea.
- **ECHO (returnează semnalul reflectat)** → Conectat la pinul **10** de pe Arduino (fir portocaliu). Acest pin returnează durata necesară pentru ca semnalul să se întoarcă, pe baza căreia se calculează distanța.

### **2. LED-uri (Roșu și Verde) cu rezistențe**
Două LED-uri sunt conectate pe breadboard, împreună cu rezistențe, pentru a indica anumite condiții în funcție de distanța măsurată de senzor.

#### **Conexiuni:**
- **LED-ul roșu**:
  - **Anodul (pinul lung)** → Conectat la pinul **3** pe Arduino (fir galben-verde).
  - **Catodul (pinul scurt)** → Conectat la **GND** printr-o **rezistență** (de aproximativ **220Ω** pentru a limita curentul).

- **LED-ul verde**:
  - **Anodul** → Conectat la pinul **4** pe Arduino (fir verde).
  - **Catodul** → Conectat la **GND** printr-o rezistență similară.

### **3. Servomotor (SG90)**
Servomotorul este folosit pentru a realiza o mișcare controlată de rotație, de obicei între **0° și 180°**.

#### **Conexiuni:**
- **Firul roșu (alimentare)** → Conectat la **5V** pe Arduino.
- **Firul negru (GND)** → Conectat la **GND** pe Arduino.
- **Firul galben (semnal)** → Conectat la pinul **11** pe Arduino.

### **6. Conexiuni GND și VCC**
- Toate componentele împart **GND** (împământare) pentru a crea un circuit electric comun.
- **5V** de la Arduino este utilizat pentru alimentarea senzorului HC-SR04 și a servomotorului.
