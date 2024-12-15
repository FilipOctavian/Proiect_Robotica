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


# Descrierea Funcționalității Hardware

## **1. Componente Hardware Utilizate**

### **1.1. Arduino UNO**
- Microcontroller principal folosit pentru controlul întregului sistem.
- Tip de microcontroller: **ATmega328P**.
- Conexiuni disponibile:
  - **Digital I/O Pins**: folosite pentru controlul LED-urilor, al servomotorului și al senzorului ultrasonic.
  - **Alimentare**: Alimentare cu 5V necesară componentelor externe.

### **1.2. LED-uri**
- **LED roșu:** indică faptul că bariera este coborâtă.
- **LED verde:** indică faptul că bariera este ridicată.
- Conexiuni:
  - LED-urile sunt conectate la pinii digitali ai Arduino prin rezistențe pentru limitarea curentului.
  - Rezistențele utilizate sunt de **220Ω** pentru a preveni arderea LED-urilor.
  - Controlul se realizează prin comenzi digitale de tip HIGH/LOW de la microcontroller.

### **1.3. Senzor ultrasonic HC-SR04**
- Utilizat pentru detectarea prezenței mașinuțelor de jucărie.
- Specificații tehnice:
  - **Distanța de detectare:** 2cm - 400cm.
  - **Precizie:** ±3mm.
  - Alimentare: **5V DC**.
- Conexiuni:
  - **Trig**: conectat la un pin digital pentru generarea impulsurilor de declanșare.
  - **Echo**: conectat la un alt pin digital pentru citirea răspunsului ultrasonic (timpul de întoarcere).
  - Alimentarea și masa sunt conectate la pinii de 5V și GND ai Arduino.

### **1.4. Servomotor SG90**
- Utilizat pentru acționarea barierei mecanice.
- Specificații tehnice:
  - **Unghi de rotație:** 0° - 180°.
  - **Tensiune de operare:** 4.8V - 6V.
  - **Cuplu maxim:** ~1.8kg/cm (la 5V).
- Conexiuni:
  - Firul de semnal (control): conectat la un pin PWM al Arduino.
  - Alimentare și masă: conectate la pinii 5V și GND ai Arduino.

### **1.5. Breadboard și cabluri**
- **Breadboard-ul:** folosit pentru realizarea conexiunilor fără lipire între componente și Arduino.
- **Cabluri de conectare:** folosite pentru conectarea senzorului, LED-urilor și servomotorului.

---

## **2. Descrierea Funcționalității**
1. **Detectarea mașinuțelor:**
   - Senzorul ultrasonic HC-SR04 măsoară distanța până la obiectele din fața lui.
   - Dacă distanța este mai mică de un prag definit (de exemplu, **10 cm**), sistemul determină că o mașinuță este prezentă.

2. **Controlul barierei:**
   - Dacă o mașinuță este detectată, bariera se ridică automat prin rotirea servomotorului la 90°.
   - După ce mașinuța trece (distanța crește peste prag), bariera se coboară la poziția inițială (0°).

3. **Indicatorii LED:**
   - LED-ul roșu se aprinde când bariera este coborâtă.
   - LED-ul verde se aprinde când bariera este ridicată.

---

## **3. Specificații de Comunicație și Procesare**
- **Comunicația cu senzorul ultrasonic:** 
  - Modulul HC-SR04 utilizează impulsuri de semnal digital. Arduino trimite un puls de 10 µs pe pinul **Trig**, iar răspunsul este măsurat pe pinul **Echo**, calculând distanța pe baza duratei semnalului reflectat.
  
- **Controlul Servomotorului:**
  - Arduino trimite un semnal PWM (Pulse Width Modulation) pe firul de semnal al servomotorului pentru a regla poziția acestuia (în grade).
  - Frecvența semnalului PWM: **50Hz**.

- **Controlul LED-urilor:**
  - Comenzi simple HIGH/LOW pentru aprindere/stingere, transmise prin pinii digitali.


# Pin folositi si metode de conectare a componentelor

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
