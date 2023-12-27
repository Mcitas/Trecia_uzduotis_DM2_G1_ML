# **v1.0**

Ši programa naudojama darbui su studentų pažymiais. Galima skaičiuoti vidurkius, medianas, rikiuoti pagal norimą parametrą (vardą, pavardę, vidurkį).
Programos galimybės:
- duomenų įrašymas ranka;
- duomenų skaitymas iš failų;
- duomenų atsitiktinis generavimas.

**Programos analizė**

Programai rašyti buvo naudojamos 3 skirtingos strategijos ir 2 konteinerių tipai: vector ir list. 
Tačiau kurią strategiją ir kurį konteinerį naudojant programa veikia sparčiausiai?

Testavimui buvo naudojami 5 skirtingo dydžio tekstiniai failai: 1000, 10000, 100000, 1000000, 10000000 duomenų eilučių.
Buvo registruojamas pagrindinių programos dalių veikimo laikas ir bendra jų suma.

**Rezultatai:**

_Vector konteinerio atveju_

|                                               |     1000    |     10000    | 100000   | 1000000    | 10000000     |
| --------------------------------------------- |:-----------:|:------------:|:--------:|:----------:|:------------:|
|  Failo nuskaitymo vidutinis laikas            |  0 s        |   0,03 s     |  0,25 s  |  2,14 s    |   22,8 s     |
|  Failo išrūšiavimo vidutinis laikas           |  0 s        |   0 s        |  0,01 s  |  0,2 s     |  2 s         |
|  Kietiakų failo spausdinimo vidutinis laikas  |  0,09 s     |   0,06 s     |  0,43 s  |  4 s       |   42,2 s     |
|  Vargšelių failo spausdinimo vidutinis laikas |  0,06 s     |   0,03 s     |  0,3 s   |  3,4 s     |   29,2 s     |
|  **Bendrai užtrukta**                         | ** 0,15 s** |  ** 0,12 s** | ** 1 s** | ** 9,9 s** |  ** 96,5 s** |

_List konteinerio atveju_

|                                               |  1000       |  10000       | 100000      | 1000000     | 10000000      |
| --------------------------------------------- |:-----------:|:------------:|:-----------:|:-----------:|:-------------:|
|  Failo nuskaitymo vidutinis laikas            |  0 s        |   0,03 s     | 0,6 s       | 3,5 s       |  34,7 s       |
|  Failo išrūšiavimo vidutinis laikas           |  0 s        |   0 s        | 0,1 s       | 0,84 s      |  8,88 s       |
|  Kietiakų failo spausdinimo vidutinis laikas  |  0,09 s     |  0,06 s      | 0,8 s       | 4,7 s       |  47,5 s       |
|  Vargšelių failo spausdinimo vidutinis laikas |  0,07 s     |   0,05 s     | 0,6 s       | 3,8 s       |  32,3 s       |
|  **Bendrai užtrukta**                         | ** 0,16 s** |  ** 0,14 s** | ** 2,11 s** | ** 12,9 s** |  ** 123,4 s** |

Matome, jog vector tipo konteineris veikia greičiausiai.
O kuri strategija greičiausia?

_Vector konteinerio atveju_
|            |   1 strategija     |    2 strategija   |   3 strategija   | 
| ---------- |:------------------:|:-----------------:|:----------------:|
|  1000      |  0 s               |  0 s              |  0 s             |
|  10000     |  0 s               |  0,01 s           |  0 s             |
|  100000    |  0,05 s            |  0,2 s            | 0,01  s          |
|  1000000   |  0,46 s            |  2,6 s            |  0,2 s           |
|  10000000  |  4,66 s            |  32 s             |  2 s             |

_List konteinerio atveju_
|            |   1 strategija     |    2 strategija   |   3 strategija   | 
| ---------- |:------------------:|:-----------------:|:----------------:|
|  1000      |  0 s               | 0  s              |  0 s             |
|  10000     |  0,01 s            | 0,01  s           |  0 s             |
|  100000    |  0,12 s            |  0,07 s           |  0,1 s           |
|  1000000   | 0,47 s             | 0,8  s            | 0,84  s          |
|  10000000  |  15,4 s            |  8 s              |  8,88 s          |

Kaip matome, sparčiausiai veikė vector tipo konteineris naudojant 3 strategiją.

**Naudojimosi instrukcija**

1. Parsisiųsti source ir header failus iš šios GitHub repozitorijos (3 strategija, jei norime greičiausios programos). Taip pat RUNMEE.bat, Studentai1000.txt ir CMakeLists.txt.
2. Susikurti aplanką norimoje vietoje. Šiame aplanke įkopijuoti RUNMEE ir CMakeLists ir susikurti dar du aplankus: src ir include.
3. src ir include aplankuose atitinkamai sukelti source ir header failus. Taip pat į src failą įkelti Studentai1000.txt.
4. Paleidžiame RUNMEE (paleidimui reikalinga cmake programa 3.28 versija).
5. Terminalui užsidarius atidarome atsiradusį Debug aplanką. Ten spaudžiame ant v1.0_strat3.exe.
6. Pasirenkame, su kurio tipo konteineriu dirbsime.
7. Pasirenkame duomenų įvedimą (1 - ranka, 2 - skaitymas iš failo) arba generavimą (3).
  1) a)Įvedame studentų skaičių;
     b)Įvedame kiekvieno studento duomenis (pasirinktų studentų pažymius galima generuoti);
     c)Pasirenkame, pagal kurį parametrą rikiuoti.
  2) a)Įvedame failo pavadinimą, iš kurio norime skaityti duomenis. (Studentai1000.txt yra pavyzdinis duomenų paketas)
     b)Pasirenkame, pagal kurį parametrą rikiuoti.
     c)Programos rezultatai bus surašyti į Debug aplanką, RezultataiVargseliai.txt ir RezultataiKietiakai.txt failus.
  3) a)Įvedame studentų skaičių;
     b)Įvedame studento pažymių skaičių;
     c)Debug aplanke atsiras StudentaiX.txt failas (X - pasirinktas studentų skaičius), kurį galite nuskaityti vėl paleidę .exe programą ir pasirinkę duomenų skaitymą iš failo(2).
     


