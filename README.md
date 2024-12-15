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

### **3. Senzor cu ultrasunete HC-SR04**

#### **Conexiuni:**
- **VCC (alimentare)** → Conectat la **5V** pe Arduino (fir roșu). Acest pin furnizează tensiunea necesară senzorului.
- **GND (împământare)** → Conectat la **GND** pe Arduino (fir negru).
- **TRIG (triggerează semnalul ultrasonic)** → Conectat la pinul **9** de pe Arduino (fir galben). Acesta trimite un semnal către senzor pentru a iniția măsurătoarea.
- **ECHO (returnează semnalul reflectat)** → Conectat la pinul **10** de pe Arduino (fir portocaliu). Acest pin returnează durata necesară pentru ca semnalul să se întoarcă, pe baza căreia se calculează distanța.
