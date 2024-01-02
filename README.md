# **v1.5**

Užduotis: v1.2 kode aprašyti naują abstrakčią klasę: Žmogus, kurios išvestinė klasė būtų Studentas.

**Nauja klasė: Žmogus**

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/ed79b3f9-ee99-4d86-bf78-a14454f2b427)

Kadangi Žmogus - abstrakčioji klasė, negalima sukurti šios klasės tipo objekto.

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/e58798d5-1b7c-4d48-a662-d7921f83a2c2)

# **v1.2**

Užduotis: v1.1 kodui pritaikyti Rule of Three taisyklę ir perdengti įvesties/išvesties operatorius Studentas klasei.

**Rule of Three**

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/800f5d0c-6f94-4bf2-8ef3-3e4251dacedd)


Šiai taisyklei demonstruoti prie pasirinkimų duomenis įrašyti ranka, skaityti iš failo arba generuoti failą, pridėtas 4 pasirinkimas - demonstruoti rule of three veikimą.

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/b3357db0-9661-46b7-ad9f-9d18849c14ff)

Rezultatai pasirinkus 4 funkciją:

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/033c1954-bc55-47b3-9e96-40ba2cc1fae9)


**Įvesties ir išvesties operatoriai**

Įvesties ir išvesties operatoriai klasei Studentas pakeisti taip, kad įvedamas/nuskaitomas/išvedamas studento vardas ir pavardė.

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/555e2a56-a50c-4c1f-a533-fc5920b0d499)

# **v1.1**

Užduotis: palyginti programos veikimo greitį naudojant struct ir class duomenų sistemizavimo būdus. Abiejais atvejais naudota v1.0 išanalizuota 3 strategija.

Taip pat stebėsime programos veikimo laiką ir .exe failo užimamą vietą keičiant optimizavimo lygius (-o1, -o2, -o3).

Su struct:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,33 s               |  3,21 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,017 s               |  0,22 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,32 s            |  3,1 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,22 s            |  2,2 s            |
|  **Bendrai užtrukta**                           |  0,88 s            |  8,78 s             |
Užimama vieta: 119 808 bytes.

Su class:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,43 s               |  4,14 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,017 s               |  0,18 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,33 s            |  3,3 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,23 s            |  2,3 s            |
|  **Bendrai užtrukta**                           |  1,02 s            |  9,9 s             |
Užimama vieta: 95 232 bytes.

Struct programa veikia šiek tiek greičiau, tačiau užima daugiau vietos.

SU STRUCT:
Su O1 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,21 s               |  2,06 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,007 s               |  0,11 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,3 s            |  2,9 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,21 s            |  2 s            |
|  **Bendrai užtrukta**                           |  0,73 s            |  7,2 s             |
Užimama vieta: 72 192 bytes.


Su O2 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,2 s               |  2,07 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,007 s               |  0,12 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,3 s            |  2,9 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,2 s            |  2 s            |
|  **Bendrai užtrukta**                           |  0,71 s            |  7,1 s             |
Užimama vieta: 80 384 bytes.

Su O3 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,21 s               |  2,04 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,007 s               |  0,12 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,3 s            |  2,9 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,2 s            |  2,1 s            |
|  **Bendrai užtrukta**                           |  0,72 s            |  7,19 s             |
Užimama vieta: 82 944 bytes.

Programa veikia greičiausiai su -o2 optimizavimo lygiu, o mažiausiai vietos užima su -o1. -o3 yra balansas tarp šių dviejų parametrų.

SU CLASS:
Su O1 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,24 s               |  2,4 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,005 s               |  0,06 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,29 s            |  3 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,21 s            |  2 s            |
|  **Bendrai užtrukta**                           |  0,74 s            |  7,5 s             |
Užimama vieta: 60 928 bytes.

Su O2 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,24 s               |  2,4 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,005 s               |  0,06 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,3 s            |  3 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,21 s            |  2 s            |
|  **Bendrai užtrukta**                           |  0,74 s            |  7,5 s             |
Užimama vieta: 67 584 bytes.

Su O3 flag:
|                                                 |   100000           |    1000000        |
| ----------------------------------------------- |:------------------:|:-----------------:|
|  Failo nuskaitymo vidutinis laikas              |  0,23 s               |  2,35 s              |
|  Failo išrūšiavimo vidutinis laikas             |  0,006 s               |  0,06 s           |
|  Kietiakų failo spausdinimo vidutinis laikas    |  0,3 s            | 3 s            |
|  Vargšelių failo spausdinimo vidutinis laikas   |  0,21 s            |  2,1 s            |
|  **Bendrai užtrukta**                           |  0,74 s            |  7,5 s             |
Užimama vieta: 68 096 bytes.

Tas pats ir su class: programa veikia greičiausiai su -o2 optimizavimo lygiu, o mažiausiai vietos užima su -o1. -o3 yra balansas tarp šių dviejų parametrų.

Lyginant class ir struct rezultatus naudojant optimizavimo lygius, struct visvien veikia šiek tiek greičiau, o mažiau vietos užima class.

Sistemos parametrai:

![image](https://github.com/Mcitas/Antra_uzduotis_DM2_G1_ML/assets/144427355/535590ea-053e-4dd3-ba1d-d38bdab11bf7)

**Naudojimosi instrukcija**

1. Parsisiųsti source ir header aplankus iš šios GitHub repozitorijos. Taip pat RUNMEE.bat ir CMakeLists.txt.
2. Susikurti aplanką norimoje vietoje. Šiame aplanke įkopijuoti src, include aplankus, RUNMEE.bat ir CMakeLists.txt.
3. Paleidžiame RUNMEE (paleidimui reikalinga cmake programa 3.28 versija).
4. Terminalui užsidarius atidarome atsiradusį Debug aplanką. Ten spaudžiame ant v2.0.exe.
5. Pasirenkame duomenų įvedimą (1 - ranka, 2 - skaitymas iš failo), generavimą (3) arba Rule of Three testavimą (4).
  1) a)Įvedame studentų skaičių;
     b)Įvedame kiekvieno studento duomenis (pasirinktų studentų pažymius galima generuoti);
     c)Pasirenkame, pagal kurį parametrą rikiuoti.
  2) a)Įvedame failo pavadinimą, iš kurio norime skaityti duomenis. (Studentai1000.txt yra pavyzdinis duomenų paketas)
     b)Pasirenkame, pagal kurį parametrą rikiuoti.
     c)Programos rezultatai bus surašyti į Debug aplanką, RezultataiVargseliai.txt ir RezultataiKietiakai.txt failus.
  3) a)Įvedame studentų skaičių;
     b)Įvedame studento pažymių skaičių;
     c)Debug aplanke atsiras StudentaiX.txt failas (X - pasirinktas studentų skaičius), kurį galite nuskaityti vėl paleidę .exe programą ir pasirinkę duomenų skaitymą iš failo(2).
  4) a) Stebime rezultatus. 
