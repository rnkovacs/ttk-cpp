# Beadandók

Az elkészült feladatokat a `rekanikolett@gmail.com` cimre várom, ideális esetben `[TTK C++]` kezdetű tárggyal.

## 0. Mario piramis

**Beadási határidő**: február 27.

Rajzoljuk ki a terminálra a Mario játékból ismert lépcsősort! A magasságát a felhasználótól kérjük be. (1 pont)

<img src="http://www.infendo.com/wp-content/uploads/2008/06/mario.png" height="220"> <img src="http://www.korenlc.com/wp-content/uploads/2014/03/mario.jpg1.png" height="220">

Kérdezzük meg a felhasználótól, hogy fél- vagy egész piramist szeretne-e látni. Ha egészet, akkor a lépcsősor tükörképe is jelenjen meg a jobboldalon. A két fél legyen vizuálisan elkülönitve. (+ 2 pont)

```
   ## ##
  ### ###
 #### ####
##### #####
```

## 1. Hitelkártya

**Beadási határidő**: március 13.

Irjunk egy programot, ami eldönti a felhasználótól beolvasott kártyaszámról, hogy
valódi-e (5 pont). A beolvasott szám tárolására használjunk `long long` tipust.
A validálást a [Luhn-algoritmussal](https://hu.wikipedia.org/wiki/Luhn-formula) végezzük!

Legyen szó első körben MasterCard kártyákról. Ezekről azt tudjuk,
hogy 16 számjegyből állnak, és az első két számjegyük az alábbi lehetőségek közül
kerül ki: 51, 52, 53, 53, 55. A program viselkedése legyen a következő:

```
$ ./credit
Card number: -378
Invalid

$ ./credit
Card number: foo
Invalid

$ ./credit
Card number: 4716904945120806
Invalid

$ ./credit
Card number: 5531762164721732
Valid
```

(+ 2 pont) Ismerjünk fel más kártyatipusokat is! A Visa kártyák számai 4-essel
kezdődnek, és vagy 13, vagy 16 számjegyből állnak. Az American Express kártyák
15 számjegyből állnak, és 34-re vagy 37-re kezdődnek.

```
$ ./credit
Card number: 4716904945120806
Visa

$ ./credit
Card number: 5531762164721732
MasterCard

$ ./credit
Card number: 370214777555219
American Express

$ ./credit
Card number: 4716904945120807
Invalid

$ ./credit
Card number: 4716904
Invalid
```
Teszteléshez valid hitelkártya-számokat [itt](http://www.getcreditcardnumbers.com/how-to-get-a-master-card-credit-card) találtok.


## 2. Mátrixszorzás

**Beadási határidő**: április 3.

Irjunk egy mátrixszorzó programot! (8 pont) A bemenet két szöveges fájl, ami a várakozásaink szerint egy-egy mátrixot tartalmaz. A fájlok neveit a felhasználó parancssori argumentumként adja meg, ahogyan a kimeneti fájl kivánt nevét is. Utóbbit mi hozzuk létre, hogy beleirjuk a mátrixszorzás eredményét.

Ha kevesebb, mint két parancssori argumentumot kapunk a felhasználótól (a program nevén kivül), vagy többet, mint hármat, akkor irjunk ki egy segitő szöveget, pl.

```
$ ./matmul 
Matrix multiplier program.

Usage: ./matmul [IN1] [IN2] [OUT]
IN1 : input matrix file 1,
IN2 : input matrix file 2,
OUT : output file to store the result.
```

A `Usage` szó után mindig a futtatható állomány neve iródjon ki (attól függetlenül, milyen névre kereszteli, aki forditja, pl. Windowson lehet `enyem.exe` is)! Ha csak két parancssori bemenetet kapunk a program neve után (`IN1` és `IN2`), akkor egy általunk választott alapértelmezett nevű fájlba rakjuk el az eredményt, és erről tájékoztassuk a felhasználót. Pl.

```
$ ./matmul m1.data m2.data
[Note] No output path specified, using default output location. 
[Note] Results will be saved to './product.data'.
...
```

Ne feledjük, hogy a bemeneti fájlokból csak akkor tudunk olvasni, ha sikerült őket megnyitni. Ez igaz arra a fájlra is, amibe irni fogunk. 

A bemeneti mátrixok olvasásakor (ill. utána) ellenőrizzük a méreteiket! Egy mátrixnak minden sora ugyanolyan hosszú, valamint két mátrixot csak akkor tudunk összeszorozni, ha az első mátrix oszlopainak a száma megegyezik a második mátrix sorainak a számával. Ha ezek közül valamelyik nem teljesül, akkor tájékoztassuk a felhasználót a problémáról, és lépjünk ki a programból. Pl.

```
$ ./matmul m1.data m2.data out.data
[Error] Matrix in 'm1.data' is ill-formed (different row lengths).
```

Figyeljünk rá, hogy a programkódunk szép moduláris legyen, pl. a mátrixszorzás logikája legyen külön függvényben. Ezen a ponton még feltételezhetjük, hogy a mátrixaink nem lesznek túl nagyok. Az alapfeladat helyes megoldásán felül kreativitásért és extra hozzáadott értékért pluszpontok szerezhetők.
