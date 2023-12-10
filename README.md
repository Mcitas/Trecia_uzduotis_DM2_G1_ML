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



