# **v3.0**

Užduotis: sukurti setup.msi installer'į v1.5 programai.

**Naudojimosi instrukcija**

1. Parsisiųsti ProgramInstallSetup.msi iš šios GitHub repozitorijos.
2. Paleidžiame ProgramInstallSetup.msi ir, pasirinke norimus parametrus, suinstaliuojame programą.
3. Atsidarome instaliavimo vietą ir paleidžiame AppWithDll.exe arba paleidžiame darbalaukyje atsiradusį MyConsoleApp.
4. Pasirenkame duomenų įvedimą (1 - ranka, 2 - skaitymas iš failo), generavimą (3) arba Rule of Three testavimą (4).
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
